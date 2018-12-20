#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[30];
	scanf("%s",a);
	for(int i=0;i<=strlen(a)-1;i++)
	{
		if(i==0&&a[i]>='0'&&a[i]<='9')
		{
			printf("no");return 0;
		}
		else 
		{
			if(a[i]=='_'||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9'))
				;
			else
			{
				printf("no");return 0;
			}
		}
	}
	
	printf("yes");
	return 0;
}