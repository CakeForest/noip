#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[1020];
	scanf("%s",a);
	int i=1;//���
	int n=2;//��ǰ�ǵ�n������ 
	int shuzi=a[0];
	while(a[i]!='\0')
	{
		if(shuzi==a[i])
			n++;	
		else if(shuzi!=a[i])
		{
			printf("%d%d",n-1,shuzi-48);
			n=1;
			shuzi=a[i];
			n++;
		}
		i++;
	}
	printf("%d%d",n-1,shuzi-48);
	
	
	
	
	return 0;
}