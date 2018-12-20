#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=50020;
int lsum[MAX<<2],rsum[MAX<<2],msum[MAX<<2],lazy[MAX<<2];

void Build(int l,int r,int rt){
	lazy[rt]=-1;
	lsum[rt]=rsum[rt]=msum[rt]=r-l+1;//初始化长度为区间长度
	if(l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void PushDown(int rt,int k){//k为当前区间长度 
	if(lazy[rt]!=-1){//如果有人入住或者退房 
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];//lazy传递 
		lsum[rt<<1]=rsum[rt<<1]=msum[rt<<1]=lazy[rt]?0:(k-(k>>1));//给对应的sum全部赋值 
		lsum[rt<<1|1]=rsum[rt<<1|1]=msum[rt<<1|1]=lazy[rt]?0:(k>>1);//有人入住为0，否则为区间长度 
		lazy[rt]=-1;//lazy复原 
	}
}

void PushUp(int rt,int k){//k为当前区间长度 
	lsum[rt]=lsum[rt<<1];
	rsum[rt]=rsum[rt<<1|1];
	if(lsum[rt]==k-(k>>1))//如果左区间的lsum被填满，就加上右区间的lsum值 
		lsum[rt]+=lsum[rt<<1|1];
	if(rsum[rt]==k>>1)//右区间同理 
		rsum[rt]+=rsum[rt<<1];
	msum[rt]=max(rsum[rt<<1]+lsum[rt<<1|1],max(msum[rt<<1],msum[rt<<1|1]));//取三种情况最大值 
}

void Revise(int L,int R,int data,int l,int r,int rt){
	if(L<=l&&r<=R){
		lsum[rt]=rsum[rt]=msum[rt]=data?0:r-l+1;//有人入住，sum为0，否则sum为区间长度 
		lazy[rt]=data;//lazy标记 
		return;
	}
	PushDown(rt,r-l+1);//向下更新 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,data,lson);
	if(R>=m+1) Revise(L,R,data,rson);	
	PushUp(rt,r-l+1);//向上更新 
}

int View(int w,int l,int r,int rt){
	if(l==r) return 1;
	PushDown(rt,r-l+1);//向下更新 
	int m=(l+r)>>1;
	if(msum[rt<<1]>=w)//当前左区间可以装下所有客人 
		return View(w,lson);
	else if(rsum[rt<<1]+lsum[rt<<1|1]>=w)//左区间和右区间并在一起的区间可以装下所有客人 
		return m-rsum[rt<<1]+1;//取房间的起点 
	else return View(w,rson);//右区间可以装下所有客人 
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,m,t,a,b;
	scanf("%d%d",&n,&m);
	Build(1,n,1);
	while(m--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&a);
			if(msum[1]<a)//没有符合要求的连续房间
				printf("0\n");
			else{
				t=View(a,1,n,1);//找房间 
				printf("%d\n",t);
				Revise(t,t+a-1,1,1,n,1);//房间入住 
			}	
		}else{
			scanf("%d%d",&a,&b);
			Revise(a,a+b-1,0,1,n,1);//退房 
		}
	}
	
	
	return 0;
}
