#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=300;
int n,m,w[MAXSIZE],v[MAXSIZE],f[MAXSIZE][MAXSIZE];
int main()
{
//	freopen("in.txt","r",stdin);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=-1;
			int now=0;
			while(now*w[i]<=j)
			{
				if(f[i-1][j-now*w[i]]!=-1)
					f[i][j]=max(f[i][j],f[i-1][j-now*w[i]]+now*v[i]);
				now++;
			}
		}

	cout<<"max="<<f[n][m];
	
	return 0;
}
