#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int returnStatus = fork();

    if(returnStatus == 0)
    {
        //Child Process
        close(STDOUT_FILENO);
        printf("Hello, World!\n");  //Output will not be visible on console as we have close the standard output
    }
    else if (returnStatus > 0)
    {
        //Parent Process
        wait(NULL);
    }
    else
    {
        printf("Fork failed.\n");
    }
}