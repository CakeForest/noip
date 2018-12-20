#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int first[MAX],nxt[MAX],go[MAX],arcnum,vis[MAX],w[MAX];
int que[MAX],top,rear,father[MAX],f[MAX],dp[MAX];

void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	w[arcnum]=c;
}

int main(){
	freopen("in.txt","r",stdin);
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		getchar();getchar();
		addarc(a,b,c);
		addarc(b,a,c);
	}
	vis[1]=1; que[rear++]=1;//任意找一个点作为根节点 
	do{
		int i=que[top++],son=0;
		for(int p=first[i];p!=0;p=nxt[p]){
			int j=go[p];
			if(vis[j]) father[i]=j;
			else{
				que[rear++]=j;
				vis[j]=1;
				son++;
			}
		}
		if(son==0) first[i]=0;//i为叶子节点 
	}while(top!=rear);
	
	for(int k=top-1;k>=0;k--){
		int i=que[k],j,max1=0,max2=0,worth;
		if(first[i]==0) continue;
		for(int p=first[i];p!=0;p=nxt[p]){
			j=go[p]; worth=f[j]+w[p];
			if(father[i]==j) continue;
			f[i]=max(f[i],worth);
			if(max1==0) max1=worth;
			else if(max2==0) max2=worth;
			else{
				if(max1>max2){
					if(worth>max2) max2=worth;
					else if(worth>max1) max1=worth;
				}
				else{
					if(worth>max1) max1=worth;
					else if(worth>max2) max2=worth;
				}
			}
		}
		dp[i]=max(dp[i],max1+max2);
	}
	printf("%d",dp[1]);
	
	
	return 0;
}
