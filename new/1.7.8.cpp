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
		if((a[i]>='A'&&a[i]<='Y')||(a[i]>='a'&&a[i]<='y'))
			printf("%c",a[i]+1);
		else if(a[i]=='Z'||a[i]=='z')
			printf("%c",a[i]-25);
		else 
			printf("%c",a[i]);
		
	}

	
	return 0;
}