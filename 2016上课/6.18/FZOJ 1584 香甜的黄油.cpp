#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,P,C,a,b,d,cow[1000],w[1000][1000],f[1000][1000];
int go[1500],nextt[1500],first[1500],arcnum=1;
int queue[3000],top,rear,exist[1000];
void addarc(int a,int b,int d){
	nextt[arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	w[a][b]=d;
	arcnum++;
}
int main(){
	freopen("in.txt","r",stdin);
	memset(f,127,sizeof(f));
	memset(w,127,sizeof(w));
	scanf("%d%d%d",&N,&P,&C);
	for(int i=1;i<=N;i++){
		scanf("%d",&a);
		cow[a]++;
	}
	for(int i=1;i<=C;i++){
		scanf("%d%d%d",&a,&b,&d);
		addarc(a,b,d); addarc(b,a,d);
	}
	for(int i=1;i<=P;i++){
		top=0; rear=1; 
		queue[0]=i; f[i][i]=0;
		do{
			int u=queue[top];
			exist[u]=0;
			for(int p=first[u];p!=0;p=nextt[p]){
				int v=go[p];
				if(f[i][u]+w[u][v]<f[i][v]){
					f[i][v]=f[i][u]+w[u][v];
					if(!exist[v]){
						queue[rear++]=v;
						exist[v]=1;
					}
				}
			}
			top++;	
		}while(top!=rear);
	}
	int minx=99999999,sum;
	for(int i=1;i<=P;i++){
		sum=0;
		for(int j=1;j<=P;j++)
			sum+=f[i][j]*cow[j];
		minx=min(minx,sum);
	}
	printf("%d",minx);
	return 0;
}
