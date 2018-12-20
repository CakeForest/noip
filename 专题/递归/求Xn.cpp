#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long cf(int x,int n)
{
	if(n==1)
		return x;
	else
		return x*cf(x,n-1);
}

int main()
{
	int x,n;
	scanf("%d %d",&x,&n);
	printf("%lld",cf(x,n));

	
	return 0;
}
