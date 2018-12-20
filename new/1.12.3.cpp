#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int j=0;
	char a[300][10];
	double tem;
	int truth,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s %lf %d",a[j],&tem,&truth);
		if(tem>=37.5&&truth==1)
		{
			sum++;
			j++;
		}
	}
	j--;
	for(int i=0;i<=j;i++)
		printf("%s\n",a[i]);
	printf("%d",sum);
	
	return 0;
}