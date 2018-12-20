#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	node *pre;
	char info[150];
};
int main()
{
	char end[4]="end";
	node *p,*last;
	last=new node;
	last->info[0]=NULL;
	p=new node;
	p->pre=last;
	do{
		gets(p->info);
		last=p;
		p=new node;
		p->pre=last;
	}while(strcmp(p->pre->info,end));
	
	
	return 0;
}
