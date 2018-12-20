#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int ans[20000]={2};
int sum;
void work(int k,int loc)
{
	if(k==1)
		sum++;
	else
	{
		for(int i=ans[loc-1];i<=k;i++)
		{
			if(k%i==0)
			{
				ans[loc]=i;
				work(k/i,loc+1);
			}
		}
	}
}

int main()
{
	int n,a[2000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum=0;
		work(a[i],1);
		printf("%d",sum);
		if(i!=n)
			printf("\n");
	}
}
