#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int vis[10000000],prime[1000000];
int main(){
//	freopen("in.txt","r",stdin);
	int n,m,cnt=1;
	cin>>n;
	m=sqrt(n+0.5);
	memset(vis,0,sizeof(vis));
	memset(prime,0,sizeof(prime));
	int i=2;
	for(;i<=m;i++)
		if(!vis[i]){
			prime[cnt++]=i;
			for(int j=i*i;j<=n;j+=i) vis[j]=1;
		}
	for(;i<=n;i++)
		if(!vis[i]) prime[cnt++]=i;

	for(int i=1;i<cnt;i++) cout<<prime[i]<<" ";
	
	return 0;
}
