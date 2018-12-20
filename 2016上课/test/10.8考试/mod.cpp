#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;

void exgcd(LL a,LL b,LL c,LL &x,LL &y){
	if(!a){ x=0; y=c/b; }
	else{ exgcd(b%a,a,c,x,y); y=x; x=(c-b*y)/a; }
}

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	
	long long x,y,a,b;
	scanf("%lld%lld",&a,&b);
	exgcd(a,-b,1,x,y);
	
	while(x<=0) x+=b;
	printf("%lld",x);
	
	return 0;
}

