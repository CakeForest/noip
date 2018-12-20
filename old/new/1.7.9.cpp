#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char key[300]={0};//key[密文]=原文 
	char yu[10000];//原信息 
	char mi[10000];//加密后的信息
	char miwen[10000];
	scanf("%s %s %s",mi,yu,miwen);
	int i=0;
	int sum=0;
	for(int i=0;i<=strlen(yu)-1;i++)
	{
		char a=mi[i];//加密 后的一个字符
		char b=yu[i];//原文 中的一个字符
		if(key[a]!=0&&key[a]!=b)
		{
			printf("Failed");//检查是否多个密文对一个原文 
			return 0;
		}
		else
		{
			for(int d='A';d<='Z';d++)//检查是否一个密文对应多个原文 
			{
				if(d!=a)
					if(b==key[d])
					{
						printf("Failed");
						return 0;
					}
			}
			
			key[a]=b;
			sum++;
		}
		if(sum==26)
			break;
	} 
	if(sum!=26)
	{
		printf("Failed");
		return 0;
	}
	
	char prin[10000];
	for(int i=0;i<=strlen(miwen)-1;i++)
	{
		if(key[miwen[i]]!=0)
			prin[i]=key[miwen[i]];
		else 
		{
				printf("Failed");
				return 0;
		}
		if(i==strlen(miwen))
			prin[i+1]=0;
	}
	
	printf("%s",prin);	
	return 0;
}