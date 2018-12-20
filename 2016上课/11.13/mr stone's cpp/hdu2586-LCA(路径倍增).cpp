#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 40005
using namespace std;
struct node{
	int go,len;
	node(int a,int b):go(a),len(b){}
};
vector<node> tree[MAXN];
int n,m,root,dis[MAXN],depth[MAXN];
int father[MAXN][32];//father��ʾi���������2^j�η����ܴﵽ�ĵ�
bool visit[MAXN],rot[MAXN];
void dfs(int u){//dfs������ 
    visit[u]=true;
    for(int i=0;i<tree[u].size();i++){
        int v=tree[u][i].go;
        if(!visit[v]){
            depth[v]=depth[u]+1;//�޸���� 
            dis[v]=dis[u]+tree[u][i].len;//�޸Ľ�㵽���ڵ����� 
            dfs(v);
        }
    }   
}

void buildz(){//������������ 
	for(int j=1;j<=30;j++)//����ָ�� 
		for(int i=1;i<=n;i++)//������� 
			father[i][j]=father[father[i][j-1]][j-1];
}

int LCA(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);//v�����u���� 
	int dc=depth[u]-depth[v];
	for(int i=0;i<30;i++){
		if((1<<i)&dc)
			u=father[u][i];
	}
	if(u==v) return u;
	for(int i=29;i>=0;i--)
		if(father[u][i]!=father[v][i]){
			u=father[u][i];
			v=father[v][i];
		}
	return father[u][0];
}

int main(){
	int i,a,b,c,ance;
	int tcase;
	freopen("hdu2586.txt","r",stdin);
	scanf("%d",&tcase);
	while(tcase--){
		memset(visit,0,sizeof(visit));
		memset(rot,0,sizeof(rot));
		memset(father,0,sizeof(father));
		for(i=1;i<=n;i++){
	 		tree[i].clear();
			dis[i]=0;//��ʼ�� 
	 	}
	 	scanf("%d%d",&n,&m);
		for(i=1;i<n;i++){
	 		scanf("%d%d%d",&a,&b,&c);
	 		tree[a].push_back(node(b,c));
	 		rot[b]=true;//����Ƿ��и��� 
	 		father[b][0]=a;//b������һ��Ϊa 
	 	}
		for(i=1;i<=n;i++)//�Ҹ��ڵ� 
			if(!rot[i]){
	 			root=i;
	 			break;
			} 
	 	dfs(root); 
	 	buildz();//���ϱ���
	 	for(i=1;i<=m;i++){
	 		scanf("%d%d",&a,&b);
	 		ance=LCA(a,b);
	 		printf("%d\n",dis[a]+dis[b]-2*dis[ance]);
	 	}
	}
	return 0;
} 
