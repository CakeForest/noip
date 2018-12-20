#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=20;
int n,m,f[MAXSIZE][MAXSIZE],t[MAXSIZE][MAXSIZE],g[MAXSIZE][MAXSIZE],pre[MAXSIZE][MAXSIZE],ans[MAXSIZE];
//f[i][j]表示在前i个公司使用j台设备的最大盈利
int main()
{
//	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>t[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=j;k++)
				if(f[i-1][j-k]+t[i][k]>=f[i][j])
					f[i][j]=f[i-1][j-k]+t[i][k],g[i][j]=k,pre[i][j]=j-k;
	
	int now=m;
	for(int i=n;i>=1;i--)
		ans[i]=g[i][now],now=pre[i][now];
	cout<<f[n][m]<<endl;
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<ans[i]<<endl;
	
	return 0;
}
