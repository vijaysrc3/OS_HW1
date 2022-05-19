#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main()
{
	if(0 == fork())
	{
		printf("\r\nchild running pid: %d", getpid());
		//wait(NULL); // check if wait is placed in child 
		exit(0);	
	
	}
	else
	{
		int status;
		wait(&status);
		printf("\r\nParent running pid: %d", getppid());
		printf("\r\nreturn child terminate status: %d", status);
	}
	
	return 0;

}
