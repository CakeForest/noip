#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int first[MAX],nxt[MAX],go[MAX],arcnum;
int bear[MAX],mg[MAX],l[MAX];
int que[MAX],top,rear,num[MAX][MAX];//num表示dp[i][j]的状态挂了多少吊灯 
long long dp[MAX][MAX],temp[MAX],father[MAX];
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}
int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d%d%d%d",&t,&mg[i],&bear[i],&l[i]);
		if(t!=0) addarc(t,i);
	}
	
	que[rear++]=1; 
	do{
		int u=que[top++];
		if(first[u]==0)
			dp[u][0]=l[u];//每个结点不挂灯的亮度 吊灯本身不计入承受范围
		for(int p=first[u];p!=0;p=nxt[p])
			que[rear++]=go[p],father[go[p]]=u;
	}while(top!=rear);
	
	
	for(int k=top-1;k>=0;k--){
		int u=que[k],v;
		if(first[u]==0){
			for(int j=0;j<=bear[u];j++)
				num[u][j]=1;
			continue;
		}
		for(int p=first[u];p!=0;p=nxt[p]){
			v=go[p];
			for(int i=0;i<=bear[u];i++)
				temp[i]=dp[u][i];
			for(int m=0;m<=bear[u];m++){//分配的重量 
				int i=m-mg[v];
				if(i<0) continue;
				for(int j=0;j<=bear[v]&&j<=bear[u];j++){
					long long add=temp[j]+dp[v][i-j];
					if(dp[u][m]<add)
						dp[u][m]=add,num[u][m]=num[u][j]+num[v][i-j];
				}
			}
		}
		for(int i=0;i<=bear[u];i++)//最后再加入根节点的权值 
			dp[u][i]+=l[u],num[u][i]+=1;
	}
	
	long long maxx=-1;
	int log;
	for(int i=0;i<=bear[1];i++)
		if(dp[1][i]>maxx)
			maxx=dp[1][i],log=num[1][i];
			
	printf("%d %lld\n",log,maxx);
	
/*	printf("\n\n\n\n");
	for(int i=1;i<=n;i++){
		for(int j=0;j<=bear[i];j++)
			printf("%d ",num[i][j]);
		printf("\n\n");
	}*/
	
	return 0;
}
