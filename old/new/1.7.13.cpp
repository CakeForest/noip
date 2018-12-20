#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d",&n);
	char a[120][30];
	
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int m=0;m<=strlen(a[i])-1;m++)
		{
			if(m==0&&a[i][m]>='a'&&a[i][m]<='z')
				a[i][m]-=32;
			else if(m!=0&&a[i][m]>='A'&&a[i][m]<='Z')
				a[i][m]+=32;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		printf("%s",a[i]);
		if(i!=n)
			printf("\n");
	}
	return 0;
}