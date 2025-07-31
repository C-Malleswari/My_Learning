/*
    pipe() for IPC
 parent - send a message 
 child - read and print
*/
// write  a c program use pipe ipc mechanism.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    if (pipe(fd) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
