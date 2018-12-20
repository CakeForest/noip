#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[22],f[3020];

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=m;j++)
			f[j]=f[j]+f[j-a[i]];
	cout<<f[m];
	
	return 0;
}
