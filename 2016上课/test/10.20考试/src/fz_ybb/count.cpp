#include<cstdio>
using namespace std;
long long n,k,ans=0,p=1000000007;
long long w(int n)
{
	long long r=0;
	while(n>1){r+=n*n%p;n--;}
	return r;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	ans=w(n-2);
	if(k==1){ans=(ans+(n-1)*(n-1)+1)%p;printf("%d\n",ans);return 0;}
	ans=2*ans%p;ans=(ans+n-1+(n-1)*(n-1))%p;
	printf("%d\n",ans);
	return 0;
}
