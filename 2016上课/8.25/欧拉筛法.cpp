#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int MAX=100000;
int prime[MAX],vis[MAX],cnt;
int main(){
//	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime[cnt++]=i;
		for(int j=0;j<cnt;j++){
			if(i*prime[j]>MAX) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	
	for(int i=0;i<cnt;i++) cout<<prime[i]<<" ";
	
	return 0;
}
