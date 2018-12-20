#include <iostream>
using namespace std;
const int mod=1000000007;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,k,f1=0,f2=0;
	cin>>n>>k;
	for(long long i=1;i<n;i++){
		f1=(f1+i*i)%mod;
		f2=(f2+f1)%mod;
	}
	if(k==1) cout<<f1<<endl;
	else cout<<f2<<endl;
	return 0;
}
