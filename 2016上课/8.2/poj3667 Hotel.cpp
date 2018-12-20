#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=50020;
int lsum[MAX<<2],rsum[MAX<<2],msum[MAX<<2],lazy[MAX<<2];

void Build(int l,int r,int rt){
	lazy[rt]=-1;
	lsum[rt]=rsum[rt]=msum[rt]=r-l+1;//��ʼ������Ϊ���䳤��
	if(l==r) return;
	int m=(l+r)>>1;
	Build(lson);
	Build(rson);
}

void PushDown(int rt,int k){//kΪ��ǰ���䳤�� 
	if(lazy[rt]!=-1){//���������ס�����˷� 
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];//lazy���� 
		lsum[rt<<1]=rsum[rt<<1]=msum[rt<<1]=lazy[rt]?0:(k-(k>>1));//����Ӧ��sumȫ����ֵ 
		lsum[rt<<1|1]=rsum[rt<<1|1]=msum[rt<<1|1]=lazy[rt]?0:(k>>1);//������סΪ0������Ϊ���䳤�� 
		lazy[rt]=-1;//lazy��ԭ 
	}
}

void PushUp(int rt,int k){//kΪ��ǰ���䳤�� 
	lsum[rt]=lsum[rt<<1];
	rsum[rt]=rsum[rt<<1|1];
	if(lsum[rt]==k-(k>>1))//����������lsum���������ͼ����������lsumֵ 
		lsum[rt]+=lsum[rt<<1|1];
	if(rsum[rt]==k>>1)//������ͬ�� 
		rsum[rt]+=rsum[rt<<1];
	msum[rt]=max(rsum[rt<<1]+lsum[rt<<1|1],max(msum[rt<<1],msum[rt<<1|1]));//ȡ����������ֵ 
}

void Revise(int L,int R,int data,int l,int r,int rt){
	if(L<=l&&r<=R){
		lsum[rt]=rsum[rt]=msum[rt]=data?0:r-l+1;//������ס��sumΪ0������sumΪ���䳤�� 
		lazy[rt]=data;//lazy��� 
		return;
	}
	PushDown(rt,r-l+1);//���¸��� 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,data,lson);
	if(R>=m+1) Revise(L,R,data,rson);	
	PushUp(rt,r-l+1);//���ϸ��� 
}

int View(int w,int l,int r,int rt){
	if(l==r) return 1;
	PushDown(rt,r-l+1);//���¸��� 
	int m=(l+r)>>1;
	if(msum[rt<<1]>=w)//��ǰ���������װ�����п��� 
		return View(w,lson);
	else if(rsum[rt<<1]+lsum[rt<<1|1]>=w)//������������䲢��һ����������װ�����п��� 
		return m-rsum[rt<<1]+1;//ȡ�������� 
	else return View(w,rson);//���������װ�����п��� 
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
			if(msum[1]<a)//û�з���Ҫ�����������
				printf("0\n");
			else{
				t=View(a,1,n,1);//�ҷ��� 
				printf("%d\n",t);
				Revise(t,t+a-1,1,1,n,1);//������ס 
			}	
		}else{
			scanf("%d%d",&a,&b);
			Revise(a,a+b-1,0,1,n,1);//�˷� 
		}
	}
	
	
	return 0;
}
