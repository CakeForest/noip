#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
long long n,m,p=1000000007;
inline void in(long long& x)
{  
    char tt=getchar();  
	bool mark=0;
    for(;tt<'0'||'9'<tt;tt=getchar()) if(tt=='-') mark=1;  
    for(x=0;'0'<=tt&&tt<='9';x=(x<<1)+(x<<3)+tt-'0',tt=getchar());  
    x=mark?-x:x;  
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long b,c,d,e,x,y,i,j,k,ans=0;
	in(n);in(k);
	for(i=1;i<=n;i++)
		{
			e=n-i;
			ans=(e+ans)%p;
			e--;
			ans=(ans+(1+e)*e%p)%p;
		}
	if(k==1)printf("%I64d",ans);
	else
	{
		cout<<(ans*10/7)%p;
	}
}
