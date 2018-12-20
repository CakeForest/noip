#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[260];//AGTC
	scanf("%s",a);
	

	for(int i=0;a[i]!=0;i++)
	{
		if(a[i]=='A')
			printf("T");
		else if(a[i]=='T')
			printf("A");
		else if(a[i]=='G')
			printf("C");
		else if(a[i]=='C')
			printf("G");
			
	}
	
	return 0;
}
