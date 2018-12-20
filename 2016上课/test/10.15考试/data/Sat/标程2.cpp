#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct FM{	
	int x,y,z;
}w[1005]={0};
int N,Maxx=0x7fffffff/2;
int Minn=0,tot=0,Map[10005][2]={0},h[2005]={0},Times[2005]={0};
int Lowlink[2005]={0},inzan[2005]={0},zan[2005]={0},scc=0,color[2005]={0};
int Getdis(FM A,FM B)
{
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
} 
void Add(int x,int y) {
	tot++;Map[tot][0]=h[x];Map[tot][1]=y;h[x]=tot;
}
int Dfs(int x)
{
	int i,j;tot++;Times[x]=tot;Lowlink[x]=tot;
	zan[0]++;zan[zan[0]]=x;inzan[x]=1;
	for(i=h[x];i!=0;i=Map[i][0]) {
		j=Map[i][1];
		if(Times[j]==0) {
			Dfs(j);Lowlink[x]=min(Lowlink[x],Lowlink[j]);
		}
		else {
			if(inzan[j]) Lowlink[x]=min(Lowlink[x],Times[j]);
		}
	}
	if(Lowlink[x]==Times[x]) {
		scc++;
		while(zan[zan[0]]!=x)
        {
        	color[zan[zan[0]]]=scc;
        	inzan[zan[zan[0]]]=0;
        	zan[0]--;
        }
        color[zan[zan[0]]]=scc;
        inzan[zan[zan[0]]]=0;
        zan[0]--;
	}
	return 0;
}
int Pd(int XXX)
{
	int i,j;
	tot=0;memset(h,0,sizeof(h));
	for(i=1;i<=N;i++) {
		for(j=1;j<i;j++) {
			w[i].y+=w[i].z;w[j].y+=w[j].z;
			if(Getdis(w[i],w[j])<XXX) {
			   Add(i,N+j);Add(j,N+i);
			}
			w[i].y-=w[i].z*2;w[j].y-=w[j].z*2;
			if(Getdis(w[i],w[j])<XXX) {
				Add(N+i,j);Add(N+j,i);
			}
			w[j].y+=w[j].z*2;
			if(Getdis(w[i],w[j])<XXX) {
				Add(N+i,N+j);Add(j,i);
			}
			w[j].y-=w[j].z*2;w[i].y+=w[i].z*2;
			if(Getdis(w[i],w[j])<XXX) {
				Add(i,j);Add(N+j,N+i);} 
			w[j].y+=w[j].z;w[i].y-=w[i].z;	
		}
	}
	memset(Times,0,sizeof(Times));
	memset(inzan,0,sizeof(inzan));
	memset(Lowlink,0,sizeof(Lowlink));
	zan[0]=0;scc=0;tot=0;
	for(i=1;i<=2*N;i++) 
		if(Times[i]==0) Dfs(i);
	for(i=1;i<=N;i++) 
		if(color[i]==color[N+i]) return 0;
	return 1;
} 
int Work(int l,int r)
{
		cout<<l<<" "<<r<<endl;
	if(l==r) return l;
	int mid=(l+r+1)/2,PD=Pd(mid);
	if(!PD) return Work(l,mid-1);
	else return Work(mid,r);
}
int main()
{
	freopen("Sat5.in","r",stdin);
	//freopen("Sat5.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) 
		scanf("%d%d%d",&w[i].x,&w[i].y,&w[i].z);

	for(int i=1;i<=N;i++) 
		for(int j=1;j<i;j++)
		    Minn=min(Minn,Getdis(w[i],w[j]));
 	printf("%d",Work(Minn,Maxx));
    return 0;
} 
