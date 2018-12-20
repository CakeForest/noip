#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[1100][510],N,M,K,a[110],b[110];

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>N>>M>>K;
	for(int i=1;i<=K;i++)
		cin>>a[i]>>b[i];
	for(int k=1;k<=K;k++)
	{
		for(int i=N;i>=1;i--)
			for(int j=M;j>=1;j--)
				if(i>=a[k]&&j>=b[k])
					f[i][j]=max(f[i][j],f[i-a[k]][j-b[k]]+1);
	}				
	int maxn=-1,maxm;
	for(int j=0;j<=M;j++)
		if(f[N][j]>maxn)
			maxn=f[N][j],maxm=M-j;

	cout<<maxn<<" "<<maxm;
	
	return 0;
}
