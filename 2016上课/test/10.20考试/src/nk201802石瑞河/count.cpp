#include<iostream>   
#include<algorithm>   
#include<cstring>   
#include<cstdlib>   
#include<cstdio>   
#include<vector>   
#include<cmath>   
#include<queue>   
#define LL  long long  
using namespace std;
LL n,k;
const LL MOD=1000000007;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	LL p=(n-1)*(n)*(2*n-1)/6%MOD; 
	if(k==1)
	{
		cout<<p;
		return 0;
	}
	else 
	{
		LL i,ans=0;
		for(i=1;i<=n;i++)
		   ans+=(n-i)*(n-i)*(i-1)%MOD;
		ans+=p;
		ans%=MOD;
		cout<<ans;
	}
}
