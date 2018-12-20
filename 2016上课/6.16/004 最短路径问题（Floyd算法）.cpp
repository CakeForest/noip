#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[120],dy[120],first[120],next[2000],go[2000],arcnum=1;
double f[120][120];
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
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addarc(x,y);
	}
	scanf("%d%d",&s,&t);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=99999999;
	for(int i=1;i<=n;i++){
		for(int p=first[i];p!=0;p=next[p]){
			int j=go[p];
			f[i][j]=sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
		}
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	printf("%.2f",f[s][t]);
	
	return 0;
}
