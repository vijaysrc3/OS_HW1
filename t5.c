#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main()
{	
	if(0 == fork())
	{
		printf("\r\nchild 1 running pid: %d", getpid());
		sleep(2);
		exit(0);	
	
	}
	else
	{
		int i;
		waitpid(-1, &i, 0);
		printf("\r\nParent 1 running pid: %d", getppid());
		printf("\r\nwaited untill child 1 terminates: %d", i);
	}
	
	if(0 == fork())
	{
		printf("\r\nchild 2 running pid: %d", getpid());
		sleep(5);
		exit(0);				
	
	}
	else
	{
		int status;
		waitpid(-1, &status, 0);
		printf("\r\nParent 2 running pid: %d", getppid());
		printf("\r\nnwaited untill child 2 terminates: %d", status);
	}	
	
	return 0;

}
