#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXSIZE=20;
int n,a[MAXSIZE],f[MAXSIZE],maxx=-1;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=i-1;j>=1;j--)
			if(a[i]<=a[j])
				f[i]=max(f[i],f[j]+1);
		maxx=max(maxx,f[i]);
	}
	cout<<maxx;
	
}
