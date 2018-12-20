#include<stdio.h>
#include<algorithm>
#define maxn 20005
using namespace std;
//0 第一个 1 第二个 
int n,m,nums[maxn],f[maxn][maxn];
int dp(int dep,int u){
	if(dep>m)return 0;
	if(u==0){
		f[dep][u]+=nums[dep*2-1];
		int y=max(dp(dep+1,u),dp(dep+2,0));
		y=max(y,dp(dep+2,1));
		f[dep][u]+=y; 
		return f[dep][u];
	}
	else if(u==1){
		f[dep][u]+=nums[dep*2];
		int y=max(dp(dep+1,u),dp(dep+2,0));
		y=max(y,dp(dep+2,1));
		f[dep][u]+=y; 
		return f[dep][u];
	}
}
inline int _read(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int t=0;
	while(c<='9'&&c>='0')t=t*10+c-'0',c=getchar();
	return t;
}

int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	n=_read();m=_read();
	if((n/2)<m){
		printf("%s","Error!");
		return 0;
	}
	for(int i=1;i<=n;i++){
		nums[i]=_read();
	}
	dp(1,1);
	printf("%d",f[1][1]);
	
}
