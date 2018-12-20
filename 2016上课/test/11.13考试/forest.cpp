#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 99999999
using namespace std;
const int MAX=500000;
long long mod=1e9+7;
//每次增加一条边，并算出直径
struct node{
	int x,y;
}t[MAX];
int inside,n;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int val[MAX],list[MAX],minn[MAX];
long long out[MAX],sum;
bool vis[MAX],exist[MAX];
queue <int> q;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	nxt[++arcnum]=first[b];
	first[b]=arcnum;
	go[arcnum]=a;
}

void bfs(int s){//遍历整棵树 
	memset(exist,0,sizeof(exist));
	q.push(s); inside=0;
	do{
		int u=q.front(); q.pop();
		vis[u]=true;
		for(int p=first[u];p;p=nxt[p]){
			int v=go[p];
			if(!exist[v]){
				exist[v]=true;
				inside++;
				q.push(v);
			}
		}
	}while(!q.empty());
	exist[s]=false; inside--;
}

int prim(int s){//最大生成树 
	memset(minn,0,sizeof(minn));
	bfs(s);//确定一棵树的所有节点 
	minn[s]=val[s];
	int cnt=minn[s];
	for(int p=first[s];p;p=nxt[p]){
		int v=go[p];
		minn[v]=minn[s]+val[v];
	}

	for(int i=1;i<=inside;i++){
		int chose=0,minj=-1;
		for(int i=1;i<=n;i++)
			if(exist[i]&&minn[i]>minj)
				chose=i,minj=val[i];
//		if(!chose) break;
		exist[chose]=false;
		cnt+=minj;
		for(int p=first[chose];p;p=nxt[p]){
			int v=go[p];
			if(exist[v]&&minn[chose]+val[v]>minn[v])
				minn[v]=minn[chose]+val[v];
		}
	}
	return cnt;
}

int main(){
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);//每个点权值 
	for(int i=1;i<=n-1;i++)
		scanf("%d%d",&t[i].x,&t[i].y);//边相连 
	for(int i=n-1;i>=1;i--)
		scanf("%d",&list[i]);//删除边的顺序 
	for(int i=0;i<=n-1;i++){//i的初始值为0 
		memset(vis,0,sizeof(vis)); sum=1;
		if(i)//第一次不需要加边 
			addarc(t[list[i]].x,t[list[i]].y);
		for(int j=1;j<=n;j++)
			if(!vis[j])//如果j属于的树未被遍历 
				sum=(sum%mod)*(prim(j)%mod)%mod;
		out[i]=sum;
	}
	for(int i=n-1;i>=0;i--)
		printf("%lld\n",out[i]);
	
	return 0;
}
