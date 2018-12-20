#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
//map[][]存放是否为基站 t[][]存放是否被遍历 
int h,w,map[50][50],t[50][50],move_x[4]={0,0,1,-1},move_y[4]={1,-1,0,0},n;
int first[MAX],nxt[MAX],go[MAX],arcnum=1;
int match[MAX],vis[MAX];
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}
void SearchMap(int x,int y){
	if(t[x][y]) return;
	t[x][y]=1;
	if(!map[x][y]) return;
	int newx,newy;
	for(int i=0;i<=3;i++){
		newx=x+move_x[i];//下一个要遍历的点的xy值 
		newy=y+move_y[i];
		if(!t[newx][newy]&&map[newx][newy]){
			addarc(map[x][y],map[newx][newy]);
			addarc(map[newx][newy],map[x][y]);
		}
	}
}

int DFS(int u){
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p],w=match[v];
		if(w<0||!vis[w]&&DFS(w)){
			match[u]=v;
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int MaxFlow(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=n;i++)
		if(match[i]<0){
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ans++;
		}
	return ans;
}
int main(){
	freopen("in.txt","r",stdin);
	int k; char c;
	scanf("%d",&k);
	while(k--){
		memset(map,0,sizeof(map));
		memset(t,0,sizeof(t));
		n=0;
		scanf("%d%d",&h,&w);
		for(int i=1;i<=h;i++){
			getchar();
			for(int j=1;j<=w;j++){
				c=getchar();
				if(c=='*');
				map[i][j]=++n;
			}
		}
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				SearchMap(i,j);
		printf("%d\n",MaxFlow());
	}
	
	return 0;
}
