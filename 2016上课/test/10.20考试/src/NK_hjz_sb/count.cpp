#include<stdio.h>
#define ll long long
ll n,re,ans=0;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%I64d%I64d",&n,&re);
		for(ll i=n-1;i>=1;i--){
			ans+=(i*i);
			ans%=1000000007;
		}
	if(re==1){
		printf("%I64d",ans);
		return 0;
	}
	
	if(re==2){
		ll y;
		if(n>=3){
			y=n-2;
			ans+=y*y;
			ans%=1000000007;
		}
		for(ll i=4;i<=n;i++){
			y=n-(i-1);
			if(!(1&i))ans=ans+y*y*2;//Å¼Êý 
			else ans=ans+y*y*3;
			ans%=1000000007;
		}
		printf("%I64d",ans);
		return 0;
	}
}
