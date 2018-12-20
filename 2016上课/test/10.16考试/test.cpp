#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100],vis[100];
int f[100],n;
void dfs(int cnt){
	if(cnt==n+1){
		int sum=0;
		for(int i=1;i<=n-1;i++)
			if(a[i]<a[i+1]) sum++;
		f[sum]++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("ip.in","r",stdin);
//	freopen("ip.out","w",stdout);
	
	scanf("%d",&n);
	dfs(1);
	printf("f[i]:");
	for(int i=0;i<=n-1;i++) printf("%d ",f[i]);
	
	
	return 0;
}
