#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int lch[MAX],rch[MAX],father[MAX],dis[MAX],data[MAX];
int n,m;
bool cmp(int a,int b){
	return a>b;
}

int Merge(int a,int b){
	if(a==0) return b;
	if(b==0) return a;
	if(!cmp(data[a],data[b])) swap(a,b);
	rch[a]=Merge(rch[a],b);
	father[rch[a]]=a;//��¼���� 
	if(dis[rch[a]]>dis[lch[a]]) swap(lch[a],rch[a]);//a�ľ���������b 
	dis[a]=dis[rch[a]]+1;//a�ľ������ 
	return a;
}

int Getfather(int p){
	if(father[p]==p) return p;
	father[p]=Getfather(father[p]);
	return father[p];
}

void Fight(int a,int b){//���ｫaa bb��ɾ��,�������Ƕ��Ӻϲ�������ϲ����ٽ������Ѻϲ���ʹ��ƫ�����϶ѵ����� 
	int temp,xroot,yroot,aa,bb;
	aa=Getfather(a); bb=Getfather(b);//�ҵ�ս������ǿ�ĺ���aa,bb 
	data[aa]>>=1; data[bb]>>=1;//ս��������һ�� 
	temp=Merge(lch[aa],rch[aa]);//�ϲ�aa���ӵĺ�� 
	lch[aa]=rch[aa]=0;
	xroot=Merge(aa,temp);//aa������aa���Ӻ���ϲ� 
	temp=Merge(lch[bb],rch[bb]);//�ϲ�bb���� �ĺ�� 
	lch[bb]=rch[bb]=0;
	yroot=Merge(bb,temp);//bb������bb���Ӻ���ϲ�
	temp=Merge(xroot,yroot);//�ϲ��õ���ǰ��ǿ׳�ĺ��� 
	father[a]=father[b]=father[aa]=father[bb]=father[xroot]=father[yroot]=temp;
	printf("%d\n",data[temp]);
}

int main(){
//	freopen("in.txt","r",stdin);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	for(int i=1;i<=n;i++)
		father[i]=i;
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		Fight(a,b);
	}
	
	return 0;
}
