#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
	int pr=0;
    printf("hi, enter the amount of proccese u would like to have(from 1 to 10):\n");
	scanf("%d",&pr);
    float TAT=0,WT=0;
	int at[10], bt[10],tat[10],wt[10],CT[10];
	printf("aaaaand enter arrival time & burst time(one after another):\n");
	for(int i=0;i<pr;i++) {
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
	}
	int sum = 0;
	for(int i=0;i<pr;i++) {
		//for CT
		sum+=bt[i];
		CT[i]=sum;
		//for TAT
		tat[i]=CT[i]-at[i];
		TAT+=tat[i];
		//for WT
		wt[i]=tat[i]-bt[i];
		WT+=wt[i];
	}

	for(int i=0;i<pr;i++) printf("Process[%d]:  arrivalTime:%d  burstTime:%d  completionTime:%d  turnAroundTime:%d  waitingTime:%d\n",i+1,at[i],bt[i],CT[i],tat[i],wt[i]);
	printf("averageTurnAroundTime:  %.2f\n",TAT/pr);
	printf("averageWaitingTime:  %.2f\n",WT/pr);

	return 0;
}
