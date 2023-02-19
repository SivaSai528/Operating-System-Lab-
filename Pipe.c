#include<stdio.h>
#include<unistd.h>
void main()
{
    int pfd[2],p;
    pipe(pfd);
    p=fork();
    if(p==0)//for child
    {
        close(pfd[0]);
        close(1);
        dup(pfd[1]);
        execlp("/bin/ls","ls","-l",(char *)0);
    }
    else
    {
        close(pfd[1]);
        close(0);
        dup(pfd[0]);
        execlp("sort","sort ",(char *)0);
    }
}
