#include<stdio.h>
using namespace std;
int stack[6],output[40]={0},log,top,now=1;

int push()
{
	if(top<4)
	{
		top++;
		stack[top]=now++;
		return 1;
	}
	return -1;
}

int pop()
{
	if(top>=0){
		output[log]=stack[top];
		log++;top--;
		return 1;
	}
	return -1;
}

int main()
{
	int n,flag=0;
	char c;
	top=-1;log=1;
	scanf("%d",&n);
	char a[40];
	scanf("%s",a);
	for(int i=0;i<n&&flag!=1;i++)
	{
		c=a[i];
		if(c=='A')
		{
			output[log]=now;
			log++;now++;
		}
		else if(c=='B')
		{
			if(push()==-1)
				flag=1;
		}
		else if(c=='C')
		{
			if(pop()==-1)
				flag=1;
		}
	}
	if(flag)
		printf("No");
	else
	{
		printf("Yes\n");
		for(int i=1;i<log;i++)
			printf("%d\n",output[i]);
	}
	return 0;
}
