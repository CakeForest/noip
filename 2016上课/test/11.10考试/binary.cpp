#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int f[2][5000000],sum[2];
int T,temp[4],len;
bool now; int aim;
void dfs(int id,int t,int cnt){
	if(cnt==aim){
		f[now][++sum[now]]=id;
		return;
	}
	if(t==len+1) return;
	if(aim-cnt>1+len-t) return;
	dfs(id|(1<<(t-1)),t+1,cnt+1);
	dfs(id,t+1,cnt);
}

int calc(int t){
	int cnt=0;
	while(t) cnt+=t&1,t>>=1;
	return cnt;
}

int calclen(int t){
	int ans=30;
	while(!(t>>(ans-1))) ans--;
	return ans;
}

int main(){
	freopen("binary.in","r",stdin);
//	freopen("binary.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		sum[0]=sum[1]=0;
		scanf("%d%d%d",&temp[0],&temp[1],&temp[2]);
		temp[3]=99999999;
		sort(temp,temp+4);
		len=calclen(temp[2]);
	//	printf("%d",len);
		now=0; aim=calc(temp[0]);
		dfs(0,1,0);
		now=1; aim=calc(temp[1]);
		dfs(0,1,0);
	//	printf("%d %d",sum[0],sum[1]);
		sort(f[0]+1,f[0]+1+sum[0]);
		sort(f[1]+1,f[1]+1+sum[1]);
		
		int ans=99999999; aim=calc(temp[2]);
		for(int i=1;i<=sum[0];i++){
			for(int j=1;j<=sum[1];j++){
				int t=f[0][i]+f[1][j];
				if(t>ans) break;
				if(calc(t)==aim&&calclen(t)<=len){
					ans=t;
					break;
				}
			}
		}
		if(ans==99999999) printf("-1\n");
		else printf("%d\n",ans);
	}
	
	
	return 0;
}
