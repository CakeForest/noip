#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//最大生成树 
struct Arc{
	int a,b,c;
}arc[20200];
int arcnum=1,father[20200];
void addarc(int a,int b,int c){
	arc[arcnum].a=a;
	arc[arcnum].b=b;
	arc[arcnum++].c=c;
}
bool cmp(Arc a,Arc b){
	return a.c>b.c;
}
int Getfather(int p){
	if(father[p]==p) return p;
	father[p]=Getfather(father[p]);
	return father[p];
}
void unions(int s,int f){
	s=Getfather(s); f=Getfather(f);
	if(s!=f) father[s]=f;
}


int main(){
	freopen("cowtract.in","r",stdin);
	freopen("cowtract.out","w",stdout);
	int n,m,a,b,c,sum=0,k=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
	}
	for(int i=1;i<=n;i++)
		father[i]=i;
	sort(arc+1,arc+arcnum,cmp);
	for(int i=1;i<arcnum;i++){
		int u=arc[i].a,v=arc[i].b;
		if(Getfather(u)!=Getfather(v)){
			sum+=arc[i].c,k++;
			unions(u,v);
		}
		if(k==n-1) goto end;
	}
	printf("-1");
	return 0;
	end:printf("%d",sum);
	return 0;
}
