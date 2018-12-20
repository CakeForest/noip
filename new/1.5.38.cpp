#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	long long n;
	long long x,y;
	scanf("%lld",&n);
	
	if(n%2==0)
	{
       x=2;
       y=n/x;
    }
    else
    {
        for(int i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)
            {
             x=i;
             y=n/x;
           }
        }
    }
    
    
    printf("%lld",x>y?x:y);

	
	
	return 0;
}