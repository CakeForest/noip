#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,a;
	char name[120][30];
	scanf("%d",&n);
	int max=0,log=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %s",&a,name[i]);
		if(a>=max)
		{
			max=a;
			log=i;
		}
	}
	printf("%s",name[log]);
	
	return 0;
}