#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char z;//��ǰ�ַ� 
void output(int p1,int p2,int p3,char x,char y);
char dxx(char j,int p1);
void repeat(char j,int p2);

int main()
{
	int p1;//p1=1���Сд  p1=2����д  p1=3���* 
	int p2;//����ַ����ظ�����
	int p3;//�Ƿ�������� 1�� 2�� 
	char a[200];
	scanf("%d %d %d",&p1,&p2,&p3);
	getchar();
	gets(a); 
	char x,y;//��ĩλ�ַ�
	int i=0;//���
	int fuck=1;//�Ƿ�Ϊ���ź������ 
	
	do{/////////////////////////////////////////���� ���������޷��ж� 
		x=a[i];y=a[i+2];
		if(fuck)//�ж��Ƿ������ǰ�ַ� 
			printf("%c",x);
		fuck=1;
		if(a[i+1]=='-')
		{
			if(x=='-')
			{
				printf("-");
				i--;	
			}
			else if(y=='-')
			{
				printf("-");	
			}
			else if(x-y>=40||y-x>=40||x>=y)
				printf("-%c",y);
			else if(y-x==1)
				printf("%c",y);
			else if(x<y)
			{
				if(p3==1)
					z=x+1;
				else if(p3==2)
					z=y-1;
				output(p1,p2,p3,x,y);
				printf("%c",y);
				fuck=0;
			}
			i++;
		}
		
		
		
		
		
		i++;
	}while (a[i]!='\0');
	
	
	

	
	return 0;
}

void output(int p1,int p2,int p3,char x,char y)
{
	do{
		repeat(dxx(z,p1),p2);
		if(p3==1)
			z++;
		else if(p3==2)
			z--;
	}while(z!=x&&z!=y);
}

char dxx(char j,int p1)//ת����Сд  ���1 
{
	if(p1==1)
	{
		if(j>='A'&&j<='Z')
			return j+32;
	}
	else if(p1==2)
	{
		if(j>='a'&&j<='z')
			return j-32;
	}
	else if(p1==3)
		return '*';
}

void repeat(char j,int p2)//���2 
{
	for(int i=1;i<=p2;i++)
		printf("%c",j);
}
