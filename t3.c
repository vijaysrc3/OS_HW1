#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int returnStatus = fork();

    if(returnStatus == 0)
    {
        //Child
        //execl("/bin/ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, NULL);

        char *args[2];
        args[0] = "/bin/ls";
        args[1] = NULL;

        //execv(args[0], args);
        //execvp("/bin/ls", args);
        execvpe("/bin/ls", args, NULL);
    }
    else if (returnStatus > 0)
    {
        //Parent
        wait(NULL);
    }
    else
    {
        printf("Fork failed.\n");
    }
}