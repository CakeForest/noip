#include<stdio.h>
#include<stdlib.h>

int main()
{
	long n;
	scanf("%ld",&n);
	
	bool end=1;
	while(n!=1)
	{
		if(n%2==1)
		{
			long m=3*n+1;
			printf("%ld *3+1=%ld\n",n,m);
			n=m;
		}
		else if(n%2==0)
		{
			long m=n/2;
			printf("%ld/2=%ld\n",n,m);
			n=m;
		}
		
		
		if(n==1)
			end=0;
	}
	printf("End");
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
