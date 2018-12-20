#include<cstdio>
#include<iostream>
#define mod 1000000007
using namespace std;
long long n,k,i,ans;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	for(i=2;i<=n;i++)
	{
		ans+=(i-1)*(i-1);
		ans%=mod;
		if(k==2&&i>=3)
		{
			ans+=(n+1-i)*(n+1-i)*(i-2);
			ans%=mod;
		}
	}
	cout<<ans;
}
