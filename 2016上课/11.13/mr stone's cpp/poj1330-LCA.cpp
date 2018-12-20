#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 10005
using namespace std;
vector<int> tree[MAXN],que[MAXN];
int n,cnt,qa,qb,father[MAXN],anscestor[MAXN];
bool visited[MAXN],root[MAXN];
int getfa(int x){//ȡ���� 
	if(father[x]==x) return x;
	father[x]=getfa(father[x]);
	return father[x];
}

void unionn(int a,int b){//�ϲ� 
	a=getfa(a);
	b=getfa(b);
	if(a!=b)father[b]=a;
}
      
void tarjan(int u){
	father[u]=u;//��ǰ����Ϊu���� 
	int size=tree[u].size();
	for(int i=0;i<size;i++){//�������������ĵ� 
		int v=tree[u][i];
		tarjan(v);//�ȼ������±��� 
		unionn(u,v);//�ٽ�������ϲ����� 
		anscestor[getfa(u)]=u;//
	}
	visited[u]=true;//�Ѿ����� 
	for(int i=0;i<que[u].size();i++){//���и�u���ѯ���йصĵ���и��� 
		if(visited[que[u][i]]){
			printf("%d\n",anscestor[getfa(que[u][i])]);
			break;
		}
	}
}
void init(){
	memset(visited,false,sizeof(visited));
	memset(root,false,sizeof(root));
	for(int i=1;i<=n;i++){
		father[i]=i;
		tree[i].clear();
		que[i].clear();
	}
}
int main(){
	int tcase,i,a,b;
	freopen("poj1330.txt","r",stdin);
	scanf("%d",&tcase);
	while(tcase--){
		init();
		scanf("%d",&n);
		for(i=1;i<=n-1;i++){
			scanf("%d%d",&a,&b);
			root[b]=true;
			tree[a].push_back(b);
		}
		scanf("%d%d",&qa,&qb);
		que[qa].push_back(qb);
		que[qb].push_back(qa);
		for(i=1;i<=n;i++)
			if(!root[i]){
				tarjan(i);
				break;
			}
	}
	return 0;
}
