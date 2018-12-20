#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a,b,sum;
	
	int max=0,log=-1;
	scanf("%d %d",&a,&b);
	sum=a+b-8;
	max=sum>0?sum:0;
	log=a>0?1:-1;
	for(int i=2;i<=7;i++)
	{
		scanf("%d %d",&a,&b);
		sum=a+b-8;
		if(sum>max)
		{
			max=sum;
			log=i;	
		}
	}
	printf("%d",log==-1?0:log);
	
	
	return 0;
}