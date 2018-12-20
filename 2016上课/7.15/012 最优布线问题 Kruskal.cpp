#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000;
int map[MAX][MAX],arcnum=1,sum,father[MAX];
struct arc{
	int a,b,l;
}Arc[MAX];

bool cmp(arc a,arc b){
	return a.l<b.l;
}
void addarc(int a,int b,int l){
	Arc[arcnum].a=a;
	Arc[arcnum].b=b;
	Arc[arcnum].l=l;
	arcnum++;
}
int Getfather(int p){
	if(father[p]==p)
		return p;
	father[p]=Getfather(father[p]);
	return father[p];
}
void unions(int f,int s){
	f=Getfather(f); s=Getfather(s);
	if(f==s) return;
	father[s]=f; return;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,l,k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		father[i]=i;
		for(int j=1;j<=n;j++){
			scanf("%d",&l);
			if(l>0) addarc(i,j,l);
		}
	}
	sort(Arc+1,Arc+1+arcnum,cmp);
	for(int i=1;i<arcnum;i++){
		int u=Arc[i].a,v=Arc[i].b;
		if(Getfather(u)!=Getfather(v)){
			sum+=Arc[i].l,k++;
			unions(u,v);
		}
		if(k==n-1) break;
	}
	printf("%d",sum);
	
	return 0;
}
