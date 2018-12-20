#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100020;
struct hehe{
	int a,b,dis;
}per[MAX];
int father[MAX],val[MAX],cnt;
int cmp(hehe a,hehe b){
	return a.dis>b.dis;
}
int Getfather(int p){
	if(p==father[p]) return p;
	int temp=father[p];//记录父亲结点 
	father[p]=Getfather(father[p]);
	val[p]=(val[p]+val[temp])%2;//更新权值 
	return father[p];
}
void unions(int a,int b){
	int x=Getfather(a),y=Getfather(b);
	if(x!=y){
		father[x]=y;
		val[x]=(val[a]+val[b])^1;
	}
}
int Judge(int a,int b){
	if(Getfather(a)!=Getfather(b)) return -1;//还并未合并
	return (val[a]+val[b])%2; 
}
int main(){
	freopen("prison.in","r",stdin);
	freopen("prison.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&per[i].a,&per[i].b,&per[i].dis);
	sort(per+1,per+1+m,cmp);
	
	for(int i=1;i<=n;i++) father[i]=i;
	
	for(int i=1;i<=m;i++){
		int a=per[i].a,b=per[i].b,d=per[i].dis;
		switch(Judge(a,b)){
			case -1:unions(a,b);break;
			case 0:printf("%d",d);return 0;//与已知冲突 
			case 1:break;//不冲突 
		}
	}
	printf("0");

/*	for(int i=1;i<=4;i++)
		father[i]=i;
	unions(1,2);
	unions(3,4);
	unions(3,2);
	printf("%d",Judge(1,4));*/

	return 0;
}
