#include<cstdio>
#include<iostream>
using namespace std;
const long long mod=1000000007;

long long n,k,ans;

int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>k;
    if(k==1){
    	n--;
    	ans=n*(n+1)*(2*n+1)/6%mod;
    	cout<<ans<<endl;
	}
	else {
		long long cnt=0;
		for(long long i=3;i<=n;i++){
			long long t=i-2;
			(cnt+= (t*(t+1)*(2*t+1)/6))%=mod;
		}
		n--;
		ans=n*(n+1)*(2*n+1)/6%mod;
		cout<<(ans+cnt)%mod<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

