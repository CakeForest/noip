#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int min,max;
	int a;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(i==1)
		{
			max=a;
			min=a;
		}
		else if(a>max)	
			max=a;
		else if(a<min)
			min=a;
	}
	printf("%d",max-min);
	return 0;
}