
/**
 * apkenv
 * Copyright (c) 2012, Thomas Perl <m@thp.io>
 * Based on code from libhybris: Copyright (c) 2012 Carsten Munk
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

#include "pthread_wrappers.h"
#include <sys/time.h>

/**
 * This will take care of doing the right thing for mutexes that are not
 * yet initialized correctly (e.g. because they were statically initialized
 * on the Bionic-using side). This function should be called at the start
 * of every function that takes a pthread_mutex_t * as parameter.
 *
 * Returns the "real" glibc pthread_mutex_t *
 **/
pthread_mutex_t *
late_init_pthread_mutex(pthread_mutex_t *mutex)
{
    if (mutex == NULL) {
        printf("Mutex is NULL in %s\n", __func__);
        exit(1);
    }

    pthread_mutex_t *realmutex = (pthread_mutex_t*) (*((int*)mutex));
    if (realmutex == NULL) {
        printf("late-initializing normal mutex\n");
        realmutex = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(realmutex, NULL);
        *((int *)mutex) = (int)realmutex;
    } else if (realmutex == BIONIC_PTHREAD_RECURSIVE_MUTEX) {
        printf("late-initializing recursive mutex\n");
        realmutex = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_t tmp = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
        memcpy(realmutex, &tmp, sizeof(pthread_mutex_t));
        *((int *)mutex) = (int)realmutex;
    } else if (realmutex == BIONIC_PTHREAD_ERRORCHECK_MUTEX) {
        printf("late-initializing errorcheck mutex\n");
        realmutex = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_t tmp = PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;
        memcpy(realmutex, &tmp, sizeof(pthread_mutex_t));
        *((int *)mutex) = (int)realmutex;
    }

    return realmutex;
}

/**
 * Same thing as above, but for pthread_cond_t * variables.
 *
 * Returns the "real" glibc pthread_cond_t *
 **/
pthread_cond_t *
late_init_pthread_cond(pthread_cond_t *cond)
{
    if (cond == NULL) {
        printf("Cond iS NULL in %s\n", __func__);
        exit(1);
    }

    pthread_cond_t *realcond = (pthread_cond_t *) *(int *) cond;
    if (realcond == NULL) {
        printf("late-initializing cond\n");
        realcond = malloc(sizeof(pthread_cond_t));
        pthread_cond_t tmp = PTHREAD_COND_INITIALIZER;
        memcpy(realcond, &tmp, sizeof(pthread_cond_t));
        *((int *) cond) = (int)realcond;
    }

    return realcond;
}

int
my_pthread_mutex_init (pthread_mutex_t *__mutex,
        __const pthread_mutexattr_t *__mutexattr)
{
    pthread_mutex_t *realmutex = malloc(sizeof(pthread_mutex_t));
    *((int *)__mutex) = (int) realmutex;
    return pthread_mutex_init(realmutex, __mutexattr);
}

int
my_pthread_mutex_lock (pthread_mutex_t *__mutex)
{
    pthread_mutex_t *realmutex = late_init_pthread_mutex(__mutex);
    return pthread_mutex_lock(realmutex);
}

int
my_pthread_mutex_trylock (pthread_mutex_t *__mutex)
{
    pthread_mutex_t *realmutex = late_init_pthread_mutex(__mutex);
    return pthread_mutex_trylock(realmutex);
}

int
my_pthread_mutex_unlock (pthread_mutex_t *__mutex)
{
    pthread_mutex_t *realmutex = late_init_pthread_mutex(__mutex);
    return pthread_mutex_unlock(realmutex);
}

int
my_pthread_mutex_destroy (pthread_mutex_t *__mutex)
{
    pthread_mutex_t *realmutex = late_init_pthread_mutex(__mutex);
    int ret = pthread_mutex_destroy(realmutex);
    free(realmutex);
    return ret;
}

int
my_pthread_cond_init(pthread_cond_t *cond,
        const pthread_condattr_t *attr)
{
    assert(cond != NULL);
    pthread_cond_t *realcond = malloc(sizeof(pthread_cond_t));
    *((int *) cond) = (int) realcond;
    return pthread_cond_init(realcond, attr);
}

int
my_pthread_cond_destroy(pthread_cond_t *cond)
{
    pthread_cond_t *realcond = late_init_pthread_cond(cond);
    int ret = pthread_cond_destroy(realcond);
    free(realcond);
    return ret;
}

int
my_pthread_cond_broadcast(pthread_cond_t *cond)
{
    pthread_cond_t *realcond = late_init_pthread_cond(cond);
    return pthread_cond_broadcast(realcond);
}

int
my_pthread_cond_signal(pthread_cond_t *cond)
{
    pthread_cond_t *realcond = late_init_pthread_cond(cond);
    return pthread_cond_signal(realcond);
}

int
my_pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex)
{
    pthread_cond_t *realcond = late_init_pthread_cond(cond);
    pthread_mutex_t *realmutex = late_init_pthread_mutex(mutex);
    return pthread_cond_wait(realcond, realmutex);
}

int
my_pthread_cond_timedwait(pthread_cond_t *cond,
        pthread_mutex_t *mutex, const struct timespec *abstime)
{
    pthread_cond_t *realcond = late_init_pthread_cond(cond);
    pthread_mutex_t *realmutex = late_init_pthread_mutex(mutex);
    return pthread_cond_timedwait(realcond, realmutex, abstime);
}

int
my_pthread_attr_init(pthread_attr_t *__attr)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;

    realattr = malloc(sizeof(pthread_attr_t));
    *((int *)__attr) = (int) realattr;

    return pthread_attr_init(realattr);
}

int
my_pthread_attr_destroy(pthread_attr_t *__attr)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_destroy(realattr);
}

int
my_pthread_attr_setdetachstate(pthread_attr_t *__attr, int detachstate)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_setdetachstate(realattr, detachstate);
}


int
my_pthread_attr_getdetachstate(pthread_attr_t *__attr, int* detachstate)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_getdetachstate(realattr, detachstate);
}

int
my_pthread_attr_setschedparam (pthread_attr_t * __attr,struct sched_param * __param)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_setschedparam(realattr,__param);
}

int
my_pthread_attr_setstacksize(pthread_attr_t *__attr, size_t stacksize)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_setstacksize (realattr,stacksize);
}


int
my_pthread_attr_getstack(pthread_attr_t *__attr, void** stackaddr, size_t* stacksize)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_getstack(realattr,stackaddr,stacksize);
}

int
my_pthread_attr_setstack(pthread_attr_t *__attr, void* stackaddr, size_t stacksize)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_setstack(realattr,stackaddr,stacksize);
}

int
my_pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_attr_setschedpolicy(realattr, __policy);
}

int
my_pthread_getattr_np(pthread_t __th, pthread_attr_t *__attr)
{
    assert(__attr != NULL);
    pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
    assert(realattr != NULL);
    return pthread_getattr_np(__th,realattr);
}

void
my_pthread_cleanup_pop(int execute)
{
	printf("UNIMPLEMENTED: pthread_cleanup_pop\n");
	exit(1);
}
void
my_pthread_cleanup_push(void (*routine) (void *), void *arg)
{
	printf("UNIMPLEMENTED: pthread_cleanup_push\n");
	exit(1);

}

// Android specific, passes relative time, we need to convert to absolute time then call the non *_np version.
int       
my_pthread_cond_timedwait_relative_np(pthread_cond_t *__cond, 
									  pthread_mutex_t *__mutex,
									  const struct timespec *relative_time)
{
	pthread_cond_t *realcond = late_init_pthread_cond(__cond);
	pthread_mutex_t *realmutex = late_init_pthread_mutex(__mutex);

	struct timespec now;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	TIMEVAL_TO_TIMESPEC(&tv, &now);

	now.tv_sec	+= relative_time->tv_sec;
	now.tv_nsec	+= relative_time->tv_nsec;


	return (pthread_cond_timedwait(realcond, realmutex, &now));
}

int 
my_pthread_condattr_init(pthread_condattr_t *attr)
{
	printf("UNIMPLEMENTED: my_pthread_condattr_init\n");
	exit(1);
	return 0;
}

int 
my_pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared)
{
	printf("UNIMPLEMENTED: my_pthread_condattr_setpshared\n");
	exit(1);
	return 0;
} 

int 
my_pthread_condattr_destroy(pthread_condattr_t *attr)
{
	printf("UNIMPLEMENTED: my_pthread_condattr_destroy\n");
	exit(1);
	return 0;
}

int 
my_pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared)
{
	printf("UNIMPLEMENTED: my_pthread_mutexattr_setpshared\n");
	exit(1);
	return 0;
}

int 
my_pthread_create(pthread_t *thread, const pthread_attr_t *__attr, void *(*start_routine)(void*), void *arg)
{
	assert(__attr != NULL);
	pthread_attr_t *realattr = (pthread_attr_t *) *(int *) __attr;
	assert(realattr != NULL);

	int result = pthread_create( thread, realattr, start_routine, arg );

	if ( result != 0 )
	{
		printf( "my_pthread_create failed to create thread (return : %d)\n", result );
	}

	return result;
}

int 
my_pthread_key_create(pthread_key_t *key, void (*destructor)(void*))
{
	assert(key != NULL);
	pthread_key_t *realkey = malloc(sizeof(pthread_key_t));
	*((int *) key) = (int) realkey;
	return pthread_key_create(realkey, destructor);
}

void *
my_pthread_getspecific(pthread_key_t __key)
{
	assert(__key != 0);
	pthread_key_t *realkey = (pthread_key_t *) __key;
	assert(realkey != NULL);
	return pthread_getspecific( *realkey );
}

int 
my_pthread_setspecific(pthread_key_t __key, const void *value)
{
	assert(__key != 0);
	pthread_key_t *realkey = (pthread_key_t *) __key;
	assert(realkey != NULL);
	return pthread_setspecific( *realkey, value );
}

int 
my_pthread_key_delete(pthread_key_t __key)
{
	assert(__key != 0);
	pthread_key_t *realkey = (pthread_key_t *) __key;
	assert(realkey != NULL);
	return pthread_key_delete( *realkey );
}
