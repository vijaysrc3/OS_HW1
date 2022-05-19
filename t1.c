
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int var = 0;
	var = 100;
	
	if(0 == fork())
	{	
		printf("\r\nChild var value : %d, child pid : %d", var++, getpid());
		printf("\r\nChild var Incr : %d", var);		
		exit(0);		
	}
	else
	{	
		sleep(1);
		printf("\r\nParent var value : %d parent pid : %d", var, getpid());
		var = 200;
		printf("\r\nParent var value : %d", var);
		exit(0);
	}
}
