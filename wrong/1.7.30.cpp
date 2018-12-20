#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char z;//当前字符 
void output(int p1,int p2,int p3,char x,char y);
char dxx(char j,int p1);
void repeat(char j,int p2);

int main()
{
	int p1;//p1=1填充小写  p1=2填充大写  p1=3填充* 
	int p2;//填充字符的重复个数
	int p3;//是否逆序输出 1否 2是 
	char a[200];
	scanf("%d %d %d",&p1,&p2,&p3);
	getchar();
	gets(a); 
	char x,y;//首末位字符
	int i=0;//光标
	int fuck=1;//是否为减号后的数字 
	
	do{/////////////////////////////////////////错误 连续减号无法判断 
		x=a[i];y=a[i+2];
		if(fuck)//判断是否输出当前字符 
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

char dxx(char j,int p1)//转换大小写  情况1 
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

void repeat(char j,int p2)//情况2 
{
	for(int i=1;i<=p2;i++)
		printf("%c",j);
}
