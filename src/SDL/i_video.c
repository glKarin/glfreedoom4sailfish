/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  DOOM graphics stuff for SDL
 *
 *-----------------------------------------------------------------------------
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "SDL.h"

#include "m_argv.h"
#include "doomstat.h"
#include "doomdef.h"
#include "doomtype.h"
#include "v_video.h"
#include "r_draw.h"
#include "d_main.h"
#include "d_event.h"
#include "i_joy.h"
#include "i_video.h"
#include "z_zone.h"
#include "s_sound.h"
#include "sounds.h"
#include "w_wad.h"
#include "st_stuff.h"
#include "lprintf.h"


int gl_colorbuffer_bits=16;
int gl_depthbuffer_bits=16;

extern void M_QuitDOOM(int choice);
#ifdef DISABLE_DOUBLEBUFFER
int use_doublebuffer = 0;
#else
int use_doublebuffer = 1; // Included not to break m_misc, but not relevant to SDL
#endif
int use_fullscreen;
int desired_fullscreen;
SDL_Window *screen;
static SDL_Renderer *renderer;
static SDL_GLContext gl_context;

#ifdef _HARMATTAN
#include "gl_vkb.h"
#include "fbo.h"
extern karin_FrameBufferObject *fbo;

#define KARIN_TOUCH_BUTTON 1
#define VID_WIDTH  0
#define VID_HEIGHT 0

#define KARIN_MAX_TOUCH_COUNT 10

#define FLOAT_TO_INT // round

static int I_TranslateKey(SDL_Keysym* key);
static unsigned karinHandleVKBAction(int action, unsigned pressed, int dx, int dy);

static inline void karinCoord(int ox, int oy, int w, int h, int *rx, int *ry)
{
	if(!rx || !ry)
		return;

	K_UNUSED(w);
	K_UNUSED(h);

	*rx = oy;
	*ry = ox;
}

static inline void karinSDLTouchPos(float fx, float fy, int *x, int *y)
{
	//int wlw, wlh;

	if(!x || !y)
		return;

	//SDL_GetWindowSize(screen, &wlw, &wlh); // SDLTouchFingerEvent.x|y|dx|dy is not a normalized clamped float number.
	
	if(x)
		*x = (int)FLOAT_TO_INT(/*(float)wlw * */fx);
	if(y)
		*y = (int)FLOAT_TO_INT(/*(float)wlh * */fy);

}

static unsigned karinXI2MouseEvent(int button, unsigned pressed, int x, int y)
{
	int rx;
	int ry;

#if 0
	int wlw, wlh;
	SDL_GetWindowSize(screen, &wlw, &wlh);
#endif

	karinCoord(x, y, VID_WIDTH, VID_HEIGHT, &rx, &ry);

	return karinGLVKBMouseEvent(button, pressed, rx, ry, karinHandleVKBAction);
}

static unsigned karinXI2MotionEvent(int button, unsigned pressed, int x, int y, int dx, int dy)
{
	int rx;
	int ry;

#if 0
	int wlw, wlh;
	SDL_GetWindowSize(screen, &wlw, &wlh);
#endif

	karinCoord(x, y, VID_WIDTH, VID_HEIGHT, &rx, &ry);

	return karinGLVKBMouseMotionEvent(button, pressed, rx, ry, dy, dx, karinHandleVKBAction);
}

static inline void KARIN_EmulateKeyEvent(int key, unsigned pressed)
{
	event_t event;
	event.type = pressed ? ev_keydown : ev_keyup;
	event.data1 = key;
	D_PostEvent(&event);
}

static inline void KARIN_EmulateKeyEvent_Motion(int dx, int dy)
{
#define karinSwipeSens
	int fdx;
	int fdy;
	event_t event;

	fdx = karinSwipeSens(dx);
	fdy = karinSwipeSens(dy);
	if(fdx != 0 || fdy != 0)
	{
		event.type = ev_mouse;
		event.data1 = 0;
		event.data2 = fdx << 5;
		event.data3 = -fdy << 5;
		D_PostEvent(&event);
	}
}

static inline void KARIN_EmulateCheat(int cheat_index)
{
		cheat[cheat_index].func(); // in m_cheat.c
}

unsigned karinHandleVKBAction(int action, unsigned pressed, int dx, int dy)
{
	int r;
	intptr_t k;
	SDL_Keysym keysym;
	
	r = karinGetActionData(action, &k);

	if(r == Action_Data)
	{
		KARIN_EmulateKeyEvent(k, pressed);
	}
	else if(r == Key_Data)
	{
		keysym.sym = k;
		KARIN_EmulateKeyEvent(I_TranslateKey(&keysym), pressed);
	}
	else if(r == Char_Data)
	{
		if(pressed)
		{
			keysym.sym = k;
			KARIN_EmulateKeyEvent(I_TranslateKey(&keysym), pressed);
		}
	}
	else if(r == Button_Data)
	{
		if(pressed)
			KARIN_EmulateKeyEvent_Motion(dx, dy);
	}
	else if(r == Cmd_Data) // cheat
	{
		if(pressed)
			KARIN_EmulateCheat(k);
	}
	else if(r == Func_Data) // local func
	{
		if(pressed)
			((void (*)(void))k)();
	}

	return 0;
}

static unsigned KARIN_CheckVirtualButtons(const SDL_Event *ev)
{
	int x;
	int y;

	if(!ev)
		return 0;
	if(ev->type != SDL_FINGERDOWN && ev->type != SDL_FINGERUP)
		return 0;

	karinSDLTouchPos(ev->tfinger.x, ev->tfinger.y, &x, &y);

	if(ev->type == SDL_FINGERDOWN)
	{
		return karinXI2MouseEvent(KARIN_TOUCH_BUTTON, 1, x, y);
	}
	else
	{
		return karinXI2MouseEvent(KARIN_TOUCH_BUTTON, 0, x, y);
	}
}

static unsigned KARIN_CheckVirtualButtons_Motion(const SDL_Event *ev)
{
	int x, y;
	int dx, dy;

	if(!ev)
		return 0;

	karinSDLTouchPos(ev->tfinger.x, ev->tfinger.y, &x, &y);
	karinSDLTouchPos(ev->tfinger.dx, ev->tfinger.dy, &dx, &dy);

	return karinXI2MotionEvent(KARIN_TOUCH_BUTTON, 1, x, y, dx, dy);
}

#endif

////////////////////////////////////////////////////////////////////////////
// Input code
int             leds_always_off = 0; // Expected by m_misc, not relevant

// Mouse handling
extern int     usemouse;        // config file var
#ifndef _NON_HARMATTAN
#else
static boolean mouse_enabled; // usemouse, but can be overriden by -nomouse
static boolean mouse_currently_grabbed;
#endif

/////////////////////////////////////////////////////////////////////////////////
// Keyboard handling

//
//  Translates the key currently in key
//

int I_TranslateKey(SDL_Keysym* key)
{
  int rc = 0;

  switch (key->sym) {
  case SDLK_LEFT: rc = KEYD_LEFTARROW;  break;
  case SDLK_RIGHT:  rc = KEYD_RIGHTARROW; break;
  case SDLK_DOWN: rc = KEYD_DOWNARROW;  break;
  case SDLK_UP:   rc = KEYD_UPARROW;  break;
  case SDLK_ESCAPE: rc = KEYD_ESCAPE; break;
  case SDLK_RETURN: rc = KEYD_ENTER;  break;
  case SDLK_TAB:  rc = KEYD_TAB;    break;
  case SDLK_F1:   rc = KEYD_F1;   break;
  case SDLK_F2:   rc = KEYD_F2;   break;
  case SDLK_F3:   rc = KEYD_F3;   break;
  case SDLK_F4:   rc = KEYD_F4;   break;
  case SDLK_F5:   rc = KEYD_F5;   break;
  case SDLK_F6:   rc = KEYD_F6;   break;
  case SDLK_F7:   rc = KEYD_F7;   break;
  case SDLK_F8:   rc = KEYD_F8;   break;
  case SDLK_F9:   rc = KEYD_F9;   break;
  case SDLK_F10:  rc = KEYD_F10;    break;
  case SDLK_F11:  rc = KEYD_F11;    break;
  case SDLK_F12:  rc = KEYD_F12;    break;
  case SDLK_BACKSPACE:  rc = KEYD_BACKSPACE;  break;
  case SDLK_DELETE: rc = KEYD_DEL;  break;
  case SDLK_INSERT: rc = KEYD_INSERT; break;
  case SDLK_PAGEUP: rc = KEYD_PAGEUP; break;
  case SDLK_PAGEDOWN: rc = KEYD_PAGEDOWN; break;
  case SDLK_HOME: rc = KEYD_HOME; break;
  case SDLK_END:  rc = KEYD_END;  break;
  case SDLK_PAUSE:  rc = KEYD_PAUSE;  break;
  case SDLK_EQUALS: rc = KEYD_EQUALS; break;
  case SDLK_MINUS:  rc = KEYD_MINUS;  break;
  case SDLK_KP_0:  rc = KEYD_KEYPAD0;  break;
  case SDLK_KP_1:  rc = KEYD_KEYPAD1;  break;
  case SDLK_KP_2:  rc = KEYD_KEYPAD2;  break;
  case SDLK_KP_3:  rc = KEYD_KEYPAD3;  break;
  case SDLK_KP_4:  rc = KEYD_KEYPAD4;  break;
  case SDLK_KP_5:  rc = KEYD_KEYPAD5;  break;
  case SDLK_KP_6:  rc = KEYD_KEYPAD6;  break;
  case SDLK_KP_7:  rc = KEYD_KEYPAD7;  break;
  case SDLK_KP_8:  rc = KEYD_KEYPAD8;  break;
  case SDLK_KP_9:  rc = KEYD_KEYPAD9;  break;
  case SDLK_KP_PLUS:  rc = KEYD_KEYPADPLUS; break;
  case SDLK_KP_MINUS: rc = KEYD_KEYPADMINUS;  break;
  case SDLK_KP_DIVIDE:  rc = KEYD_KEYPADDIVIDE; break;
  case SDLK_KP_MULTIPLY: rc = KEYD_KEYPADMULTIPLY; break;
  case SDLK_KP_ENTER: rc = KEYD_KEYPADENTER;  break;
  case SDLK_KP_PERIOD:  rc = KEYD_KEYPADPERIOD; break;
  case SDLK_LSHIFT:
  case SDLK_RSHIFT: rc = KEYD_RSHIFT; break;
  case SDLK_LCTRL:
  case SDLK_RCTRL:  rc = KEYD_RCTRL;  break;
  case SDLK_LALT:
  // case SDLK_LMETA:
  case SDLK_RALT:
  // case SDLK_RMETA:
										rc = KEYD_RALT;   break;
  case SDLK_CAPSLOCK: rc = KEYD_CAPSLOCK; break;
  default:    rc = key->sym;    break;
  }

  return rc;

}

/////////////////////////////////////////////////////////////////////////////////
// Main input code

/* cph - pulled out common button code logic */
static int I_SDLtoDoomMouseState(Uint8 buttonstate)
{
  return 0
      | (buttonstate & SDL_BUTTON(1) ? 1 : 0)
      | (buttonstate & SDL_BUTTON(2) ? 2 : 0)
      | (buttonstate & SDL_BUTTON(3) ? 4 : 0);
}

static void I_GetEvent(SDL_Event *Event)
{
  event_t event;

  switch (Event->type) {
  case SDL_KEYDOWN:
    event.type = ev_keydown;
    event.data1 = I_TranslateKey(&Event->key.keysym);
    D_PostEvent(&event);
    break;

  case SDL_KEYUP:
  {
    event.type = ev_keyup;
    event.data1 = I_TranslateKey(&Event->key.keysym);
    D_PostEvent(&event);
  }
  break;

	// in SDL2, emit touch event when click screen, and not a mouse event.
	case SDL_FINGERDOWN:
	case SDL_FINGERUP:
	KARIN_CheckVirtualButtons(Event);
	break;
	case SDL_FINGERMOTION:
	KARIN_CheckVirtualButtons_Motion(Event);
	break;

  case SDL_MOUSEBUTTONDOWN:
  case SDL_MOUSEBUTTONUP:
#ifdef _NON_HARMATTAN
  if (mouse_enabled) // recognise clicks even if the pointer isn't grabbed
  {
    event.type = ev_mouse;
    event.data1 = I_SDLtoDoomMouseState(SDL_GetMouseState(NULL, NULL));
    event.data2 = event.data3 = 0;
    D_PostEvent(&event);
  }
#endif
  break;

  case SDL_MOUSEMOTION:
#ifdef _NON_HARMATTAN
  if (mouse_currently_grabbed) {
    event.type = ev_mouse;
    event.data1 = I_SDLtoDoomMouseState(Event->motion.state);
    event.data2 = Event->motion.xrel << 5;
    event.data3 = -Event->motion.yrel << 5;
    D_PostEvent(&event);
  }
#endif
  break;


  case SDL_QUIT:
    S_StartSound(NULL, sfx_swtchn);
    M_QuitDOOM(0);

  default:
    break;
  }
}


//
// I_StartTic
//

void I_StartTic (void)
{
  SDL_Event Event;
#ifndef _NON_HARMATTAN
#else
  {
    boolean should_be_grabbed = mouse_enabled &&
      !(paused || (gamestate != GS_LEVEL) || demoplayback);

    if (mouse_currently_grabbed != should_be_grabbed)
      SDL_WM_GrabInput((mouse_currently_grabbed = should_be_grabbed)
          ? SDL_GRAB_ON : SDL_GRAB_OFF);
  }
#endif

  while ( SDL_PollEvent(&Event) )
    I_GetEvent(&Event);

  I_PollJoystick();
}

//
// I_StartFrame
//
void I_StartFrame (void)
{
}

//
// I_InitInputs
//

static void I_InitInputs(void)
{
  int nomouse_parm = M_CheckParm("-nomouse");

  // check if the user wants to use the mouse
#ifndef _NON_HARMATTAN
#else
  mouse_enabled = usemouse && !nomouse_parm;
#endif

  // e6y: fix for turn-snapping bug on fullscreen in software mode
  if (!nomouse_parm)
    SDL_WarpMouseInWindow(screen, (unsigned short)(SCREENWIDTH/2), (unsigned short)(SCREENHEIGHT/2));

  I_InitJoystick();
}
/////////////////////////////////////////////////////////////////////////////

// I_SkipFrame
//
// Returns true if it thinks we can afford to skip this frame

inline static boolean I_SkipFrame(void)
{
  static int frameno;

  frameno++;
  switch (gamestate) {
  case GS_LEVEL:
    if (!paused)
      return false;
  default:
    // Skip odd frames
    return (frameno & 1) ? true : false;
  }
}

///////////////////////////////////////////////////////////
// Palette stuff.
//
static void I_UploadNewPalette(int pal)
{
  // This is used to replace the current 256 colour cmap with a new one
  // Used by 256 colour PseudoColor modes

  // Array of SDL_Color structs used for setting the 256-colour palette
  static SDL_Color* colours;
  static int cachedgamma;
  static size_t num_pals;

  if (V_GetMode() == VID_MODEGL)
    return;

  if ((colours == NULL) || (cachedgamma != usegamma)) {
    int pplump = W_GetNumForName("PLAYPAL");
    int gtlump = (W_CheckNumForName)("GAMMATBL",ns_prboom);
    register const byte * palette = W_CacheLumpNum(pplump);
    register const byte * const gtable = (const byte *)W_CacheLumpNum(gtlump) + 256*(cachedgamma = usegamma);
    register int i;

    num_pals = W_LumpLength(pplump) / (3*256);
    num_pals *= 256;

    if (!colours) {
      // First call - allocate and prepare colour array
      colours = malloc(sizeof(*colours)*num_pals);
    }

    // set the colormap entries
    for (i=0 ; (size_t)i<num_pals ; i++) {
      colours[i].r = gtable[palette[0]];
      colours[i].g = gtable[palette[1]];
      colours[i].b = gtable[palette[2]];
      palette += 3;
    }

    W_UnlockLumpNum(pplump);
    W_UnlockLumpNum(gtlump);
    num_pals/=256;
  }

#ifdef RANGECHECK
  if ((size_t)pal >= num_pals)
    I_Error("I_UploadNewPalette: Palette number out of range (%d>=%d)",
      pal, num_pals);
#endif

  // store the colors to the current display
  // SDL_SetColors(SDL_GetVideoSurface(), colours+256*pal, 0, 256);
#ifdef _HARMATTAN_SDL1_2
  SDL_SetPalette(
      SDL_GetVideoSurface(),
      SDL_LOGPAL | SDL_PHYSPAL,
      colours+256*pal, 0, 256);
#endif
}

//////////////////////////////////////////////////////////////////////////////
// Graphics API

void I_ShutdownGraphics(void)
{
	lprintf(LO_INFO, "[Harmattan]: Destroy OpenGL FBO......");
	fbo->unbind(fbo);
	fbo->delete__(fbo);
	lprintf(LO_INFO, "done\n");
	lprintf(LO_INFO, "[Harmattan]: Destroy virtual button layer......");
	karinGLDeleteVKB();
	lprintf(LO_INFO, "done\n");
}

//
// I_UpdateNoBlit
//
void I_UpdateNoBlit (void)
{
}

//
// I_FinishUpdate
//
static int newpal = 0;
#define NO_PALETTE_CHANGE 1000

void I_FinishUpdate (void)
{
  if (I_SkipFrame()) return;

#ifdef MONITOR_VISIBILITY
  if (!(SDL_GetAppState()&SDL_APPACTIVE)) {
    return;
  }
#endif

#ifdef GL_DOOM
  if (V_GetMode() == VID_MODEGL) {
    // proff 04/05/2000: swap OpenGL buffers
    gld_Finish();
    return;
  }
#endif
#ifdef _HARMATTAN_SDL1_2
  if (SDL_MUSTLOCK(screen)) {
      int h;
      byte *src;
      byte *dest;

      if (SDL_LockSurface(screen) < 0) {
        lprintf(LO_INFO,"I_FinishUpdate: %s\n", SDL_GetError());
        return;
      }
      dest=screen->pixels;
      src=screens[0].data;
      h=screen->h;
      for (; h>0; h--)
      {
        memcpy(dest,src,SCREENWIDTH*V_GetPixelDepth());
        dest+=screen->pitch;
        src+=screens[0].byte_pitch;
      }
      SDL_UnlockSurface(screen);
  }
#endif
  /* Update the display buffer (flipping video pages if supported)
   * If we need to change palette, that implicitely does a flip */
  if (newpal != NO_PALETTE_CHANGE) {
    I_UploadNewPalette(newpal);
    newpal = NO_PALETTE_CHANGE;
  }
}

//
// I_ScreenShot - moved to i_sshot.c
//

//
// I_SetPalette
//
void I_SetPalette (int pal)
{
  newpal = pal;
}

// I_PreInitGraphics

static void I_ShutdownSDL(void)
{
	lprintf(LO_INFO, "[Harmattan]: Destroy OpenGL render context......");
	if(gl_context)
	{
		SDL_GL_MakeCurrent(screen, NULL);
		SDL_GL_DeleteContext(gl_context);
		gl_context = NULL;
	}
	if(screen)
	{
		SDL_DestroyWindow(screen);
		screen = NULL;
	}
	lprintf(LO_INFO, "done\n");
  SDL_Quit();
  return;
}

void I_PreInitGraphics(void)
{
  // Initialize SDL
  unsigned int flags = 0;
  if (!(M_CheckParm("-nodraw") && M_CheckParm("-nosound")))
    flags = SDL_INIT_VIDEO;
#ifdef _DEBUG
  flags |= SDL_INIT_NOPARACHUTE;
#endif
  if ( SDL_Init(flags) < 0 ) {
    I_Error("Could not initialize SDL [%s]", SDL_GetError());
  }

  atexit(I_ShutdownSDL);
}

// e6y
// GLBoom use this function for trying to set the closest supported resolution if the requested mode can't be set correctly.
// For example glboom.exe -geom 1025x768 -nowindow will set 1024x768.
// It should be used only for fullscreen modes.
static void I_ClosestResolution (int *width, int *height, int flags)
{
  int twidth, theight;
  int cwidth = 0, cheight = 0;
//  int iteration;
  int i;
  unsigned int closest = UINT_MAX;
  unsigned int dist;
	int num_video_display;
	int num_display_mode;
	SDL_DisplayMode display_mode;
	int j;

	num_video_display = SDL_GetNumVideoDisplays();
	for(i = 0; i < num_video_display; i++)
	{
		num_display_mode = SDL_GetNumDisplayModes(i);
		for(j = 0; j < num_video_display; j++)
		{
			if(SDL_GetDisplayMode(i, j, &display_mode) != 0)
				continue;
			{
				twidth = display_mode.w;
				theight = display_mode.h;

				if (twidth > MAX_SCREENWIDTH || theight> MAX_SCREENHEIGHT)
					continue;

				if (twidth == *width && theight == *height)
					return;

				//if (iteration == 0 && (twidth < *width || theight < *height))
				//  continue;

				dist = (twidth - *width) * (twidth - *width) + 
					(theight - *height) * (theight - *height);

				if (dist < closest)
				{
					closest = dist;
					cwidth = twidth;
					cheight = theight;
				}
			}
		}
	}
	if (closest != 4294967295u)
	{
		*width = cwidth;
		*height = cheight;
		return;
	}

}  

// CPhipps -
// I_CalculateRes
// Calculates the screen resolution, possibly using the supplied guide
void I_CalculateRes(unsigned int width, unsigned int height)
{
  // e6y: how about 1680x1050?
  /*
  SCREENWIDTH = (width+3) & ~3;
  SCREENHEIGHT = (height+3) & ~3;
  */

// e6y
// GLBoom will try to set the closest supported resolution 
// if the requested mode can't be set correctly.
// For example glboom.exe -geom 1025x768 -nowindow will set 1024x768.
// It affects only fullscreen modes.
  if (V_GetMode() == VID_MODEGL) {
    if ( desired_fullscreen )
    {
      I_ClosestResolution(&width, &height, SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN);
    }
    SCREENWIDTH = width;
    SCREENHEIGHT = height;
    SCREENPITCH = SCREENWIDTH;
  } else {
    SCREENWIDTH = (width+15) & ~15;
#ifndef _NON_HARMATTAN
		if(SCREENWIDTH > N950_W)
			SCREENWIDTH = N950_W;
#endif
    SCREENHEIGHT = height;
#ifndef _NON_HARMATTAN
		if(SCREENHEIGHT > N950_H)
			SCREENHEIGHT = N950_H;
#endif
    if (!(SCREENWIDTH % 1024)) {
      SCREENPITCH = SCREENWIDTH*V_GetPixelDepth()+32;
    } else {
      SCREENPITCH = SCREENWIDTH*V_GetPixelDepth();
    }
  }
}

// CPhipps -
// I_SetRes
// Sets the screen resolution
void I_SetRes(void)
{
  int i;

  I_CalculateRes(SCREENWIDTH, SCREENHEIGHT);

  // set first three to standard values
  for (i=0; i<3; i++) {
    screens[i].width = SCREENWIDTH;
    screens[i].height = SCREENHEIGHT;
    screens[i].byte_pitch = SCREENPITCH;
    screens[i].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
    screens[i].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);
  }

  // statusbar
  screens[4].width = SCREENWIDTH;
  screens[4].height = (ST_SCALED_HEIGHT+1);
  screens[4].byte_pitch = SCREENPITCH;
  screens[4].short_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE16);
  screens[4].int_pitch = SCREENPITCH / V_GetModePixelDepth(VID_MODE32);

  lprintf(LO_INFO,"I_SetRes: Using resolution %dx%d\n", SCREENWIDTH, SCREENHEIGHT);
}

void I_InitGraphics(void)
{
  char titlebuffer[2048];
  static int    firsttime=1;

  if (firsttime)
  {
    firsttime = 0;

    atexit(I_ShutdownGraphics);
    lprintf(LO_INFO, "I_InitGraphics: %dx%d\n", SCREENWIDTH, SCREENHEIGHT);

    /* Set the video mode */
    I_UpdateVideoMode();

    /* Setup the window title */
    strcpy(titlebuffer,PACKAGE);
    strcat(titlebuffer," ");
    strcat(titlebuffer,VERSION);
    SDL_SetWindowTitle(screen, titlebuffer);

    /* Initialize the input system */
    I_InitInputs();
  }
}

int I_GetModeFromString(const char *modestr)
{
  video_mode_t mode;

  if (!stricmp(modestr,"15")) {
    mode = VID_MODE15;
  } else if (!stricmp(modestr,"15bit")) {
    mode = VID_MODE15;
  } else if (!stricmp(modestr,"16")) {
    mode = VID_MODE16;
  } else if (!stricmp(modestr,"16bit")) {
    mode = VID_MODE16;
  } else if (!stricmp(modestr,"32")) {
    mode = VID_MODE32;
  } else if (!stricmp(modestr,"32bit")) {
    mode = VID_MODE32;
  } else if (!stricmp(modestr,"gl")) {
    mode = VID_MODEGL;
  } else if (!stricmp(modestr,"OpenGL")) {
    mode = VID_MODEGL;
  } else {
    mode = VID_MODE8;
  }
  return mode;
}

void I_UpdateVideoMode(void)
{
  int init_flags;
  int i;
  video_mode_t mode;

  lprintf(LO_INFO, "I_UpdateVideoMode: %dx%d (%s)\n", SCREENWIDTH, SCREENHEIGHT, desired_fullscreen ? "fullscreen" : "nofullscreen");

  mode = I_GetModeFromString(default_videomode);
  if ((i=M_CheckParm("-vidmode")) && i<myargc-1) {
    mode = I_GetModeFromString(myargv[i+1]);
  }

	mode = VID_MODEGL;
  V_InitMode(mode);
  V_DestroyUnusedTrueColorPalettes();
  V_FreeScreens();

  I_SetRes();

  // Initialize SDL with this graphics mode
  if (V_GetMode() == VID_MODEGL) {
    init_flags = SDL_WINDOW_OPENGL;
  } else {
    if (use_doublebuffer)
      ; //k init_flags = SDL_DOUBLEBUF;
    else
      ; //k init_flags = SDL_SWSURFACE;
#ifndef _DEBUG
    ; //k init_flags |= SDL_HWPALETTE;
#endif
  }

  if ( desired_fullscreen )
    init_flags |= SDL_WINDOW_FULLSCREEN;

  if (V_GetMode() == VID_MODEGL) {
		lprintf(LO_INFO, "[Harmattan]: Initialize OpenGL render context......");
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_ACCUM_RED_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_ACCUM_GREEN_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_ACCUM_BLUE_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_ACCUM_ALPHA_SIZE, 0 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
		// set OpenGL to 1.1
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, gl_colorbuffer_bits );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, gl_depthbuffer_bits );
		screen = SDL_CreateWindow("Free DOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, init_flags | SDL_WINDOW_SHOWN); // now, kill them all.
		gl_context = SDL_GL_CreateContext(screen);
		SDL_GL_MakeCurrent(screen, gl_context);
		lprintf(LO_INFO, "done\n");
  } else { // not execute this, only OpenGL rendering
		screen = SDL_CreateWindow("Free DOOM", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, init_flags);
		renderer = SDL_CreateRenderer(screen, -1, 0);
  }

  if(screen == NULL) {
    I_Error("Couldn't set %dx%d video mode [%s]", SCREENWIDTH, SCREENHEIGHT, SDL_GetError());
  }

  //k lprintf(LO_INFO, "I_UpdateVideoMode: 0x%x, %s, %s\n", init_flags, screen->pixels ? "SDL buffer" : "own buffer", SDL_MUSTLOCK(screen) ? "lock-and-copy": "direct access");

#ifndef _NON_HARMATTAN
#else
  mouse_currently_grabbed = false;
#endif

  // Get the info needed to render to the display
#ifdef _HARMATTAN_SDL1_2
  if (!SDL_MUSTLOCK(screen))
  {
    screens[0].not_on_heap = true;
    screens[0].data = (unsigned char *) (screen->pixels);
    screens[0].byte_pitch = screen->pitch;
    screens[0].short_pitch = screen->pitch / V_GetModePixelDepth(VID_MODE16);
    screens[0].int_pitch = screen->pitch / V_GetModePixelDepth(VID_MODE32);
  }
  else
#endif
  {
    screens[0].not_on_heap = false;
  }

  V_AllocScreens();

  // Hide pointer while over this window
  SDL_ShowCursor(0);

  R_InitBuffer(SCREENWIDTH, SCREENHEIGHT);

  if (V_GetMode() == VID_MODEGL) {
    int temp;
    lprintf(LO_INFO,"SDL OpenGL PixelFormat:\n");
    SDL_GL_GetAttribute( SDL_GL_RED_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_RED_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_GREEN_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_GREEN_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_BLUE_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_BLUE_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_STENCIL_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_STENCIL_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_ACCUM_RED_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_ACCUM_RED_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_ACCUM_GREEN_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_ACCUM_GREEN_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_ACCUM_BLUE_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_ACCUM_BLUE_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_ACCUM_ALPHA_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_ACCUM_ALPHA_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_DOUBLEBUFFER, &temp );
    lprintf(LO_INFO,"    SDL_GL_DOUBLEBUFFER: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_BUFFER_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_BUFFER_SIZE: %i\n",temp);
    SDL_GL_GetAttribute( SDL_GL_DEPTH_SIZE, &temp );
    lprintf(LO_INFO,"    SDL_GL_DEPTH_SIZE: %i\n",temp);
#ifdef GL_DOOM
    gld_Init(SCREENWIDTH, SCREENHEIGHT);
#endif
  }
	
}
