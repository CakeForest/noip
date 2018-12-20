#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;
inline void _in(int &x)
{
	char t=getchar();bool mark=0;
	for(;!isdigit(t);t=getchar())if(t=='-')mark=1;
	for(x=0;isdigit(t);x=x*10+t-'0',t=getchar());
	x=mark?-x:x;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,k,i,ans1=0,ans2=0;
	cin>>n>>k;
	for(i=2;i<=n;++i){
	    ans2=(ans2+ans1)%mod;
	    ans1=(ans1+(i-1)*(i-1))%mod;
    }
	if(k==1)cout<<ans1;
	else cout<<(ans1+ans2)%mod;
}
