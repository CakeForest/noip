#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,min=999999,h,now,i,j;
	scanf("%d",&n);
	for(i=1;i<=n/3;i++)
		for(j=i;j<=n/3;j++)
			if(n%(i*j)==0)
			{
				h=n/(i*j);
				now=i*j*2+i*h*2+j*h*2;
				if(now<min)
					min=now;
			}
	printf("%d",min);
	return 0;
}
