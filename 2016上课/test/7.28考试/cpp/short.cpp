#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	int x,y,id;
}P[120];
const int MAX=1000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int que[100000],top,rear,exist[MAX];
double data[MAX],dist[MAX];
double calc(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void addarc(int a,int b,double d){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	data[arcnum]=d;
}

int main(){
	freopen("short.in","r",stdin);
	freopen("short.out","w",stdout);
	
	int n,m,a,b,s,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&P[i].x,&P[i].y);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		double t=calc(P[a],P[b]);
		addarc(a,b,t);
		addarc(b,a,t);
	}
	
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++)
		dist[i]=9999999;
	top=rear=0;
	que[rear++]=s;
	dist[s]=0;
	do{
		int u=que[top++],v;
		exist[u]=0;
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			if(dist[v]>dist[u]+data[p]){
				dist[v]=dist[u]+data[p];
				if(!exist[v]){
					exist[v]=1;
					que[rear++]=v;
				}	
			}
		}
	}while(top!=rear);
	printf("%.2f",dist[t]);
	
	
	return 0;
}
