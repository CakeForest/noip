#include<stdio.h>
#include<stdlib.h>

int main()
{
	int h;
	scanf("%d",&h);
	
	double sum=h;
	double he=h;
	for(int i=1;i<=10;i++)
	{
		
		if(i!=10)
			sum+=1.0*he/2*2;
	
			
		
		he/=2;
		
	}
	
	
	printf("%g %g",sum,he);
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
