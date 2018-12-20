#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=2222;
struct Seg{
	double h,l,r;
	int s;//标记此线段是否为结尾，如果为结尾就为-1 
	Seg(){}
	Seg(double a,double b,double c,int d) : l(a) , r(b) , h(c) , s(d) {}
	bool operator < (const Seg &cmp) const {
		return h < cmp.h;
	}
}ss[MAX];
int cnt[MAX<<2];
double sum[MAX<<2],X[MAX];

void PushUp(int rt,int l,int r){
	if(cnt[rt]) sum[rt]=X[r+1]-X[l];//如果cnt仍然为正，那么sum值为两端点的距离 
	else if(l==r) sum[rt]=0;//如果当前是根节点，没有子节点，那么sum为0 
	else sum[rt]=sum[rt<<1]+sum[rt<<1|1];//否则直接根据两个子节点更新根节点 
}

void update(int L,int R,int c,int l,int r,int rt){
	if(L<=l&&r<=R){
		cnt[rt]+=c;//更新目标区间的cnt值 
		PushUp(rt,l,r);//向上更新 
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) update(L,R,c,lson);
	if(R>=m+1) update(L,R,c,rson);
	PushUp(rt,l,r);
}

int Bin(double key,int n,double X[]){//二分找离散优化对应元素 
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)>>1;
		if(X[m]==key) return m;
		if(X[m]<key) l=m+1;
		else r=m-1;
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,cas=1;
	while(~scanf("%d",&n)&&n){
		int m=0;
		while(n--){
			double a,b,c,d;
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			X[m]=a;
			ss[m++]=Seg(a,c,b,1);//创建线段
			X[m]=c;
			ss[m++]=Seg(a,c,d,-1);//创建线段 
		}
		sort(X,X+m);//x轴元素排序 
		sort(ss,ss+m);//线段排序 
		int k=1;
		for(int i=1;i<m;i++)
			if(X[i]!=X[i-1]) X[k++]=X[i];//离散去重 
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		double ret=0;
		for(int i=0;i<m-1;i++){
			int l=Bin(ss[i].l,k,X);//离散优化，查找对应的点 
			int r=Bin(ss[i].r,k,X)-1;
			update(l,r,ss[i].s,0,k-1,1);//更新线段树 
			ret+=sum[1]*(ss[i+1].h-ss[i].h);//更新面积，如果两条线处于同一高度，则不执行 
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",cas++,ret);
	}
	return 0;
}
