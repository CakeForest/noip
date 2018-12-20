#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int low[MAX],dfn[MAX],dex;
bool gd[MAX];//��¼��� 
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

void tarjan(int u,int fa){
	low[u]=dfn[u]=++dex;
	int son=0;
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		if(!dfn[v]){
			tarjan(v,u); son++;//�ӽڵ� 
			low[u]=min(low[u],low[v]);
			if(u==1&&son>1||low[v]>=dfn[u]) gd[u]++;
	/*uΪ���ڵ�ʱ������������ӽڵ���Ϊ���
	 ����Ǹ��ڵ㣬low[v]���ڵ���dfn[u]���� 
	 */
		}else if(v!=fa) low[u]=min(low[u],dfn[v]);//������v������v�ĸ��� 
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
		addarc(b,a);
	}
	tarjan(1);
	
}
