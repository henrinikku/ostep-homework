#ifndef __common_threads_h__
#define __common_threads_h__

#include <pthread.h>
#include <assert.h>
#include <sched.h>

//#include <semaphore.h>
#include <dispatch/dispatch.h>

#define Pthread_create(thread, attr, start_routine, arg) assert(pthread_create(thread, attr, start_routine, arg) == 0);
#define Pthread_join(thread, value_ptr)                  assert(pthread_join(thread, value_ptr) == 0);

#define Pthread_mutex_init(m, v)                         assert(pthread_mutex_init(m, v) == 0);
#define Pthread_mutex_lock(m)                            assert(pthread_mutex_lock(m) == 0);
#define Pthread_mutex_unlock(m)                          assert(pthread_mutex_unlock(m) == 0);

#define Pthread_cond_init(cond, v)                       assert(pthread_cond_init(cond, v) == 0);
#define Pthread_cond_signal(cond)                        assert(pthread_cond_signal(cond) == 0);
#define Pthread_cond_wait(cond, mutex)                   assert(pthread_cond_wait(cond, mutex) == 0);

#define Mutex_init(m)                                    assert(pthread_mutex_init(m, NULL) == 0);
#define Mutex_lock(m)                                    assert(pthread_mutex_lock(m) == 0);
#define Mutex_unlock(m)                                  assert(pthread_mutex_unlock(m) == 0);

#define Cond_init(cond)                                  assert(pthread_cond_init(cond, NULL) == 0);
#define Cond_signal(cond)                                assert(pthread_cond_signal(cond) == 0);
#define Cond_wait(cond, mutex)                           assert(pthread_cond_wait(cond, mutex) == 0);

#define Sem_create(value)                                dispatch_semaphore_create(value);
#define Sem_wait(sem)                                    dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
#define Sem_post(sem)                                    dispatch_semaphore_signal(sem);
#define Sem_close(sem)                                   dispatch_release(sem);

#endif // __common_threads_h__
