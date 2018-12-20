#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
long long ans;
void dfs1()
{
	n--;
	ans+=(2*n + 1)*n*(n + 1) / 6;
}
void dfs2()
{
	dfs1();
	dfs1();
	
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	dfs1();
	if(k==2)dfs2();
	cout<<ans;
}
