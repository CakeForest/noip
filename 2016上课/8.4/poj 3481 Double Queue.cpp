#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000000;
struct node{
	int l,r,pri,h,id;
}q[MAX];
int cnt=1,sum;

int H(int rt){
	if(rt==0) return -1;
	return q[rt].h;
}
int SRWL(int rt){//SingleRotateWithLeft
	int t=q[rt].l;
	q[rt].l=q[t].r;
	q[t].r=rt;
	q[t].h=max(H(q[t].l),H(q[t].r))+1;
	q[rt].h=max(H(q[rt].l),H(q[t].r))+1;
	return t;
}
int SRWR(int rt){//SingleRotateWithRight
	int t=q[rt].r;
	q[rt].r=q[t].l;
	q[t].l=rt;
	q[t].h=max(H(q[t].l),H(q[t].r))+1;
	q[rt].h=max(H(q[rt].l),H(q[rt].r))+1;
	return t;
}
int DRWL(int rt){//DoubleRotateWithLeft
	q[rt].l=SRWR(q[rt].l);
	return SRWL(rt);
}
int DRWR(int rt){//DoubleRotateWithRight
	q[rt].r=SRWR(q[rt].r);
	return SRWR(rt);
}
int newnode(int k){
	q[cnt].h=q[cnt].l=q[cnt].r=0;
	q[cnt].key=k;
	sum++;
	return cnt++;
}
int Insert(int rt,int k){
	if(rt==0)
}
int main(){
//	freopen("in.txt","r",stdin);
	int cmd,k,p,root=1;
	while(~scanf("%d",&cmd)&&cmd){
		if(cmd==1){
			scanf("%d%d",&k,&p);
			root=Insert(root,)
		}
		
	}
	
	
	return 0;
}
