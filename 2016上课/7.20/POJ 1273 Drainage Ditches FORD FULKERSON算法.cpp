#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=600;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum=1;
int vis[MAX];
void addarc(int a,int b,int c){//�ӱ� 
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;//��¼�ñ����� 
}

int Dfs(int u,int t,int minc){//���u���յ�t������·����������СΪminc
 	if(u==t) return minc;
 	vis[u]=1;
 	for(int p=first[u];p!=0;p=nxt[p]){
 		int v=go[p];
 		if(!vis[v]&&flow[p]>0){
 			int f=Dfs(v,t,min(minc,flow[p]));
 			if(f>0){
 				flow[p]-=f;//����߼�ȥ��������� 
 				flow[p^1]+=f;//����߼������������
 				/* nΪ����ż��Ȼ������ôn^1=n+1;(n+1)^1=n    */
				return f; 
 			}
 		}
 	}
	return 0;//���������������������0 
}

int MaxFlow(int s,int t){
	int ans=0;
	while(1){
		memset(vis,0,sizeof(vis));
		int f=Dfs(s,t,99999999);
		if(f<=0) return ans;
		ans+=f;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,a,b,c;
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(first,0,sizeof(first));
		memset(flow,0,sizeof(flow));
		arcnum=1;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			addarc(a,b,c);//���������Ϊc 
			addarc(b,a,0);//���������Ϊ0 
		}
		printf("%d\n",MaxFlow(1,n));
	}
	
	return 0;
}
