#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[260];//AGTC
	gets(a);
	int len=strlen(a);
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			printf("%c",a[i]+32);
		else if(a[i]>='a'&&a[i]<='z')
			printf("%c",a[i]-32);
		else 
			printf("%c",a[i]);
		
	}

	
	return 0;
}