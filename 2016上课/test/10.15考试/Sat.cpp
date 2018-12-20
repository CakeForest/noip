#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=1020;
struct node{
	int x,ys,ye;
}l[MAX];
int n,fuel[MAX];
//二分贪心  判断最小距离是否成立 
bool cmp(node a,node b){
	return a.ys<b.ys;
}

bool judge(int m){
	int prey=l[1].ys,prex=l[1].x;
	for(int i=2;i<=n;i++){
		if(sqrt(0.5+(prex-l[i].x)*(prex-l[i].x)+(prey-l[i].ys))*(prey-l[i].ys)))
		
		
	}
	
	
}

int main(){
	freopen("Sat.in","r",stdin);
//	freopen("Sat.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&l[i].x,&l[i].ys,&fuel[i]);
		l[i].ye=l[i].ys+fuel[i];
		l[i].ys-=fuel[i];
	}
	sort(l+1,l+1+n,cmp);
	
	int s=0,e=99999999;
	while(s<=e){
		int m=(s+e)>>1;
		bool t=judge(m);
		if(t) s=m+1;
		else e=m-1;
	}
	printf("%lld",e*e);
	return 0;
}
