#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int q[100]={0},p[100]={0};
	
	p[1]=1;
	q[1]=2;

	
	
	
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=1.0*q[i]/p[i];
		int lastq=q[i];
		q[i+1]=q[i]+p[i];
		p[i+1]=lastq;

		
		
		
	}	
	
	printf("%.4lf",sum);
	
	
	
	
	
	return 0;
}
