#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int loc[120],p[120];

int Work(int n,int k)
{
	int f[120]={0},maxx=-1;
	for(int i=1;i<=n;i++)
	{
		f[i]=p[i];
		for(int j=i-1;j>=1;j--)
			if(loc[i]-loc[j]>k)
				f[i]=max(f[i],f[j]+p[i]);
		maxx=max(maxx,f[i]);
	}
	return maxx;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int t; cin>>t;
	for(int m=1;m<=t;m++)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>loc[i];
		for(int i=1;i<=n;i++)
			cin>>p[i];
		cout<<Work(n,k)<<endl;
	}
	
	return 0;
}
