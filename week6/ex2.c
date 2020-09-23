#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
	int pr=0;
    printf("hi, enter the amount of proccese u would like to have(from 1 to 10):\n");
	scanf("%d",&pr);
    float TAT=0,WT=0;
	int at[10], bt[10],tat[10],wt[10],eT[10], a, mini;
	int min = INT_MAX;
	printf("aaaaand enter arrival time & burst time(one after another):\n");
	for(int i=0;i<pr;i++) {
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
	}
	//sort
	for(int i = 0; i<pr; i++) {
		for(int j = i+1; j<pr; j++) {
			if(bt[i]>bt[j]){
				a = bt[i];
				bt[i] = bt[j];
				bt[j] = a;
				a = at[i];
				at[i] = at[j];
				at[j] = a;
			}
		}
	}
	for(int i = 0 ; i<pr; i++) {
		if(min>at[i]) {
			min=at[i];
			mini = i;
		}
	}
	eT[mini]=min+bt[mini];
	int et = eT[mini];
	for(int i=0;i<pr;i++) {
		//for eT
		if(at[i]!=min) {
			eT[i] = et + bt[i];
			et = eT[i];
		}
		//for TAT
		tat[i]=eT[i]-at[i];
		TAT+=tat[i];
		//for WT
		wt[i]=tat[i]-bt[i];
		WT+=wt[i];
	}
	for(int i=0;i<pr;i++) printf("Process[%d]:  arrivalTime:%d  burstTime:%d  turnAroundTime:%d  waitingTime:%d\n",i+1,at[i],bt[i],tat[i],wt[i]);
	printf("averageTurnAroundTime:  %.2f\n",TAT/pr);
	printf("averageWaitingTime:  %.2f\n",WT/pr);

	return 0;
}
	