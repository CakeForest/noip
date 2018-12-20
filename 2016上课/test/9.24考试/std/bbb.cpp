#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000100
using namespace std;
typedef long long ll;
ll n,p,q,x,y;
char s[N];
ll sum[N<<1];
int que[N<<1];
ll mi[N];
int calc[N];
ll allsum;
int main()
{
	freopen("bbb.in","r",stdin);
	freopen("bbb.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&n,&p,&q,&x,&y);
    scanf("%s",s+1);
    for(int i=n<<1;i>n;i--)sum[i]=sum[i+1]+(s[i-n]=='+'?1:-1);
    allsum=sum[n+1];
    for(int i=n;i>=1;i--)sum[i]=sum[i+1]+(s[i]=='+'?1:-1);
    int head=1,tail=0;
    for(int i=n<<1;i>=1;i--)
    {
        while(head<=tail&&sum[i]>sum[que[tail]])tail--;
        que[++tail]=i;
        while(head<=tail&&que[head]-i>=n)head++;
        if(i<=n)mi[i]=sum[i]-sum[que[head]];
    }
    ll ans=0x7f7f7f7f7f7f7f7fll;
    ll nowtmp;
    ll tmpcalc=(q-p-allsum)/2;
    calc[1]=1;
    for(int i=2;i<=n;i++)calc[i]=n-i+2;
    for(int i=0;i<n;i++)
    {
        nowtmp=(ll)i*y+abs(tmpcalc)*x;
        mi[calc[i+1]]+=p+max(tmpcalc,0ll)*2ll;
        if(mi[calc[i+1]]<0)
            nowtmp+=2*x*((1-mi[calc[i+1]])/2ll);
        ans=min(ans,nowtmp);
    }
    printf("%lld\n",ans);
}
