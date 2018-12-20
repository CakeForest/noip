#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL p=1000000007;
const LL inv1=166666668;
const LL inv2=83333334;
template<class T> 
inline void Read(T &x,bool mark=0){ 
    char t=getchar(); 
    for(;t<'0'||t>'9';t=getchar()) if(t=='-') mark=true; 
    for(x=0;t>='0'&&t<='9';x=(x<<1)+(x<<3)+t-'0',t=getchar()); 
    x=mark?-x:x; 
} 
LL n,k,ans;
LL montgomery(LL a,LL b,LL c){
	LL ans=1;
	a=(a*a)%c;
	while(b){
		if(b&1) ans=(ans*a)%c;
		b>>=1;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	Read(n);
	Read(k);
	if(k==1){
		ans=((n-1)*n%p)*(2*n-1)%p*inv1%p;
		printf("%I64d\n",ans);
	}
	else if(k==2){
		ans=n*n%p*(n-1)%p*(n+1)%p*inv2%p;
		printf("%I64d\n",ans);
	}
}

