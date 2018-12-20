#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

LL mod(LL a,LL b,LL c){//a^b mod c
	LL ans=1,base=a%c;
	while(b){
		if(b&1) ans=(ans*base)%c;
		base=(base*base)%c;
		b>>=1;
	}
	return ans;
}

int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	LL n,m,k,x;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	LL move=(x+mod(10,k,n)*m)%n;
	printf("%lld",move);
	
	return 0;
}
