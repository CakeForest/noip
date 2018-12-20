#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;//�����ͼ����� 
const int MAX=10000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int match[MAX],vis[MAX];
int n,m,k,b;
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
		if(w<0||!vis[w]&&DFS(w)){//Ѱ�Һ�v��ԵĽ�㣡�������� 
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

int MaxFlow(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=n;i++){//ö��ÿͷţ 
		if(match[i]>0) continue;//����Ѿ���ԣ��Ͳ������ 
		memset(vis,0,sizeof(vis));
		if(DFS(i)) ans++;
	}
	return ans;
}

int main(){
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&b);
			addarc(i,b+n);
			addarc(b+n,i);
		}
	}
	printf("%d",MaxFlow());
	
	
	return 0;
}
