#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n=1;
char a[3000];
double work()
{
	scanf("%s",a);
	int len=strlen(a);
	if(len==1&&!(a[0]>='0'&&a[0]<='9'))
		switch(a[0])
		{
			case '+':return work() + work();
			case '-':return work() - work();
			case '*':return work() * work();
			case '/':return work() / work();
		}
	else
	{
		return atof(a);
	}
}

int main()
{
	printf("%f",work());
}
