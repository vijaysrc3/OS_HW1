#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define READ 0
#define WRITE 1

int main()
{
    int fd[2];
    pipe(fd);
    int returnStatus = fork();

    if(returnStatus == 0)
    {
        //first child
        close(fd[READ]);    //First child only needs to write so we close the read end

        int someData = 100; //Some random data to write to pipe.
        write(fd[WRITE], &someData, sizeof(int));
        close(fd[WRITE]);   //The first child is done writing so we close the write end.
    }
    else if (returnStatus > 0)
    {
        //Parent
        //Parent will read data from the pipe and pass it to the second child using a new pipe
        close(fd[WRITE]);   //Immediately close the write end as Parent only needs to read.
        wait(NULL);

        int receivedData = -1;
        read(fd[READ], &receivedData, sizeof(int));
        close(fd[READ]);

        int fd1[2];
        pipe(fd1);
        
        write(fd1[WRITE], &receivedData, sizeof(int));
        int returnStatus1 = fork();
        if(returnStatus1 == 0)
        {
            //Second child
            close(fd1[WRITE]);
            int receivedFromChild = -1;
            read(fd1[READ], &receivedFromChild, sizeof(int));
            printf("Recieved from first child: %d\n", receivedFromChild);
            close(fd1[READ]);
        }
        else if (returnStatus1 > 0)
        {
            //Parent
            close(fd1[READ]);
            close(fd1[WRITE]);
            wait(NULL);
        }
        else
        {
            printf("Second Fork failed.\n");
        }
    }
    else
    {
        printf("First fork failed.\n");
    }
}