#include<cstdio>
using namespace std;
int pow_calc(int a,int b,int mod){
	int r=1,base=a%mod;
	while(b){
		if(b&1) r=(r*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return r;
}
int main(){
//	freopen("in.txt","r",stdin);
	int a,b,c;//º∆À„a^b%c
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",pow_calc(a,b,c));
	
	return 0;
}
