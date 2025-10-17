#include <stdio.h>


struct process{
	int pid;
	int bt,wt,tat;
};

int main(){
	int n;
	int totwt=0;
	int tottat=0;
	float avgwt,avgtat;
	
	printf("Enter the no of processes:\n");
	scanf("%d",&n);
	
	struct process p[n];
	
	for(int i=0;i<n;i++){
		p[i].pid = i+1;
		printf("Enter the burst time for process %d:",p[i].pid);
		scanf("%d",&p[i].bt);
	}
	
	p[0].wt = 0;
	p[0].tat = p[0].wt + p[0].bt;
	
	for(int i=1;i<n;i++){
		p[i].wt = p[i-1].wt + p[i-1].bt;
		p[i].tat = p[i].wt + p[i].bt;	
	}
	printf("-----------------------------------------------\n");
	printf("\t\tFCFS Scheduling\n");
	printf("-----------------------------------------------\n");
	printf("PID\tBT\tWT\tTAT\n");
	printf("-----------------------------------------------\n");
	for(int i = 0;i<n;i++){
		printf("%d\t %d\t %d\t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
		totwt += p[i].wt;
		tottat += p[i].tat;
	}
	printf("-----------------------------------------------\n");
	avgwt = totwt/n;
	avgtat = tottat/n;
	printf("Total waiting time is:%d\n",totwt);
	printf("Total turn around time is:%d\n",tottat);
	printf("Average waiting time is:%f\n",avgwt);
	printf("Average turn around time is:%f\n",avgtat);
	
	
}

