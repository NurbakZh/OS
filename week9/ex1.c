#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

struct pageFrame {
	int pn; //number
	unsigned char pa; //age
	bool R; //ref
};

//hit and miss
int h=0, m=0;

//initialize frame array with initial values.
void p_init(int n, struct pageFrame *pF) {
	for(int i  = 0; i < n; i++) {
		pF[i].pn = -1;
		pF[i].pa = 0;
		pF[i].R = 0;
	}
}

//update age by new ref
void p_age_add(struct pageFrame *pF) {
	pF->pa = (pF->R << 8) | (pF->pa >> 1);
}

//change old page with new page
void p_change(struct pageFrame *pF, int a) {
	pF->pn = a;
	pF->pa = 0;
	pF->R = 1;
}

//algorithm itself
void p_alg(int a, int n, struct pageFrame *pF) {
	int min = 0; //index for minimal age number
	for(int i = 0; i < n; i++) { //check for hit
		if(pF[i].pn == a) {
			pF[i].R = 1;
			h++; return;
		}
	}
	m++; //add miss, if no hit
	for(int i = 0; i < n; i++) { //check for unused page frame
		if(pF[i].pn == -1 && pF[i].pa == 0 && pF[i].R == 0) {
			p_change(&pF[i], a); return;
		}
	}
	for(int i = 0; i < n; i++) { //find lower age page 
		if(pF[i].pa < pF[min].pa) min = i;
	}
	p_change(&pF[min], a);
}

//clock cycle
void p_clock(int n, struct pageFrame *pF) {
	for(int i  = 0; i < n; i++) {
		if(pF[i].R == 1) p_age_add(&pF[i]);
	}
}

int main() {
	int n = 100;
	struct pageFrame pFrame[n];
	p_init(n, pFrame);
	//open file 
	FILE *inp = fopen("Lab09input.txt","r");
	if(inp == NULL) {
		fprintf(stdout,"can't open that file\n");
		return 1;
	}
	int pageN;
	//read integers and pusg then to aging algorithm func.
	while(fscanf(inp,"%d",&pageN) != EOF) {
		p_alg(pageN, n, pFrame);
		p_clock(n, pFrame);
	}
	fclose(inp);
	printf("Hit: %d, Miss: %d\n", h,m);
	printf("Hit/Miss: %f\n", (double)h/m);
	return 0;
}