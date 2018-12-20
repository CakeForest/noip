#include<stdio.h>
using namespace std;
const int MAXSIZE=100020;
int stuck[MAXSIZE],top=0,rear=0;

int push(int a)
{
	stuck[rear++]=a;
}

int pop()
{
	if(top!=rear)
	{
		top++;
		return 1;
	}
	return -1;
	
}

int main()
{
	int n,c,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d",&c);
			push(c);
		}
		else
		{
			if(pop()==-1)
			{
				flag=1;
				break;
			}
		}
	}
	if(top==rear||flag)
		printf("impossible!");
	else
		printf("%d",stuck[top]);
	
	return 0;
}
