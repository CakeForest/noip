#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct hs
{
	int x;
	int y;
	int num;
};
int a[30][30];
int sum=0;
int m,n,k,now=1,tian=0;
hs log[1000];

bool cmp(hs x1,hs y1)//可采的花生按从大到小排序 
{
	if(x1.num>y1.num)
		return true;
	else
		return false;
}

void work(int left)
{
	tian++;
	if(tian==now)//猴子花生田采完 
		return;
	if(tian==1)//第一次，猴子进入花生田所需步数 
	{
		left--;
		left-=log[tian].x-1;
	}
	else//第n次，猴子进入下一个花生田所需步数 
		left-=abs(log[tian].x-log[tian-1].x)+abs(log[tian].y-log[tian-1].y);//计算两田距离 
	if(left<=log[tian].x)//如果步数不够采花生，返回 
		return;
	else
	{
		sum+=log[tian].num;//如果采了花生还有时间，就采下一个花生田 
		left--;
		work(left);
		return;
	}
}

int main()
{
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	{
		int c;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c);
			if(c!=0)
			{
				a[i][j]=c;
				log[now].num=c;
				log[now].x=i;
				log[now].y=j;
				now++;
			}	
		}
	}
	sort(log+1,log+now+1,cmp);
	work(k);
	printf("%d",sum);
	
	
	
	
	
	return 0;
}
