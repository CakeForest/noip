#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[200],b[200];
	gets(a); gets(b);
	
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			a[i]+=32;
	}
	for(int i=0;i<=strlen(b)-1;i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
			b[i]+=32;
	}
	int ans=strcmp(a,b);
	
	if(ans==0)
		printf("=");
	else if(ans>0)
		printf(">");
	else if(ans<0)
		printf("<");

	
	return 0;
}