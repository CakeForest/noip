#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=99999999;
struct node{
	int a,b,l;
}arc[1000];
int arcnum,father[1000];
void addarc(int a,int b,int l){
	arc[++arcnum].a=a;
	arc[arcnum].b=b;
	arc[arcnum].l=l;
}
bool cmp(node a,node b){
	return a.l<b.l;
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
	freopen("in.txt","r",stdin);
	int n,m,a,b,c,delta=INF,t;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		addarc(a,b,c);
	}
	sort(arc+1,arc+1+m,cmp);
	for(int i=1;i<=m;i++){//枚举每条边 
		int	rt=arc[i].l,k=1;//基准边 
		for(int j=1;j<=n;j++) father[j]=j;
		for(int j=i+1;j<=m;j++){//枚举比它大的边 
			int u=arc[j].a,v=arc[j].b;
			if(Getfather(u)!=Getfather(v))
				unions(u,v),k++,t=max(t,arc[j].l);
		}
		if(k==n-1) delta=min(delta,t-arc[i].l);
	}
	printf("%d",delta);

	return 0;
}
