#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=30;

double calc(double a,double b){
	return a*a+b*b;
}

struct node{
	double x,y;
	bool friend operator<(const node &a,const node &b){
		return calc(a.x,a.y)<calc(b.x,b.y);
	}
}t[MAX];


int main(){
	freopen("angrybirds.in","r",stdin);
	freopen("angrybirds.out","w",stdout);
	
	int n,m,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&t[i].x,&t[i].y);
		}
		
		if(n<=2){
			sort(t+1,t+1+n);
			double k=t[1].y/t[1].x;
			if(t[2].y/t[2].x>k) printf("2\n");
			else printf("1\n");	
		}
	}
	
	
}
