#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=300;
int V,N,T,w[11][MAXSIZE],c[11][MAXSIZE],p[11],f[MAXSIZE];

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>V>>N>>T;
	for(int i=1;i<=N;i++)
	{
		int x,y,z;cin>>x>>y>>z;
		p[z]++;w[z][p[z]]=x;c[z][p[z]]=y;
	}
	
	for(int k=1;k<=T;k++)
		for(int j=V;j>=1;j--)
			for(int i=1;i<=p[k];i++)
				if(j>=w[k][i])
					f[j]=max(f[j],f[j-w[k][i]]+c[k][i]);
	cout<<f[V];
	
	return 0;
}
