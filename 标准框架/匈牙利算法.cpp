#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//匈牙利算法
const int MAX=100000;
int match[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

bool dfs(int u){
	vis[u]=true;//标记已经遍历 
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		int w=match[v];//与v匹配的点 
		/*
			如果当前无与v匹配的点
		或者与v匹配的点未被遍历，然后被遍历后有增广路 
		*/
		if(!w||!vis[w]&&dfs(w)){//此处容易出错 
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;//记得在无增广路时输出false 
}

int solve(){
	int ans=0;
	memset(match,0,sizeof(match));//匹配路径清空 
	for(int i=1;i<=n;i++)
		if(!match[i]){//如果i还没匹配 
			memset(vis,0,sizeof(vis));//清空vis 
			if(dfs(i)) ans++;//进行dfs 
		}
	return ans;
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
	}
	printf("%d",solve());
	
	return 0;
}
