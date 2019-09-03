#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>

int main()
{
 int ret;
 int mypid;
 mypid = getpid();
 printf("Before Fork, my PID is %d\n", mypid);
 ret = fork();
 sleep(1);
 printf("After Fork, fork() returns %d, but my PID is %d\n", ret, getpid()); 
 return(0);
}
