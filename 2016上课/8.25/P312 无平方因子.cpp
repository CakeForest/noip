#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int MAX=1e6+10;
int prime[MAX],vis[MAX],cnt;

void CalcPrime(int n){
	cnt=1;
	memset(prime,0,sizeof(prime));
	memset(vis,0,sizeof(vis));
	int m=sqrt(n+0.5),i=2;
	for(;i<=m;i++){
		if(!vis[i]) prime[cnt++]=i;
		for(int j=i*i;j<=n;j++) vis[j]=1;
	}
	for(;i<=n;i++) prime[cnt++]=i;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,m,cnt=1;
	cin>>n>>m;
	
	CalcPrime(sqrt(m+0.5));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<cnt;i++){
		int pri=prime[i];
		for(long long j=2*n-n%pri;j<=m;j+=pri) vis[j%n]=1;
	}
	
	cnt=0;
	for(int i=0;i<=m%n;i++) cnt++;
	printf("%d",cnt);
	
	
	return 0;
}
