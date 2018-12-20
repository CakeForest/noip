#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int zc(char a[],char b[])//ÅĞ¶ÏaÊÇ·ñÎªbµÄ×Ö´® 
{
	if(strlen(a)>strlen(b))
		return 0;
	else
	{
		int i=0;
		do
		{
			
			if(a[0]==b[i]&&a[strlen(a)-1]==b[i+strlen(a)-1])
			{
				int sum=0;
				int n=1;
				for(int m=i+1;m<i+strlen(a)-1;m++)
				{
					if(a[n]!=b[m])
						sum++;
					n++;
				}
				if(sum==0)
					return 1;
			}
			i++;
		}while (i+strlen(a)-1<=strlen(b));
		return 0; 
	}
}
int main()
{
	char str1[300],str2[300];
	scanf("%s %s",str1,str2);
	if(strcmp(str1,str2)==0)
		printf("%s is substring of %s",str1,str2);
	else if(zc(str1,str2)==1)
		printf("%s is substring of %s",str1,str2);
	else if(zc(str2,str1)==1)
		printf("%s is substring of %s",str2,str1);
	else 
		printf("No substring");
	
	return 0;
}