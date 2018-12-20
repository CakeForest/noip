#include <iostream>
using namespace std;
const long long MAXN = 1000005LL, MOD = 1000000007LL;
long long a[MAXN];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(k==1)cout<<((n-1)*n*(2*n-1)/6)%MOD;
	else
	{
	   a[2]=1LL;
	   for(long long i=3;i<=n;i++)
	   {
		  a[i]=a[i-1]+(i-1)*i*(2*i-1)/6;
		  a[i]%=MOD;
	   }
	   cout<<a[n]<<endl;
    }
	return 0;
}
