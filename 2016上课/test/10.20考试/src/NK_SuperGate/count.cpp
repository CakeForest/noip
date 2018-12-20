#include<cstdio>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1000000007;
LL n,k;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	LL i,j,sum;
	sum=(((n-1)*n)*(2*n-1)/6)%mod;
	if(k==1){
	    cout<<sum;	
	    return 0;
	}
	for(i=n-2;i;i--)
	    sum=(sum+i*i%mod*(n-i-1)%mod)%mod;
	cout<<sum;
}
/*
98765 2
*/
