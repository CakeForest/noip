#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int mod = 1000000007;
int n,k; 

typedef long long ll;

int sol1(){
	int ans = 0;
	for(int i=1;i<=n-1;i++){
		ans = (ans+(ll)(n-i)*(n-i))%mod;
	}
	return ans;
}	

int sol2(){
	int ans = 0;
	for(int i=2;i<=n-1;i++){
		ans = (ans+((ll)(n-i)*(n-i)%mod)*(i-1)%mod)%mod;
	}
	return ans;
}

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	int ans = 0;
	ans = sol1();
	if(!(k&1)) ans = (ans + sol2()) % mod;
	cout<<ans<<endl;
}
