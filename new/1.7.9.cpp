#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char key[300]={0};//key[����]=ԭ�� 
	char yu[10000];//ԭ��Ϣ 
	char mi[10000];//���ܺ����Ϣ
	char miwen[10000];
	scanf("%s %s %s",mi,yu,miwen);
	int i=0;
	int sum=0;
	for(int i=0;i<=strlen(yu)-1;i++)
	{
		char a=mi[i];//���� ���һ���ַ�
		char b=yu[i];//ԭ�� �е�һ���ַ�
		if(key[a]!=0&&key[a]!=b)
		{
			printf("Failed");//����Ƿ������Ķ�һ��ԭ�� 
			return 0;
		}
		else
		{
			for(int d='A';d<='Z';d++)//����Ƿ�һ�����Ķ�Ӧ���ԭ�� 
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