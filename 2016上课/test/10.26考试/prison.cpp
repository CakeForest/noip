#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int who[1200];
//f[i][j]第i个人到第j个人出狱时的肉 

int minn=99999999;
int a[1000],vis[1000],n,m;
bool pri[1200];
void dfs(int t){
	if(t==m+1){
		int cnt=0;
		memset(pri,0,sizeof(pri));
		for(int i=1;i<=m;i++){
			pri[a[i]]=true;
			int now=a[i]-1;
			while(now>0&&!pri[now]){
				now--;cnt++;
			}
			now=a[i]+1;
			while(now<=n&&!pri[now]){
				now++;cnt++;
			}
		}
		minn=min(minn,cnt);
		return;
	}
	
	for(int i=1;i<=m;i++)
		if(!vis[i]){
			vis[i]=1; a[t]=who[i];
			dfs(t+1);
			vis[i]=0;
		}
	
}

int main(){
	freopen("prison.in","r",stdin);
	freopen("prison.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&who[i]);
	sort(who+1,who+1+m);
	
	dfs(1);
	printf("%d",minn);
	/*for(int len=2;len<=m;len++)
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m-len+1;j++){
				
				
			}*/
	return 0;
}
