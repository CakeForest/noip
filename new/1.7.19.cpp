#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[220];
	gets(a);
	bool x=0;
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]==' '&&x==0)
		{
			x=1;
			printf("%c",a[i]);
		}
		else if(a[i]!=' ')
			printf("%c",a[i]);
		if(a[i]!=' ')
			x=0;
		
		
		
		
	}
	
	
	
	
	return 0;
}