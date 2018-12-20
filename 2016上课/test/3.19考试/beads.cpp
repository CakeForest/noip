#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXSIZE=370;
char beads[MAXSIZE];
int pre[MAXSIZE],next[MAXSIZE],n;//左边珠子 右边珠子  

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&n);
	char c;
	c=getchar();
	for(int i=1;i<=n;i++)
	{
		c=getchar();
		beads[i]=c;
		pre[i]=i-1;
		next[i]=i+1;
	}
	pre[1]=n;
	next[n]=1;

	char first;
	int now;
	int max=-1,sum=0;//sum记录可以获得的珠子数 如果sum超过n则返回 
	for(int cut=1;cut<=n;cut++)//枚举切开的位置,设切开cut与next[cut]之间的线 
	{
		sum=0;
		now=next[cut];//向右边数
		first=beads[now]; sum++;
		now=next[now];
		while(sum<=n&&first=='w')//如果开头是白色珠子，一直找到没有白色珠子为止 
		{
			first=beads[now];
			sum++;
			now=next[now];
		}
		
		while(sum<=n&&(beads[now]==first||beads[now]=='w'))
		{
			sum++;
			now=next[now];
		} 
		
		now=cut;//向左边数 
		first=beads[now]; sum++;
		now=pre[now];
		while(sum<=n&&first=='w')//如果开头是白色珠子，一直找到没有白色珠子为止 
		{
			first=beads[now];
			sum++;
			now=pre[now];
		}
		while(sum<=n&&(beads[now]==first||beads[now]=='w'))
		{
			sum++;
			now=pre[now];
		}
		if(sum>max)
			max=sum;
	}
	printf("%d",max>=n?n:max);
	
	return 0;
}
