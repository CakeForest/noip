#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int sum;
	double pri[20]={0,28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
	double he=0;
	for(int i=1;i<=10;i++)
	{
		int num;
		scanf("%d",&num);
		he+=1.0*num*pri[i];
	}
	
	printf("%.1lf",he);
	return 0;
}