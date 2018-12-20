#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int sum=0;
	int day=0;
	for(int i=1;;i++)
	{
		for(int m=1;m<=i;m++)
		{
			sum+=i;
			day++;
			if(day==n)
			{
				printf("%d",sum);
				return 0;
			}
		}
	}
	
	
	
	
	return 0;
}