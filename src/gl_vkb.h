#ifndef _KARIN_GL_VKB_H
#define _KARIN_GL_VKB_H

#include "vkb.h"

void karinGLNewVKB(float x, float y, float z, float w, float h);
void karinGLDeleteVKB(void);
void karinGLRenderVKB(void);
void karinGLResizeVKB(float w, float h);
unsigned karinGLVKBMouseMotionEvent(int b, int p, int x, int y, int dx, int dy, VKB_Key_Action_Function f);
unsigned karinGLVKBMouseEvent(int b, int p, int x, int y, VKB_Key_Action_Function f);

#endif
