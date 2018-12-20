#include<cstdio>
#define MAX 1000020
#define lson l,m,rt<<1 //����� 
#define rson m+1,r,rt<<1|1 //�Ҷ��� 
//�������߶��� 
int sum[MAX];
char str[10];
void PushUP(int rt) {
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void Revise(int p,int data,int l,int r,int rt){
	if(l==r){//���䳤��Ϊ1 
		sum[rt]+=data;
		return;
	}
	int m=(l+r)>>1;//ȡ�е� 
	if(p<=m) Revise(p,data,lson);//����ݹ��߶��� 
	else Revise(p,data,rson);//���ҵݹ��߶��� 
	PushUP(rt);//���¸��ڵ��sum 
}

int Query(int L,int R,int l,int r,int rt){//[L,R]Ϊ���ҵ����� ��[l,r]Ϊ��ǰ���������� 
	if(L<=l&&R>=r) //���ҵ������������������
		return sum[rt];
	int m=(l+r)>>1,tot=0;
	if(L<=m) tot+=Query(L,R,lson);
	if(R>m) tot+=Query(L,R,rson);
	return tot;
}

void build(int l,int r,int rt) {
	if (l==r){
		scanf("%d",&sum[rt]);
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUP(rt);//���¸��ڵ��sum 
}

int main(){
//	freopen("in.txt","r",stdin);
	int t,n,a,b;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
/*		for(int j=1;j<=n;j++){
			scanf("%d",&a);
			Revise(j,a,1,n,1);
		}*/
		build(1,n,1);
		printf("Case %d:\n",i);
		while(scanf("%s",str)!=EOF&&str[0]!='E'){
			scanf("%d%d",&a,&b);
			if(str[0]=='A') Revise(a,b,1,n,1);
			else if(str[0]=='S') Revise(a,-b,1,n,1);
			else printf("%d\n",Query(a,b,1,n,1));
		}
	}
	
	return 0;
}
