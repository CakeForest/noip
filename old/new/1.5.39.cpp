#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)	
		printf("2");
	else if(n==2)
		printf("3");
	else if(n==3)
		printf("5");
	else
	{
		int zhi=5;
		for(int count=3;count<=n;count++)
		{
			if(n==count)
			{
				printf("%d",zhi);
				return 0;
			}
			for(int i=zhi+2;;i+=2)
			{
				int sum=0;
				int max=sqrt(i);
				for(int m=2;m<=max;m++)
				{
					if(i%m==0)
					{
						sum++;
						break;
					}
				}
				if(sum==0)
				{
					zhi=i;
					break;
				}
				
			}
			
			
			
		}
	}
	
	return 0;
}