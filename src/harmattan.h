#ifndef _HARMATTAN_H
#define _HARMATTAN_H

#include <GLES/gl.h>
#include <GLES/glext.h>

#define K_UNUSED(x) (void)(x)
#define K_MASK(x) (1 << (x))
#define K_MASK_ALL (~0)
typedef unsigned enum_t;
typedef unsigned long mask_t;

// only for port from OpenGL to OpenGL ES1.1
// funcptr
typedef void (* PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);

// glFunc
#define glClearDepth glClearDepthf
#define glTexCoord2f(s, t) (s), (t)
#define glVertex2f(x, y) (x), (y)
#define glVertex2i(x, y) (GLfloat)(x), (GLfloat)(y)
#define glVertex3f(x, y, z) (x), (y), (z)
#define glColor3f(r, g, b) glColor4f(r, g, b, 1.0)
#define glColor4fv(v) glColor4f((v)[0], (v)[1], (v)[2], (v)[3])
#define glOrtho glOrthof
#define glMultMatrixd glMultMatrixf

#define glTexCoord2fv(v) memcpy(harm_Temp_Data, (v), sizeof(GLfloat) * 2)
#define glVertex3fv(v) memcpy(harm_Temp_Data, (v), sizeof(GLfloat) * 3)

// typedef
typedef GLfloat GLdouble;
typedef GLclampf GLclampd;

#define GL_CLAMP GL_CLAMP_TO_EDGE

// glBegin() - glEnd()
// special variants:
// harm_Render_Type: render entity type
// harm_Vertex_Size: glVertexPointer() first arg
// harm_TexCoord_Size: glTexCoordPointer() first arg, UNUSED, always 2
// harm_Data: vertex array data
// harm_Temp_Data: temp vertex array data
// harm_Vertex_Count: vertex count
// harm_Enable_TexCoord: enable texture coord array

#define DISABLE_TEXCOORD_ARRAY harm_Enable_TexCoord = GL_FALSE;
#define VERTEX_COUNT(x) harm_Vertex_Count = x;
#define VERTEX_SIZE(x) harm_Vertex_Size = x;
#define TEXCOORD_SIZE(x) harm_TexCoord_Size = x;

#define glBegin(t) \
{ \
	GLenum harm_Render_Type = t; \
	GLint harm_Vertex_Size = 2; \
	GLint harm_TexCoord_Size = 2; \
	GLint harm_Vertex_Count = 4; \
	GLboolean harm_Enable_TexCoord = GL_TRUE;

#define DECL_ARRAY GLfloat harm_Data[] = {
#define END_ARRAY };

#define glEnd() \
	glEnableClientState(GL_VERTEX_ARRAY); \
	if(harm_Enable_TexCoord) \
		glEnableClientState(GL_TEXTURE_COORD_ARRAY); \
	if(harm_Enable_TexCoord) \
		glTexCoordPointer(harm_TexCoord_Size, GL_FLOAT, (harm_TexCoord_Size + harm_Vertex_Size) * sizeof(GLfloat), harm_Data); \
	glVertexPointer(harm_Vertex_Size, GL_FLOAT, harm_Enable_TexCoord ? (harm_Vertex_Size + harm_TexCoord_Size) * sizeof(GLfloat) : 0, harm_Data + (harm_Enable_TexCoord ? harm_TexCoord_Size : 0)); \
	glDrawArrays(harm_Render_Type, 0, harm_Vertex_Count); \
	if(harm_Enable_TexCoord) \
		glDisableClientState(GL_TEXTURE_COORD_ARRAY); \
	glDisableClientState(GL_VERTEX_ARRAY); \
}

#if 0 // test
int main(void)
{
	glBegin(GL_TRIANGLE_STRIP)
		DECL_ARRAY
		glTexCoord2f(fU1, fV1), glVertex2f((xpos),(ypos)),
		glTexCoord2f(fU1, fV2), glVertex2f((xpos),(ypos+height)),
		glTexCoord2f(fU2, fV1), glVertex2f((xpos+width),(ypos)),
		glTexCoord2f(fU2, fV2), glVertex2f((xpos+width),(ypos+height)),
		END_ARRAY
	glEnd()
}
#endif

// GLU
#include "mesa_glu.h"

#endif
