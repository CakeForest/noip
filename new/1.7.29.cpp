#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[1000];
int h(int k,int j)
{
	while(k<=j)
	{
		if(a[k]!=a[j])
			return 0;
		k++;j--;	
	} 
	return 1;
}
int main()
{
	gets(a);
	int len=strlen(a);
	int left,right;
	bool succeed=0;
	for(int n=0;n<=len-1;n++)//�ַ������n 
	{
		for(int m=0;m<=len-1;m++)//�ַ�����ʼλ��m
		{
			left=m;//Ҫ�ж��ַ���������� 
			right=m+1+n;//Ҫ�ж��ַ��������Ҷ�
			if(right>len-1)
				break;
			else if(h(left,right))
			{
				if(succeed)
					printf("\n");
				for(int i=left;i<=right;i++)
					printf("%c",a[i]);
				succeed=1;
			}
		} 
	}
	
	return 0;
}