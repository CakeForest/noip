#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=3000000;
char stack[MAXSIZE],top;

int push(char c)
{
	if(top<MAXSIZE-1)
	{
		top++;
		stack[top]=c;
		return 1;
	}
	return -1;
}

int pop()
{
	if(top>=0){
		top--;
		return 1;
	}
	return -1;
}

int judge(char c)
{
	char now=stack[top];
	switch(c)
	{
		case ']':return now=='[';
		case '>':return now=='<';
		case ')':return now=='(';
		case '}':return now=='{';
		default:return false; 
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,flag;
	char c;
	scanf("%d",&n);
	scanf("%c",&c);
	for(int i=1;i<=n;i++)
	{
		top=-1;
		flag=0;
		while(scanf("%c",&c)!=EOF&&c!='\n')
		{
			if(flag==1)
				continue;
			if(c=='('||c=='['||c=='{'||c=='<')
				push(c);//入栈 
			else
				if(judge(c)!=1||pop()==-1) 
				{//判断是否符合规则，并且 
					printf("FALSE");
					flag=1;
				}
		}
		if(flag==0)
			if(top==-1)
				printf("TRUE");
			else
				printf("FALSE");
		printf("\n");
	}
	return 0;
}
