#include<stdio.h>
#include<stdlib.h>

int a[200000];
void asort(int l,int r)
{
	if(l>=r)
		return;
	int i=l,j=r,key=a[l];
	while(i<j)
	{
		while(i<j&&a[j]>=key) j--;
		a[i]=a[j];
		while(i<j&&a[i]<=key) i++;
		a[j]=a[i];
	}
	a[i]=key;
	asort(l,i-1);
	asort(i+1,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	asort(1,n);
	
	for(int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
		if(i!=n)
			printf(" ");
	}
}
