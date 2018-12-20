#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int out[10];
void translate(int n,int j)//����ԭ�� 
{
	if(j<=0)
		return;
	out[j]=n%2;
	translate(n/2,j-1);
}

int main()
{
	int r,c;
	scanf("%d %d",&r,&c);
	int map[30][30];
	int key[300];
	getchar();
	int len=0;
	char ch;
	do{//�����ַ� 
		len++;
		ch=getchar();
		key[len]=ch-'A'+1;
	}while(ch!='\n');
	len-=1;
	
	for(int i=1;i<=c;i++)//��ʼ������ 
		for(int j=1;j<=r;j++)
			map[i][j]=-1;

	int x=1,y=1,dir=2;
	int j=1;
	int nextx,nexty;
	for(int i=1;i<=len;i++)//���������� 
	{
		translate(key[i],5);
		while(j<=5)
		{
			map[x][y]=out[j];
			nextx=x+(dir%2==0?(dir%4==0?-1:1):0);//Ԥ����һ������ 
			nexty=y+(dir%2==1?(((dir-(dir/4)*4)%3)==0?1:-1):0);
			if(map[nextx][nexty]!=-1)//����һ�����겻����䣬����ת������� 
			{
				dir++;
				x=x+(dir%2==0?(dir%4==0?-1:1):0);
				y=y+(dir%2==1?(((dir-(dir/4)*4)%3)==0?1:-1):0);
			}
			else
			{
				x=nextx;
				y=nexty;
			}
			j++;
		}
		j=1;
	}
	
	
	
	
	
	for(int j=1;j<=r;j++)
		for(int i=1;i<=c;i++)
			printf("%d",map[i][j]==-1?0:map[i][j]); //δ������ֱ�����0 
	
	
	
	return 0;
}