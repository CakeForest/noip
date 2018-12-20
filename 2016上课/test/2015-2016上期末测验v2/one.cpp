#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

int sum=0;
void zheng(int n,int i)
{
	int j=n/2;
	sum+=n-j*2==1?1:0;
	if(j==0)
		return;
	else
		return zheng(j,i+1);
}

void fu(int n,int i)
{
	
}

int main()
{
	freopen("one.in","r",stdin);
	freopen("one.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n>=0)
		zheng(n,0);
	else
		fu(n,0);
		

	printf("%d",sum%2==1?1:2);
	
	return 0;
}
