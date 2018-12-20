#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	node *next;
	int id;
};

int game(int n,int m)
{
	node *p,*head,*last;
	head=new node;
	p=head;
	for(int i=1;i<=n;i++)
	{
		p->id=i;
		if(i!=n)
		{
			p->next=new node;
			p=p->next;
		}
	}
	p->next=head;
	last=p;
	p=head;
	
	
	while(n>1)
	{
		for(int i=1;i<m;i++)
		{
			last=p;
			p=p->next;
		}
		last->next=p->next;
		delete p;
		p=last->next;
		n--;
	}
	return p->id;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m,ans[100];
	scanf("%d %d",&n,&m);
	int k=1;
	while(!((n==0)&&(m==0)))
	{
		ans[k++]=game(n,m);
		scanf("%d %d",&n,&m);
	}
	k--;
	for(int i=1;i<=k;i++)
	{
		printf("%d",ans[i]);
		if(i!=k)
			printf("\n");
	}
	return 0;
}
