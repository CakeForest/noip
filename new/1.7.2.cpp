#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num[10000];
	char str[100020];
	
	scanf("%s",&str);
	int i=0;
	while(str[i]!=0)
	{
		num[str[i]]++;
		i++;
	}
	for(i=0;i<=strlen(str);i++)
	{
		if(num[str[i]]==1)
		{
			printf("%c",str[i]);
			return 0;
		}
	}
	printf("no");
	
	return 0;
}