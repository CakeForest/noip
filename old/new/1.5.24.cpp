#include<stdio.h>
#include<stdlib.h>

int main()
{
	int k;
	scanf("%d",&k);
	
	bool end=0;
	for(int i=1; ;i++)
	{
		double x=1.0;
		for(int m=2;m<=i;m++)
		{
			x+=1.0/m;
		}
		if(x>k)
		{
			printf("%d",i);
			return 0;
		}
	}
	
	
	
	
	
	
	
	return 0;
}
