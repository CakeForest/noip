#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100];
	gets(a);
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
			a[i]-=32;
	}
	printf("%s",a);
	
	return 0;
}