#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
int C[MAX],U[MAX],rd[MAX],cd[MAX];
int que[MAX],top,rear;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	cd[a]++; rd[b]++;
	flow[arcnum]=c;
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&C[i],&U[i]);
	for(int i=1;i<=p;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
	}
	
	for(int i=1;i<=n;i++)
		if(!rd[i]) que[rear++]=i,U[i]=0;
	
	do{
		int u=que[top++],v,flag=1;
		C[u]=C[u]-U[u];
		if(C[u]<=0) flag=0;
		for(int p=first[u];p;p=nxt[p]){
			v=go[p];
			rd[v]--;
			if(!rd[v]) que[rear++]=v;
			if(flag) C[v]+=flow[p]*C[u];
		}
	}while(top!=rear);
	
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!cd[i]&&C[i]>0){printf("%d %d\n",i,C[i]);cnt++;}
	
	if(!cnt) printf("NULL\n");
	
	return 0;
}
