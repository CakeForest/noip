#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void work(int n)
{
	if(n==1)//��ʼ�ж����������nΪ1��2��ֱ����� 
	{
		printf("2(0)");
		return;
	}
	else if(n==2)
	{
		printf("2");
		return; 
	} 
	else
	{
		int j=1,i=0;//jÿ�γ�2,���������n�ͷֽ������iΪ��ǰ���� 
		while(1)
		{
			j*=2;
			if(j>n)
			{
				j/=2;
				if(i==1)//�ⲽ�ǳ���Ҫ��ȷ���Ƿ���Ҫ���� 2() 
					printf("2");
				else
				{
					printf("2(");
					work(i);
					printf(")");
				}	
				if(n-j!=0)//���n�ֽ�֮����ʣ���������ô�����ֽ� 
				{
					printf("+");
					work(n-j);
				}
				return;
			}
			else
				i++;
		}
	}	
					
	
}

int main()
{
	int n;
	scanf("%d",&n);
	work(n);
}
