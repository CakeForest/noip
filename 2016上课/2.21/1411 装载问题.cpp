#include<stdio.h>
#include<algorithm>
using namespace std;
int sum[2000],a[2000],w[2000],n,c,ans=-1,flag=0,tot=0;
bool cmp(int x,int y)
{
	return x>y;
}
void hs(int t)
{
	if(flag) return;
	if(tot>c)//如果总数大于载重，返回 
		return;
	if(tot==c)//如果总数等于载重，返回 
	{
		ans=c; flag=1;
		return;
	}
	if(tot>ans)//如果总数大于之前的最大载重，更新最大载重 
		ans=tot;
	if(tot+sum[a[t-1]+1]<ans)//如果当前已选箱子加上之后的所有的箱子都不能大于当前最大重量，返回 
		return;
	if(tot+w[n]>c)//如果当前已选箱子加上最小的箱子都大于载重量，返回 
		return;
	for(int i=a[t-1]+1;i<=n;i++)
	{
		tot+=w[i];
		a[t]=i;
		hs(t+1);
		tot-=w[i];
	}
	
}
int main()
{
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+1+n,cmp);//从大到小排序
	sum[n]=w[n];
	for(int i=n-1;i>=1;i--)//计算从最后一个箱子到当前箱子总重 
		sum[i]=sum[i+1]+w[i];
	hs(1);
	printf("%d",ans);

	
	return 0;
}
