#include<stdio.h>
#include<stdlib.h>
using namespace std;
int stack[260],top=-1;

int push(int a)
{
	stack[++top]=a;
}

int pop(char c)
{
	int a,b,ans;
	a=stack[top-1];
	b=stack[top];
	switch(c)
	{
		case '+':ans=a+b;break;
		case '-':ans=a-b;break;
		case '*':ans=a*b;break;
		case '/':ans=a/b;break;
	}
	stack[top-1]=ans;
	top--;
}

int main()
{
//	freopen("in.txt","r",stdin);
	char str[10],c;
	int i;
	while(scanf("%c",&c)!=EOF&&c!='@')
	{
		if(c=='+'||c=='-'||c=='*'||c=='/')
			pop(c);
		else
		{
			str[0]=c;
			i=1;
			while(scanf("%c",&c)!=EOF&&c!=' '&&c!='@')
				str[i++]=c;
			str[i]=0;
			push(atoi(str));
		}
	}
	
	
	
	printf("%d",stack[0]);

	
	return 0;
}
