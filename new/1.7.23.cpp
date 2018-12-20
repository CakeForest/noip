#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char a[600][100];
	char in[100000];
	int space[600];
	gets(in);
	int i=0,j=1,sum=0;
	do{
		if(in[i]!=' ')
		{
			a[j][sum]=in[i];
			sum++;
		}
		else if(sum>0)
		{
			j++;
			sum=0;
			space[j]++;
		}
		else
		{
			space[j]++;
		}
		i++;
	}while(in[i]!=0);
	
	for(i=1;i<=j;i++)
	{
		int m;
		for(m=strlen(a[i])-1;m>=0;m--)
		{
			printf("%c",a[i][m]);
		}
		for(int n=space[i+1];n>=1;n--)
				printf(" ");
			
	}
	return 0;
}