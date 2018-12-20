#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[120];
	char b[120];
	
	gets(a);
	
	int len=strlen(a);
	for(int i=0;i<=len-1;i++)
	{
		if(i!=len-1)
			b[i]=a[i]+a[i+1];
		else
			b[i]=a[i]+a[0];
	}
	
	for(int i=0;i<=len-1;i++)
	{
		printf("%c",b[i]);
	}
	return 0;
}