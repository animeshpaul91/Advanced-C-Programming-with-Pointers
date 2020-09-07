#include <stdio.h>
#include <unistd.h>

int main()
{
 int ret, mypid;
 mypid = getpid();
 printf("Before Fork, my PID is %d\n", mypid);
 ret = fork();
 sleep(1);
 printf("After Fork, fork() returns %d, but my PID is %d\n", ret, getpid()); 
 return(0);
}
