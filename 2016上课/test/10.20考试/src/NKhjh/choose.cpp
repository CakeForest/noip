#include<iostream>
#include<cstdio>
using namespace std;
inline int red()
{
	int l=0;char m=getchar();bool f=false;
	while(m<'0'||m>'9')
	{
		if(m=='-')f=true;
		m=getchar();
	}
	while(m>='0'&&m<='9')l=(l<<1)+(l<<3)+m-'0',m=getchar();
	if(f)return -l;
	return l;
}
int n,m,a[400005],ans=0,cnt=0;
void dfs(int pos,int sum,int en,int num)
{
	cnt++;
	if(cnt>10000005)return;
	if(num==m)
	{
		if(sum>ans)ans=sum;
		return;
	}
	if(pos>en)return;
	int i;
	for(i=pos+2;i<=en&&(en-i)>=2*(m-num-1);i++)
	dfs(i,sum+a[i],en,num+1);
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	n=red(),m=red();
	int i,j;
	for(i=1;i<=n;i++)
	a[i]=red(),a[i+n]=a[i];
	if(n/m<2)
	{
		printf("Error!");
		return 0;
	}
	for(i=1;i<=n;i++)
	dfs(i,a[i],i+n-2,1);
	printf("%d",ans);
	return 0;
}
