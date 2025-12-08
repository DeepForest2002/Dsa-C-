#include <stdio.h>
#include <unistd.h> // IMPORTANT: fork() lives here
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    if (pid > 0)
    {
        printf("Parent pid is %d", getpid(), "\n");
        printf("child pid is %d (will become zombie process)", pid);
        sleep(30);
    }
    else if (pid == 0)
    {
        printf("Child exiting\n");
        exit(0);
    }

    return 0;
}