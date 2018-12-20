#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100002
#define mod 1000000007
#define inf 0x7FFFFFE
using namespace std;
typedef long long ll;
template<typename T>
inline void _r(T &d){char t=getchar();bool f=false;while(t<48||t>57){if(t==45)f=true;t=getchar();}for(d=0;t>=48&&t<=57;t=getchar())d=d*10+t-48;if(f)d=-d;}
ll n,k,ans,tmp;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ll i,j;
	_r(n);_r(k);
	for(i=1;i<n;i++)
	{
		tmp=(tmp+ans)%mod;
		ans=(ans+i*i)%mod;
	}
	if(k==2)printf("%I64d\n",(ans+tmp)%mod);
	else printf("%I64d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

