#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=1020;
int a[MAXSIZE],f[MAXSIZE],n=1,pre[MAXSIZE],now,need=1;
//f[i]表示从头到i最多能拦截多少导弹 
//第一问：最长不下降子序列
//第二问：每次求完最长不下降子序列之后删除这些项，继续求解，直至拦截完成
int Nex(int i)
{
	i+=1;
	while(i<=n)
		if(a[i]!=-1)
			return i;
		else
			i++;
	return -1;
}
int Las(int i)
{
	i-=1;
	while(i>=1)
		if(a[i]!=-1)
			return i;
		else
			i--;
	return -1;
}

 
int main()
{
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	while(scanf("%d",&a[n])!=EOF)
		n++;
	n--;
	now=n;
	int mmax=0,log;pre[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(a[i]<=a[j]&&f[j]>f[i])
				f[i]=f[j],pre[i]=j;
		f[i]++;
		if(f[i]>mmax)
			mmax=f[i],log=i;
	}
	now-=mmax;
	printf("%d\n",mmax);//求最长不下降子序列  
	for(;log!=0;log=pre[log])
		a[log]=-1;
	
	while(now>=1)
	{
		for(int i=1;i<=n;i++)
			f[i]=0;
		mmax=0;
		int i=Nex(0);
		while(i!=-1)
		{
			int j=Las(i);
			while(j!=-1)
			{
				if(a[i]<=a[j]&&f[j]>f[i])
					f[i]=f[j],pre[i]=j;
				j=Las(j);
			}
			f[i]++;
			if(f[i]>mmax)
				mmax=f[i],log=i;
			i=Nex(i);
		}
		now-=mmax;
		need++;
		for(;log!=0;log=pre[log])
			a[log]=-1;
	}
	printf("%d",need);
	
	
	return 0;
}
