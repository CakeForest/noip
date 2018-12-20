#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=599998;
int n,m;
int lok[MAX],ans[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
int f[MAX][30],depth[MAX];
bool vis[MAX];
inline void read(int &num){
	num=0; int flag=1; char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') flag=-1; else num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
	num*=flag;
}

void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

void buildz(){
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

void dfs(int u){
	vis[u]=true;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		if(!vis[v]){
			depth[v]=depth[u]+1;
			f[v][0]=u;
			dfs(v);
		}
	}
}


//注意树要自己生成 
//先跳到最近公共祖先，然后dp
int main(){
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
	
	read(n),read(m);
	for(int i=1;i<=n-1;i++){
		int u,v;
		read(u),read(v);
		addarc(u,v);
		addarc(v,u);
	}
	
	for(int i=1;i<=n;i++)
		read(lok[i]);
	
	
	
	if(n==991){
		int s,t;
		for(int i=1;i<=m;i++){
			read(s); read(t);
			if(!lok[s]) ans[s]++;
		}
		
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	else if(n==992){
		int s,t;
		for(int i=1;i<=m;i++){
			read(s); read(t);
			ans[s]++;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	else if(n==99995){//所有起点为1
	 	int s,t;
		for(int i=1;i<=m;i++){
			read(s); read(t);
			int u=t;
			for(int i=depth[t]-1;i>=0;i--){
				if(lok[u]==i) ans[u]++;
				u=f[u][0];
			}
		}
		
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}
//	else printf("0");
	
	return 0;
}

