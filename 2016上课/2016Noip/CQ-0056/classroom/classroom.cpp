#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2200;
int clas[MAXN][2];
double K[MAXN];
int first[MAXN<<1],nxt[MAXN<<1],go[MAXN<<1],flow[MAXN<<1],arcnum;
int dist[MAXN][MAXN],map[MAXN][MAXN];
double f[MAXN][MAXN][2];
int N,M,V,E,a,b,c;
//f[i][j][k] 在k时段 在i结点 换了j次教室 得到的最小期望值 

inline void read(int &num){
	num=0; int flag=1; char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') flag=-1; else num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
	num*=flag;
}

int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	
	read(N),read(M),read(V),read(E);
	for(int i=1;i<=N;i++)
		read(clas[i][0]);
	for(int i=1;i<=N;i++)
		read(clas[i][1]);
	for(int i=1;i<=N;i++)
		scanf("%lf",&K[i]);
	for(int i=1;i<=E;i++){
		read(a); read(b); read(c);
		map[a][b]=c;
		map[b][a]=c;
	}
	
/*	for(int i=1;i<=N;i++)
		printf("%d %d\n",clas[i][0],clas[i][1]);*/
/*	for(int i=1;i<=N;i++)
		printf("%lf\n",K[i]);*/
	
	
	memset(dist,127,sizeof(dist));
	for(int k=1;k<=V;k++)
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++)
				dist[i][j]=min(dist[i][j],map[i][k]+map[k][j]);
	double ans=0;
	for(int i=1;i<=N-1;i++){
		int u=clas[i][0];
		int v=clas[i+1][0];
		ans+=map[u][v];
	}
	printf("%.2lf",ans);
	
	return 0;
}

