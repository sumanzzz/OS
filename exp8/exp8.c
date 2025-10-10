#include <stdio.h>

struct process {
	int pid;
	int bt,wt,tat;
};

void main(){
	int n;
	int totalWt = 0;
	int totalTat = 0;
	float avgWt,avgTat;
	int timeQ;
	
	
	printf("Enter the number of process:");
	scanf("%d",&n);
	int remBt[n];
	struct process p[n];
	
	for(int i=0;i<n;i++){
		p[i].pid = i+1;
		printf("Enter the burst time for process %d:",i+1);
		
		scanf("%d",&p[i].bt);
		remBt[i] = p[i].bt;

	}
	
	printf("Enter the time quantum:");
	scanf("%d",&timeQ);
	
	int time=0;
	int flag=0;
	
	while(flag==0){
		flag =1;
		for(int i=0;i<n;i++){
			if(remBt[i] > 0){
				flag = 0;
				if(remBt[i]>timeQ){
					time += timeQ;
					remBt[i]-= timeQ;
				}
				else{
					time += remBt[i];
					remBt[i] = 0;
					p[i].tat = time;
					p[i].wt = p[i].tat - p[i].bt;
				}
				
			}
			
		}
	}
	
	printf("-----------------------------------------------\n");
	printf("\t\tRound Robin Scheduling\n");
	printf("-----------------------------------------------\n");
	printf("PID\tBT\tWT\tTAT\n");
	printf("-----------------------------------------------\n");
	for(int i = 0;i<n;i++){
		printf("P%d\t %d\t %d\t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
		totalWt += p[i].wt;
		totalTat += p[i].tat;
	}
	printf("-----------------------------------------------\n");
	avgWt = (float)totalWt/n;
	avgTat = (float)totalTat/n;
	printf("Total waiting time is:%d\n",totalWt);
	printf("Total turn around time is:%d\n",totalTat);
	printf("Average waiting time is:%f\n",avgWt);
	printf("Average turn around time is:%f\n",avgTat);
	
	
}
	
