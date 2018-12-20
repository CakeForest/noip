#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[120],dy[120],first[120],next[2000],go[2000],arcnum=1;
int queue[2000],exist[120],time[120],top=0,rear=1;
double dist[120],w[120][120];
void addarc(int x,int y){
	go[arcnum]=x;
	next[arcnum]=first[y];
	first[y]=arcnum;
	arcnum++;
	go[arcnum]=y;
	next[arcnum]=first[x];
	first[x]=arcnum;
	arcnum++;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m,s,t,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		dx[i]=x; dy[i]=y;
		dist[i]=9999999;
	}
		
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addarc(x,y);
	}
	for(int u=1;u<=n;u++){
		for(int p=first[u];p!=0;p=next[p]){
			int v=go[p];
			w[u][v]=sqrt((dx[u]-dx[v])*(dx[u]-dx[v])+(dy[u]-dy[v])*(dy[u]-dy[v]));
		}
	}
	
	
	scanf("%d%d",&s,&t);
	queue[0]=s;dist[s]=0;time[s]=1;
	do{
		int u=queue[top];
		exist[u]=0;
		for(int p=first[u];p!=0;p=next[p]){
			int v=go[p];
			if(dist[u]+w[u][v]<dist[v]){
				dist[v]=dist[u]+w[u][v];
				if(!exist[v]){
					queue[rear++]=v; time[v]++;
				//	if(time[v]>n) return false;//¸ºÈ¨»· 
					exist[v]=1;
				}
			}
		}
		top++;
	}while(top!=rear);
	printf("%.2f",dist[t]);
	
	
	return 0;
}
