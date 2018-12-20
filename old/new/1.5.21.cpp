#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int a[200];
	int b[200];
	int x=0;
	int max=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(a[i]>=90&&a[i]<=140&&b[i]>=60&&b[i]<=90)
		{
			x++;
			if(x>=max)
				max=x;
		}
		else
		{	
			x=0;
		}
	}
	
	
	
	printf("%d",max);
	

	
	return 0;
}
