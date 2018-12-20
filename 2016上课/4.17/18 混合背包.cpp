#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int v,n,w[40],c[40],p[40],f[2][300];
int main()
{
	freopen("in.txt","r",stdin);
	cin>>v>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>c[i]>>p[i];
	for(int i=1;i<=n;i++)
	{
		int now=i%2,last=(i+1)%2;
		for(int j=1;j<=v;j++)
			if(p[i]==0&&j-w[i]>=0)
				f[now][j]=max(f[last][j],f[now][j-w[i]]+c[i]);
			else
				for(int k=0;k<=min(p[i],j/w[i]);k++)
					f[now][j]=max(f[now][j],f[last][j-k*w[i]]+k*c[i]);
	}
	cout<<f[n%2][v];
	return 0;
}
