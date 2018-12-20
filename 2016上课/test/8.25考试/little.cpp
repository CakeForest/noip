#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=120;
const int MAXM=5200;
struct Arcc{
	int a,b,c;
}arcc[MAXM];
int father[MAXN];
bool cmp(Arcc a,Arcc b){
	return a.c<b.c;
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
	freopen("little.in","r",stdin);
	freopen("little.out","w",stdout);
	
	int n,m,x,y,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&arcc[i].a,&arcc[i].b,&arcc[i].c);
	}
	sort(arcc+1,arcc+1+m,cmp);
	
	int value=99999999;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) father[j]=j;
		int k=0;
		for(int j=i;j<=m;j++){
			int u=arcc[j].a,v=arcc[j].b;
			if(Getfather(u)!=Getfather(v)){
//				highest=max(highest,arcc[j].c);
				unions(u,v);
				k++;
			}
			if(k==n-1){
				value=min(value,arcc[j].c-arcc[i].c);
				break;
			}
		}
		
	}
	printf("%d",value);
	
	return 0;
}
