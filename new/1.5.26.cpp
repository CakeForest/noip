#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[100]={0};
	
	 
	scanf("%s",&a);
	int n=strlen(a);
	
	bool fu=0,ling=0,fuck=0;
	if(a[0]=='-')
	{
		fu=1;
		printf("-");
	}
		
	
	for(int i=n-1;i>=0;i--)
	{
		
		
		if(ling==0&&a[i]=='0')
		{
			fuck=1;
		}
		
		if(a[i]!='0')
		{
			ling=1;
		}
		
		if(fuck==0)
		{
			printf("%c",a[i]);
		
		
			if(fu==1&&i==1)
			{
				return 0;
			}
		}
		else
		{
			fuck=0;
		}
		
		
		
		
		
		
		
	}
	

	
	return 0;
}
