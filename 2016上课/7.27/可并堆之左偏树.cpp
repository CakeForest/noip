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
	father[rch[a]]=a;//记录父亲 
	if(dis[rch[a]]>dis[lch[a]]) swap(lch[a],rch[a]);//a的距离必须大于b 
	dis[a]=dis[rch[a]]+1;//a的距离更新 
	return a;
}

int Getfather(int p){
	if(father[p]==p) return p;
	father[p]=Getfather(father[p]);
	return father[p];
}

void Fight(int a,int b){//这里将aa bb先删除,再与他们儿子合并后的树合并，再将两个堆合并，使左偏树符合堆的性质 
	int temp,xroot,yroot,aa,bb;
	aa=Getfather(a); bb=Getfather(b);//找到战斗力最强的猴子aa,bb 
	data[aa]>>=1; data[bb]>>=1;//战斗力减少一半 
	temp=Merge(lch[aa],rch[aa]);//合并aa猴子的后代 
	lch[aa]=rch[aa]=0;
	xroot=Merge(aa,temp);//aa猴子与aa猴子后代合并 
	temp=Merge(lch[bb],rch[bb]);//合并bb猴子 的后代 
	lch[bb]=rch[bb]=0;
	yroot=Merge(bb,temp);//bb猴子与bb猴子后代合并
	temp=Merge(xroot,yroot);//合并得到当前最强壮的猴子 
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
