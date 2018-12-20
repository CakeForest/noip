#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m[300]={0};
	int n;
	int count=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		int g=m[i];
		if((g%10)-(g/1000)-( (g/100)%10          )-((g/10)%10)>0)
		{
			count++;
		}
	}
	printf("%d",count);
	
	
	
	
	
	
	
	
	return 0;
}
