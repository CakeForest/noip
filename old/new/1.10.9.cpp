#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1010],key;
void asort(int l,int r)
{
	if(l>=r)
		return;
	int i=l,j=r;
	key=a[l];
	while(i<j)
	{
		while(i<j&&a[j]>=key)
			j--;
		a[i]=a[j];
		while(i<j&&a[i]<=key)
			i++;
		a[j]=a[i];
	}
	a[i]=key;
	asort(l,i-1);
	asort(j+1,r);
	return;
}

int main()
{
	int n,judge[1100]={0};
	scanf("%d",&n);
	int j,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&j);
		if(judge[j]==0)
		{
			judge[j]++;
			sum++;
			a[sum]=j;
		}
	}
	asort(1,sum);
	
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)
	{
		printf("%d",a[i]);
		if(i!=sum)
			printf(" ");
	}

	return 0;
}
