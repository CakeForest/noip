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
			if(j-w[i]<0)
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);


/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}cout<<endl<<endl;*/
	cout<<f[n][m];
	
	return 0;
}
