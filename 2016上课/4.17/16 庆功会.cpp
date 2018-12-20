#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=550;
int n,m,v[MAXSIZE],w[MAXSIZE],s[MAXSIZE],f[6100];
int main()
{
//	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>w[i]>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			for(int k=0;k<=min(s[i],j/v[i]);k++)
					f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
	cout<<f[m];
	return 0;
}
