#include<stdio.h>
#include<unistd.h>
void main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        execlp("/bin/ls","ls","-l",NULL);
    }
    else
    {
        wait(NULL);
        printf("child complete\n");
    }
}
