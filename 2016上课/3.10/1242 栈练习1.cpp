#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=1000;
int stack[MAXSIZE],top;

int push(int b)
{
	if(top<MAXSIZE-1)
	{
		top++;
		stack[top]=b;
		return 1;
	}
	return -1;
}

int pop()
{
	if(top>=0)
	{
		top--;
		return 1;
	}
	return -1;
}

int main()
{
	int n,a,b;
	scanf("%d",&n);
	for(int i=1,top=-1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d",&b);
			if(push(b)==-1)
			{
				printf("impossible!");
				return 0;
			}
		}
		else if(pop()==-1)
		{
			printf("impossible!");
			return 0;
		}	
	}
	if(top!=-1)
		printf("%d",stack[top]);
	else
		printf("impossible!");

	
	return 0;
}
