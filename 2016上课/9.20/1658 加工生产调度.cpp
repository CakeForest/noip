#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b,id;
}x[1020],y[1020],z[1020];
int xnum,ynum,znum,A[1020],B[1020];
int step[1020],cnt;
bool cmp1(node a,node b){
	return a.a<b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) scanf("%d",&B[i]);
	for(int i=1;i<=n;i++){
		a=A[i]; b=B[i];
		if(a>b){
			x[++xnum].a=a;
			x[xnum].b=b;
			x[xnum].id=i;
		}else if(a==b){
			y[++ynum].a=a;
			y[ynum].b=b;
			y[ynum].id=i;
		}else{
			z[++znum].a=a;
			z[znum].b=b;
			z[znum].id=i;
		}
	}
	sort(z+1,z+1+znum,cmp1);
	sort(x+1,x+1+xnum,cmp2);
	
	a=b=0;
	for(int i=1;i<=znum;i++){
		step[++cnt]=z[i].id;
		a=a+z[i].a;
		if(a>b) b=a+z[i].b;
		else b+=z[i].b;
	}
	for(int i=1;i<=ynum;i++){
		step[++cnt]=y[i].id;
		a=a+y[i].a;
		if(a>b) b=a+y[i].b;
		else b+=y[i].b;
	}
	
	for(int i=1;i<=xnum;i++){
		step[++cnt]=x[i].id;
		a=a+x[i].a;
		if(a>b) b=a+x[i].b;
		else b+=x[i].b;
	}
	
	printf("%d\n",b);
	for(int i=1;i<=cnt;i++) printf("%d ",step[i]);
	
	
	return 0;
}
