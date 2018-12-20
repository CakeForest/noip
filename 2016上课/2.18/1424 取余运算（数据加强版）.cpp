#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int k;
int m;
long long mod(int a,int b)
{
	long long t;
	if(b==1)
		return a%k;
	else if(b%2==0)
	{
		t=mod(a,b/2);
		return (t*t)%k;
	}
	else
	{
		t=mod(a,b/2);
		return (t*t*a)%k;
	}
}

int main()
{
	int b,p;
	scanf("%d %d %d",&b,&p,&k);
	printf("%d^%d mod %d=%lld",b,p,k,mod(b,p));
	return 0;
}
