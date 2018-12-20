#include<stdio.h>
#include<string.h>
long long int n,k,i;
int one(int m)
{
	long long int num=0;
	for(i=1;i<m;i++)
	{
		num=(num+(i*i))%1000000007;
	}
	return num;
}
int two(int m)
{
	long long int num=0;
	num+=one(m);
	long long int js=0;
	for(i=(m-3);i>=1;i--)
	{
		js+=i*i;
		js=js%1000000007;
//		printf("%lld\n\n",js);
	}
	num+=(js*2)%1000000007;
	for(int i=m-2;i>=1;i=i-2)
	{
		num+=i*i;
		num=num%1000000007;
	}
	return num;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long int w;
	if(k==1)
	{
		w=one(n);
	}
	else
	{
		w=two(n);
	}
	printf("%lld",w);
}
