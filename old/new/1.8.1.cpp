#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[6][30];
	int m,n;
	for(int i=1;i<=5;i++)
	{
		gets(a[i]);
//		getchar();	
	}
	scanf("%d %d",&m,&n);
	for(int i=1;i<=5;i++)
	{
		if(i==m)
			printf("%s",a[n]);
		else if(i==n)
			printf("%s",a[m]);
		else
			printf("%s",a[i]);
		printf("\n");
	}
	
	return 0;
}