#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=2222;
struct Seg{
	double h,l,r;
	int s;//��Ǵ��߶��Ƿ�Ϊ��β�����Ϊ��β��Ϊ-1 
	Seg(){}
	Seg(double a,double b,double c,int d) : l(a) , r(b) , h(c) , s(d) {}
	bool operator < (const Seg &cmp) const {
		return h < cmp.h;
	}
}ss[MAX];
int cnt[MAX<<2];
double sum[MAX<<2],X[MAX];

void PushUp(int rt,int l,int r){
	if(cnt[rt]) sum[rt]=X[r+1]-X[l];//���cnt��ȻΪ������ôsumֵΪ���˵�ľ��� 
	else if(l==r) sum[rt]=0;//�����ǰ�Ǹ��ڵ㣬û���ӽڵ㣬��ôsumΪ0 
	else sum[rt]=sum[rt<<1]+sum[rt<<1|1];//����ֱ�Ӹ��������ӽڵ���¸��ڵ� 
}

void update(int L,int R,int c,int l,int r,int rt){
	if(L<=l&&r<=R){
		cnt[rt]+=c;//����Ŀ�������cntֵ 
		PushUp(rt,l,r);//���ϸ��� 
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) update(L,R,c,lson);
	if(R>=m+1) update(L,R,c,rson);
	PushUp(rt,l,r);
}

int Bin(double key,int n,double X[]){//��������ɢ�Ż���ӦԪ�� 
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
			ss[m++]=Seg(a,c,b,1);//�����߶�
			X[m]=c;
			ss[m++]=Seg(a,c,d,-1);//�����߶� 
		}
		sort(X,X+m);//x��Ԫ������ 
		sort(ss,ss+m);//�߶����� 
		int k=1;
		for(int i=1;i<m;i++)
			if(X[i]!=X[i-1]) X[k++]=X[i];//��ɢȥ�� 
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		double ret=0;
		for(int i=0;i<m-1;i++){
			int l=Bin(ss[i].l,k,X);//��ɢ�Ż������Ҷ�Ӧ�ĵ� 
			int r=Bin(ss[i].r,k,X)-1;
			update(l,r,ss[i].s,0,k-1,1);//�����߶��� 
			ret+=sum[1]*(ss[i+1].h-ss[i].h);//�����������������ߴ���ͬһ�߶ȣ���ִ�� 
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",cas++,ret);
	}
	return 0;
}
