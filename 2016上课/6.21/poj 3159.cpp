#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a,b,c;
int first[31000],nxt[160000],go[160000],cha[160000],arcnum=1;
int queue[10000000],f[31000],exist[31000],top=0,rear=1;
void addarc(int a,int b,int c){//a到b有条权为c的边 
	nxt[arcnum]=first[a];
	go[arcnum]=b;
	first[a]=arcnum;
	cha[arcnum]=c;
	arcnum++;
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=99999999;
	for(int i=0;i<=159999;i++)
		cha[i]=99999999;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);//b-a<=c
	}
	f[1]=0; queue[0]=1; exist[1]=1;
	top=0; rear=1;
	do{
		int u=queue[top];
		exist[u]=0;
		for(int p=first[u];p!=0;p=nxt[p]){
			int v=go[p],dis=cha[p];//u到v距离dis 
			if(f[v]>f[u]+dis){
				f[v]=f[u]+dis;
				if(!exist[v]){
					queue[rear++]=v;
					exist[v]=1;
				}
			}
		}
		top++;
	}while(top!=rear);
	printf("%d",f[n]);
	
	return 0;
}
