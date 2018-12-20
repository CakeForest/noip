#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int v,n,a[40],f[35][20020];
int main()
{
//	freopen("in.txt","r",stdin);
	cin>>v>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=20000;j++)
			if(a[i]>j)
				f[i][j]=f[i-1][j];
			else if(j-f[i-1][j]<j-f[i-1][j-a[i]]-a[i])
				f[i][j]=f[i-1][j];
			else
				f[i][j]=f[i-1][j-a[i]]+a[i];
	cout<<v-f[n][v];
	
	return 0;
}
