#include <stdio.h>
#define inf 1000000007
long long n,k;
long long easypyb(long long i)
{
	long long ret=i%inf;
	return (ret*ret)%inf;
}
long long hardpyb(long long i)
{
	//√€∑‰ªπ «≤ª√€∑‰£ø
	if(i==1) return 1;
	else return easypyb(i)+easypyb(hardpyb(i-1));
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long ans=0;
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<n;i++) ans+=easypyb(i);
	if(k==2) for(long long i=n-2;i>=1;i--) ans+=hardpyb(i);
	printf("%lld",ans);
	return 0;
}
