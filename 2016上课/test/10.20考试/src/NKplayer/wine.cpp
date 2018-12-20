#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
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
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	cout<<"Impossible";
}
