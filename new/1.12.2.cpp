#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,j;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&j);
		sum+=j%70==0?j/70:j/70+1;
	}
	double cash=sum*0.1;
	printf("%.1lf",cash);
	
	return 0;
}