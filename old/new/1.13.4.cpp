#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char c[100];
	int a[27]={0};
	for(int k=1;k<=4;k++)
	{
		gets(c);
		for(int i=0;i<=strlen(c)-1;i++)//读入文章 
			if(c[i]>='A'&&c[i]<='Z')
				a[c[i]-'A'+1]++;
	}
	
	int max=-1;
	for(int i=1;i<=26;i++)//寻找最大个数 
		if(a[i]>max)
			max=a[i];
	
	for(int i=max;i>=1;i--)
	{
		for(int j=1;j<=26;j++)
		{
			if(a[j]<i)
				printf(" ");
			else
				printf("*");
			if(j!=26)
				printf(" ");
			else
				printf("\n");
		}
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	
	return 0;
}