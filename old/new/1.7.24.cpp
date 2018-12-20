#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char word[120][20];
	char a[100000];
	gets(a);
	int i=0,j=1,sum=0;
	while(1)
	{
		if(a[i]!=' ')
		{
			word[j][sum]=a[i];
			sum++;
			if(a[i]==0)
				break;
		}
		else if(a[i]==' '&&sum>0)
		{
			word[j][sum]=0;
			sum=0;
			j++;
		}
		i++;
	}
	for(i=j;i>=1;i--)
	{
		printf("%s",word[i]);
		if(i!=1)
			printf(" ");
	}
	
	return 0;
}