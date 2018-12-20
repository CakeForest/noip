#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 99999999
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int dist[MAX],n,m;
queue <int> q;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int dfs(int u,int t,int minc){
	if(u==t) return minc;//�����յ㣬���ش�ʱ����������� 
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p],f;
		if(dist[v]==dist[u]+1&&flow[p]>0)
			if(f=dfs(v,t,min(minc,flow[p]))){//���㣬������СΪ���бߵ���̴�С 
				flow[p]-=f;//���� 
				flow[p^1]+=f;
				return f;//�������ӵ�������С 
			}
	}
	return 0;//�޷����� ����0 
}

bool bfs(int s,int t){
	for(int i=1;i<=n;i++) dist[i]=INF;
	q.push(s); dist[s]=0;
	do{
		int u=q.front(); q.pop();
		for(int p=first[u];p!=0;p=nxt[p]){
			int v=go[p];
			if(dist[v]==INF&&flow[p]>0){//����flowһ��Ҫ����0���ܼ��� 
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}while(!q.empty());
	return dist[t]<INF;//���s��t��Ȼ������·���򷵻��� 
}

int dinic(int s,int t){
	int ans=0,f;
	while(bfs(s,t))//�����Ȼ������· 
		while(f=dfs(s,t,INF))//�����������������������´� 
			ans+=f;
	return ans;
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
		addarc(b,a,-c);
	}
	printf("%d",dinic(1,n));
}
