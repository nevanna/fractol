# fractol
pthread_create - create a new thread
#include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
Создание потока происходит с помощью функции
pthread_create(pthread_t *tid, const pthread_attr_t *attr, void*(*function)(void*), void* arg),
где: tid — идентификатор потока, attr — параметры потока (NULL — атрибуты по умолчанию, подробности в man), function — указатель на потоковую функцию, в нашем случае threadFunc и arg — указатель на передаваемые данные в поток.


pthread_exit - terminate calling thread
#include <pthread.h>

       void pthread_exit(void *retval);

       Compile and link with -pthread.

pthread_join - join with a terminated thread
#include <pthread.h>

       int pthread_join(pthread_t thread, void **retval);

       Compile and link with -pthread.
Функция pthread_join ожидает завершения потока thread. Второй параметр этой функции — результат, возвращаемый потоком.


pthread_mutex_init(pthread_mutex_t* lock, pthread_mutexattr_t
       *attr) - инициализирует взаимоисключающую блокировку. attr -
       содержит аттрибуты для взаимоисключающей блокировки. В случае,
       если attr == NULL, используются установки по умолчаниию.
     * pthread_mutex_destroy(pthread_mutex_t* lock) - удаляет
       взаимоисключающую блокировку.
     * pthread_mutex_lock(pthread_mutex_t* lock) - устанавливает
       блокировку. В случае, если блокировка была установлена другим
       процессом, текущий процесс останавливается до снятия блокировки
       другим процессом.
     * pthread_mutex_unlock(pthread_mutex_t* lock) - снимает блокировку.
     * pthread_join(pthread_t tid, void **statusp) - ожидает завершение
       неотсоединенного процесса, результат возвращаемый функцией
       сохраняется в statusp.
     * pthread_detach(pthread_t tid) - отсоединяет процесс. Это же можно
       задать при создании процесса, установив аттрибут detachstate
       вызовом pthread_attr_setdetachstate.

http://grafika.me/node/55

