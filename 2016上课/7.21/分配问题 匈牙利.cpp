#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
int n,k,m,a,b;
int first[MAX],nxt[MAX],go[MAX],vis[MAX],match[MAX],arcnum=1;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int DFS(int u){
	vis[u]=1;
	for(int p=first[u];p!=0;p=nxt[p]){
		int v=go[p],w;
		w=match[v];
		if(w<0||!vis[w]&&DFS(w)){
//�����vû�б�ƥ�䣬��ôֱ��ƥ��u��v 
//�����vδ����������ôDFS(w)������ҵ�����·��ƥ��u��v		
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int MaxFlow(){
	int ans=0,f;
	memset(match,-1,sizeof(match));//ÿ��  
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));//���� 
		if(!vis[i]&&DFS(i))	ans++;
	}
	return ans;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		addarc(a,n+b);
		addarc(n+b,a);
	}
	printf("%d",MaxFlow());
	
	return 0;
}
