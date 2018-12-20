#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100]={0};
	
	
	scanf("%s",&a);
	int n=strlen(a);
	
	for(int i=n-1;i>=0;i--)
	{
		printf("%c",a[i]);
		
		
		if(i!=0)
			printf(" ");
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
