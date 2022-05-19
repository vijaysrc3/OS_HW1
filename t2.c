
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char gu8_buff[100];
int gu32_size = 0;

int main()
{
	int fd = open("temp.txt", O_EXCL | O_RDWR);
	system("chmod 777 temp.txt");
	memset(gu8_buff, 0x00, sizeof(gu8_buff));
	
	if(fd != -1)
	{
		if(0 == fork())
		{
			write(fd, "Hello world", strlen((const char *)"Hello world"));
			gu32_size = read(fd, gu8_buff, sizeof(gu8_buff));
			if(gu32_size == 0)
			{
				printf("Parent process is aquired cannot access fd");			
			}
			else
			{
				printf("size:%d, String:%s", gu32_size, gu8_buff);
			}
			close(fd);
			exit(0);
		}
		else
		{
			write(fd, "Hi world!!!", strlen((const char *)"Hi world!!!"));
			gu32_size = read(fd, gu8_buff, sizeof(gu8_buff));
			if(gu32_size == 0)
			{
				printf("Child process is aquired cannot access fd");
			}
			else
			{
				printf("size:%d, String:%s", gu32_size, gu8_buff);
			}
			sleep(1);	
			close(fd);					
			exit(0);			
		}
	}
	else
	{
		perror("file already created");
		close(fd);
	}

}



