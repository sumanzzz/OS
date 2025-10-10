#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char filename[25];
	printf("Enter filename:");
	
	if(scanf("%s",filename)!=1)
	{
		fprintf(stderr,"Error!could not read filename");
		exit(1);
	}
	if(execl("/bin/sh","sh",filename,(char*)NULL)==-1)
	{
		perror("Error executing file");
		exit(1);
	}
	return 0;
	
}
