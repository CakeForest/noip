#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	node *next;
	int x;
};

int main()
{
	int n,k;
	node *p,*head,*last;
	scanf("%d",&n);
	
	head=new node;
	p=head;
	for(int i=1;i<=n;i++)//�������� 
	{
		p->next=new node;
		p=p->next;
		scanf("%d",&p->x);
	}
	p->next=new node;
	p=p->next;
	p->next=NULL;
	scanf("%d",&k);
	
	last=head;
	for(p=head->next;p->next->next!=NULL;)
		if(p->x==k)//ɾ��Ԫ�� 
		{
			last->next=p->next;
			delete p;
			p=last->next;
		}
		else
		{
			last=p;
			p=p->next;
		}
			
	for(p=head->next;p->next->next!=NULL;p=p->next)//��� 
		printf("%d ",p->x);
			
	
	return 0;
}
