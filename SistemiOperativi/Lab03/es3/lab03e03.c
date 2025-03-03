#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#define T 1

int main ()
{
  int statloc;
  pid_t pid1, pid2;
  printf("P1\n, PID=%d\n", getpid());

  sleep(T);
  pid1=fork();
  
  if(pid1==0){
    printf("P3\n, PID=%d\n", getpid());
  }
  else{
    printf("P2\n, PID=%d\n", getpid());
  }
  sleep(T);
  pid2=fork();
  
  if(pid1>0 && pid2==0){
    printf("P5\n, PID=%d\n", getpid());
    sleep(T);
    return 0;
  }
  else if(pid1==0 && pid2==0){
    printf("P6\n, PID=%d\n", getpid());
    sleep(T);
    return 0;
  }
  else if(pid1>0 && pid2>0){
     printf("P4\n, PID=%d\n", getpid());
  }
  
  sleep(T);
 
  if(pid2>0)
    wait(&statloc);
  if(pid1>0){
    printf("P7\n, PID=%d\n", getpid());
    sleep(T);
  wait(&statloc);
  }
  else{
     printf("P8\n, PID=%d\n", getpid());
     sleep(T);
     return 0;
  }
  printf("P9\n, PID=%d\n", getpid());
  sleep(T);
  return 0;
}
