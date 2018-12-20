#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=110;
int t,m,ti[MAXSIZE],v[MAXSIZE],f[MAXSIZE][1020];

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>ti[i]>>v[i];
	//»®·ÖÐÍDP 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=t;j++)
		{
			if(j-ti[i]<0)
				f[i][j]=f[i-1][j];
			else
				f[i][j]=max(f[i-1][j],f[i-1][j-ti[i]]+v[i]);
		}
	cout<<f[m][t];
	
	return 0;
}
