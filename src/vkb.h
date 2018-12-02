#ifndef _KARIN_VKB_H
#define _KARIN_VKB_H

#include "harmattan.h"
#include "g_game.h"
#include "m_cheat.h"

#define HARMATTAN_WIDTH 854
#define HARMATTAN_HEIGHT 480
#define HARMATTAN_NO_FULL_HEIGHT 376

#define N950_W HARMATTAN_WIDTH
#define N950_H HARMATTAN_HEIGHT

#define FREMANTLE_WIDTH 800
#define FREMANTLE_HEIGHT 480

#define NO_BINDING_KEY -1

// _ - . ? ! /
#define VKB_COUNT ((17 + 1 + 3 + 4) + 5 + 2 + (26 + 10 + 5 + 9))// button style, game + map + general + keyboard
#define JOYSTICK_COUNT (1 + 1 + 1 + 1)// joystick style, game, menu, keyboard, map
#define SWIPE_COUNT 1 // swipe style // 0
#define CURSOR_COUNT 2 // cursor style // 0
#define TOTAL_VKB_COUNT (VKB_COUNT + SWIPE_COUNT + JOYSTICK_COUNT + CURSOR_COUNT)

#define VKB_TEX_COUNT 5

#define VB_WIDTH 64
#define VB_HEIGHT 64
#define VB_SPACING 10

#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define TEX_FULL_WIDTH 512
#define TEX_FULL_HEIGHT 512

enum{
	VKB_In_Game = K_MASK(0), // GS_LEVEL
	VKB_In_Map = K_MASK(1),
	VKB_In_Message = K_MASK(2),
	VKB_In_Menu = K_MASK(3),
	VKB_In_Loading = K_MASK(4),
	VKB_In_All = K_MASK_ALL,
};

enum {
	Position_Coord = 0,
	Texture_Coord,
	Total_Coord
};

typedef unsigned int uint;
typedef float clampf;
typedef unsigned uenum;
typedef int sizei;

typedef enum _vkb_type
{
	vkb_button_type = 0,
	vkb_joystick_type,
	vkb_swipe_type,
	vkb_cursor_type,
	vkb_total_type
} vkb_type;

typedef enum _circle_direction
{
	circle_center = 0,
	circle_top_direction,
	circle_righttop_direction,
	circle_right_direction,
	circle_rightbottom_direction,
	circle_bottom_direction,
	circle_leftbottom_direction,
	circle_left_direction,
	circle_lefttop_direction,
	circle_outside
} circle_direction;

typedef enum _coord_base
{
	opengl_s_base = 0,
	opengl_mf_base,
	opengl_mb_base,
	opengl_e_base
} coord_base;

typedef enum _mouse_motion_button_status
{
	all_out_range_status = 0,
	last_out_now_in_range_status = 1,
	last_in_now_out_range_status = 1 << 1,
	all_in_range_status = last_out_now_in_range_status | last_in_now_out_range_status
} mouse_motion_button_status;

enum{
	Invalid_Data = 0,
	Cmd_Data, // for cheat, int
	Key_Data, // key, int
	Char_Data, // character, int
	Button_Data, // mouse, int
	Action_Data, // game action
	Func_Data, // function, void (*) (void)
};

// sort by setting in Q2
typedef enum _Game_Act
{
	// order by Harmattan ver
	Forward_Action,
	Backward_Action,
	MoveLeft_Action,
	MoveRight_Action,
	Attack_Action,
	Menu_Action, //
	UseItem_Action,
	Run_Action,
	WeaponToggle_Action, //
	//NextWeapon_Action,
	//PrevWeapon_Action,
	Weapon1_Action,
	Weapon2_Action,
	Weapon3_Action,
	Weapon4_Action,
	Weapon5_Action,
	Weapon6_Action,
	Weapon7_Action,
	Weapon8_Action,
	Weapon9_Action,
	Reverse_Action,
	TurnLeft_Action,
	TurnRight_Action,

	// others
	Pause_Action,
	MenuRight_Action,
	MenuLeft_Action,
	MenuUp_Action,
	MenuDown_Action,
	MenuBackspace_Action,
	MenuEscape_Action,
	MenuEnter_Action,

	// map
	Map_Action,
	MapUp_Action,
	MapDown_Action,
	MapLeft_Action,
	MapRight_Action,
	MapZoomIn_Action,
	MapZoomOut_Action,
	MapOverlay_Action,

	SaveGame_Action,
	LoadGame_Action,
	ZoomIn_Action,
	ZoomOut_Action,
	Help_Action,
	QuickSave_Action,
	QuickLoad_Action,
	Quit_Action,
	ScreenShot_Action,
//int     mousebfire;

	TurnUp_Action,
	TurnDown_Action,
	Total_Action, // invalid

	Up_Key = 100,
	Down_Key,
	Left_Key,
	Right_Key,
	Escape_Key,
	Console_Key,
	PageUp_Key,
	PageDown_Key,
	Tab_Key,
	Shift_Key,
	Enter_Key,
	Backspace_Key,
	Space_Key,
	A_Key,
	B_Key,
	C_Key,
	D_Key,
	E_Key,
	F_Key,
	G_Key,
	H_Key,
	I_Key,
	J_Key,
	K_Key,
	L_Key,
	M_Key,
	N_Key,
	O_Key,
	P_Key,
	Q_Key,
	R_Key,
	S_Key,
	T_Key,
	U_Key,
	V_Key,
	W_Key,
	X_Key,
	Y_Key,
	Z_Key,
	Num0_Key,
	Num1_Key,
	Num2_Key,
	Num3_Key,
	Num4_Key,
	Num5_Key,
	Num6_Key,
	Num7_Key,
	Num8_Key,
	Num9_Key,
	Underscore_Key,
	Minus_Key,
	Period_Key,
	Slash_Key,
	Plus_Key,
	Equal_Key,
	Question_Key,
	BackSlash_Key,
	Mouse1_Button,
	Total_Key, // invalid

	God_Cmd = 200,
	GiveAll_Cmd,
	NoClip_Cmd,
	PowerUp_Cmd,
	Total_Cmd, // invalid

	OpenKeyboard_Func = 300,
	CloseKeyboard_Func,
	ToggleKeyboard_Func,
	Total_Func, // invalid
} Game_Action;

struct vkb_cursor
{
	int x;
	int y;
	uint r;
	clampf eminr;
	clampf emaxr;
	boolean render;
	uint tex_index;
	float ignore_distance;
	int tx;
	int ty;
	int tw;
	float joy_r;
	int joy_tx;
	int joy_ty;
	int joy_tw;
	int joy_ptx;
	int joy_pty;
	int joy_ptw;
	uenum x_base;
	uenum y_base;
	boolean ava;
	int z;
	uint mask;
	Game_Action action;
	Game_Action action0;
	Game_Action action1;
	Game_Action action2;
	Game_Action action3;
};

struct vkb_swipe
{
	int x;
	int y;
	uint w;
	uint h;
	uint ex;
	uint ey;
	uint ew;
	uint eh;
	boolean render;
	int tx;
	int ty;
	int tw;
	int th;
	uenum x_base;
	uenum y_base;
	boolean ava;
	int z;
	uint mask;
	Game_Action action;
	Game_Action action0;
	Game_Action action1;
	Game_Action action2;
	Game_Action action3;
};

struct vkb_joystick
{
	int x;
	int y;
	uint r;
	clampf eminr;
	clampf emaxr;
	int tx;
	int ty;
	int tw;
	float joy_r;
	int joy_tx;
	int joy_ty;
	int joy_tw;
	uenum x_base;
	uenum y_base;
	boolean ava;
	int z;
	uint mask;
	Game_Action action0;
	Game_Action action1;
	Game_Action action2;
	Game_Action action3;
};

struct vkb_button
{
	int x;
	int y;
	uint w;
	uint h;
	uint ex;
	uint ey;
	uint ew;
	uint eh;
	int tx;
	int ty;
	int tw;
	int th;
	int ptx;
	int pty;
	int ptw;
	int pth;
	uenum x_base;
	uenum y_base;
	boolean ava;
	int z;
	uint mask;
	uint tex_index;
	Game_Action action;
};

typedef unsigned (* VKB_Key_Action_Function)(int, unsigned, int, int);

extern unsigned client_state;
extern const char *Tex_Files[VKB_TEX_COUNT];
extern struct vkb_button VKB_Button[VKB_COUNT];
extern struct vkb_joystick VKB_Joystick[JOYSTICK_COUNT];
extern struct vkb_swipe VKB_Swipe[SWIPE_COUNT];
extern struct vkb_cursor VKB_Cursor[CURSOR_COUNT];
extern boolean render_lock;

float karinFormatAngle(float angle);
unsigned karinGetClientState(void);
int karinGetActionData(unsigned action, intptr_t *rkey);
void karinToggleKeyboard(void);
void karinOpenKeyboard(void);
void karinCloseKeyboard(void);

#endif
