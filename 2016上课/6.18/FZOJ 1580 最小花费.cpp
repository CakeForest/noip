#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y,z,a,b;
int rear,top,queue[10000],exist[10000];
int go[10000],first[2100],nextt[10000],arcnum=1;
double f[2100],w[2100][2100];//w[i][j]表示i经过j后的存款是原来的w[i][j]倍 
void addarc(int x,int y,int z){
	nextt[arcnum]=first[x];
	first[x]=arcnum;
	go[arcnum]=y;
	arcnum++;
}

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=99999999;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=0.000000001;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		addarc(y,x,z);//x到y有条路径 
		w[y][x]=1-0.01*z; 
	}
	scanf("%d%d",&a,&b);
	top=0; rear=1;
	queue[0]=b; exist[b]=1; f[b]=100;//从b到a进行SPFA 
	do{
		int u=queue[top];
		exist[u]=0;
		for(int p=first[u];p!=0;p=nextt[p]){
			int v=go[p];
			if(f[v]>f[u]/w[u][v]){
				f[v]=f[u]/w[u][v];
				if(!exist[v]){
					queue[rear++]=v;
					exist[v]=1;
		}}}
		top++;
	}while(top!=rear);
	printf("%.8lf",f[a]);
	
	return 0;
}
