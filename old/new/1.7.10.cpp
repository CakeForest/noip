#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[51];
	scanf("%s",a);
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]<=90)
			a[i]+=32;
		else 
			a[i]-=32;
	}
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if((a[i]>='a'&&a[i]<='w')||(a[i]>='A'&&a[i]<='W'))
			a[i]+=3;
		else if(a[i]>='x'&&a[i]<='z')
		{
			int x=a[i]+3-'z';
			a[i]='a'+x-1;
		}
		else
		{
			int x=a[i]+3-'Z';
			a[i]='A'+x-1;
		}
	}
	for(int i=strlen(a)-1;i>=0;i--)
	{
		printf("%c",a[i]);
	}
//	printf("0");
	
	
	
	
	return 0;
}