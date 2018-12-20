#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[120],dy[120],first[120],next[2000],go[2000],arcnum=1,sure[120];
double f[120][120],dis[120],w[120][120];
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
//	freopen("in.txt","r",stdin);
	int n,m,s,t,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		dx[i]=x; dy[i]=y;
		dis[i]=99999999;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addarc(x,y);
	}
	for(int i=1;i<=n;i++)//¼ÆËã¾àÀë 
		for(int p=first[i];p!=0;p=next[p]){
			int j=go[p];
			w[i][j]=sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
		}
			
	scanf("%d%d",&s,&t);
	
	dis[s]=0; sure[s]=1;
	for(int p=first[s];p!=0;p=next[p])
		dis[go[p]]=dis[s]+w[s][go[p]];//³õÊ¼»¯¾àÀë 
	
	for(int i=2;i<=n;i++){
		double minx=9999999; int log,j;
		for(int i=1;i<=n;i++)
			if(!sure[i]&&dis[i]<minx)
				minx=dis[i],log=i;
		sure[log]=1; s=log;
		for(int p=first[s];p!=0;p=next[p]){
			j=go[p];
			if(dis[s]+w[s][j]<dis[j])
				dis[j]=dis[s]+w[s][j];
		}
	}
	printf("%.2f",dis[t]);
	
	
	return 0;
}
