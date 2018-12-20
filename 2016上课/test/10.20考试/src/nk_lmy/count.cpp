#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define mod 1000000007

long long n;
int k;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	cin>>n>>k;
	
	long long ans=0;
	ans=n;
	ans=ans*(n-1)%mod;
	ans=ans*(2*n-1)%mod;
	ans=ans/6;
	if(k==1){
		printf("%I64d",ans);
		return 0;
	}
	int i;
	long long tmp=0;
	for(i=1;i<=n;i++){
		tmp=(n-i)*(n-i)%mod;
		tmp=tmp*(i-1)%mod;
		ans+=tmp;
		ans%=mod;
	}
	printf("%I64d",ans);
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
