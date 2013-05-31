
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
 * Rayman Jungle Run v2.0.8 - By: Steven Craft
 *
 **/

#include "common.h"

#include <string.h>
#include <limits.h>
#include "SDL/SDL.h"
#include <assert.h>

// Typedefs. Got these from classes.dex (http://stackoverflow.com/questions/1249973/decompiling-dex-into-java-sourcecode)
typedef void (*raymanjunglerun_nativecreate_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*raymanjunglerun_nativedestroy_t)(JNIEnv *env, jobject obj) SOFTFP;
typedef void (*raymanjunglerun_nativeenablegalleryaswallpaper_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativeenablemoreraymanbutton_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativeenableofflinegallery_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativeenableproxy_t)(JNIEnv *env, jobject obj, jboolean p1, jstring p2) SOFTFP;
typedef void (*raymanjunglerun_nativeenableskins_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativeenableskinsinapppurchase_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativeenablesocialnetwork_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativekeydown_t)(JNIEnv *env, jobject obj, int p1) SOFTFP;
typedef void (*raymanjunglerun_nativekeyup_t)(JNIEnv *env, jobject obj, int p1) SOFTFP;
typedef jboolean (*raymanjunglerun_nativenotifypushnotification_t)(JNIEnv *env, jobject obj, jstring p1) SOFTFP;
typedef void (*raymanjunglerun_nativeonwindowfocuschanged_t)(JNIEnv *env, jobject obj, jboolean p1) SOFTFP;
typedef void (*raymanjunglerun_nativepause_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef jboolean (*raymanjunglerun_nativepressback_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativepresskey_t)(JNIEnv *env, jobject obj, jint p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativepressmenu_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativereleasekey_t)(JNIEnv *env, jobject obj, jint p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativereloadtextures_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativeresume_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativerun_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativesetassetmanager_t)(JNIEnv *env, jobject obj, jobject assetManager ) SOFTFP;
typedef void (*raymanjunglerun_nativesetbrowsedirectory_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetheight_t)(JNIEnv *env, jobject obj, jint p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetkindlefiremode_t)(JNIEnv *env, jobject obj, jboolean p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetlanguage_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetmousepressed_t)(JNIEnv *env, jobject obj, jboolean p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetmousexy_t)(JNIEnv *env, jobject obj, jint p1, jint p2 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetnookmode_t)(JNIEnv *env, jobject obj, jboolean p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetpersistencerootdirectory_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetplayername_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetrootdirectory_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetwidth_t)(JNIEnv *env, jobject obj, jint p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativesetwritetemprootdirectory_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef void (*raymanjunglerun_nativestart_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativestop_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativetouchscrend_t)(JNIEnv *env, jobject obj, jint p1, jint p2 ) SOFTFP;
typedef void (*raymanjunglerun_nativetouchscrmove_t)(JNIEnv *env, jobject obj, jint p1, jint p2, jint p3, jint p4 ) SOFTFP;
typedef void (*raymanjunglerun_nativetouchscrstart_t)(JNIEnv *env, jobject obj, jint p1, jint p2 ) SOFTFP;
typedef void (*raymanjunglerun_nativeupdatesize_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativesetupflurry_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativeenablestore_t)(JNIEnv *env, jobject obj ) SOFTFP;
typedef void (*raymanjunglerun_nativenotifypurchasecanceled_t)(JNIEnv *env, jobject obj, jstring p1, jint p2, jlong p3 ) SOFTFP;
typedef void (*raymanjunglerun_nativenotifypurchasedone_t)(JNIEnv *env, jobject obj, jstring p1, jint p2, jlong p3 ) SOFTFP;
typedef void (*raymanjunglerun_nativenotifypurchasefailed_t)(JNIEnv *env, jobject obj, jstring p1 ) SOFTFP;
typedef jint (*raymanjunglerun_fmodgetinfo_t)(JNIEnv *env, jobject obj, jint p1 ) SOFTFP;
typedef jint (*raymanjunglerun_fmodprocess_t)(JNIEnv *env, jobject obj, jobject byteBuffer ) SOFTFP;

struct SupportModulePriv {
    jni_onload_t JNI_OnLoad;
	raymanjunglerun_nativecreate_t create;
	raymanjunglerun_nativedestroy_t destroy;
	raymanjunglerun_nativeenablegalleryaswallpaper_t enablegalleryaswallpaper;
	raymanjunglerun_nativeenablemoreraymanbutton_t enablemoreraymanbutton;
	raymanjunglerun_nativeenableofflinegallery_t enableofflinegallery;
	raymanjunglerun_nativeenableproxy_t enableproxy;
	raymanjunglerun_nativeenableskins_t enableskins;
	raymanjunglerun_nativeenableskinsinapppurchase_t enableskinsinapppurchase;
	raymanjunglerun_nativeenablesocialnetwork_t enablesocialnetwork;
	raymanjunglerun_nativekeydown_t keydown;
	raymanjunglerun_nativekeyup_t keyup;
	raymanjunglerun_nativenotifypushnotification_t notifypushnotification;
	raymanjunglerun_nativeonwindowfocuschanged_t onwindowfocuschanged;
	raymanjunglerun_nativepause_t pause;
	raymanjunglerun_nativepressback_t pressback;
	raymanjunglerun_nativepresskey_t presskey;
	raymanjunglerun_nativepressmenu_t pressmenu;
	raymanjunglerun_nativereleasekey_t releasekey;
	raymanjunglerun_nativereloadtextures_t reloadtextures;
	raymanjunglerun_nativeresume_t resume;
	raymanjunglerun_nativerun_t run;
	raymanjunglerun_nativesetassetmanager_t setassetmanager;
	raymanjunglerun_nativesetbrowsedirectory_t setbrowsedirectory;
	raymanjunglerun_nativesetheight_t setheight;
	raymanjunglerun_nativesetkindlefiremode_t setkindlefiremode;
	raymanjunglerun_nativesetlanguage_t setlanguage;
	raymanjunglerun_nativesetmousepressed_t setmousepressed;
	raymanjunglerun_nativesetmousexy_t setmousexy;
	raymanjunglerun_nativesetnookmode_t setnookmode;
	raymanjunglerun_nativesetpersistencerootdirectory_t setpersistencerootdirectory;
	raymanjunglerun_nativesetplayername_t setplayername;
	raymanjunglerun_nativesetrootdirectory_t setrootdirectory;
	raymanjunglerun_nativesetwidth_t setwidth;
	raymanjunglerun_nativesetwritetemprootdirectory_t setwritetemprootdirectory;
	raymanjunglerun_nativestart_t start;
	raymanjunglerun_nativestop_t stop;
	raymanjunglerun_nativetouchscrend_t touchscrend;
	raymanjunglerun_nativetouchscrmove_t touchscrmove;
	raymanjunglerun_nativetouchscrstart_t touchscrstart;
	raymanjunglerun_nativeupdatesize_t updatesize;
	raymanjunglerun_nativesetupflurry_t setupflurry;
	raymanjunglerun_nativeenablestore_t enablestore;
	raymanjunglerun_nativenotifypurchasecanceled_t notifypurchasecanceled;
	raymanjunglerun_nativenotifypurchasedone_t notifypurchasedone;
	raymanjunglerun_nativenotifypurchasefailed_t notifypurchasefailed;
	raymanjunglerun_fmodgetinfo_t fmodgetinfo;
	raymanjunglerun_fmodprocess_t fmodprocess;
    const char *myHome;
};
static struct SupportModulePriv raymanjunglerun_priv;

/* Global application state so we can call this from override thingie */
struct GlobalState *global;

/* CallVoidMethodV override. Signal when to start or stop audio */
void
JNIEnv_CallVoidMethodV(JNIEnv* p0, jobject p1, jmethodID p2, va_list p3)
{
    MODULE_DEBUG_PRINTF("module_JNIEnv_CallVoidMethodV(%p, %s, %s)\n", p1, p2->name, p2->sig);
}

/* NewObjectV override. Initialize audio output */
jobject
JNIEnv_NewObjectV(JNIEnv *env, jclass p1, jmethodID p2, va_list p3)
{
    struct dummy_jclass *clazz = p1;

    MODULE_DEBUG_PRINTF("module_JNIEnv_NewObjectV(%p, %s, %s)\n", p1, p2->name, clazz->name);

	return GLOBAL_J(env);
}

/* CallObjectMethodV override. AB calls readFile to read data from apk */
jobject
JNIEnv_CallObjectMethodV(JNIEnv *env, jobject p1, jmethodID p2, va_list p3)
{
    MODULE_DEBUG_PRINTF("module_JNIEnv_CallObjectMethodV(%p, %s, %s, ...)\n", p1, p2->name, p2->sig);
   
    return NULL;
}

/* DeleteLocalRef override. Free some memory :) */
void
JNIEnv_DeleteLocalRef(JNIEnv* p0, jobject p1)
{
    MODULE_DEBUG_PRINTF("JNIEnv_DeleteLocalRef(%p)\n", p1);
    if (p1 == GLOBAL_J(p0) || p1 == NULL) {
        MODULE_DEBUG_PRINTF("WARNING: DeleteLocalRef on global\n");
        return;
    }
    free(p1);
}


jsize
JNIEnv_GetArrayLength(JNIEnv* env, jarray p1)
{
    MODULE_DEBUG_PRINTF("JNIEnv_GetArrayLength(%p)\n", p1);

    if (p1 != GLOBAL_J(env)) {

        //if(access_ok())

        struct dummy_byte_array *array = p1;
        MODULE_DEBUG_PRINTF("JNIEnv_GetArrayLength(%p) -> %ld\n", p1, array->size);
        return array->size;
    }
    return 0;
}

void _ZN11AInputQueue11finishEventEP11AInputEventb( )
{

}


static int
raymanjunglerun_try_init(struct SupportModule *self)
{
/*	self->priv->create;
	self->priv->destroy;
	self->priv->enablegalleryaswallpaper;
	self->priv->enablemoreraymanbutton;
	self->priv->enableofflinegallery;
	self->priv->enableproxy;
	self->priv->enableskins;
	self->priv->enableskinsinapppurchase;
	self->priv->enablesocialnetwork;
	self->priv->keydown;
	self->priv->keyup;
	self->priv->notifypushnotification;
	self->priv->onwindowfocuschanged;
	self->priv->pause;
	self->priv->pressback;
	self->priv->presskey;
	self->priv->pressmenu;
	self->priv->releasekey;
	self->priv->reloadtextures;
	self->priv->resume;
	self->priv->run;
	self->priv->setassetmanager;
	self->priv->setbrowsedirectory;
	self->priv->setheight;
	self->priv->setkindlefiremode;
	self->priv->setlanguage;
	self->priv->setmousepressed;
	self->priv->setmousexy;
	self->priv->setnookmode;
	self->priv->setpersistencerootdirectory;
	self->priv->setplayername;
	self->priv->setrootdirectory;
	self->priv->setwidth;
	self->priv->setwritetemprootdirectory;
	self->priv->start;
	self->priv->stop;
	self->priv->touchscrend;
	self->priv->touchscrmove;
	self->priv->touchscrstart;
	self->priv->updatesize;
	self->priv->setupflurry;
	self->priv->enablestore;
	self->priv->notifypurchasecanceled;
	self->priv->notifypurchasedone;
	self->priv->notifypurchasefailed;
	self->priv->fmodgetinfo;
	self->priv->fmodprocess;*/

    /* Overrides for JNIEnv_ */
    self->override_env.CallObjectMethodV = JNIEnv_CallObjectMethodV;
    self->override_env.DeleteLocalRef = JNIEnv_DeleteLocalRef;
    self->override_env.CallVoidMethodV = JNIEnv_CallVoidMethodV;
    self->override_env.NewObjectV = JNIEnv_NewObjectV;
    self->override_env.GetArrayLength = JNIEnv_GetArrayLength;

	return 	(
		self->priv->create != NULL &&
		self->priv->destroy != NULL &&
		self->priv->enablegalleryaswallpaper != NULL &&
		self->priv->enablemoreraymanbutton != NULL &&
		self->priv->enableofflinegallery != NULL &&
		self->priv->enableproxy != NULL &&
		self->priv->enableskins != NULL &&
		self->priv->enableskinsinapppurchase != NULL &&
		self->priv->enablesocialnetwork != NULL &&
		self->priv->keydown != NULL &&
		self->priv->keyup != NULL &&
		self->priv->notifypushnotification != NULL &&
		self->priv->onwindowfocuschanged != NULL &&
		self->priv->pause != NULL &&
		self->priv->pressback != NULL &&
		self->priv->presskey != NULL &&
		self->priv->pressmenu != NULL &&
		self->priv->releasekey != NULL &&
		self->priv->reloadtextures != NULL &&
		self->priv->resume != NULL &&
		self->priv->run != NULL &&
		self->priv->setassetmanager != NULL &&
		self->priv->setbrowsedirectory != NULL &&
		self->priv->setheight != NULL &&
		self->priv->setkindlefiremode != NULL &&
		self->priv->setlanguage != NULL &&
		self->priv->setmousepressed != NULL &&
		self->priv->setmousexy != NULL &&
		self->priv->setnookmode != NULL &&
		self->priv->setpersistencerootdirectory != NULL &&
		self->priv->setplayername != NULL &&
		self->priv->setrootdirectory != NULL &&
		self->priv->setwidth != NULL &&
		self->priv->setwritetemprootdirectory != NULL &&
		self->priv->start != NULL &&
		self->priv->stop != NULL &&
		self->priv->touchscrend != NULL &&
		self->priv->touchscrmove != NULL &&
		self->priv->touchscrstart != NULL &&
		self->priv->updatesize != NULL &&
		self->priv->setupflurry != NULL &&
		self->priv->enablestore != NULL &&
		self->priv->notifypurchasecanceled != NULL &&
		self->priv->notifypurchasedone != NULL &&
		self->priv->notifypurchasefailed != NULL &&
		self->priv->fmodgetinfo != NULL &&
		self->priv->fmodprocess != NULL
	);
}

static void
raymanjunglerun_init(struct SupportModule *self, int width, int height, const char *home)
{
    MODULE_DEBUG_PRINTF("Module: Init(%i,%i,%s)\n",width,height,home);

    self->priv->myHome = strdup(home);
    global = GLOBAL_M;

	self->priv->create( ENV_M, GLOBAL_M );
	self->priv->start( ENV_M, GLOBAL_M );
}

static void
raymanjunglerun_input(struct SupportModule *self, int event, int x, int y, int finger)
{
}

static void
raymanjunglerun_key_input(struct SupportModule *self, int event, int keycode, int unicode)
{
}

static void
raymanjunglerun_update(struct SupportModule *self)
{
	self->priv->run( ENV_M, GLOBAL_M );
}

static void
raymanjunglerun_deinit(struct SupportModule *self)
{
}

static void
raymanjunglerun_pause(struct SupportModule *self)
{
}

static void
raymanjunglerun_resume(struct SupportModule *self)
{
}

static int
raymanjunglerun_requests_exit(struct SupportModule *self)
{
    return 0;
}

APKENV_MODULE(raymanjunglerun, MODULE_PRIORITY_GAME)

