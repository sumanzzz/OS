#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{	
	int pid ;
	for(int i = 1 ;i<=5 ;i++)
	{
		
		 pid = fork();
	
		if(pid < 0)
		{
			printf("fork error");
			exit(1);
		}
		else if(pid == 0)
		{
			printf("Forked child process %d running processid:%d = %d\n",i,getpid());
			exit(0);
		}
		else
		{
			printf("parent created child %d with PID: %d\n",i,pid);
		}
		
		
	}
	for(int i=1;i<=5;i++)
	{
		wait(NULL);
	}
	printf("parent process (PID = %d) after finishing creating all children\n",getpid());
	return 0;
	
}

