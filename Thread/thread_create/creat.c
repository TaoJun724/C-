#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


void *rout(void *arg)
{
  int i ;
  for( i = 0;i<5;i++)
  {
    printf("i am thread 1\n");
    sleep(1);
  }
}



int main()
{
  pthread_t tid;
  pthread_create(&tid,NULL,rout,NULL);
  int j;
  for( j = 0 ;j< 5;j++)
  {
    printf("man is running...\n");
    sleep(1);
  }
}
