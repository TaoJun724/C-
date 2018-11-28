#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *thread_run(void *arg){
  pthread_detach(pthread_self());
  printf("%s\n",(char*)arg);
  return NULL;
}

int main()
{
  pthread_t tid;
   if (pthread_create(&tid, NULL, thread_run, (void*)("thread 1 ")) > 0)
   {
     printf( "pthread_create error!");
   }
   sleep(1);
   int ret = 0;
   if (pthread_join(tid, NULL) == 0)
   {
      printf("wait success");
   }
   else{
    printf( "wait error!");
         ret = 1;
   }
   
     return ret;
}
