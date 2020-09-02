#include <stdio.h>
#include <stdlib.h>
  
struct node { 
    int d; 
    struct node* next; 
}; 
  
void print_list(struct node* h){ 
	while(h!=NULL) {
		printf("%d ",h->d);
		h=h->next;
	}
	printf("\n");
}

//novi is new on russian, novinovi is newnew, like very new
//hope you will be able to read it)
void insert_node(int a, int b, struct node **h){ 
	struct node* novi = NULL;
	novi=malloc(sizeof(struct node));
    novi->d=a;
    novi->next=NULL;
    if(b==1){
        novi->next=*h;
        *h=novi;
        return;
    }
    struct node* novinovi = *h;
    for(int i=0; i<b-2;i++){
        novinovi=novinovi->next;
    }
    novi->next=novinovi->next;
    novinovi->next=novi;
}

void delete_node(int a, struct node **h) {
	if(*h==NULL) return;
	struct node* novi = *h;
	if(a==0) {
		*h = novi->next;
		free(novi);
		return;
	}
	for(int k = 0; novi!=NULL && k<a-1; k++) {
		novi = novi->next;
	}
	struct node* novinovi = novi->next->next;
	free(novi->next);
	novi->next = novinovi;
}	
  
int main() { 
	struct node* h = NULL;
	struct node* i = NULL;
	struct node* t = NULL;
  	printf("please enter number of elements of your linked list: ");
	int a;
	scanf("%d", &a);
	printf("now enter elements ^_^ : \n");
	for (int f = 0; f<a; f++) {
		t = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&(t->d));
		t->next = NULL;
		if(h==NULL) h = t;
		else {
			i = h;
			while(i->next!=NULL) {
				i=i->next;
			}
			i->next = t;
		}
	}
	//next lines hard to read, but they are making interaction with user
	//it asks if user wants to use the functions that we have done
	//asking to print 
	
	printf("do you want to see your LinkedList?(enter 1 for yes, 0 for no) ");
	int yn;
	scanf("%d",&yn);
	if(yn==1) print_list(h);
	else printf("ok :c \n");
	
	//asking to delete
	
	printf("do you want to delete any element?(1 for yes, 0 for no) ");
	scanf("%d",&yn);
	if(yn==1) {
		int m;
		printf("Enter index of number to be deleted now: ");
		scanf("%d", &m);
		printf("Here is new LinkedList: \n");
		delete_node(m,&h);
		print_list(h);
	}
	else printf("ok :c \n");
	
	//asking to insert
	printf("do you want to insert any element?(1 for yes, 0 for no) ");
	scanf("%d",&yn);
	if(yn==1) {
		int m, l;
		printf("Enter index, after which your number will be inserted now: ");
		scanf("%d", &m);
		printf("Enter the number to be inserted now: ");
		scanf("%d", &l);
		printf("Here is new LinkedList: \n");
		insert_node(l,m+1,&h);
		print_list(h);
	}
	else printf("ok bye lazy person!!! \n");
    return 0; 
} 
