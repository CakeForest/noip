#include<cstdio>
#define mod 1000000007
typedef long long LL;
LL ans;
int main(){
	int n,k,i,j;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++){
		ans+=i*i;
		ans%=mod;
	}
	if(k==2){
		for(j=1;j<n-1;j++)
			for(i=1;i<n-j;i++){
				ans+=i*i;
				ans%=mod;
			}
	}
	printf("%lld",ans);
	return 0;
}
