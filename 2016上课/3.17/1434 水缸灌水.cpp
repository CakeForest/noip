#include<stdio.h>
using namespace std;
const int MAXSIZE=1000000;
struct node{
	int x,y;
	int dad;
}queue[MAXSIZE];
int top,rear;
int ansx[MAXSIZE]={0},ansy[MAXSIZE]={0};
int amax,bmax,aim;
int use[1000][1000];/*这个数组用来记录步骤是否已经尝试 
						 这步很重要，否则程序会陷入死循环 */

void pri(int now)//输入当前方案的最后一步的位置
{
	int n=MAXSIZE-1;
	for(;now!=0;now=queue[now].dad)
	{
		ansx[n]=queue[now].x;
		ansy[n]=queue[now].y;
		n--;
	}
	ansx[n]=queue[now].x;
	ansy[n]=queue[now].y;
	
	for(int i=0;n<=MAXSIZE-1;n++)
	{
		printf("sep%3d:%5d%5d\n",i,ansx[n],ansy[n]);
		i++;
	}
} 

int main()
{
	scanf("%d%d%d",&amax,&bmax,&aim);
	top=0;rear=1;
	queue[0].x=amax; queue[0].y=0; queue[0].dad=-1;
	do{//进行操作 判断各自是否可行 
		node now; int delta;
		now.x=queue[top].x; now.y=queue[top].y;
		if(now.y==aim)//如果达到目标 
		{
			pri(top);
			return 0;
		}
		if(use[now.x][now.y]==0)
		{
			use[now.x][now.y]=1;
			if(now.x!=amax)//向a壶倒水
			{
				delta=amax-now.x>=now.y?now.y:amax-now.x;//y壶可以倒空则倒完，否则倒一部分 
				queue[rear].x=now.x+delta;
				queue[rear].y=now.y-delta;
				queue[rear].dad=top;
				rear++;
			} 
			if(now.y!=bmax)//向b壶倒水
			{
				delta=bmax-now.y>=now.x?now.x:bmax-now.y;//x壶可以倒空则倒完，否则倒一部分 
				queue[rear].y=now.y+delta;
				queue[rear].x=now.x-delta;
				queue[rear].dad=top;
				rear++;
			} 
			if(now.x!=amax&&now.y!=0)//把a壶倒满水 
			{
				queue[rear].x=amax;
				queue[rear].y=now.y;
				queue[rear].dad=top;
				rear++;
			}
			if(now.y!=bmax&&now.x!=0)//把b壶倒满水 
			{
				queue[rear].y=bmax;
				queue[rear].x=now.x;
				queue[rear].dad=top;
				rear++;
			}
			if(now.x!=0&&now.y!=0)//分别倒空两壶的水 
			{
				queue[rear].x=0;
				queue[rear].y=now.y;
				queue[rear].dad=top;
				rear++;
				queue[rear].y=0;
				queue[rear].x=now.x;
				queue[rear].dad=top;
				rear++;
			}
		}
		top++;
	}while(top!=rear);
	printf("No answer!");
	return 0;
}
