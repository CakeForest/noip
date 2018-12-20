#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int first[MAX],go[MAX],nxt[MAX],dis[MAX][MAX],arcnum=1;
int stack[MAX],top,ve[MAX],vl[MAX],e[MAX],l[MAX],rd[MAX];
int order[MAX],ans[MAX],sum;
void addarc(int a,int b,int c){
	nxt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum++]=b;
	dis[a][b]=c;
}
int main(){
//	freopen("in.txt","r",stdin);
	int n,m,a,b,c,k=0;
	scanf("%d%d",&n,&m);
	memset(vl,127,sizeof(vl));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
		rd[b]++;
	}
	for(int i=1;i<=n;i++)
		if(rd[i]==0)
			stack[++top]=i;//入栈
	do{//第一次，求事件最早发生时间 
		int u=stack[top--],v; k++;
		order[k]=u;//记录顺序 
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p]; rd[v]--;
			ve[v]=max(ve[v],ve[u]+dis[u][v]);
			if(rd[v]==0)
				stack[++top]=v;
		}
	}while(top!=0);
	
	vl[n]=ve[n];//中点的事件最晚发生时间等于最早发生时间 
	for(int i=n-1;i>=1;i--){
		int u=order[i],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			vl[u]=min(vl[u],vl[v]-dis[u][v]);
		}
	}
	
	for(int i=1;i<=n-1;i++){//计算活动的最早发生时间和最晚发生时间 
		int u=order[i],v;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			e[p]=ve[u];//活动最早发生时间等于起始点的最早发生时间 
			l[p]=vl[v]-dis[u][v];//活动最晚发生时间等于终点最晚发生时间减去活动的长度 
			if(e[p]==l[p]) ans[++sum]=p;
		}
	}
	
	sort(ans+1,ans+1+sum);
	for(int i=1;i<=sum;i++)
		printf("%d\n",ans[i]);
	return 0;
}

