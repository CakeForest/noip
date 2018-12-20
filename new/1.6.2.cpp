#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int apple[20];
	for	(int i=1;i<=10;i++)
	{
		scanf("%d",&apple[i]);
	}
	int hand;
	scanf("%d",&hand);
	
	int sum=0;
	for(int i=1;i<=10;i++)
	{
		if(hand+30>=apple[i])
			sum++;
	}
	printf("%d",sum);
	
	
	return 0;
}