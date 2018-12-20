#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=40000;
struct node{
	int x,y;
}HashTable[1000000];
int Hasht[1000000];
bool vis[MAX];
int match[MAX],game[300][300],n,m,t;
int bex[300][300],bey[300][300];
int first[MAX],nxt[MAX],go[MAX],arcnum;

int Hash1(int x,int y){
	return (x*y*2 +233)%999999;
}

int Hash2(int x,int y){
	return (x*y*y*3 +3)%999999;
}

void Insert(int x,int y,node a){
	int t1=Hash1(x,y),t2=Hash2(x,y);
	while(Hasht[t1]) t1=(t1+233)%999999;
	Hasht[t1]=t2;
	HashTable[t1].x=a.x;
	HashTable[t1].y=a.y;
}

node Get(int x,int y){
	int t1=Hash1(x,y),t2=Hash2(x,y);
	while(Hasht[t1]!=t2) t1=(t1+233)%999999;
	return HashTable[t1];
}

void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

bool dfs(int u){
	vis[u]=1;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		int w=match[v];//v的匹配点 
//如果当前结点未配对 或者当前配对的结点还可以找到增广路 
		if(w<0||!vis[w]&&dfs(w)){ 
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;
}

int solve(){//二分图匹配 
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=t;i++)
		if(match[i]<0){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
	return ans;
}

int main(){
	freopen("guards.in","r",stdin);
//	freopen("guards.out","w",stdout);
	
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&game[i][j]);
	
	int cnt=0; t++;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(game[i][j]==2){
				if(cnt) t++,cnt=0;
			}
			else bex[i][j]=t,cnt++;
		}
		if(cnt) t++,cnt=0;
	}
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(game[i][j]==2){
				if(cnt) t++,cnt=0;
			}
			else bey[i][j]=t,cnt++;
		}
		if(cnt) t++,cnt=0;
	}
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			node a;
			a.x=i; a.y=j;
			Insert(bex[i][j],bey[i][j],a);
		}
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(game[i][j]==0){
				addarc(bex[i][j],bey[i][j]);
				addarc(bey[i][j],bex[i][j]);
			}
		}
	printf("%d\n",solve());
	
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=t;i++)
		if(match[i]>0&&!vis[i]){
			vis[i]=vis[match[i]]=true;
			node t=Get(i,match[i]);
			printf("%d %d\n",t.x,t.y);
		}
	
	return 0;
}
