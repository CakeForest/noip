#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[20][30];
	char first[500];
	gets(first);
	int sum=1;
	int j=0;
	for(int len=0;len<=strlen(first)-1;len++)
	{
		if(first[len]!=' ')
		{
			str[sum][j]=first[len];	
			j++;
		}
		else if(first[len]==' ')
		{
			str[sum][j]=0;	
			sum++;
			j=0;
		}
	}
	
	
	
	
	char change[30],word[30];
	scanf("%s %s",word,change);
	for(int i=1;i<=sum;i++)
	{
		if(strcmp(str[i],word)==0)
			printf("%s",change);
		else
			printf("%s",str[i]);
		if(i!=sum)
			printf(" ");
	}
	
	
	return 0;
}