#include "fbo.h"

#include <stdio.h>
#include <string.h>

#include <SDL_opengles.h>
#include <SDL_video.h>

#include "gl_vkb.h"

#define SDLDLSYM(name) q##name = SDL_GL_GetProcAddress(#name)

static unsigned fboProcInited = 0;
PFNGLISRENDERBUFFEROESPROC qglIsRenderbuffer = NULL;
PFNGLBINDRENDERBUFFEROESPROC qglBindRenderbuffer = NULL;
PFNGLDELETERENDERBUFFERSOESPROC qglDeleteRenderbuffers = NULL;
PFNGLGENRENDERBUFFERSOESPROC qglGenRenderbuffers = NULL;
PFNGLRENDERBUFFERSTORAGEOESPROC qglRenderbufferStorage = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVOESPROC qglGetRenderbufferParameteriv = NULL;
PFNGLISFRAMEBUFFEROESPROC qglIsFramebuffer = NULL;
PFNGLBINDFRAMEBUFFEROESPROC qglBindFramebuffer = NULL;
PFNGLDELETEFRAMEBUFFERSOESPROC qglDeleteFramebuffers = NULL;
PFNGLGENFRAMEBUFFERSOESPROC qglGenFramebuffers = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSOESPROC qglCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERRENDERBUFFEROESPROC qglFramebufferRenderbuffer = NULL;
PFNGLFRAMEBUFFERTEXTURE2DOESPROC qglFramebufferTexture2D = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVOESPROC qglGetFramebufferAttachmentParameteriv = NULL;
PFNGLGENERATEMIPMAPOESPROC qglGenerateMipmap = NULL;

static const GLuint M_MinSize = 2;
static const GLenum M_TextureFormat = GL_RGB;

static void bind(karin_FrameBufferObject *fbo);
static void unbind(karin_FrameBufferObject *fbo);
static unsigned isBind(const karin_FrameBufferObject *fbo);
static void blit(karin_FrameBufferObject *fbo);
static void resize(karin_FrameBufferObject *fbo, GLuint w, GLuint h, GLuint vw, GLuint vh);
static unsigned init(karin_FrameBufferObject *fbo, GLuint width, GLuint height);
static void delete_karin_FrameBufferObject(karin_FrameBufferObject *fbo);
static void destory(karin_FrameBufferObject *fbo);
static void initBuffer(karin_FrameBufferObject *fbo, GLfloat w, GLfloat h);
static void attachFrameBuffer(karin_FrameBufferObject *fbo, GLuint w, GLuint h);

static void getFBOProc(void);
static unsigned getError(void);
static unsigned getFBOStatus(void);
static void printRenderBufferParams(void);
static GLuint genTexture2D(GLuint width, GLuint height);

// OpenGL ES has not glPushAttrib/glPopAttrib
// Cull Face
static struct OpenGL_CullFace_Attrib
{
	GLboolean cull_face;
	GLint front_face;
	GLint cull_face_mode;
} cull_face_attrib;
// Texture 2D
static struct OpenGL_Texture2D_Attrib
{
	GLint active_texture;
	GLboolean texture2d;
	GLint bind_texture2d;
} texture2d_attrib;
// Tex Env
static struct OpenGL_TexEnv_Attrib
{
	GLint tex_env_mode;
} tex_env_attrib;
// Alpha Test
static struct OpenGL_AlphaTest_Attrib
{
	GLfloat alpha_ref;
	GLint alpha_func;
	GLboolean alpha_test;
} alpha_test_attrib;
// Blend
static struct OpenGL_Blend_Attrib
{
	GLint blend_src;
	GLint blend_dst;
	GLboolean blend;
} blend_attrib;
// Depth Test
static struct OpenGL_DepthTest_Attrib
{
	GLboolean depth_test;
} depth_test_attrib;
// Transform(Matrix and Viewport)
static struct OpenGL_Transform_Attrib
{
	GLint matrix_mode;
	GLint viewport[4];
} transform_attrib;
// Current
static struct OpenGL_Current_Attrib
{
	GLfloat current_color[4];
} current_attrib;
// Stencil Test
static struct OpenGL_StencilTest_Attrib
{
	GLboolean stencil_test;
} stencil_test_attrib;
// scissor Test
static struct OpenGL_ScissorTest_Attrib
{
	GLboolean scissor_test;
} scissor_test_attrib;
// Client State
static struct OpenGL_ClientState_Attrib
{
	GLboolean vertex_array;
	GLboolean texcoord_array;
	GLboolean color_array;
	GLint client_active_texture;
} client_state_attrib;


static void karinBeginRender2D(GLint width, GLint height)
{
	if(render_lock)
		return;
	// Get
	{
		glGetIntegerv(GL_TEXTURE_BINDING_2D, &texture2d_attrib.bind_texture2d);
		texture2d_attrib.texture2d = glIsEnabled(GL_TEXTURE_2D);
		//glGetIntegerv(GL_ACTIVE_TEXTURE, &texture2d_attrib.active_texture);

		blend_attrib.blend = glIsEnabled(GL_BLEND);
		glGetIntegerv(GL_BLEND_SRC, &blend_attrib.blend_src);
		glGetIntegerv(GL_BLEND_DST, &blend_attrib.blend_dst);

		alpha_test_attrib.alpha_test = glIsEnabled(GL_ALPHA_TEST);
		glGetFloatv(GL_ALPHA_TEST_REF, &alpha_test_attrib.alpha_ref);
		glGetIntegerv(GL_ALPHA_TEST_FUNC, &alpha_test_attrib.alpha_func);

		depth_test_attrib.depth_test = glIsEnabled(GL_DEPTH_TEST);

		scissor_test_attrib.scissor_test = glIsEnabled(GL_SCISSOR_TEST);

		glGetIntegerv(GL_MATRIX_MODE, &transform_attrib.matrix_mode);
		glGetIntegerv(GL_VIEWPORT, transform_attrib.viewport);

		client_state_attrib.vertex_array = glIsEnabled(GL_VERTEX_ARRAY);
		client_state_attrib.texcoord_array = glIsEnabled(GL_TEXTURE_COORD_ARRAY);
		//client_state_attrib.color_array = glIsEnabled(GL_COLOR_ARRAY);
		//glGetIntegerv(GL_CLIENT_ACTIVE_TEXTURE, &client_state_attrib.client_active_texture);

		stencil_test_attrib.stencil_test = glIsEnabled(GL_STENCIL_TEST);

		glGetFloatv(GL_CURRENT_COLOR, current_attrib.current_color);

		cull_face_attrib.cull_face = glIsEnabled(GL_CULL_FACE);
		glGetIntegerv(GL_FRONT_FACE, &cull_face_attrib.front_face);
		glGetIntegerv(GL_CULL_FACE_MODE, &cull_face_attrib.cull_face_mode);

		glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &tex_env_attrib.tex_env_mode);
	}
	// Set
	{
		glDisable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glDisable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_SCISSOR_TEST);

		glDisable(GL_STENCIL_TEST);

		glColor4f(1.0, 1.0, 1.0, 1.0);

		glDisableClientState(GL_COLOR_ARRAY);
		glClientActiveTexture(GL_TEXTURE0);

		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CCW);
		glCullFace(GL_BACK);

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
	// Matrix
	{
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrthof(0.0, width, 0.0, height, -1.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
	}
	render_lock = true;
}

static void karinEndRender2D(void)
{
	if(!render_lock)
		return;
	{
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
	}
	{
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, tex_env_attrib.tex_env_mode);

		glBindTexture(GL_TEXTURE_2D, texture2d_attrib.bind_texture2d);
		if(!texture2d_attrib.texture2d)
			glDisable(GL_TEXTURE_2D);
		//glActiveTexture(texture2d_attrib.active_texture);

		glAlphaFunc(alpha_test_attrib.alpha_func, alpha_test_attrib.alpha_ref);
		if(alpha_test_attrib.alpha_test)
			glEnable(GL_ALPHA_TEST);

		if(blend_attrib.blend)
			glEnable(GL_BLEND);
		glBlendFunc(blend_attrib.blend_src, blend_attrib.blend_dst);

		if(depth_test_attrib.depth_test)
			glEnable(GL_DEPTH_TEST);

		if(scissor_test_attrib.scissor_test)
			glEnable(GL_SCISSOR_TEST);

		glMatrixMode(transform_attrib.matrix_mode);
		glViewport(transform_attrib.viewport[0], transform_attrib.viewport[1], transform_attrib.viewport[2], transform_attrib.viewport[3]);

		if(stencil_test_attrib.stencil_test)
			glEnable(GL_STENCIL_TEST);

		//glClientActiveTexture(client_state_attrib.client_active_texture);
		if(client_state_attrib.vertex_array)
			glEnableClientState(GL_VERTEX_ARRAY);
		if(client_state_attrib.texcoord_array)
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		/*
		if(client_state_attrib.color_array)
			glEnableClientState(GL_COLOR_ARRAY);
			*/

		glColor4f(current_attrib.current_color[0], current_attrib.current_color[1], current_attrib.current_color[2], current_attrib.current_color[3]);

		if(!cull_face_attrib.cull_face)
			glDisable(GL_CULL_FACE);
		glFrontFace(cull_face_attrib.front_face);
		glCullFace(cull_face_attrib.cull_face_mode);
	}
	render_lock = false;
}

karin_FrameBufferObject new_karin_FrameBufferObject(GLuint width, GLuint height, GLuint vw, GLuint vh)
{
	getFBOProc();

	karin_FrameBufferObject fbo;
	fbo.m_inited = (0);
	fbo.m_handle = (0);
	fbo.m_texture = (0);
	fbo.m_viewportWidth = (vw <= 0 ? M_MinSize : vw);
	fbo.m_viewportHeight = (vh <= 0 ? M_MinSize : vh);
	fbo.m_width = (width <= 0 ? M_MinSize : width);
	fbo.m_height = (height <= 0 ? M_MinSize : height);
	memset(fbo.m_renderBuffer, 0, Total_Render_Buffer * sizeof(GLuint));
	memset(fbo.m_buffer, 0, Total_Buffer * sizeof(GLuint));
	fbo.m_inited = init(&fbo, fbo.m_width, fbo.m_height);
	initBuffer(&fbo, fbo.m_viewportWidth, fbo.m_viewportHeight);

	fbo.bind = bind;
	fbo.unbind = unbind;
	fbo.isBind = isBind;
	fbo.blit = blit;
	fbo.resize = resize;
	fbo.delete__ = delete_karin_FrameBufferObject;

	return fbo;
}

void delete_karin_FrameBufferObject(karin_FrameBufferObject *fbo)
{
	if(!fbo)
		return;
	destory(fbo);
}

unsigned init(karin_FrameBufferObject *fbo, GLuint w, GLuint h)
{
	GLenum status;

	if(!fbo)
		return 0;
	if(fbo->m_inited)
		return 1;

	qglGenFramebuffers(1, &fbo->m_handle);
	qglBindFramebuffer(GL_FRAMEBUFFER, fbo->m_handle);

	attachFrameBuffer(fbo, fbo->m_width, fbo->m_height);

	status = getFBOStatus();

	qglBindFramebuffer(GL_FRAMEBUFFER, 0);

	return ((status == GL_FRAMEBUFFER_COMPLETE) ? 1 : 0);
}

void destory(karin_FrameBufferObject *fbo)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	qglBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteTextures(1, &fbo->m_texture);
	qglDeleteRenderbuffers(Total_Render_Buffer, fbo->m_renderBuffer);
	qglDeleteFramebuffers(1, &fbo->m_handle);
	glDeleteBuffers(Total_Buffer, fbo->m_buffer);
	fbo->m_inited = 0;
}

unsigned getFBOStatus(void)
{
#define K_CASE(x) case x: printf("[karin_FrameBufferObject]: FBO Status->%s\n", #x); return x;
	GLenum status;

	status = qglCheckFramebufferStatus(GL_FRAMEBUFFER);
	switch(status)
	{
		K_CASE(GL_FRAMEBUFFER_COMPLETE)
			K_CASE(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT)
			K_CASE(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT)
			K_CASE(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS)
			K_CASE(GL_FRAMEBUFFER_UNSUPPORTED)
	}
#undef K_CASE
	return status;
}

unsigned getError(void)
{
	GLuint error;

	static const char *ErrorString[] = {
		"GL_INVALID_ENUM", 
		"GL_INVALID_VALUE", 
		"GL_INVALID_OPERATION", 
		"GL_OUT_OF_MEMORY", 
	};
	error = glGetError();
	if(error == GL_NO_ERROR)
		return 0;
	fprintf(stderr, "[karin_FrameBufferObject]: GL Error->%s\n", ErrorString[error - 0x500]);
	return 1;
}

GLuint genTexture2D(GLuint w, GLuint h)
{
	GLuint tex;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_LINEAR);
	qglGenerateMipmap(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, M_TextureFormat, w, h, 0, M_TextureFormat, GL_UNSIGNED_BYTE, NULL);
	glBindTexture(GL_TEXTURE_2D, 0);

	return tex;
}

void bind(karin_FrameBufferObject *fbo)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	qglBindFramebuffer(GL_FRAMEBUFFER, fbo->m_handle);
}

void unbind(karin_FrameBufferObject *fbo)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	qglBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void blit(karin_FrameBufferObject *fbo)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	unbind(fbo);
	karinBeginRender2D(fbo->m_viewportWidth, fbo->m_viewportHeight);
	{
		//glClearColor(0.0, 0.0, 0.0, 1.0);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindTexture(GL_TEXTURE_2D, fbo->m_texture);
		glBindBuffer(GL_ARRAY_BUFFER, fbo->m_buffer[TexCoord_Buffer]);
		glTexCoordPointer(2, GL_FLOAT, 0, NULL);
		glBindBuffer(GL_ARRAY_BUFFER, fbo->m_buffer[Vertex_Buffer]);
		glVertexPointer(2, GL_FLOAT, 0, NULL);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);

		/*
		if(harm_usingVKB->integer)
			*/
			karinGLRenderVKB();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glFlush();
	}
	karinEndRender2D();
}

void initBuffer(karin_FrameBufferObject *fbo, GLfloat w, GLfloat h)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	const GLfloat vs[] = {
		0.0, 0.0,
		w, 0.0,
		w, h,
		0.0, h,
	};
	const GLfloat ts[] = {
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,
	};

	glGenBuffers(Total_Buffer, fbo->m_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, fbo->m_buffer[Vertex_Buffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vs), vs, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, fbo->m_buffer[TexCoord_Buffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ts), ts, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void resize(karin_FrameBufferObject *fbo, GLuint w, GLuint h, GLuint vw, GLuint vh)
{
	if(!fbo)
		return;
	if(!fbo->m_inited)
		return;

	if((w != fbo->m_width || h != fbo->m_height) && w > M_MinSize && h > M_MinSize)
	{
		fbo->m_width = w;
		fbo->m_height = h;

		qglBindFramebuffer(GL_FRAMEBUFFER, fbo->m_handle);
		qglFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, 0, 0);
		glDeleteTextures(1, &fbo->m_texture);
		fbo->m_texture = 0;

		qglFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_OES, GL_RENDERBUFFER, 0);
		qglDeleteRenderbuffers(Total_Render_Buffer, fbo->m_renderBuffer);
		memset(fbo->m_renderBuffer, 0, Total_Render_Buffer * sizeof(GLuint));
		memset(fbo->m_buffer, 0, Total_Buffer * sizeof(GLuint));

		attachFrameBuffer(fbo, fbo->m_width, fbo->m_height);

		qglBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	if((vw != fbo->m_viewportWidth || vh != fbo->m_viewportHeight) && vw > M_MinSize && vh > M_MinSize)
	{
		fbo->m_viewportWidth = vw;
		fbo->m_viewportHeight = vh;

		const GLfloat vs[] = {
			0.0, 0.0,
			fbo->m_viewportWidth, 0.0,
			fbo->m_viewportWidth, fbo->m_viewportHeight,
			0.0, fbo->m_viewportHeight,
		};

		glBindBuffer(GL_ARRAY_BUFFER, fbo->m_buffer[Vertex_Buffer]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vs), vs);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

void attachFrameBuffer(karin_FrameBufferObject *fbo, GLuint w, GLuint h)
{
	GLenum status;
	if(!fbo)
		return;

	fbo->m_texture = genTexture2D(w, h);
	qglFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo->m_texture, 0);

	qglGenRenderbuffers(Total_Render_Buffer, fbo->m_renderBuffer);

	qglBindRenderbuffer(GL_RENDERBUFFER, fbo->m_renderBuffer[Depth_Render_Buffer]);
	qglRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8_OES, w, h);
	printRenderBufferParams();
	qglBindRenderbuffer(GL_RENDERBUFFER, 0);
	qglFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo->m_renderBuffer[Depth_Render_Buffer]);
	qglFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, fbo->m_renderBuffer[Depth_Render_Buffer]);

	status = getFBOStatus();
}

unsigned isBind(const karin_FrameBufferObject *fbo)
{
	GLint cur_fbo;

	if(!fbo)
		return 0;
	if(!fbo->m_inited)
		return 0;

	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &cur_fbo);

	return cur_fbo == fbo->m_handle ? 1 : 0;
}

void printRenderBufferParams()
{
	GLint _v;
#define _GETP(x) qglGetRenderbufferParameteriv(GL_RENDERBUFFER, x, &_v); \
	printf(#x" -> %d 0x%x\n", _v, _v);
	_GETP(GL_RENDERBUFFER_WIDTH)
		_GETP(GL_RENDERBUFFER_HEIGHT)
		_GETP(GL_RENDERBUFFER_INTERNAL_FORMAT)
		_GETP(GL_RENDERBUFFER_RED_SIZE)
		_GETP(GL_RENDERBUFFER_GREEN_SIZE)
		_GETP(GL_RENDERBUFFER_BLUE_SIZE)
		_GETP(GL_RENDERBUFFER_ALPHA_SIZE)
		_GETP(GL_RENDERBUFFER_DEPTH_SIZE)
		_GETP(GL_RENDERBUFFER_STENCIL_SIZE)
#undef _GETP
}

void getFBOProc(void)
{
	if(fboProcInited)
		return;

	SDLDLSYM(glIsRenderbuffer);
	SDLDLSYM(glBindRenderbuffer);
	SDLDLSYM(glDeleteRenderbuffers);
	SDLDLSYM(glGenRenderbuffers);
	SDLDLSYM(glRenderbufferStorage);
	SDLDLSYM(glGetRenderbufferParameteriv);
	SDLDLSYM(glIsFramebuffer);
	SDLDLSYM(glBindFramebuffer);
	SDLDLSYM(glDeleteFramebuffers);
	SDLDLSYM(glGenFramebuffers);
	SDLDLSYM(glCheckFramebufferStatus);
	SDLDLSYM(glFramebufferRenderbuffer);
	SDLDLSYM(glFramebufferTexture2D);
	SDLDLSYM(glGetFramebufferAttachmentParameteriv);
	SDLDLSYM(glGenerateMipmap);

	fboProcInited = 1;
}
