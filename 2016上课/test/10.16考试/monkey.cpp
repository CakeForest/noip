#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=400020;
//逆拓扑排序
int first[MAX],nxt[MAX<<1],go[MAX<<1],arcnum;
int fa[MAX],que[MAX],top,rear,hl[MAX],hr[MAX],t[MAX];
int fir[MAX],nx[MAX],g[MAX],num,h[MAX];
bool vis[MAX];
int n,m;

void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

void add(int a,int b){
	nx[++num]=fir[a];
	fir[a]=num;
	g[num]=b;
}

int main(){
	freopen("monkey.in","r",stdin);
	freopen("monkey.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a!=-1){hl[i]=a;addarc(i,a);addarc(a,i);}
		if(b!=-1){hr[i]=b;addarc(i,b);addarc(b,i);}
	}
	
	que[rear++]=1; vis[1]=true; h[1]=1;
	do{
		int u=que[top++],v;
		for(int p=first[u];p;p=nxt[p]){
			v=go[p];
			if(!vis[v]){
				h[v]=h[u]+1;
				add(u,v);
				vis[v]=true;
				que[rear++]=v;
			}
		}
	}while(top!=rear);
	
	for(int i=1;i<=m;i++){
		int a,k;
		scanf("%d%d",&a,&k);
		
		top=rear=0;
		que[rear++]=k==1?hl[a]:hr[a];
		if(!t[que[0]]){
			if(h[que[0]]>h[a])//放手的猴子在下面时会掉落 
				t[que[0]]=i;
			do{
				int u=que[top++],v;
				for(int p=fir[u];p;p=nx[p]){
					v=g[p];
					if(!t[v]){
						t[v]=i;
						que[rear++]=v;
					}
				}	
			}while(top!=rear);
	}
		}
		
	for(int i=1;i<=n;i++) printf("%d\n",!t[i]?-1:t[i]);
	
	return 0;
}
