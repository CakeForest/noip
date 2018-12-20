#include<stdio.h>
#define ll long long
const ll mod=1000000007;
int s;
void k1(int n){
	ll q=0;
	for(int i=1;i<n;i++)
	q=(q+i*i)%mod;
	s=q;
}
void k2(int n)
{
	ll q=0,i;
	for(i=n-2;i>=1;i--)
		q=q+i;
	q=(q<<1)-(n-2); 
	if(n%2==0)
	 s=s+((q+2)*(q/2))/2;
	else
	{
	  s=s+((q+3)*(q/3))/2;
		s++;
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	k1(n);
	if(k==1)
	  printf("%lld",s);
	else if(k==2)
	{
		k2(n); printf("%lld",s);
	}
	return 0;
}
