#include<cstdio>
long long int ans1,ans2;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<n;i++)
		{
			ans1+=(n-i)*(n-i);
			ans1=ans1%1000000007;
		}
		printf("%lld\n",ans1%1000000007);
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			ans1+=(n-i)*(n-i);
			ans1=ans1%1000000007;
		}
		ans2+=ans1;
		ans2+=(n-2)*(n-2);
		for(int i=3;i<n;i++)
		{
			ans2+=(n-i)*(n-i)*2;
			ans2=ans2%1000000007;
		}
		printf("%lld\n",ans2%1000000007);
	}
	return 0;
}
