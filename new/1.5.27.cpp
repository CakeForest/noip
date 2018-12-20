#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int m;
	int k;
	scanf("%d %d",&m,&k);

	int san=0;
	char str[10]={0};
	sprintf(str,"%d",m);
	
	int n=strlen(str);
	for(int i=0;i<=n-1;i++)
	{
		if(str[i]=='3')
		{
			san++;
		}
	}
	
	
	if(m%19==0&&san==k)
	{
		printf("YES");
	}
	else 
		printf("NO");
	
	
	
	
	
	
	return 0;
}
