#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int k;
	char a[30000];
	scanf("%d",&k);
	getchar();
	gets(a);
	int n[30000]={0};
	int sum=1;
	char log=a[0];
	
	for(int i=1;i<=strlen(a);i++)
	{
		if(sum==k)
		{
			printf("%c",log);
			return 0;
		}
		if(a[i]==log)
			sum++;
		else
		{
			sum=1;
			log=a[i];
		}
	}
	printf("No");
	return 0;
}