#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=99999999;
int n;
int movex[4]={-1,0,1,0},movey[4]={0,1,0,-1};
int f[4][120][120];
char map[120][120];
//0вС 1ио 2ср 3об 
struct node{
	int x,y;
}s,t;

bool judge(int x,int y){
	return !(x<=0||x>n||y<=0||y>n||map[x][y]=='x');
}

int change(int k){
	if(k<0) return k=k+4;
	return k;
}

void dfs(int x,int y){
	
	for(int k=0;k<=3;k++){
		int tx=x+movex[k],ty=y+movey[k];
		if(!judge(tx,ty)) continue;
		int t=f[k][tx][ty];
		f[k][tx][ty]=min(min(f[change(k-1)][x][y]+1,f[change(k+1)][x][y]+1),f[k][x][y]);
		if(t!=f[k][tx][ty]) dfs(tx,ty);
	}
	
}

int main(){
	freopen("ddos.in","r",stdin);
	freopen("ddos.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=n;j++){
			for(int k=0;k<=3;k++)
				f[k][i][j]=INF;
			scanf("%c",&map[i][j]);
			if(map[i][j]=='A'){
				s.x=i;s.y=j;
			}
			if(map[i][j]=='B'){
				t.x=i;t.y=j;
			}
		}
	}
	for(int i=0;i<=3;i++) f[i][s.x][s.y]=0;
	dfs(s.x,s.y);
	
	int ans[5];
	for(int i=0;i<=3;i++) ans[i]=f[i][t.x][t.y];
	sort(ans,ans+4);
	if(ans[0]==INF) printf("-1");
	else printf("%d",ans[0]);
	
	return 0;
}
