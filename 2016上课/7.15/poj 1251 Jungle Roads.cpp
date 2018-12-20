#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
struct arc{
	int a,b,l;
}Arc[MAX];
int arcnum=1,ge,l,father[MAX];
char start,des;

void addarc(int a,int b,int l){
	Arc[arcnum].a=a;
	Arc[arcnum].b=b;
	Arc[arcnum++].l=l;
}
bool cmp(arc a,arc b){
	return a.l<b.l;
}
int Getfather(int p){
	if(father[p]==p) return p;
	father[p]=Getfather(father[p]);
	return father[p];
}
void unions(int f,int s){
	f=Getfather(f); s=Getfather(s);
	if(f==s) return;
	father[s]=f;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(1){
		int k=0,n,sum=0;
		scanf("%d",&n);
		if(n==0) return 0;
		arcnum=1;
		for(int i=1;i<=100;i++)//初始化父亲 
			father[i]=i;
		for(int i=1;i<n;i++){
			scanf(" %c %d",&start,&ge);//读取起始点和与它连接的点个数 
			for(int j=1;j<=ge;j++)
				scanf(" %c %d",&des,&l),addarc(start-'A'+1,des-'A'+1,l);//每个点所对应的编号是 ASCLL码-'A'+1 
		}
		sort(Arc+1,Arc+arcnum,cmp);
		for(int i=1;i<arcnum;i++){
			int u=Arc[i].a,v=Arc[i].b;
			if(Getfather(u)!=Getfather(v)){
				unions(u,v);
				sum+=Arc[i].l;
				k++;
			}
			if(k==n-1) break;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
