#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void signalhandler(int sig){
	if(sig == SIGINT){
		printf("Caught an interrupt signal\n");
		exit(0);
	}
	if(sig == SIGTERM){
		printf("\nCaught an terminate signal\n");
		exit(0);
	}
	if(sig == SIGHUP){
		printf("\nCaught an terminal hangup signa\n");
		exit(0);
	}
	if(sig == SIGALRM){
		printf("\nCaught an alarm signal\n");
		exit(0);
	}
	if(sig == SIGUSR1){
		printf("\nCaught an userdefined signal\n");
		exit(0);
	}
};
int main(){
	signal(SIGTERM,signalhandler);
	signal(SIGHUP,signalhandler);
	signal(SIGINT,signalhandler);
	signal(SIGALRM,signalhandler);
	signal(SIGUSR1,signalhandler);
	
	alarm(10);
	
	
	printf("program running with processid %d\n",getpid());
	while(1){
		printf("Waiting for signal\n");
		sleep(5);
	}
	return 0;
}



