#include <stdio.h>

struct process{
	int pid;
	int wt,bt,tat;
};


void main(){
	int n;
	int totwt=0;
	int tottat=0;
	float avgwt;
	float avgtat;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	
	struct process p[n];
	struct process temp;
	
	for(int i=0;i<n;i++){
		p[i].pid = i+1;
		printf("Enter the burst time for process %d:",p[i].pid);
		
		scanf("%d",&p[i].bt);
	}
	int min;
	//selection sort
	for(int i=0;i<n;i++){
			min = i;
		for(int j=i+1;j<n;j++){
			 
			if(p[j].bt < p[min].bt){
			 min = j;
			}
			temp.pid = p[i].pid;
			temp.bt = p[i].bt;
			p[i].pid = p[min].pid;
			p[i].bt = p[min].bt;
			p[min].pid = temp.pid;
			p[min].bt = temp.bt;
		}
	}
	p[0].wt = 0;
	p[0].tat = p[0].wt + p[0].bt;
	
	for(int i=1;i<n;i++){
		p[i].wt = p[i-1].wt + p[i-1].bt;
		p[i].tat = p[i].wt + p[i].bt;	
	}
	printf("-----------------------------------------------\n");
	printf("\t\tSJF Scheduling\n");
	printf("-----------------------------------------------\n");
	printf("PID\tBT\tWT\tTAT\n");
	printf("-----------------------------------------------\n");
	for(int i = 0;i<n;i++){
		printf("P%d\t %d\t %d\t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
		totwt += p[i].wt;
		tottat += p[i].tat;
	}
	printf("-----------------------------------------------\n");
	
	avgwt = (float)totwt/n;
	avgtat = (float)tottat/n;
	
	printf("Total waiting time is:%d\n",totwt);
	printf("Total turn around time is:%d\n",tottat);
	printf("Average waiting time is:%f\n",avgwt);
	printf("Average turn around time is:%f\n",avgtat);
}

