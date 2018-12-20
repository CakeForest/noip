#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAX=50020;
int n,m,k,a,b;
int sum[MAX<<2];//��4���ռ� 
void PushUp(int rt){//���ϸ��� 
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void Revise(int L,int R,int p,int l,int r,int rt){//���� 
	if(l==r){
		sum[rt]=p;//ע����±����
		return;//ע�ⷵ�� 
	}
	int m=(l+r)>>1;
	if(L<=m) Revise(L,R,p,lson);
	if(R>=m+1) Revise(L,R,p,rson);
	PushUp(rt);//ע�����ϸ��� 
}

int View(int L,int R,int l,int r,int rt){//��� 
	if(L<=l&&r<=R) return sum[rt];
	int m=(l+r)>>1,tot=0;
	if(L<=m) tot+=View(L,R,lson);
	if(R>=m+1) tot+=View(L,R,rson);
	return tot;
}

int Find(int s,int e,int aim,int l){
	//Ҫ����b��λ��Ϊ�� 
	while(s<=e){ 
		int m=(s+e)>>1,calc=View(l,m,1,n,1);
		if(m-l+1-calc==aim){
			while(View(l,m-1,1,n,1)==m-1-l+1-calc) m--;
			return m;
		}else if(m-l+1-calc<aim) s=m+1;
		else e=m-1;
	}
	return 0;
}

int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&k,&a,&b);
		if(k==1){
			a++;//��1��ʼ 
			if(View(a,n,1,n,1)==n-a+1){//һ�������Ų��� 
				printf("Can not put any one.\n");continue;
			}
			
			int s=a,e;
			while(View(s,s,1,n,1)) s++;//�ҵ���һ���ܷŵĵط�
			
			e=Find(s,n,b,s);
			if(!e){
				e=n;
				while(View(e,e,1,n,1)) e--;
			}
			Revise(s,e,1,1,n,1);
			printf("%d %d\n",s-1,e-1);
		}else{
			a++;b++;//��1��ʼ 
			printf("%d\n",View(a,b,1,n,1));
			Revise(a,b,0,1,n,1);
		}
		
	/*	printf(" now:");
		for(int i=1;i<=n;i++)
			printf("%d ",View(i,i,1,n,1));
		printf("\n\n\n");*/
	}
	
/*	n=10;
	Revise(1,10,1,1,n,1);
	printf("%d",View(1,10,1,n,1));
*/
	
	return 0;
}
