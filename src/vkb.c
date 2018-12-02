#include "vkb.h"

#include <string.h>
#include <math.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>

#include "doomstat.h"

//#undef _HARMATTAN_RESC // for local test
#ifdef _HARMATTAN_RESC
#define RESC _HARMATTAN_RESC
#else
#define RESC "resc/"
#endif

#define VB_S(n) (n * VB_SPACING)
#define VB_W(n) (n * VB_WIDTH)
#define VB_H(n) (n * VB_HEIGHT)
#define VB_S2(n) (VB_S(n) / 3 * 2)
#define VB_W2(n) (VB_W(n) / 3 * 2)
#define VB_H2(n) (VB_H(n) / 3 * 2)
#define TEX_W(n) (n * TEX_WIDTH)
#define TEX_H(n) (n * TEX_HEIGHT)

#define VKB_BUTTON_Z_BASE 2000
#define VKB_SWIPE_Z_BASE 1000
#define VKB_JOYSTICK_Z_BASE 3000 
#define VKB_CURSOR_Z_BASE 4000

#define CIRCLECENTERX 182
#define CIRCLECENTERY 308
#define JOYSTICKOFFSET 70
//small circle 139x139 center point (70,70)
//x offset=69 y offset=69
#define BIGCIRCLEX 0
#define BIGCIRCLEY 0
#define SMALLCIRCLEX 294
#define SMALLCIRCLEY 89
#define BIGCIRCLEWIDTH 283
#define SMALLCIRCLEWIDTH 139
#define MYARG 22.5

#define CIRCLEHALFLENGTH 185.0
#define CIRCLEHALFLENGTHWITHOUTLISTENER 25.0

#define TRANSLUCENTLEVEL 157

unsigned client_state = 0;
boolean render_lock = false;
unsigned open_keyboard = 0;

// array of int pointer, see g_game.c
static const int *Action_Cmds[Total_Action] = {
	&key_up,
	&key_down,
	&key_strafeleft,
	&key_straferight,
	&key_fire,
	&key_escape, // &key_setup,
	&key_use,
	&key_autorun,
	&key_weapontoggle,
	&key_weapon1,
	&key_weapon2,
	&key_weapon3,
	&key_weapon4,
	&key_weapon5,
	&key_weapon6,
	&key_weapon7,
	&key_weapon8,
	&key_weapon9,
	&key_reverse,
	&key_left,
	&key_right,

	&key_pause,
	&key_menu_right,
	&key_menu_left,
	&key_menu_up,
	&key_menu_down,
	&key_menu_backspace,
	&key_menu_escape,
	&key_menu_enter,

	&key_map,
	&key_map_up,
	&key_map_down,
	&key_map_left,
	&key_map_right,
	&key_map_zoomin,
	&key_map_zoomout,
	&key_map_overlay,

	&key_savegame,
	&key_loadgame,
	&key_zoomin,
	&key_zoomout,
	&key_help,
	&key_quicksave,
	&key_quickload,
	&key_quit,
	&key_screenshot,

	NULL,
	NULL,
};

// SDL key, will convert to DOOM key, see SDL/i_video.c
static int Key_Defs[Total_Key - Up_Key] = {
	SDLK_UP,
	SDLK_DOWN,
	SDLK_LEFT,
	SDLK_RIGHT,
	SDLK_ESCAPE,
	'~',
	SDLK_PAGEUP,
	SDLK_PAGEDOWN,
	SDLK_TAB,
	SDLK_LSHIFT,
	SDLK_RETURN,
	SDLK_BACKSPACE,
	SDLK_SPACE,
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',
	'g',
	'h',
	'i',
	'j',
	'k',
	'l',
	'm',
	'n',
	'o',
	'p',
	'q',
	'r',
	's',
	't',
	'u',
	'v',
	'w',
	'x',
	'y',
	'z',
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'_',
	'-',
	'.',
	'/',
	'+',
	'=',
	'?',
	'\\',
	SDL_BUTTON_LEFT
};

// other cheat use open keyboard to input. see m_cheat.c
static int Cmd_Strs[Total_Cmd - God_Cmd] = {
	2, // GOD mode iddqd
	3, //give all idkfa
	5, //noclip idclip
	10, // power up idbeholds
};

// my function pointer void (*)(void)
static void * Func_Ptrs[Total_Func - OpenKeyboard_Func] = {
	karinOpenKeyboard,
	karinCloseKeyboard,
	karinToggleKeyboard,
};

const char *Tex_Files[VKB_TEX_COUNT] = {
	RESC"anna_buttons.png",
	RESC"circle_joystick.png",
	RESC"A-Z_u.png",
	RESC"0-9.png",
	RESC"a-z_l.png"
};

struct vkb_cursor VKB_Cursor[CURSOR_COUNT] = {
	{VB_S(0) + VB_W(6), VB_S(2), VB_W(2) + VB_S(1), 
		0.5, 3.0, true, 1, 0.0,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		0.5, SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		opengl_e_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 3, VKB_In_Game,
		Total_Action, Total_Action, Total_Action, TurnLeft_Action, TurnRight_Action}, // ???
	{VB_S(7) + VB_W(2), VB_S(5) + VB_W(1), VB_W(1) + VB_S(2),
		1.0, 5.0, false, 0, 0.0,
		0, 0, 0,
		1.0, TEX_W(2), TEX_W(3), TEX_W(1),
		TEX_W(2), TEX_W(4), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 2, VKB_In_Game,
		Attack_Action, 
		// TurnUp_Action, TurnDown_Action, TurnLeft_Action, TurnRight_Action
		Mouse1_Button, Mouse1_Button, Mouse1_Button, Mouse1_Button
	}
};

struct vkb_swipe VKB_Swipe[SWIPE_COUNT] = {
	{HARMATTAN_WIDTH / 4 * 3, 0, HARMATTAN_WIDTH, HARMATTAN_HEIGHT,
		HARMATTAN_WIDTH / 4 * 3, 0, HARMATTAN_WIDTH, HARMATTAN_HEIGHT, false,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		opengl_e_base, opengl_s_base, true, VKB_SWIPE_Z_BASE + 1, VKB_In_Game, 
		//TurnUp_Action, TurnDown_Action, TurnLeft_Action, TurnRight_Action
		Total_Action,
		Mouse1_Button, Mouse1_Button, Mouse1_Button, Mouse1_Button
		}
};

struct vkb_joystick VKB_Joystick[JOYSTICK_COUNT] = {
	{VB_S(1), VB_S(1), VB_W(3) + VB_S(2), 
		0.0f, 1.8f,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		0.5, SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		opengl_s_base, opengl_s_base, true, VKB_JOYSTICK_Z_BASE + 1, VKB_In_Game, 
		Forward_Action, Backward_Action, MoveLeft_Action, MoveRight_Action}, // game arrow
	{VB_S(1), VB_S(1), VB_W(3) + VB_S(2), 
		0.0f, 1.0f,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		0.5, SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		opengl_s_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 50, VKB_In_Map, 
		MapUp_Action, MapDown_Action, MapLeft_Action, MapRight_Action}, // map arrow
	{VB_S(1), VB_S(1), VB_W(3) + VB_S(2), 
		0.0f, 1.0f,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		0.5, SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		opengl_s_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 100, VKB_In_Menu, 
		MenuUp_Action, MenuDown_Action, MenuLeft_Action, MenuRight_Action}, // menu arrow
	{VB_S(1), VB_S(1), VB_W(3) + VB_S(2), 
		0.0f, 1.0f,
		BIGCIRCLEX, BIGCIRCLEY + BIGCIRCLEWIDTH, BIGCIRCLEWIDTH,
		0.5, SMALLCIRCLEX, SMALLCIRCLEY + SMALLCIRCLEWIDTH, SMALLCIRCLEWIDTH,
		opengl_s_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 200, VKB_In_Message, 
		Up_Key, Down_Key, Left_Key, Right_Key} // keyboard arrow
};

struct vkb_button VKB_Button[VKB_COUNT] = {
	// game
	{VB_S(1) + VB_W(1), VB_S(3) + VB_H(2), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1), VB_S(3) + VB_H(2), VB_W(1), VB_H(1),  
		TEX_W(5), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		UseItem_Action},
	{VB_S(1) + VB_W(1), VB_S(2) + VB_H(1), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1), VB_S(2) + VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		WeaponToggle_Action},
	{VB_S(1) + VB_W(1), VB_S(1), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1), VB_S(1), VB_W(1), VB_H(1),  
		TEX_W(2), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Run_Action},
	/*
	{VB_S(-1) + VB_W(2), VB_S(0), VB_W(1), VB_H(1), 
		VB_S(-1) + VB_W(2), VB_S(0), VB_W(1), VB_H(1),  
		TEX_W(2), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		PrevWeapon_Action},
	{VB_S(-2) + VB_W(1), VB_S(0), VB_W(1), VB_H(1), 
		VB_S(-2) + VB_W(1), VB_S(0), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		NextWeapon_Action},
		*/
	{VB_S(2) + VB_W(2), VB_S(1), VB_W(1), VB_H(1), 
		VB_S(2) + VB_W(2), VB_S(1), VB_W(1), VB_H(1),  
		TEX_W(0), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Reverse_Action},
	{VB_S(5) + VB_W(2), VB_S(2) + VB_H(2), VB_W(1), VB_H(1), 
		VB_S(5) + VB_W(2), VB_S(2) + VB_H(2), VB_W(1), VB_H(1),  
		TEX_W(2), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_s_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		QuickLoad_Action},
	{VB_S(4) + VB_W(1), VB_S(2) + VB_H(2), VB_W(1), VB_H(1), 
		VB_S(4) + VB_W(1), VB_S(2) + VB_H(2), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(4), TEX_W(1), -TEX_W(1),
		TEX_W(3), TEX_W(5), TEX_W(1), -TEX_W(1),
		opengl_s_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		QuickSave_Action},

	// weapons 1 - 9
	{VB_S(4) + VB_W(1) / 2 * 9, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(4) + VB_W(1) / 2 * 9, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(6), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon1_Action},
	{VB_S(3) + VB_W(1) / 2 * 7, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(3) + VB_W(1) / 2 * 7, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(7), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon2_Action},
	{VB_S(2) + VB_W(1) / 2 * 5, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(2) + VB_W(1) / 2 * 5, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(7), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon3_Action},
	{VB_S(1) + VB_W(1) / 2 * 3, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1) / 2 * 3, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(1), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon4_Action},
	{VB_W(1) / 2, VB_H(1), VB_W(1), VB_H(1), 
		VB_W(1) / 2, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_mb_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon5_Action},
	{VB_S(1) + VB_W(1) / 2, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1) / 2, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(2), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_mf_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon6_Action},
	{VB_S(2) + VB_W(1) / 2 * 3, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(2) + VB_W(1) / 2 * 3, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(0), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_mf_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon7_Action},
	{VB_S(3) + VB_W(1) / 2 * 5, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(3) + VB_W(1) / 2 * 5, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(1), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_mf_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon8_Action},
	{VB_S(4) + VB_W(1) / 2 * 7, VB_H(1), VB_W(1), VB_H(1), 
		VB_S(4) + VB_W(1) / 2 * 7, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(6), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_mf_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 1, VKB_In_Game, 0,
		Weapon9_Action},

	// second attack in left hand
	{VB_S(2), VB_S(2) + VB_H(2), VB_W(1), VB_H(1), 
		VB_S(2), VB_S(2) + VB_H(2), VB_W(1), VB_H(1),  
		TEX_W(2), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_s_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Game, 0,
		Attack_Action},

	// map
	{VB_W(1) + VB_S(1), VB_H(2) + VB_S(2), VB_W(1), VB_H(1), 
		VB_W(1) + VB_S(1), VB_H(2) + VB_S(2), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 50, VKB_In_Game | VKB_In_Map, 0,
		Map_Action},
	{VB_S(3) + VB_W(3), VB_S(1), VB_W(1), VB_H(1), 
		VB_S(3) + VB_W(3), VB_S(1), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 50, VKB_In_Game | VKB_In_Map, 0,
		MapOverlay_Action},
	{VB_S(1) + VB_W(1), VB_S(3) + VB_H(2), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1), VB_S(3) + VB_H(2), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 50, VKB_In_Map, 0,
		MapZoomIn_Action},
	{VB_S(1) + VB_W(1), VB_S(2) + VB_H(1), VB_W(1), VB_H(1), 
		VB_S(1) + VB_W(1), VB_S(2) + VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(2), TEX_W(1), -TEX_W(1),
		TEX_W(4), TEX_W(3), TEX_W(1), -TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 50, VKB_In_Map, 0,
	MapZoomOut_Action},


	// menu
	{VB_W(1), VB_H(1), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(1), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 100, VKB_In_Menu, 0,
		MenuEscape_Action}, // escape
	{VB_S(6) + VB_W(2), VB_S(6) + VB_H(1), VB_W(1), VB_H(1),
		VB_S(6) + VB_W(2), VB_S(6) + VB_H(1), VB_W(1), VB_H(1),
		TEX_W(2), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 100, VKB_In_Menu, 0,
		MenuEnter_Action}, //enter
	{VB_S(2) + VB_W(1), VB_S(6) + VB_H(1), VB_W(1), VB_H(1),
		VB_S(2) + VB_W(1), VB_S(6) + VB_H(1), VB_W(1), VB_H(1),
		TEX_W(7), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_CURSOR_Z_BASE + 100, VKB_In_Menu, 0,
		MenuBackspace_Action}, // cancel
	{VB_S(6) + VB_W(2), VB_S(2) + VB_H(0), VB_W(1), VB_H(1), 
		VB_S(6) + VB_W(2), VB_S(2) + VB_H(0), VB_W(1), VB_H(1),  
		TEX_W(1), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 100, VKB_In_Menu, 0,
		Y_Key}, // yes
	{VB_S(2) + VB_W(1), VB_S(2) + VB_H(0), VB_W(1), VB_H(1), 
		VB_S(2) + VB_W(1), VB_S(2) + VB_H(0), VB_W(1), VB_H(1),  
		TEX_W(0), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 100, VKB_In_Menu, 0,
		N_Key}, // no
	
	// general
	{0, VB_H(1), VB_W(1), VB_H(1), 
		0, VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_s_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 500, VKB_In_All, 0,
		Pause_Action},
	{VB_W(1), VB_H(1), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(1), VB_W(1), VB_H(1),  
		TEX_W(1), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 500, VKB_In_All, 0,
		Menu_Action},
	{VB_W(2) + VB_S(2), VB_H(2) + VB_S(2), VB_W(1), VB_H(1), 
		VB_W(2) + VB_S(2), VB_H(2) + VB_S(2), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_e_base, true, VKB_BUTTON_Z_BASE + 500, VKB_In_Game | VKB_In_Message | VKB_In_Menu, 0,
	ToggleKeyboard_Func},

	// cheat
	{VB_W(5) + VB_S(4), VB_H(3) + VB_S(6), VB_W(1), VB_H(1), 
		VB_W(5) + VB_S(4), VB_H(3) + VB_S(6), VB_W(1), VB_H(1),  
		TEX_W(5), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		God_Cmd},
	{VB_W(4) + VB_S(3), VB_H(3) + VB_S(6), VB_W(1), VB_H(1), 
		VB_W(4) + VB_S(3), VB_H(3) + VB_S(6), VB_W(1), VB_H(1),  
		TEX_W(7), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		GiveAll_Cmd},
	{VB_W(3) + VB_S(2), VB_H(3) + VB_S(6), VB_W(1), VB_H(1), 
		VB_W(3) + VB_S(2), VB_H(3) + VB_S(6), VB_W(1), VB_H(1),  
		TEX_W(6), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		NoClip_Cmd},
	{VB_W(2) + VB_S(1), VB_H(3) + VB_S(6), VB_W(1), VB_H(1), 
		VB_W(2) + VB_S(1), VB_H(3) + VB_S(6), VB_W(1), VB_H(1),  
		TEX_W(0), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		PowerUp_Cmd},

	// 1 - 9 - 0
	{VB_W2(1) + VB_S2(1) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(1) + VB_S2(1) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num0_Key},
	{VB_W2(2) + VB_S2(2) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(2) + VB_S2(2) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num9_Key},
	{VB_W2(3) + VB_S2(3) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(3) + VB_S2(3) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(7), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num8_Key},
	{VB_W2(4) + VB_S2(4) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(4) + VB_S2(4) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(6), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num7_Key},
	{VB_W2(5) + VB_S2(5) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(5) + VB_S2(5) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(5), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num6_Key},
	{VB_W2(6) + VB_S2(6) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(6) + VB_S2(6) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(4), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num5_Key},
	{VB_W2(7) + VB_S2(7) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(7) + VB_S2(7) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num4_Key},
	{VB_W2(8) + VB_S2(8) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(8) + VB_S2(8) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num3_Key},
	{VB_W2(9) + VB_S2(9) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(9) + VB_S2(9) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num2_Key},
	{VB_W2(10) + VB_S2(10) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1), 
		VB_W2(10) + VB_S2(10) + VB_W(1), VB_H2(4) + VB_S2(4), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Num1_Key},

		// p - q
	{VB_W2(1) + VB_S2(1) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(1) + VB_S2(1) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		P_Key},
	{VB_W2(2) + VB_S2(2) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(2) + VB_S2(2) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		O_Key},
	{VB_W2(3) + VB_S2(3) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(3) + VB_S2(3) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(7), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		I_Key},
	{VB_W2(4) + VB_S2(4) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(4) + VB_S2(4) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(6), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		U_Key},
	{VB_W2(5) + VB_S2(5) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(5) + VB_S2(5) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(5), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Y_Key},
	{VB_W2(6) + VB_S2(6) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(6) + VB_S2(6) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(4), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		T_Key},
	{VB_W2(7) + VB_S2(7) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(7) + VB_S2(7) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		R_Key},
	{VB_W2(8) + VB_S2(8) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(8) + VB_S2(8) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		E_Key},
	{VB_W2(9) + VB_S2(9) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(9) + VB_S2(9) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		W_Key},
	{VB_W2(10) + VB_S2(10) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1), 
		VB_W2(10) + VB_S2(10) + VB_W(1), VB_H2(3) + VB_S2(3), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Q_Key},

	// l - a
	{VB_W2(1) + VB_S2(1) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(1) + VB_S2(1) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		L_Key},
	{VB_W2(2) + VB_S2(2) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(2) + VB_S2(2) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		K_Key},
	{VB_W2(3) + VB_S2(3) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(3) + VB_S2(3) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		J_Key},
	{VB_W2(4) + VB_S2(4) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(4) + VB_S2(4) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(7), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		H_Key},
	{VB_W2(5) + VB_S2(5) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(5) + VB_S2(5) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(6), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		G_Key},
	{VB_W2(6) + VB_S2(6) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(6) + VB_S2(6) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(5), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		F_Key},
	{VB_W2(7) + VB_S2(7) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(7) + VB_S2(7) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(4), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		D_Key},
	{VB_W2(8) + VB_S2(8) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(8) + VB_S2(8) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		S_Key},
	{VB_W2(9) + VB_S2(9) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1), 
		VB_W2(9) + VB_S2(9) + VB_W(1) + VB_W2(1) / 2 + VB_S2(1) / 2, VB_H2(2) + VB_S2(2), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		A_Key},

	// m - z
	{VB_W2(1) + VB_S2(1) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(1) + VB_S2(1) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(1), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(1), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		M_Key},
	{VB_W2(2) + VB_S2(2) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(2) + VB_S2(2) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		N_Key},
	{VB_W2(3) + VB_S2(3) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(3) + VB_S2(3) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(7), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		B_Key},
	{VB_W2(4) + VB_S2(4) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(4) + VB_S2(4) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(6), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		V_Key},
	{VB_W2(5) + VB_S2(5) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(5) + VB_S2(5) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(5), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		C_Key},
	{VB_W2(6) + VB_S2(6) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(6) + VB_S2(6) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(4), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		X_Key},
	{VB_W2(7) + VB_S2(7) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1), 
		VB_W2(7) + VB_S2(7) + VB_W(1) + VB_W2(3) / 2 + VB_S2(3) / 2, VB_H2(1) + VB_S2(1), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Z_Key},
	
	// _ - . / + = ! ?
	{VB_W2(1) + VB_S2(1) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(1) + VB_S2(1) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(0), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(0), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Question_Key},
	{VB_W2(2) + VB_S2(2) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(2) + VB_S2(2) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(6), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Period_Key},
	{VB_W2(3) + VB_S2(3) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(3) + VB_S2(3) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		BackSlash_Key},
	{VB_W2(4) + VB_S2(4) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(4) + VB_S2(4) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Slash_Key},

	{VB_W2(6) + VB_S2(6) + VB_W(1), VB_S2(0), VB_W2(2) + VB_S2(1), VB_H2(1), 
		VB_W2(6) + VB_S2(6) + VB_W(1), VB_S2(0), VB_W2(2) + VB_S2(1), VB_H2(1),  
		TEX_W(6), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(6), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 4,
		Space_Key},

	{VB_W2(7) + VB_S2(7) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(7) + VB_S2(7) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Underscore_Key},
	{VB_W2(8) + VB_S2(8) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(8) + VB_S2(8) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(2), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(2), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 2,
		Minus_Key},
	{VB_W2(9) + VB_S2(9) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(9) + VB_S2(9) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(4), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Equal_Key},
	{VB_W2(10) + VB_S2(10) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1), 
		VB_W2(10) + VB_S2(10) + VB_W(1), VB_S2(0), VB_W2(1), VB_H2(1),  
		TEX_W(3), TEX_W(3), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(4), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 3,
		Plus_Key},


	// special
	{VB_W(1), VB_H(4) + VB_S(5), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(4) + VB_S(5), VB_W(1), VB_H(1),  
		TEX_W(3), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(3), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		PageUp_Key},
	{VB_W(1), VB_H(3) + VB_S(4), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(3) + VB_S(4), VB_W(1), VB_H(1),  
		TEX_W(5), TEX_W(1), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(2), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		PageDown_Key},
	
	{VB_W(1), VB_H(2) + VB_S(3), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(2) + VB_S(3), VB_W(1), VB_H(1),  
		TEX_W(5), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(5), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 4,
		Backspace_Key},

	{VB_W(1), VB_H(1) + VB_S(2), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(1) + VB_S(2), VB_W(1), VB_H(1),  
		TEX_W(6), TEX_W(6), TEX_W(1), -TEX_W(1),
		TEX_W(6), TEX_W(7), TEX_W(1), -TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 4,
		Shift_Key},
	{VB_W(1), VB_H(0) + VB_S(1), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(0) + VB_S(1), VB_W(1), VB_H(1),  
		TEX_W(7), TEX_W(7), TEX_W(1), TEX_W(1),
		TEX_W(7), TEX_W(8), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 4,
		Enter_Key},
	/*
	{VB_W(1), VB_H(5) + VB_S(6), VB_W(1), VB_H(1), 
		VB_W(1), VB_H(5) + VB_S(6), VB_W(1), VB_H(1),  
		TEX_W(4), TEX_W(5), TEX_W(1), TEX_W(1),
		TEX_W(4), TEX_W(6), TEX_W(1), TEX_W(1),
		opengl_e_base, opengl_s_base, true, VKB_BUTTON_Z_BASE + 200, VKB_In_Message, 0,
		Tab_Key},
		*/
};

int karinGetActionData(unsigned action, intptr_t *rkey)
{
	int r;
	const int *command;
	int l = 0;
	int j;

	if(!rkey)
		return -1; // data is null
	if(action >= Total_Func)
		return -2; // action is invalid

	r = Invalid_Data;
	command = NULL;

	if(action < Total_Action)
	{
		command = Action_Cmds[action];
		if(command)
		{
			r = Action_Data;
			*rkey = *command;
		}
		else
		{
			r = Invalid_Data;
			//*rkey = 0;
		}
	}
	else if(action > Total_Action && action < Total_Key)
	{
		*rkey = Key_Defs[action - Up_Key];
		r = (action >= Mouse1_Button ? Button_Data : (action <= Enter_Key ? Key_Data : Char_Data));
	}
	else if(action > Total_Key && action < Total_Cmd)
	{
		*rkey = Cmd_Strs[action - God_Cmd];
		r = Cmd_Data;
	}
	else if(action > Total_Cmd && action < Total_Func)
	{
		*rkey = (intptr_t)Func_Ptrs[action - OpenKeyboard_Func];
		r = Func_Data;
	}
	return r;
}

float karinFormatAngle(float angle)
{
	int i = (int)angle;
	float f = angle - i;
	float r = 0.0;
	if(angle > 360)
	{
		r = i % 360 + f;
	}
	else if(angle < 0)
	{
		r = 360 - abs(i % 360 + f);
	}
	else
		r = angle;
	if(r == 360.0)
		r = 0.0;
	return r;
}

void karinToggleKeyboard(void)
{
	open_keyboard ^= 1;
}

void karinOpenKeyboard(void)
{
	open_keyboard = 1;
}

void karinCloseKeyboard(void)
{
	open_keyboard = 0;
}

unsigned karinGetClientState(void)
{
	//if(menuactive || (gamestate != GS_LEVEL && gamestate != GS_INTERMISSION && gamestate != GS_FINALE) || paused || demoplayback )
	if(open_keyboard)
		client_state = VKB_In_Message;
	else if(menuactive || gamestate == GS_DEMOSCREEN || paused || demoplayback )
		client_state = VKB_In_Menu;
	else
	{
		if ((automapmode & am_active) && (automapmode & am_overlay) == 0) // overlay map is not show any buttons of map layer.
			client_state = VKB_In_Map;
		else
			client_state = VKB_In_Game;
	}
	return client_state;
}

