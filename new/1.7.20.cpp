#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[2000];
	int num[1000];
	gets(a);
	int i=0;
	int sum=0,n=1;
	while(1)
	{
		if(a[i]==0)
		{
			num[n]=sum;
			break;			
		}
		if(a[i]!=' ')
			sum++;
		else if(sum>0)
		{
			num[n]=sum;
			sum=0;
			n++;
		}
		i++;
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("%d",num[i]);
		if(i!=n)
			printf(",");
	}
	return 0;
}