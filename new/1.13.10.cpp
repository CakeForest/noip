#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int x,y;
	int zhi[100030]={0,0};
	scanf("%d %d",&x,&y);
	int max=x>y?x:y;
	int min=x>y?y:x;
	for(int i=2;i<=max;i++)
		zhi[i]=1;
	for(int i=2;i<=max;i++)
		if(zhi[i]==1)
		{
			int k=2;
			while(k*i<=max)
			{
				zhi[k*i]=0;
				k++;
			}
		}
	int sum=0;
	for(int i=min;i<=max;i++)
		if(zhi[i]==1)
			sum++;
	printf("%d",sum);
	
	return 0;
}