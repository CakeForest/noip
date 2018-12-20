#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX=10000000;
int prime[MAX],vis[MAX],cnt;
int method_one(int n){//eratosthenes筛法
	memset(prime,0,sizeof(prime));
	memset(vis,0,sizeof(vis));
	cnt=0;
	int m=sqrt(n+0.5);
	int i=2;
	for(;i<=m;i++)
		if(!vis[i]){
			prime[++cnt]=i;
			for(int j=i*i;j<=n;j+=i) vis[j]=1;
		}
	for(;i<=n;i++)
		if(!vis[i]) prime[++cnt]=i;
}

int method_two(int n){
	memset(prime,0,sizeof(prime));
	memset(vis,0,sizeof(vis));
	cnt=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*prime[j]>n) break;//筛除大小超过规定大小 
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;//将要筛的数已经被筛除 
		}
	}
}


void print_out(){
	for(int i=1;i<=cnt;i++)
		printf("%d ",prime[i]);
	printf("\n\n");
}
int main(){
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	method_one(n);
	print_out();
	
	method_two(n);
	print_out();
	return 0;
}
