#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
//���������ͷ�Χʱע���longlong 
using namespace std;
const int MAX=1000200;
int n,p,q,x,y,ans;
char table[MAX];

int sum[MAX<<2],lazy[MAX<<2];//��4���ռ� 
void PushUp(int rt){//���ϸ��� 
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int c){//���¸��� 
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];//ע����+
		sum[rt<<1]+=(c-(c>>1))*lazy[rt];
		sum[rt<<1|1]+=(c>>1)*lazy[rt];//ע�������������� 
		lazy[rt]=0;//lazy��0 
	}
}
void Revise(int L,int R,int p,int l,int r,int rt){//���� 
	if(L<=l&&r<=R){
		lazy[rt]+=p;
		sum[rt]+=p*(r-l+1);//ע����±����
		return;//ע�ⷵ�� 
	}
	PushDown(rt,r-l+1);//ע�����¸��� 
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
	PushUp(rt);//ע�����ϸ��� 
}
int View(int L,int R,int l,int r,int rt){//��� 
	if(L<=l&&r<=R) return sum[rt];
	PushDown(rt,r-l+1);//ע�����¸��� 
	int m=(l+r)>>1;
	int tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>=m+1) tot+=View(L,R,rson);
	return tot;
}

int main(){
	freopen("bbb.in","r",stdin);
	freopen("bbb.out","w",stdout);
	
	
	int zheng,fu;
	zheng=fu=0;
	scanf("%d%d%d%d%d",&n,&p,&q,&x,&y);
	getchar();
	sum[0]=p;
	for(int i=1;i<=n;i++){
		char c=getchar();
		table[i]=c;
		if(c=='-') fu++,sum[i]=sum[i-1]-1;
		else zheng++,sum[i]=sum[i-1]+1;
		
	}
	
	int minn=abs(p+zheng-fu-q)/2;
	ans+=x*minn;
	printf("%d",ans);
	
	
	return 0;
}
