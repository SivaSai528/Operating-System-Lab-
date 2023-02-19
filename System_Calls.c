//2. Implementation of fork (), wait (), exec() and exit () system calls
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    pid_t pid;

    pid = fork();

    if (pid == 0) 
    {
        // Child process
        printf("Child process started\n");

        // Execute the ls command
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);

        // If execvp returns, it means there was an error
        perror("Error executing ls command");
        exit(1);
    } 
    else if (pid > 0) 
    {
        // Parent process
        printf("Parent process waiting for child to finish\n");

        // Wait for child process to finish
        int status;
        wait(&status);

        if (WIFEXITED(status)) 
        {
            // Child process exited normally
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } 
        else 
        {
            // Child process exited with an error
            printf("Child process exited with an error\n");
        }
    } 
    else 
    {
        // Fork error
        perror("Error creating child process");
        exit(1);
    }

    return 0;
}
