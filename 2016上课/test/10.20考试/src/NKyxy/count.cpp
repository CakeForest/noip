#include<cstdio>
#include<iostream>
using namespace std;
const long long mod=1000000007;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	long long ans=0;
	for(int i=1;i<n;i++) ans=(ans+(long long)i*i)%mod;
	if(k==1)
	{
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=(n&1 ? 1 : 2),nn=n-2;i<=nn;i+=2) ans=(ans+(long long)i*i)%mod;
	for(int i=1,nn=n-3;i<=nn;i++) ans=(ans+(long long)i*i*2)%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
