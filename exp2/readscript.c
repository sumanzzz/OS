#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFERSIZE 1024

int main()
{
	char filename[100];
	int fd;
	ssize_t bytesread;
	char buffer[BUFFERSIZE];
	printf("Enter the filename:");
	if(scanf("%s",filename)!=1)
	{
		fprintf(stderr,"Error");
		exit(1);
	}
	fd = open(filename,O_RDONLY);
	if(fd==-1)
	{
		perror("Error openning file");
	}
	while((bytesread=read(fd,buffer,BUFFERSIZE))>0)
	{
		if(write(STDOUT_FILENO,buffer,bytesread)==1)
		{
			perror("error writing to terminal");
			exit(1);
		}
	}
	if(bytesread==-1)
	{
		perror("Error reading file");
		exit(1);
	}
	close(fd);
	return 0;
}
