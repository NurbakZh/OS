#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
	int pr=0;
    printf("hi, enter the amount of proccese u would like to have(from 1 to 10):\n");
	scanf("%d",&pr);
    float TAT=0,WT=0;
	int at[10], bt[10],tat[10],wt[10],rt[10], tq, check=pr, checked;
	printf("aaaaand enter arrival time & burst time(one after another):\n");
	for(int i=0;i<pr;i++) {
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("hi again, enter time quantum:\n");
	scanf("%d",&tq);
	for(int t=0,i=0; check!=0 ;) {
		if(tq>=rt[i] && rt[i]>0) {
			t+=rt[i];
			rt[i]=0;
			checked=1;
		}
		else if(tq<rt[i] && rt[i]>0) {
			rt[i]-=tq;
			t+=tq;
		}
		if(rt[i]==0 && checked==1) {
			check--;
			//for TAT
			tat[i] = t-at[i];
			TAT+=tat[i];
			//for WT
			wt[i] = tat[i]-bt[i];
			WT+=wt[i];
			printf("Process[%d]: turnAroundTime:%d  waitingTime:%d\n",i+1,tat[i],wt[i]);
		}
		if(i == pr-1) i=0;
		else if(at[i+1]<=t) i++;
		else i=0; 
	}
	printf("averageTurnAroundTime:  %.2f\n",TAT/pr);
	printf("averageWaitingTime:  %.2f\n",WT/pr);

	return 0;
}
