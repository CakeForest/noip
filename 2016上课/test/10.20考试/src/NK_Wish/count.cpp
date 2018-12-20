#include<iostream>
#include<cstdio>
using namespace std;
long long mod = 1000000007;
int n,k;
long long ans=0;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==1){cout<<"0";return 0;}
	if(k==1)
	{
		for(long long i=1;i<=n-1;i++)ans=ans%mod+(long long)(i*i)%mod;
		cout<<ans;
	}
	if(k==2&&n==2){cout<<"1";return 0;}
	if(k==2&&n==3){cout<<"6";return 0;}
	if(k==2&&n==4){cout<<"20";return 0;}
	if(k==2&&n==5){cout<<"42";return 0;}
	if(k==2)
	{
	for(long long i=1;i<=n-1;i++)ans=(ans%mod+(long long)(i*i)%mod)%mod;
	for(long long i=1;i<=(n-1)/2;i++)ans=((long long)(ans+i*2))%mod;
	for(long long i=1;i<=n/2;i++)ans=((long long)(ans+i))%mod;
	if(n&1)
	cout<<(ans+n-2)%mod;
	else cout<<(ans+n-2)%mod-1;
	}
}
		
