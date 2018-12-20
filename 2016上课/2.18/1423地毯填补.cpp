#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int aim_x,aim_y,n=1,k,a[1000][1000]={0},now_x,now_y,middle_x,middle_y,kind;

void fill(int x,int y,int kind)// 填充铺过的地毯 
{
	a[x][y]=1;
	if(kind==1)
	{
		a[x-1][y]=1;
		a[x][y+1]=1;
	}
	else if(kind==2)
	{
		a[x+1][y]=1;
		a[x][y-1]=1;
	}
	else if(kind==3)
	{
		a[x-1][y]=1;
		a[x][y-1]=1;
	}
	else if(kind==4)
	{
		a[x+1][y]=1;
		a[x][y+1]=1;
	}
}


void work(int s,int e,int h)//起点x值,起点y值,边长
{
	middle_x=s-1+h/2;
	middle_y=e-1+h/2;       //有问题 
	if(h==2)//边长为2，直接输出 
	{
		now_x=s;now_y=e;
		if(a[s][e]==1)
		{
			kind=3;now_x++; now_y++;
		}
		else if(a[s+1][e]==1)
		{
			kind=2;now_y++;
		}
		else if(a[s][e+1]==1)
		{
			kind=1;now_x++;
		}
		else if(a[s+1][e+1]==1)
			kind=4;
		printf("%d %d %d\n",now_x,now_y,kind);
		fill(now_x,now_y,kind);
		return;
	}
	else//边长不为2,先填补中间，再分成四块填补 
	{
		now_x=middle_x;now_y=middle_y;
		if(aim_x<=middle_x&&aim_y<=middle_y)
		{
			kind=3;now_x++; now_y++;
		}			
		else if(aim_x>middle_x&&aim_y<=middle_y)
		{
			kind=2;now_y++;
		}
		else if(aim_x<=middle_x&&aim_y>middle_y)
		{
			kind=1;now_x++;
		}
		else if(aim_x>middle_x&&aim_y>middle_y)
			kind=4; 
		printf("%d %d %d\n",now_x,now_y,kind);
		fill(now_x,now_y,kind);
		work(s,e,h/2);//分别填补四个区域 
		work(s,e+h/2,h/2);//有问题 
		work(s+h/2,e,h/2);
		work(s+h/2,e+h/2,h/2);	
		return;
	}
} 

int main()
{
	scanf("%d",&k);
	scanf("%d %d",&aim_x,&aim_y);
	for(int i=1;i<=k;i++)
		n*=2;
	a[aim_x][aim_y]=1;
	work(1,1,n);
	return 0;
}
