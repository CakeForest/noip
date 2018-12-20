#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10200;
struct arc{
	int a,b,l;
}Arc[MAX];
int father[MAX],arcnum=1;
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
void addarc(int a,int b,int l){
	Arc[arcnum].a=a;
	Arc[arcnum].b=b;
	Arc[arcnum++].l=l;
}
bool cmp(arc a,arc b){
	return a.l<b.l;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m,sum=0,k=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		father[i]=i;
	for(int i=1;i<=m;i++){
		int p,u,v,w;
		scanf("%d%d%d%d",&p,&u,&v,&w);
		if(p==1){
			sum+=w; k++;
			unions(u,v);//直接选边 
		}else addarc(u,v,w);//记录此边 等待排序 
	}
	sort(Arc+1,Arc+arcnum,cmp);
	
	for(int i=1;i<arcnum;i++){
		int u=Arc[i].a,v=Arc[i].b;
		if(Getfather(u)!=Getfather(v)){
			sum+=Arc[i].l;
			k++;
			unions(u,v);
		}
		if(k==n-1) break;
	}
	printf("%d",sum);
	
	return 0;
}
