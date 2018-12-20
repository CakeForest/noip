#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct FM{	
	long long x,y,z;
	FM(){x=0,y=0,z=0;};
}w[1005];
int N;
long long Maxx=1LL<<60;
long long  Minn=0,tot=0;
long long Map[2000005][2]={0};
long long h[2005]={0},Times[2005]={0};
long long Lowlink[2005]={0},inzan[2005]={0},zan[2005]={0},scc=0,color[2005]={0};
long long Min(long long a,long long b)
{
 if (a<=b) return a;
   else return b;	
}
long long Getdis(FM A,FM B)
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
int Pd(long long  XXX)
{

	int i,j;
	tot=0;memset(h,0,sizeof(h));

	for(i=1;i<=N;i++) {
		for(j=1;j<i;j++) {
			
	//			cout<<"I "<<i<<"J "<<j;
			w[i].y+=w[i].z;w[j].y+=w[j].z;
			if(Getdis(w[i],w[j])<XXX) {
			   Add(i,N+j);Add(j,N+i);
			}
	//		cout<<"A";
			w[i].y-=w[i].z*2;w[j].y-=w[j].z*2;
			if(Getdis(w[i],w[j])<XXX) {
				Add(N+i,j);Add(N+j,i);
			}
		//		cout<<"B";
			w[j].y+=w[j].z*2;
			if(Getdis(w[i],w[j])<XXX) {
				Add(N+i,N+j);Add(j,i);
			}
		//	cout<<"C";
			w[j].y-=w[j].z*2;w[i].y+=w[i].z*2;
		
			if(Getdis(w[i],w[j])<XXX) {
		//			cout<<tot;
				Add(i,j);
			//	cout<<"D@";
				Add(N+j,N+i);} 
			//		cout<<"D";
			w[j].y+=w[j].z;w[i].y-=w[i].z;	
		}
	}
		cout<<"!!!";
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
int Work(long long l,long long  r)
{
	cout<<l<<" "<<r;
	if(l==r) return l;
	cout<<"~~~";
	long long mid=(l+r+1)/2;
	
	int PD=Pd(mid);
	cout<<" "<<mid<<" "<<PD<<endl;
	
	if(!PD) return Work(l,mid-1);
	else return Work(mid,r);
}
int main()
{
	freopen("Sat6.in","r",stdin);
//	freopen("Sat6.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++) 
		cin>>w[i].x>>w[i].y>>w[i].z;
	for(int i=1;i<=N;i++) 
		for(int j=1;j<i;j++)
		    Minn=Min(Minn,Getdis(w[i],w[j]));
 	cout<<Work(Minn,Maxx);
 	fclose(stdin);fclose(stdout);
    return 0;
} 
