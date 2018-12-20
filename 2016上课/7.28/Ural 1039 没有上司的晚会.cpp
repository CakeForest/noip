#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=8000;
int w[MAX],f[MAX][2],l,k,rt;
int que[MAX],top,rear,father[MAX];
int first[MAX],nxt[MAX],go[MAX],arcnum;
void addarc(int a,int b){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
		
	while(scanf("%d%d",&l,&k)!=EOF&&l!=0&&k!=0){
		father[l]=k;
		addarc(k,l);
	}
	
/*	for(int i=1;i<=n;i++){
		printf("%d ",i);
		for(int p=first[i];p!=0;p=nxt[p]){
			int j=go[p];
			printf("%d ",j);
		}
		printf("\n");
	}printf("\n");*/
	for(int i=1;i<=n;i++)
		if(!father[i]){
			rt=i; break;
		}
	que[rear++]=rt;
	do{
		for(int p=first[que[top++]];p!=0;p=nxt[p])
			que[rear++]=go[p];
	}while(top!=rear);
	
	for(int k=top-1;k>=0;k--){
		int i=que[k];
		if(first[i]==0){
			f[i][0]=0;
			f[i][1]=w[i];
		}else{
			int sum,j;
			sum=0;
			for(int p=first[i];p!=0;p=nxt[p]){
				j=go[p];
				sum+=max(f[j][0],f[j][1]);
			}
			f[i][0]=sum;
			sum=0;
			for(int p=first[i];p!=0;p=nxt[p]){
				j=go[p];
				sum+=f[j][0];
			}
			f[i][1]=sum+w[i];
		}
	}
	printf("%d",max(f[rt][0],f[rt][1]));
	
	
/*	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d %d\n",f[i][0],f[i][1]);
	}*/
	
	
	return 0;
}
