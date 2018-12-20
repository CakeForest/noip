#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 20020
using namespace std;
struct node{
	int id,data;
}peo[MAX];
long long e[MAX],t[MAX],data[MAX],lmin,rmin,lmax,rmax,ans;
int n;

bool cmp(node a,node b){
	return a.data<b.data;
}
int lowbit(int i){
	return -i&i;
}
void add(int x,int t){
	for(;x<=n;x+=lowbit(x))
		e[x]+=t;
}
long long sum(int x){
	long long s=0;
	for(;x>0;x-=lowbit(x))
		s+=e[x];
	return s;
}
int main(){
//	freopen("in.txt","r",stdin);
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n); ans=0;
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++){
			scanf("%d",&peo[i].data);
			peo[i].id=i;//位置 
		}
		sort(peo+1,peo+1+n,cmp);//按能力排序 
		add(peo[1].id,1);//实力最小的选手 
		for(int i=2;i<=n-1;i++){
			lmin=sum(peo[i].id-1);
			lmax=peo[i].id-lmin-1;
			rmin=sum(n)-sum(peo[i].id);
			rmax=n-peo[i].id-rmin;
			ans+=(lmin*rmax+lmax*rmin);
			add(peo[i].id,1);
		}
		printf("%lld\n",ans);
		
	}
	
	return 0;
}
