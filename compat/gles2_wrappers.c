#ifdef APKENV_GLES2
#include "gles2_wrappers.h"
#include <assert.h>
#ifdef APKENV_DEBUG
#  define WRAPPERS_DEBUG_PRINTF(_Fmt, ...) printf("%lu " _Fmt, pthread_self(), ## __VA_ARGS__)
#else
#  define WRAPPERS_DEBUG_PRINTF(...)
#endif

#include <pthread.h>

void
my_glActiveTexture(GLenum texture)
{
    WRAPPERS_DEBUG_PRINTF("glActiveTexture(%d)\n", texture);
    glActiveTexture(texture);
}
void
my_glAttachShader(GLuint program, GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glAttachShader(%u, %u)\n", program, shader);
    glAttachShader(program, shader);
}
void
my_glBindAttribLocation(GLuint program, GLuint index, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glBindAttribLocation(%u, %u, %s)\n", program, index, name);
    glBindAttribLocation(program, index, name);
}
void
my_glBindBuffer(GLenum target, GLuint buffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindBuffer(%d, %u)\n", target, buffer);
    glBindBuffer(target, buffer);
}
void
my_glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindFramebuffer(%d, %u)\n", target, framebuffer);
    glBindFramebuffer(target, framebuffer);
}
void
my_glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindRenderbuffer(%d, %u)\n", target, renderbuffer);
    glBindRenderbuffer(target, renderbuffer);
}
void
my_glBindTexture(GLenum target, GLuint texture)
{
    WRAPPERS_DEBUG_PRINTF("glBindTexture(%d, %u)\n", target, texture);
    glBindTexture(target, texture);
}
void
my_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendColor(%3.2f, %3.2f, %3.2f, %3.2f)\n", red, green, blue, alpha);
    glBlendColor(red, green, blue, alpha);
}
void
my_glBlendEquation(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glBlendEquation(%d)\n", mode);
    glBlendEquation(mode);
}
void
my_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendEquationSeparate(%d, %d)\n", modeRGB, modeAlpha);
    glBlendEquationSeparate(modeRGB, modeAlpha);
}
void
my_glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    WRAPPERS_DEBUG_PRINTF("glBlendFunc(%d, %d)\n", sfactor, dfactor);
    glBlendFunc(sfactor, dfactor);
}
void
my_glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendFuncSeparate(%d, %d, %d, %d)\n", srcRGB, dstRGB, srcAlpha, dstAlpha);
    glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void
my_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
    WRAPPERS_DEBUG_PRINTF("glBufferData(%d, %ld, %p, %d)\n", target, size, data, usage);
    glBufferData(target, size, data, usage);
}
void
my_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glBufferSubData(%d, %ld, %ld, %p)\n", target, offset, size, data);
    glBufferSubData(target, offset, size, data);
}
GLenum
my_glCheckFramebufferStatus(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glCheckFramebufferStatus(%d)\n", target);
    return glCheckFramebufferStatus(target);
}
void
my_glClear(GLbitfield mask)
{
    WRAPPERS_DEBUG_PRINTF("glClear(%x)\n", mask);
    glClear(mask);
}
void
my_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    WRAPPERS_DEBUG_PRINTF("glClearColor(%3.2f, %3.2f, %3.2f, %3.2f)\n", red, green, blue, alpha);
    glClearColor(red, green, blue, alpha);
}
void
my_glClearDepthf(GLclampf depth)
{
    WRAPPERS_DEBUG_PRINTF("glClearDepthf(%3.2f)\n", depth);
    glClearDepthf(depth);
}
void
my_glClearStencil(GLint s)
{
    WRAPPERS_DEBUG_PRINTF("glClearStencil(%d)\n", s);
    glClearStencil(s);
}
void
my_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	WRAPPERS_DEBUG_PRINTF("glColorMask(%s, %s, %s, %s)\n", red ? "true" : "false", green ? "true" : "false", blue ? "true" : "false", alpha ? "true" : "false");
    glColorMask(red, green, blue, alpha);
}
void
my_glCompileShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glCompileShader(%u)\n", shader);
    glCompileShader(shader);
}
void
my_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexImage2D(%d, %d, %d, %u, %u, %d, %u, %p)\n", target, level, internalformat, width, height, border, imageSize, data);
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
void
my_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexSubImage2D(%d, %d, %d, %d, %u, %u, %d, %u, %p)\n", target, level, xoffset, yoffset, width, height, format, imageSize, data);
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void
my_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexImage2D(%d, %d, %d, %d, %d, %d, %d, %d)\n", target, level, internalformat, x, y, width, height, border);
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void
my_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexSubImage2D(%d, %d, %d, %d, %d, %d, %u, %u)\n", target, level, xoffset, yoffset, x, y, width, height);
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
GLuint
my_glCreateProgram()
{
    WRAPPERS_DEBUG_PRINTF("glCreateProgram()\n");
    return glCreateProgram();
}
GLuint
my_glCreateShader(GLenum type)
{
	/*
		GL_FRAGMENT_SHADER	= 0x8B30
		GL_VERTEX_SHADER	= 0x8B31
	*/
	switch ( type )
	{
		case 0x8B30:
		{
			WRAPPERS_DEBUG_PRINTF("glCreateShader( GL_FRAGMENT_SHADER )\n" );
		}
		break;
		case 0x8B31:
		{
			WRAPPERS_DEBUG_PRINTF("glCreateShader( GL_VERTEX_SHADER )\n" );
		}
		break;
		default:
		{
			WRAPPERS_DEBUG_PRINTF("glCreateShader(%d)\n", type);
		}
	}
    return glCreateShader(type);
}
void
my_glCullFace(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glCullFace(%d)\n", mode);
    glCullFace(mode);
}
void
my_glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteBuffers(%u, %p)\n", n, buffers);
    glDeleteBuffers(n, buffers);
}
void
my_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteFramebuffers(%d, %p)\n", n, framebuffers);
    glDeleteFramebuffers(n, framebuffers);
}
void
my_glDeleteProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteProgram(%u)\n", program);
    glDeleteProgram(program);
}
void
my_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteRenderbuffers(%u, %p)\n", n, renderbuffers);
    glDeleteRenderbuffers(n, renderbuffers);
}
void
my_glDeleteShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteShader(%u)\n", shader);
    glDeleteShader(shader);
}
void
my_glDeleteTextures(GLsizei n, const GLuint *textures)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteTextures(%u, %p)\n", n, textures);
    glDeleteTextures(n, textures);
}
void
my_glDepthFunc(GLenum func)
{
    WRAPPERS_DEBUG_PRINTF("glDepthFunc(%d)\n", func);
    glDepthFunc(func);
}
void
my_glDepthMask(GLboolean flag)
{
	WRAPPERS_DEBUG_PRINTF("glDepthMask(%s)\n", flag ? "true" : "false");
    glDepthMask(flag);
}
void
my_glDepthRangef(GLclampf zNear, GLclampf zFar)
{
    WRAPPERS_DEBUG_PRINTF("glDepthRangef(%3.2f, %3.2f)\n", zNear, zFar);
    glDepthRangef(zNear, zFar);
}
void
my_glDetachShader(GLuint program, GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glDetachShader(%u, %u)\n", program, shader);
    glDetachShader(program, shader);
}
void
my_glDisable(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glDisable(%d)\n", cap);
    glDisable(cap);
}
void
my_glDisableVertexAttribArray(GLuint index)
{
    WRAPPERS_DEBUG_PRINTF("glDisableVertexAttribArray(%u)\n", index);
    glDisableVertexAttribArray(index);
}
void
my_glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    WRAPPERS_DEBUG_PRINTF("glDrawArrays(%d, %d, %u)\n", mode, first, count);
    glDrawArrays(mode, first, count);
}
void
my_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices)
{
    WRAPPERS_DEBUG_PRINTF("glDrawElements(%d, %u, %d, %p)\n", mode, count, type, indices);
    glDrawElements(mode, count, type, indices);
}
void
my_glEnable(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glEnable(%d)\n", cap);
    glEnable(cap);
}
void
my_glEnableVertexAttribArray(GLuint index)
{
    WRAPPERS_DEBUG_PRINTF("glEnableVertexAttribArray(%u)\n", index);
    glEnableVertexAttribArray(index);
}
void
my_glFinish()
{
    WRAPPERS_DEBUG_PRINTF("glFinish()\n");
    glFinish();
}
void
my_glFlush()
{
    WRAPPERS_DEBUG_PRINTF("glFlush()\n");
    glFlush();
}
void
my_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferRenderbuffer(%d, %d, %d, %u)\n", target, attachment, renderbuffertarget, renderbuffer);
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void
my_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferTexture2D(%d, %d, %d, %u, %d)\n", target, attachment, textarget, texture, level);
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void
my_glFrontFace(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glFrontFace(%d)\n", mode);
    glFrontFace(mode);
}
void
my_glGenBuffers(GLsizei n, GLuint *buffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenBuffers(%u, %p)\n", n, buffers);
    glGenBuffers(n, buffers);
}
void
my_glGenerateMipmap(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glGenerateMipmap(%d)\n", target);
    glGenerateMipmap(target);
}
void
my_glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenFramebuffers(%u, %p)\n", n, framebuffers);
    glGenFramebuffers(n, framebuffers);
}
void
my_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenRenderbuffers(%u, %p)\n", n, renderbuffers);
    glGenRenderbuffers(n, renderbuffers);
}
void
my_glGenTextures(GLsizei n, GLuint *textures)
{
    WRAPPERS_DEBUG_PRINTF("glGenTextures(%u, %p)\n", n, textures);
    glGenTextures(n, textures);
}
void
my_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetActiveAttrib(%u, %u, %u, %p, %p, %p, %s)\n", program, index, bufsize, length, size, type, name);
    glGetActiveAttrib(program, index, bufsize, length, size, type, name);
}
void
my_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetActiveUniform(%u, %u, %u, %p, %p, %p, %p)\n", program, index, bufsize, length, size, type, name);
    glGetActiveUniform(program, index, bufsize, length, size, type, name);
}
void
my_glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders)
{
    WRAPPERS_DEBUG_PRINTF("glGetAttachedShaders(%u, %u, %p, %p)\n", program, maxcount, count, shaders);
    glGetAttachedShaders(program, maxcount, count, shaders);
}
int
my_glGetAttribLocation(GLuint program, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetAttribLocation(%u, %s)\n", program, name);
    return glGetAttribLocation(program, name);
}
void
my_glGetBooleanv(GLenum pname, GLboolean *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBooleanv(%d, %p)\n", pname, params);
    glGetBooleanv(pname, params);
}
void
my_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBufferParameteriv(%d, %d, %p)\n", target, pname, params);
    glGetBufferParameteriv(target, pname, params);
}
GLenum
my_glGetError()
{
    WRAPPERS_DEBUG_PRINTF("glGetError()\n");
    return glGetError();
}
void
my_glGetFloatv(GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetFloatv(%d, %p)\n", pname, params);
    glGetFloatv(pname, params);
}
void
my_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetFramebufferAttachmentParameteriv(%d, %d, %d, %p)\n", target, attachment, pname, params);
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void
my_glGetIntegerv(GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetIntegerv(%d, %p)\n", pname, params);
    glGetIntegerv(pname, params);
}
void
my_glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramiv(%u, %d, %p)\n", program, pname, params);
    glGetProgramiv(program, pname, params);
}
void
my_glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, char *infolog)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramInfoLog(%u, %u, %p, %s)\n", program, bufsize, length, infolog);
    glGetProgramInfoLog(program, bufsize, length, infolog);
}
void
my_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetRenderbufferParameteriv(%d, %d, %p)\n", target, pname, params);
    glGetRenderbufferParameteriv(target, pname, params);
}
void
my_glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderiv(%u, %d, %p)\n", shader, pname, params);
    glGetShaderiv(shader, pname, params);
}
void
my_glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, char *infolog)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderInfoLog(%u, %u, %p, %p)\n", shader, bufsize, length, infolog);
	glGetShaderInfoLog(shader, bufsize, length, infolog);
	if ( length && *length != 0 )
	{
		WRAPPERS_DEBUG_PRINTF(" - Failed to compile! %s\n", infolog);
	}
}
void
my_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderPrecisionFormat(%d, %d, %p, %p)\n", shadertype, precisiontype, range, precision);
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
void
my_glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, char *source)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderSource(%u, %u, %p, %p)\n", shader, bufsize, length, source);
    glGetShaderSource(shader, bufsize, length, source);
}
const GLubyte *
my_glGetString(GLenum name)
{
	// #define GL_VENDOR                         0x1F00
	// #define GL_RENDERER                       0x1F01
	// #define GL_VERSION                        0x1F02
	// #define GL_EXTENSIONS                     0x1F03
	switch ( name )
	{
		case 0x1F00:
			WRAPPERS_DEBUG_PRINTF("glGetString(GL_VENDOR)\n");
			break;
		case 0x1F01:
			WRAPPERS_DEBUG_PRINTF("glGetString(GL_RENDERER)\n");
			break;
		case 0x1F02:
			WRAPPERS_DEBUG_PRINTF("glGetString(GL_VERSION)\n");
			break;
		case 0x1F03:
			WRAPPERS_DEBUG_PRINTF("glGetString(GL_EXTENSIONS)\n");
			break;
		default:
			WRAPPERS_DEBUG_PRINTF("glGetString(%x)\n", name);
	}
    return glGetString(name);
}
void
my_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexParameterfv(%d, %d, %p)\n", target, pname, params);
    glGetTexParameterfv(target, pname, params);
}
void
my_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexParameteriv(%d, %d, %p)\n", target, pname, params);
    glGetTexParameteriv(target, pname, params);
}
void
my_glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformfv(%u, %d, %p)\n", program, location, params);
    glGetUniformfv(program, location, params);
}
void
my_glGetUniformiv(GLuint program, GLint location, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformiv(%u, %d, %p)\n", program, location, params);
    glGetUniformiv(program, location, params);
}
int
my_glGetUniformLocation(GLuint program, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformLocation(%u, %s)\n", program, name);
    return glGetUniformLocation(program, name);
}
void
my_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribfv(%u, %d, %p)\n", index, pname, params);
    glGetVertexAttribfv(index, pname, params);
}
void
my_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribiv(%u, %d, %p)\n", index, pname, params);
    glGetVertexAttribiv(index, pname, params);
}
void
my_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribPointerv(%u, %d, %p)\n", index, pname, pointer);
    glGetVertexAttribPointerv(index, pname, pointer);
}
void
my_glHint(GLenum target, GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glHint(%d, %d)\n", target, mode);
    glHint(target, mode);
}
GLboolean
my_glIsBuffer(GLuint buffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsBuffer(%u)\n", buffer);
    return glIsBuffer(buffer);
}
GLboolean
my_glIsEnabled(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glIsEnabled(%d)\n", cap);
    return glIsEnabled(cap);
}
GLboolean
my_glIsFramebuffer(GLuint framebuffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsFramebuffer(%u)\n", framebuffer);
    return glIsFramebuffer(framebuffer);
}
GLboolean
my_glIsProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glIsProgram(%u)\n", program);
    return glIsProgram(program);
}
GLboolean
my_glIsRenderbuffer(GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsRenderbuffer(%u)\n", renderbuffer);
    return glIsRenderbuffer(renderbuffer);
}
GLboolean
my_glIsShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glIsShader(%u)\n", shader);
    return glIsShader(shader);
}
GLboolean
my_glIsTexture(GLuint texture)
{
    WRAPPERS_DEBUG_PRINTF("glIsTexture(%u)\n", texture);
    return glIsTexture(texture);
}
void
my_glLineWidth(GLfloat width)
{
    WRAPPERS_DEBUG_PRINTF("glLineWidth(%3.2f)\n", width);
    glLineWidth(width);
}
void
my_glLinkProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glLinkProgram(%u)\n", program);
    glLinkProgram(program);
}
void
my_glPixelStorei(GLenum pname, GLint param)
{
    WRAPPERS_DEBUG_PRINTF("glPixelStorei(%d, %d)\n", pname, param);
    glPixelStorei(pname, param);
}
void
my_glPolygonOffset(GLfloat factor, GLfloat units)
{
    WRAPPERS_DEBUG_PRINTF("glPolygonOffset(%3.2f, %3.2f)\n", factor, units);
    glPolygonOffset(factor, units);
}
void
my_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glReadPixels(%d, %d, %u, %u, %d, %d, %p)\n", x, y, width, height, format, type, pixels);
    glReadPixels(x, y, width, height, format, type, pixels);
}
void
my_glReleaseShaderCompiler()
{
    WRAPPERS_DEBUG_PRINTF("glReleaseShaderCompiler()\n");
    glReleaseShaderCompiler();
}
void
my_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glRenderbufferStorage(%d, %d, %u, %u)\n", target, internalformat, width, height);
    glRenderbufferStorage(target, internalformat, width, height);
}
void
my_glSampleCoverage(GLclampf value, GLboolean invert)
{
	WRAPPERS_DEBUG_PRINTF("glSampleCoverage(%3.2f, %s)\n", value, invert ? "true" : "false");
    glSampleCoverage(value, invert);
}
void
my_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glScissor(%d, %d, %u, %u)\n", x, y, width, height);
    glScissor(x, y, width, height);
}
void
my_glShaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const void *binary, GLint length)
{
    WRAPPERS_DEBUG_PRINTF("glShaderBinary(%d, %p, %d, %p, %d)\n", n, shaders, binaryformat, binary, length);
    glShaderBinary(n, shaders, binaryformat, binary, length);
}
void
my_glShaderSource(GLuint shader, GLsizei count, const char **string, const GLint *length)
{
    WRAPPERS_DEBUG_PRINTF("glShaderSource(%u, %u, %p, %p)\n", shader, count, string, length);
    glShaderSource(shader, count, string, length);
}
void
my_glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilFunc(%d, %d, %u)\n", func, ref, mask);
    glStencilFunc(func, ref, mask);
}
void
my_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilFuncSeparate(%d, %d, %d, %u)\n", face, func, ref, mask);
    glStencilFuncSeparate(face, func, ref, mask);
}
void
my_glStencilMask(GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilMask(%u)\n", mask);
    glStencilMask(mask);
}
void
my_glStencilMaskSeparate(GLenum face, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilMaskSeparate(%d, %u)\n", face, mask);
    glStencilMaskSeparate(face, mask);
}
void
my_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    WRAPPERS_DEBUG_PRINTF("glStencilOp(%d, %d, %d)\n", fail, zfail, zpass);
    glStencilOp(fail, zfail, zpass);
}
void
my_glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    WRAPPERS_DEBUG_PRINTF("glStencilOpSeparate(%d, %d, %d, %d)\n", face, fail, zfail, zpass);
    glStencilOpSeparate(face, fail, zfail, zpass);
}
void
my_glTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexImage2D(%d, %d, %d, %u, %u, %d, %d, %d, %p)\n", target, level, internalformat, width, height, border, format, type, pixels);
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
void
my_glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameterf(%d, %d, %3.2f)\n", target, pname, param);
    glTexParameterf(target, pname, param);
}
void
my_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameterfv(%d, %d, %p)\n", target, pname, params);
    glTexParameterfv(target, pname, params);
}
void
my_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameteri(%d, %d, %d)\n", target, pname, param);
    glTexParameteri(target, pname, param);
}
void
my_glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameteriv(%d, %d, %p)\n", target, pname, params);
    glTexParameteriv(target, pname, params);
}
void
my_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexSubImage2D(%d, %d, %d, %d, %u, %u, %d, %d, %p)\n", target, level, xoffset, yoffset, width, height, format, type, pixels);
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void
my_glUniform1f(GLint location, GLfloat x)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1f(%d, %3.2f)\n", location, x);
    glUniform1f(location, x);
}
void
my_glUniform1fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1fv(%d, %u, %p)\n", location, count, v);
    glUniform1fv(location, count, v);
}
void
my_glUniform1i(GLint location, GLint x)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1i(%d, %d)\n", location, x);
    glUniform1i(location, x);
}
void
my_glUniform1iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1iv(%d, %u, %p)\n", location, count, v);
    glUniform1iv(location, count, v);
}
void
my_glUniform2f(GLint location, GLfloat x, GLfloat y)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2f(%d, %3.2f, %3.2f)\n", location, x, y);
    glUniform2f(location, x, y);
}
void
my_glUniform2fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2fv(%d, %u, %p)\n", location, count, v);
    glUniform2fv(location, count, v);
}
void
my_glUniform2i(GLint location, GLint x, GLint y)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2i(%d, %d, %d)\n", location, x, y);
    glUniform2i(location, x, y);
}
void
my_glUniform2iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2iv(%d, %u, %p)\n", location, count, v);
    glUniform2iv(location, count, v);
}
void
my_glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3f(%d, %3.2f, %3.2f, %3.2f)\n", location, x, y, z);
    glUniform3f(location, x, y, z);
}
void
my_glUniform3fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3fv(%d, %u, %p)\n", location, count, v);
    glUniform3fv(location, count, v);
}
void
my_glUniform3i(GLint location, GLint x, GLint y, GLint z)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3i(%d, %d, %d, %d)\n", location, x, y, z);
    glUniform3i(location, x, y, z);
}
void
my_glUniform3iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3iv(%d, %u, %p)\n", location, count, v);
    glUniform3iv(location, count, v);
}
void
my_glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4f(%d, %3.2f, %3.2f, %3.2f, %3.2f)\n", location, x, y, z, w);
    glUniform4f(location, x, y, z, w);
}
void
my_glUniform4fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4fv(%d, %u, %p)\n", location, count, v);
    glUniform4fv(location, count, v);
}
void
my_glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4i(%d, %d, %d, %d, %d)\n", location, x, y, z, w);
    glUniform4i(location, x, y, z, w);
}
void
my_glUniform4iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4iv(%d, %u, %p)\n", location, count, v);
    glUniform4iv(location, count, v);
}
void
my_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	WRAPPERS_DEBUG_PRINTF("glUniformMatrix2fv(%d, %u, %s, %p)\n", location, count, transpose ? "true" : "false", value);
    glUniformMatrix2fv(location, count, transpose, value);
}
void
my_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	WRAPPERS_DEBUG_PRINTF("glUniformMatrix3fv(%d, %d, %s, %p)\n", location, count, transpose ? "true" : "false", value);
    glUniformMatrix3fv(location, count, transpose, value);
}
void
my_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	WRAPPERS_DEBUG_PRINTF("glUniformMatrix4fv(%d, %u, %s, %p)\n", location, count, transpose ? "true" : "false", value);
    glUniformMatrix4fv(location, count, transpose, value);
}
void
my_glUseProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glUseProgram(%u)\n", program);
    glUseProgram(program);
}
void
my_glValidateProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glValidateProgram(%u)\n", program);
    glValidateProgram(program);
}
void
my_glVertexAttrib1f(GLuint indx, GLfloat x)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib1f(%u, %3.2f)\n", indx, x);
    glVertexAttrib1f(indx, x);
}
void
my_glVertexAttrib1fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib1fv(%u, %p)\n", indx, values);
    glVertexAttrib1fv(indx, values);
}
void
my_glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib2f(%u, %3.2f, %3.2f)\n", indx, x, y);
    glVertexAttrib2f(indx, x, y);
}
void
my_glVertexAttrib2fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib2fv(%u, %p)\n", indx, values);
    glVertexAttrib2fv(indx, values);
}
void
my_glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib3f(%u, %3.2f, %3.2f, %3.2f)\n", indx, x, y, z);
    glVertexAttrib3f(indx, x, y, z);
}
void
my_glVertexAttrib3fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib3fv(%u, %p)\n", indx, values);
    glVertexAttrib3fv(indx, values);
}
void
my_glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib4f(%u, %3.2f, %3.2f, %3.2f, %3.2f)\n", indx, x, y, z, w);
    glVertexAttrib4f(indx, x, y, z, w);
}
void
my_glVertexAttrib4fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib4fv(%d, %p)\n", indx, values);
    glVertexAttrib4fv(indx, values);
}
void
my_glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *ptr)
{
	WRAPPERS_DEBUG_PRINTF("glVertexAttribPointer(%u, %u, %d, %s, %u, %p)\n", indx, size, type, normalized ? "true" : "false", stride, ptr);
    glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}
void
my_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glViewport(%d, %d, %u, %u)\n", x, y, width, height);
    glViewport(x, y, width, height);
}
void
my_glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image)
{
    WRAPPERS_DEBUG_PRINTF("glEGLImageTargetTexture2DOES(%d, %p)\n", target, image);
    /* No CALL */ printf("UNIMPLEMENTED: glEGLImageTargetTexture2DOES\n");
}
void
my_glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image)
{
    WRAPPERS_DEBUG_PRINTF("glEGLImageTargetRenderbufferStorageOES(%d, %p)\n", target, image);
    /* No CALL */ printf("UNIMPLEMENTED: glEGLImageTargetRenderbufferStorageOES\n");
}
void *
my_glMapBufferOES(GLenum target, GLenum access)
{
    WRAPPERS_DEBUG_PRINTF("glMapBufferOES(%d, %d)\n", target, access);
    /* No CALL */ printf("UNIMPLEMENTED: glMapBufferOES\n");
	return NULL;
}
GLboolean
my_glUnmapBufferOES(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glUnmapBufferOES(%d)\n", target);
    /* No CALL */ printf("UNIMPLEMENTED: glUnmapBufferOES\n");
	return 0;
}
void
my_glGetBufferPointervOES(GLenum target, GLenum pname, void **params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBufferPointervOES(%d, %d, %p)\n", target, pname, params);
    /* No CALL */ printf("UNIMPLEMENTED: glGetBufferPointervOES\n");
}
void
my_glTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexImage3DOES(%d, %d, %d, %u, %u, %u, %d, %d, %d, %p)\n", target, level, internalformat, width, height, depth, border, format, type, pixels);
    /* No CALL */ printf("UNIMPLEMENTED: glTexImage3DOES\n");
}
void
my_glTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexSubImage3DOES(%d, %d, %d, %d, %d, %u, %u, %u, %d, %d, %p)\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    /* No CALL */ printf("UNIMPLEMENTED: glTexSubImage3DOES\n");
}
void
my_glCopyTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexSubImage3DOES(%d, %d, %d, %d, %d, %d, %d, %u, %u)\n", target, level, xoffset, yoffset, zoffset, x, y, width, height);
    /* No CALL */ printf("UNIMPLEMENTED: glCopyTexSubImage3DOES\n");
}
void
my_glCompressedTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexImage3DOES(%d, %d, %d, %u, %u, %u, %d, %u, %p)\n", target, level, internalformat, width, height, depth, border, imageSize, data);
    /* No CALL */ printf("UNIMPLEMENTED: glCompressedTexImage3DOES\n");
}
void
my_glCompressedTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexSubImage3DOES(%d, %d, %d, %d, %d, %u, %u, %u, %d, %u, %p)\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    /* No CALL */ printf("UNIMPLEMENTED: glCompressedTexSubImage3DOES\n");
}
void
my_glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferTexture3DOES(%d, %d, %d, %u, %d, %d)\n", target, attachment, textarget, texture, level, zoffset);
    /* No CALL */ printf("UNIMPLEMENTED: glFramebufferTexture3DOES\n");
}
void
my_glMultiDrawArraysEXT(GLenum mode, GLint *first, GLsizei *count, GLsizei primcount)
{
    WRAPPERS_DEBUG_PRINTF("glMultiDrawArraysEXT(%d, %p, %p, %u)\n", mode, first, count, primcount);
    /* No CALL */ printf("UNIMPLEMENTED: glMultiDrawArraysEXT\n");
}
void
my_glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const GLvoid **indices, GLsizei primcount)
{
    WRAPPERS_DEBUG_PRINTF("glMultiDrawElementsEXT(%d, %p, %d, %p, %u)\n", mode, count, type, indices, primcount);
    /* No CALL */ printf("UNIMPLEMENTED: glMultiDrawElementsEXT\n");
}
void
my_glTexBindStreamIMG(GLint device, GLint deviceoffset)
{
    WRAPPERS_DEBUG_PRINTF("glTexBindStreamIMG(%d, %d)\n", device, deviceoffset);
    /* No CALL */ printf("UNIMPLEMENTED: glTexBindStreamIMG\n");
}
void
my_glGetTexStreamDeviceAttributeivIMG(GLint device, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexStreamDeviceAttributeivIMG(%d, %d, %p)\n", device, pname, params);
    /* No CALL */ printf("UNIMPLEMENTED: glGetTexStreamDeviceAttributeivIMG\n");
}
const GLubyte *
my_glGetTexStreamDeviceNameIMG(GLint device)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexStreamDeviceNameIMG(%d)\n", device);
    /* No CALL */ printf("UNIMPLEMENTED: glGetTexStreamDeviceNameIMG\n");
	return NULL;
}
void
my_glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramBinaryOES(%u, %u, %p, %p, %p)\n", program, bufSize, length, binaryFormat, binary);
    /* No CALL */ printf("UNIMPLEMENTED: glGetProgramBinaryOES\n");
}
void
my_glProgramBinaryOES(GLuint program, GLenum binaryFormat, const void *binary, GLint length)
{
    WRAPPERS_DEBUG_PRINTF("glProgramBinaryOES(%u, %d, %p, %d)\n", program, binaryFormat, binary, length);
    /* No CALL */ printf("UNIMPLEMENTED: glProgramBinaryOES\n");
}
#endif /* APKENV_GLES2 */
