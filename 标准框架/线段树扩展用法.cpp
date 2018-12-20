//���������ͷ�Χʱע���longlong 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=1000000;
int maxx[MAX<<2],lazy[MAX<<2];//��4���ռ� 
void PushUp(int rt){//���ϸ��� 
	maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
}
void PushDown(int rt){//���¸��� 
	if(lazy[rt]){
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		maxx[rt<<1]=lazy[rt];
		maxx[rt<<1|1]=lazy[rt];//ע�������������� 
		lazy[rt]=0;//lazy��0 
	}
}
void Revise(int L,int R,int p,int l,int r,int rt){//���� 
	if(L<=l&&r<=R){
		lazy[rt]=p;
		maxx[rt]=p;//ע����±����
		return;//ע�ⷵ�� 
	}
	PushDown(rt);//ע�����¸��� 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
	PushUp(rt);//ע�����ϸ��� 
}
int View(int L,int R,int l,int r,int rt){//�����ֵ 
	if(L<=l&&r<=R) return maxx[rt];
	PushDown(rt);//ע�����¸��� 
	int m=(l+r)>>1;
	int tot=0;
	if(L<=m) tot=max(tot,View(L,R,lson));
	if(R>=m+1) tot=max(tot,View(L,R,rson));
	return tot;
}

int main(){
	int n;
	scanf("%d",&n);
	srand(unsigned(time(NULL)));
	for(int i=1;i<=n;i++){
		int t=rand()%20;
		Revise(i,i,t,1,n,1);
		printf("%d ",t);
	}
	printf("\n");
	
	int l,r;
	while(scanf("%d%d",&l,&r)){
		printf("%d\n",View(l,r,1,n,1));
	}
	
	return 0;
}
