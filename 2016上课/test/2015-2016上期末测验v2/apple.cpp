#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

int sum=0;
int m,n;
int a[20];

void work(int k,int i)//k个苹果，第i个盘子
{
	if(i==n)
	{
		if(k>=a[i-1])
			sum++;
		return;
	}
	for(int j=a[i-1];j<=k/2;j++)
	{
		a[i]=j;
		work(k-j,i+1);	
	}
	return;
} 

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d %d",&m,&n);
	a[0]=0;
	work(m,1);
	
	printf("%d",sum);
	
	
	return 0;
}
