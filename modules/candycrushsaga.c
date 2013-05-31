
/**
 * apkenv
 * Copyright (c) 2012, Thomas Perl <m@thp.io>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **/

/**
 * Candy Crush Saga 1.0.10 - By: Steven Craft
 *
 **/

#include "common.h"

#include <string.h>
#include <limits.h>
#include "SDL/SDL.h"
#include <assert.h>

// Typedefs. Got these from classes.dex (http://stackoverflow.com/questions/1249973/decompiling-dex-into-java-sourcecode)
typedef jint (*candycrushsaga_createnativeinstance_t)(JNIEnv *env, jobject obj1, jobject obj2) SOFTFP;
typedef void (*candycrushsaga_create_t)(JNIEnv *env, jobject obj, int paramInt, jobject paramActivity, jobject paramContext) SOFTFP;
typedef void (*candycrushsaga_destroy_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*candycrushsaga_init_t)(JNIEnv *env, jobject obj, int paramInt1, int paramInt2, int paramInt3, int paramInt4) SOFTFP;
typedef void (*candycrushsaga_onaccelerometer_t)(JNIEnv *env, jobject obj, float paramFloat1, float paramFloat2, float paramFloat3) SOFTFP;
typedef void (*candycrushsaga_onbackkeydown_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*candycrushsaga_onbackkeyup_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*candycrushsaga_onkeydown_t)(JNIEnv *env, jobject obj, int paramInt) SOFTFP;
typedef void (*candycrushsaga_onkeyup_t)(JNIEnv *env, jobject obj, int paramInt) SOFTFP;
typedef void (*candycrushsaga_onmenukeydown_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*candycrushsaga_onmenukeyup_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*candycrushsaga_onsystemevent_t)(JNIEnv *env, jobject obj, int paramInt) SOFTFP;
typedef void (*candycrushsaga_ontouchevent_t)(JNIEnv *env, jobject obj, int paramInt1, int paramInt2, int paramInt3, int paramInt4) SOFTFP;
typedef jboolean (*candycrushsaga_step_t)(JNIEnv *env, jobject obj, int paramInt1) SOFTFP;
typedef void (*candycrushsaga_updateorientation_t)(JNIEnv *env, jobject obj, int paramInt1) SOFTFP;
typedef void (*candycrushsaga_updatescreensize_t)(JNIEnv *env, jobject obj, int paramInt1, int paramInt2) SOFTFP;

struct SupportModulePriv {
    jni_onload_t JNI_OnLoad;
    candycrushsaga_createnativeinstance_t native_createnativeinstance;
    candycrushsaga_create_t native_create;
    candycrushsaga_destroy_t native_destroy;
    candycrushsaga_init_t native_init;
    candycrushsaga_onaccelerometer_t native_onaccelerometer;
    candycrushsaga_onbackkeydown_t native_onbackkeydown;
    candycrushsaga_onbackkeyup_t native_onbackkeyup;
	candycrushsaga_onkeydown_t native_onkeydown;
	candycrushsaga_onkeyup_t native_onkeyup;
	candycrushsaga_onmenukeydown_t native_onmenukeydown;
	candycrushsaga_onmenukeyup_t native_onmenukeyup;
	candycrushsaga_onsystemevent_t native_onsystemevent;
	candycrushsaga_ontouchevent_t native_ontouchevent;
	candycrushsaga_step_t native_step;
	candycrushsaga_updateorientation_t native_updateorientation;
	candycrushsaga_updatescreensize_t native_updatescreensize;
	const char *myHome;
};
static struct SupportModulePriv candycrushsaga_priv;

/* Global application state so we can call this from override thingie */
struct GlobalState *global;
struct SupportModule *global_self;

jthrowable
candycrashsaga_JNIEnv_ExceptionOccurred(JNIEnv* p0)
{
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_ExceptionOccurred()\n");
	return NULL;
}

typedef struct
{
	int		in_use;
	char *	data;
	size_t	size;
	int		offset;
} candycrushsaga_filehandle;

static candycrushsaga_filehandle candycrushsaga_filehandles[ 32 ];

jint
candycrashsaga_JNIEnv_CallStaticIntMethodV(JNIEnv* p0, jclass p1, jmethodID p2, va_list p3)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_CallStaticIntMethodV(%p, %s, %s)\n", p2->clazz, p2->name, p2->sig);

	if ( strcmp( p2->name, "fileOpen" ) == 0 )
	{
		/* FILE_MODE
			0	READ
			1	APPEND
			2	WRITE
		*/
		size_t ix = 0;
		for ( ix = 0; ix < 32; ++ix )
		{
			if ( candycrushsaga_filehandles[ ix ].in_use == 0 )
			{
				struct dummy_jstring * filenamePtr;
				jint fileMode;
				char filenameFixed[ 512 ] = { '\0' };

				filenamePtr = va_arg( p3, struct dummy_jstring * );
				fileMode = va_arg( p3, jint );

				if ( fileMode >= 0 && fileMode <= 2 )
				{
					MODULE_DEBUG_PRINTF( "fileOpen( %s, %s )\n", filenamePtr->data ? filenamePtr->data : "(null)", fileMode == 0 ? "READ" : fileMode == 1 ? "APPEND" : fileMode == 2 ? "WRITE" : "UNKNOWN" );

					if ( fileMode != 0 )
					{
						static int debugStopHere = 0;
						++debugStopHere;
					}

					if ( filenamePtr->data )
					{
						int r = 1;

						strcat( filenameFixed, "assets/");
						strcat( filenameFixed, filenamePtr->data );

						char * b = NULL;
						r = global->read_file(filenameFixed, &b, &candycrushsaga_filehandles[ ix ].size);

						if ( r == 1 )
						{
							candycrushsaga_filehandles[ ix ].data = malloc( candycrushsaga_filehandles[ ix ].size + 1 );
							memcpy( candycrushsaga_filehandles[ ix ].data, b, candycrushsaga_filehandles[ ix ].size );
							candycrushsaga_filehandles[ ix ].data[ candycrushsaga_filehandles[ ix ].size ] = '\0';

							if ( b )
								free( b );

							candycrushsaga_filehandles[ ix ].offset = 0;
							candycrushsaga_filehandles[ ix ].in_use = 1;
							return ix + 1;
						}
						else
						{
							if ( b )
								free( b );

							return 0;
						}
					}
				}
			}
		}
	}
	else if ( strcmp( p2->name, "fileGetSize" ) == 0 )
	{
		jint fileHandle = va_arg( p3, jint );
		fileHandle -= 1;
		if ( fileHandle >= 0 && fileHandle < 32 )
		{
			return candycrushsaga_filehandles[ fileHandle ].size;
		}

		return 0;
	}

	return 0;
}

void
candycrashsaga_JNIEnv_CallStaticVoidMethodV(JNIEnv* p0, jclass p1, jmethodID p2, va_list p3)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_CallStaticVoidMethodV(%p, %s, %s)\n", p2->clazz, p2->name, p2->sig);

	if ( strcmp( p2->name, "setupPlatform" ) == 0 )
	{
		jint width = va_arg( p3, jint );
		jint height = va_arg( p3, jint );
		jint rotation = va_arg( p3, jint );
		jint glVersion = va_arg( p3, jint );
		jint targetFps = va_arg( p3, jint );

		MODULE_DEBUG_PRINTF( " => Width/Height : %d,%d  -  Rotation %d  -  GL Version : %d  -  Target FPS : %d\n", width, height, rotation, glVersion, targetFps );
	}
	else if ( strcmp( p2->name, "fileClose" ) == 0 )
	{
		jint fileHandle = va_arg( p3, jint );
		fileHandle -= 1;
		if ( fileHandle >= 0 && fileHandle < 32 )
		{
			free( candycrushsaga_filehandles[ fileHandle ].data );
			candycrushsaga_filehandles[ fileHandle ].in_use = 0;
		}
	}
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
}

jobject
candycrashsaga_JNIEnv_CallStaticObjectMethodV(JNIEnv* p0, jclass p1, jmethodID p2, va_list p3)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_CallStaticObjectMethodV(%p, %s, %s)\n", p2->clazz, p2->name, p2->sig);

	if ( strcmp( p2->name, "fileRead" ) == 0 )
	{
		jint fileHandle = va_arg( p3, jint );
		jint bytesToRead = va_arg( p3, jint );

		fileHandle -= 1;
		if ( fileHandle >= 0 && fileHandle < 32 )
		{
			if ( candycrushsaga_filehandles[ fileHandle ].size - candycrushsaga_filehandles[ fileHandle ].offset >= bytesToRead )
			{
				struct dummy_byte_array *result = malloc(sizeof(struct dummy_byte_array));
				int currentOffset = candycrushsaga_filehandles[ fileHandle ].offset;
				candycrushsaga_filehandles[ fileHandle ].offset += bytesToRead;

				result->data = &candycrushsaga_filehandles[ fileHandle ].data[ currentOffset ];
				result->size = bytesToRead;

				return result;
			}			
		}
	}
	else if ( strcmp( p2->name, "getDeviceId" ) == 0 )
	{
		jobject dummy = va_arg( p3, jobject );

		// TODO: Return a unique ID for this device.
		MODULE_DEBUG_PRINTF(" - getDeviceId : 9774d56d682e549c\n" );
		return (*p0)->NewStringUTF( p0, "9774d56d682e549c " );
	}
	else if ( strcmp( p2->name, "getLanguageCode" ) == 0 )
	{
		// TODO: Return the right lowercase ISO 639 code for this device.
		MODULE_DEBUG_PRINTF(" - getLanguageCode : en\n" );
		return (*p0)->NewStringUTF( p0, "en" );
	}
	else if ( strcmp( p2->name, "getCountryCode" ) == 0 )
	{
		// TODO: Return the right ISO 3166 code for this device.
		MODULE_DEBUG_PRINTF(" - getCountryCode : GB\n" );
		return (*p0)->NewStringUTF( p0, "GB" );
	}
	else if ( strcmp( p2->name, "getInstallerPackageName" ) == 0 )
	{
		jobject dummy = va_arg( p3, jobject );

		MODULE_DEBUG_PRINTF(" - getInstallerPackageName : installer_package_name_unknown\n" );
		return (*p0)->NewStringUTF( p0, "installer_package_name_unknown" );
	}

	return NULL;
}

jboolean
candycrashsaga_JNIEnv_CallStaticBooleanMethodV(JNIEnv* p0, jclass p1, jmethodID p2, va_list p3)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_CallStaticBooleanMethodV(%p, %s, %s)\n", p2->clazz, p2->name, p2->sig);

	if ( strcmp( p2->name, "fileSeek" ) == 0 )
	{
		jint fileHandle = va_arg( p3, jint );
		jint distance = va_arg( p3, jint );

		fileHandle -= 1;
		if ( fileHandle >= 0 && fileHandle < 32 )
		{
			candycrushsaga_filehandles[ fileHandle ].offset = distance;
			return JNI_TRUE;
		}
	}

	return JNI_FALSE;
}


jobject
candycrashsaga_JNIEnv_CallObjectMethodV(JNIEnv *env, jobject p1, jmethodID p2, va_list p3)
{
	MODULE_DEBUG_PRINTF("candycrashsaga_JNIEnv_CallObjectMethodV(%p, %s, %s, ...)\n", p1, p2->name, p2->sig);

	if ( strcmp( p2->name, "getHomeDirectory" ) == 0 )
	{
		MODULE_DEBUG_PRINTF( " - getHomeDirectory : %s\n", candycrushsaga_priv.myHome );
		return (*env)->NewStringUTF( env, candycrushsaga_priv.myHome );
	}

	return GLOBAL_J(env);
}

enum FieldIdMap
{
	MANUFACTURER = 0xf0,
	MODEL,
	SDK_INT,
};

jfieldID
candycrushsaga_JNIEnv_GetStaticFieldID(JNIEnv* env, jclass p1, const char* p2, const char* p3)
{
	MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetStaticFieldID(%s, %s)\n", p2, p3);

	if ( strcmp( p2, "MANUFACTURER" ) == 0 )
	{
		return (jfieldID)MANUFACTURER;
	}
	else if ( strcmp( p2, "MODEL" ) == 0 )
	{
		return (jfieldID)MODEL;
	}
	else if ( strcmp( p2, "SDK_INT" ) == 0 )
	{
		return (jfieldID)SDK_INT;
	}

	return (jfieldID)GLOBAL_J(env);
}

jobject
candycrushsaga_JNIEnv_GetStaticObjectField(JNIEnv* p0, jclass p1, jfieldID p2)
{
	MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetStaticObjectField()\n");

	// TODO: Only switching on field ID, not class, would probably need to track this from JNIEnv_GetStaticFieldID?
	if ( p2 == ( jfieldID )MANUFACTURER )
	{
		MODULE_DEBUG_PRINTF( " - MANUFACTURER : OpenPandora\n" );
		return (*p0)->NewStringUTF( p0, "OpenPandora" );
	}
	else if ( p2 == ( jfieldID )MODEL )
	{
		MODULE_DEBUG_PRINTF( " - MODEL : OpenPandora\n" );
		return (*p0)->NewStringUTF( p0, "OpenPandora" );
	}

	return NULL;
}

jint
candycrushsaga_JNIEnv_GetStaticIntField(JNIEnv* p0, jclass p1, jfieldID p2)
{
	MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetStaticIntField()\n");

	if ( p2 == ( jfieldID )SDK_INT )
	{
		enum
		{
			BASE = 0,
			BASE_1_1,
			CUPCAKE,
			CUR_DEVELOPMENT,
			DONUT,
			ECLAIR,
			ECLAIR_0_1,
			ECLAIR_MR1,
			FROYO,
			GINGERBREAD,
			GINGERBREAD_MR1,
			HONEYCOMB,
			HONEYCOMB_MR1,
			HONEYCOMB_MR2,
			ICE_CREAM_SANDWICH,
			ICE_CREAM_SANDWICH_MR1,
			JELLY_BEAN,
			JELLY_BEAN_MR1
		};

		MODULE_DEBUG_PRINTF( " - SDK_INT : %d\n", ICE_CREAM_SANDWICH );
		return ICE_CREAM_SANDWICH;
	}

	return 0;
}

jsize
candycrushsaga_JNIEnv_GetArrayLength(JNIEnv* env, jarray p1)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("JNIEnv_GetArrayLength(%p)\n", p1);

	if (p1 != GLOBAL_J(env)) {

		//if(access_ok())

		struct dummy_byte_array *array = p1;
		MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetArrayLength(%p) -> %ld\n", p1, array->size);
		return array->size;
	}
	return 0;
}

jbyte*
candycrushsaga_JNIEnv_GetByteArrayElements(JNIEnv* env, jbyteArray p1, jboolean* p2)
{
	//printf( "Value : %3.2f\n", strtod( "5.5", 0 ) );
	MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetByteArrayElements(%p)\n", p1);
	if (p1 != GLOBAL_J(env)) {

		//if(access_ok())

		struct dummy_byte_array *array = p1;
		MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_GetByteArrayElements(%p) -> %p\n", p1, array->data);
		if ( p2 )
		{
			*p2 = JNI_FALSE;
		}
		return ( jbyte *)array->data;
	}
	return p1;
}

struct candycrushsaga_jobject {
	struct dummy_jclass *class;
	void *priv;
};

jobject
candycrushsaga_JNIEnv_NewObjectV(JNIEnv *env, jclass p1, jmethodID p2, va_list p3)
{
	MODULE_DEBUG_PRINTF("candycrushsaga_JNIEnv_NewObjectV(%p, %s)\n", p1, p2->name);
	struct candycrushsaga_jobject *object = malloc(sizeof(*object));
	object->class = p1;
	object->priv = NULL;
	return (jobject)object;
}

static int
candycrushsaga_try_init(struct SupportModule *self)
{
	global_self = self;

	self->priv->JNI_OnLoad = (jni_onload_t)LOOKUP_M("JNI_OnLoad");
	self->priv->native_createnativeinstance = (candycrushsaga_createnativeinstance_t)LOOKUP_M("Java_com_king_candycrushsaga_PlatformProxy_createNativeInstance");
	self->priv->native_create = (candycrushsaga_create_t)LOOKUP_M("Java_com_king_core_NativeApplication_create");
	self->priv->native_destroy = (candycrushsaga_destroy_t)LOOKUP_M("Java_com_king_core_NativeApplication_destroy");
	self->priv->native_init = (candycrushsaga_init_t)LOOKUP_M("Java_com_king_core_NativeApplication_init");
	self->priv->native_onaccelerometer = (candycrushsaga_onaccelerometer_t)LOOKUP_M("Java_com_king_core_NativeApplication_onAccelerometer");
	self->priv->native_onbackkeydown = (candycrushsaga_onbackkeydown_t)LOOKUP_M("Java_com_king_core_NativeApplication_onBackKeyDown");
	self->priv->native_onbackkeyup = (candycrushsaga_onbackkeyup_t)LOOKUP_M("Java_com_king_core_NativeApplication_onBackKeyUp");
	self->priv->native_onkeydown = (candycrushsaga_onkeydown_t)LOOKUP_M("Java_com_king_core_NativeApplication_onKeyDown");
	self->priv->native_onkeyup = (candycrushsaga_onkeyup_t)LOOKUP_M("Java_com_king_core_NativeApplication_onKeyUp");
	self->priv->native_onmenukeydown = (candycrushsaga_onmenukeydown_t)LOOKUP_M("Java_com_king_core_NativeApplication_onMenuKeyDown");
	self->priv->native_onmenukeyup = (candycrushsaga_onmenukeyup_t)LOOKUP_M("Java_com_king_core_NativeApplication_onMenuKeyUp");
	self->priv->native_onsystemevent = (candycrushsaga_onsystemevent_t)LOOKUP_M("Java_com_king_core_NativeApplication_onSystemEvent");
	self->priv->native_ontouchevent = (candycrushsaga_ontouchevent_t)LOOKUP_M("Java_com_king_core_NativeApplication_onTouchEvent");
	self->priv->native_step = (candycrushsaga_step_t)LOOKUP_M("Java_com_king_core_NativeApplication_step");
	self->priv->native_updateorientation = (candycrushsaga_updateorientation_t)LOOKUP_M("Java_com_king_core_NativeApplication_updateOrientation");
	self->priv->native_updatescreensize = (candycrushsaga_updatescreensize_t)LOOKUP_M("Java_com_king_core_NativeApplication_updateScreenSize");
#if 1
    /* Overrides for JNIEnv_ */
	self->override_env.ExceptionOccurred = candycrashsaga_JNIEnv_ExceptionOccurred;
	self->override_env.CallStaticIntMethodV = candycrashsaga_JNIEnv_CallStaticIntMethodV;
	self->override_env.CallStaticVoidMethodV = candycrashsaga_JNIEnv_CallStaticVoidMethodV;
	self->override_env.CallStaticObjectMethodV = candycrashsaga_JNIEnv_CallStaticObjectMethodV;
	self->override_env.CallStaticBooleanMethodV = candycrashsaga_JNIEnv_CallStaticBooleanMethodV;
	self->override_env.GetArrayLength = candycrushsaga_JNIEnv_GetArrayLength;
	self->override_env.GetByteArrayElements = candycrushsaga_JNIEnv_GetByteArrayElements;
	self->override_env.NewObjectV = candycrushsaga_JNIEnv_NewObjectV;
	self->override_env.CallObjectMethodV = candycrashsaga_JNIEnv_CallObjectMethodV;
	self->override_env.GetStaticFieldID = candycrushsaga_JNIEnv_GetStaticFieldID;
	self->override_env.GetStaticObjectField = candycrushsaga_JNIEnv_GetStaticObjectField;
	self->override_env.GetStaticIntField = candycrushsaga_JNIEnv_GetStaticIntField;
#endif
    return (self->priv->JNI_OnLoad != NULL &&
			self->priv->native_createnativeinstance != NULL &&
            self->priv->native_create != NULL &&
            self->priv->native_destroy != NULL &&
            self->priv->native_init != NULL &&
            self->priv->native_onaccelerometer != NULL &&
            self->priv->native_onbackkeydown != NULL &&
            self->priv->native_onbackkeyup != NULL &&
			self->priv->native_onkeydown != NULL &&
			self->priv->native_onkeyup != NULL &&
			self->priv->native_onmenukeydown != NULL &&
			self->priv->native_onmenukeyup != NULL &&
			self->priv->native_onsystemevent != NULL &&
			self->priv->native_ontouchevent != NULL &&
			self->priv->native_step != NULL &&
			self->priv->native_updateorientation != NULL &&
			self->priv->native_updatescreensize);
}

static void
candycrushsaga_init(struct SupportModule *self, int width, int height, const char *home)
{
	MODULE_DEBUG_PRINTF("Module: Init(%i,%i,%s)\n",width,height,home);

	size_t strLen = strlen( home );
	char lastChar = home[ strLen - 1 ];

	if ( lastChar == '/' )
	{
		self->priv->myHome = strdup( home );
	}
	else
	{
		self->priv->myHome = malloc( strLen + 2 );
		sprintf( ( char *)&self->priv->myHome[ 0 ], "%s/", home );
	}

	global = GLOBAL_M;

	// init the game
	void *candyCrushSagaActivity = (void*)0xF00;
	void *candyCrushGameContext = (void*)0xF02;
	int glVersion = 2;

	jint createNativeInterfaceReturn = self->priv->native_createnativeinstance( ENV_M, GLOBAL_M, candyCrushSagaActivity );

	self->priv->native_create(ENV_M, GLOBAL_M, createNativeInterfaceReturn, candyCrushSagaActivity, candyCrushGameContext );

	//self->priv->native_onsystemevent(ENV_M, GLOBAL_M, 1);

	self->priv->native_init( ENV_M, GLOBAL_M, width, height, 0, glVersion );
}

static void
candycrushsaga_input(struct SupportModule *self, int event, int x, int y, int finger)
{
    self->priv->native_ontouchevent(ENV_M, GLOBAL_M, event, x, y, finger);
}

static void
candycrushsaga_key_input(struct SupportModule *self, int event, int keycode, int unicode)
{
}

static void
candycrushsaga_update(struct SupportModule *self)
{
	self->priv->native_onsystemevent(ENV_M, GLOBAL_M, 4);
    self->priv->native_step(ENV_M, GLOBAL_M, 1000.f / 60.f);
}

static void
candycrushsaga_deinit(struct SupportModule *self)
{
    self->priv->native_destroy(ENV_M, GLOBAL_M);
}

static void
candycrushsaga_pause(struct SupportModule *self)
{
//    self->priv->native_pause(ENV_M, GLOBAL_M);
}

static void
candycrushsaga_resume(struct SupportModule *self)
{
//    self->priv->native_resume(ENV_M, GLOBAL_M);
}

static int
candycrushsaga_requests_exit(struct SupportModule *self)
{
    return 0;
}

APKENV_MODULE(candycrushsaga, MODULE_PRIORITY_GAME)

