#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL calc(LL a,LL b,LL k){
	LL res=1,base=a%k;
	while(b){
		if(b&1) res=(res*base)%k;
		base=(base*base)%k;
		b>>=1;		
	}
	return res;
}

int main(){
	
	LL b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,calc(b,p,k));
	
}
