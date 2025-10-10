#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	int fd;
	char fname[100];
	
	
	char buffer[1000];
	printf("\nEnter the filename:\n");
	scanf("%s",fname);
	fd = open(fname,O_CREAT|O_WRONLY|O_TRUNC,0644);
	if(fd==-1)
	{
		perror("Error ");
		exit(0);
	}
	printf("\nEnter the contents to be written:\n");
	while(1)
	{
		int n = read(0,buffer,sizeof(buffer));
		if(n>0)
		{
			write(fd,buffer,n);
		}
		else if(n==0)
		{
			exit(0);
		}
		else
		{
			printf("Read error");
			close(fd);
			return 0;
		}
		close(fd);
	}
	
	close(fd);
	printf("\nContent written to %s\n",fname);
	return 0;
}
