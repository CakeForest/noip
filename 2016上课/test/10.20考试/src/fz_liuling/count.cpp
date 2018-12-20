#include <cstdio>
const int mod=1000000007;
long long fc[100001];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	fc[1]=1;
	for(int i=2;i<=100000;i++) fc[i]=(fc[i-1]+((i*i)%mod))%mod;
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1){
		printf("0"); return 0;
	}
	if(n==2){
		printf("1"); return 0;
	}
	if(k==1) printf("%lld",fc[n-1]);
	else printf("%lld",(fc[n-1]+((n-2)*(n-2))%mod+(fc[n-3]*2)%mod)%mod);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
