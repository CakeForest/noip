#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int mod=10007;
int a,b,k,n,m;
int f[1020][1020];
int qpow(int a,int b){
	int r=1;
	int base=a%mod;
	while(b){
		if(b&1) r=(r*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return r;
}

int main(){
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	
	cin>>a>>b>>k>>n>>m;
	for(int i=0;i<=k;i++){
		f[i][0]=1;
		for(int j=1;j<=i;j++)//从1开始循环 
			f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
	}f[0][0]=0;
	
	printf("%d",(((f[k][k-n]*qpow(a,n))%mod)*qpow(b,m))%mod);
	
//	printf("%d",qpow(2,31));
	
/*	cout<<endl<<endl;
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}	*/
	
	return 0;
}
