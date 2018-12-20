#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

long long ansa,ansb;

long long pw(long long x){
    return ((x%1000000007)*(x%1000000007))%1000000007;
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	if(k==1)
	{
		for(int i=2;i<=n;i++)
			ansa=(ansa+pw(i-1))%1000000007;
		printf("%lld",ansa);
	}
	if(k==2)
	{
		for(int i=2;i<n;i++)
		{
			ansb=(ansb+pw(i-1))%1000000007;
			ansb=(ansb+2*pw(i-2))%1000000007;
		}
		ansb=(ansb+pw(n-1))%1000000007;
		ansb=(ansb+pw(n-2))%1000000007;
		printf("%lld",ansb);
	}
	return 0;
}
