#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//�������㷨
const int MAX=100000;
int match[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

bool dfs(int u){
	vis[u]=true;//����Ѿ����� 
	for(int p=first[u];p;p=nxt[p]){
		int v=go[p];
		int w=match[v];//��vƥ��ĵ� 
		/*
			�����ǰ����vƥ��ĵ�
		������vƥ��ĵ�δ��������Ȼ�󱻱�����������· 
		*/
		if(!w||!vis[w]&&dfs(w)){//�˴����׳��� 
			match[u]=v;
			match[v]=u;
			return true;
		}
	}
	return false;//�ǵ���������·ʱ���false 
}

int solve(){
	int ans=0;
	memset(match,0,sizeof(match));//ƥ��·����� 
	for(int i=1;i<=n;i++)
		if(!match[i]){//���i��ûƥ�� 
			memset(vis,0,sizeof(vis));//���vis 
			if(dfs(i)) ans++;//����dfs 
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
