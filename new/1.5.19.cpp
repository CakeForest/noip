#include<stdio.h>
#include<stdlib.h>

int main()
{
	int yu[20];
	for(int i=1;i<=12;i++)
	{
		scanf("%d",&yu[i]);
	}
	
	int now=0;//手中的钱 
	int cun=0;//存的钱 
	for(int i=1;i<=12;i++)
	{
		now+=300;
		if(now<yu[i])
		{
			printf("-%d",i);
			return 0;
		}
		while(now-yu[i]>=100)
		{
			cun+=100;
			now-=100;
		}
		
		now-=yu[i];
		
		
	}
	now+=cun*1.2;
	printf("%d",now);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
