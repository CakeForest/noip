#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100020;
struct node{
	int left,right,height,key,lazy;
}tree[MAX];
int cnt=1,sum=0;

int h(int rt){
	if(rt==0) return -1;//树为空则返回 
	return tree[rt].height;
}

int SingleRotateWithLeft(int rt){//左单旋 
	int t;
	t=tree[rt].left;
	tree[rt].left=tree[t].right;
	tree[t].right=rt;
	tree[t].height=max(h(tree[t].left),h(tree[t].right))+1;
	tree[rt].height=max(h(tree[rt].left),h(tree[rt].right))+1;
	return t;
}

int SingleRotateWithRight(int rt){//右单旋 
	int t;
	t=tree[rt].right;
	tree[rt].right=tree[rt].left;
	tree[t].left=rt;
	tree[t].height=max(h(tree[t].left),h(tree[t].right))+1;
	tree[rt].height=max(h(tree[rt].left),h(tree[rt].right))+1;
	return t;
}

int DoubleRotateWithLeft(int rt){//左双旋 相当于先右旋再左旋 
	tree[rt].left=SingleRotateWithRight(tree[rt].left);
	return SingleRotateWithLeft(rt);
}

int DoubleRotateWithRight(int rt){//右双旋 相当于先左旋再右旋 
	tree[rt].right=SingleRotateWithLeft(tree[rt].right);
	return SingleRotateWithRight(rt);
}

int newnode(int k){//加入新节点 
	tree[cnt].height=tree[cnt].left=tree[cnt].right=0;
	tree[cnt].key=k;
	tree[cnt].lazy=true;
	sum++;
	return cnt++;
}

int Insert(int rt,int k){
	if(!rt||cnt==1) rt=newnode(k);
	else if(tree[rt].key==k){
		tree[rt].lazy=1;
		sum++;
		return rt;
	}
	else if(k<tree[rt].key){
		tree[rt].left=Insert(tree[rt].left,k);
		if(h(tree[rt].left)-h(tree[rt].right)==2){
			if(k<tree[tree[rt].left].key) rt=SingleRotateWithLeft(rt);
			else rt=DoubleRotateWithLeft(rt);	
		}
	}else if(k>tree[rt].key){
		tree[rt].right=Insert(tree[rt].right,k);
		if(h(tree[rt].right)-h(tree[rt].left)==2){
			if(k>tree[tree[rt].right].key) rt=SingleRotateWithRight(rt);
			else rt=DoubleRotateWithRight(rt);
		}
	}
	tree[rt].height=max(h(tree[rt].left),h(tree[rt].right))+1;
	return rt;
}

int Find(int rt,int c){
	if(!sum||!rt) return 0;//未插入结点和当前结点为0 
	if(tree[rt].key==c){
		if(tree[rt].lazy) return rt;//返回结点位置
		else return 0;//不存在 
	}
	if(tree[rt].key>c) return Find(tree[rt].left,c);//找左子树 
	else return Find(tree[rt].right,c);//找右子树 
}

void Delete(int rt){
	tree[rt].lazy=0;//标记删除 
	sum--;
}

int main(){
//	freopen("in.txt","r",stdin);
	int n,c,root=1; char op[2];
	memset(tree,0,sizeof(tree));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%d",op,&c);
		int t=Find(root,c);
		if(op[0]=='I'){
			if(t) printf("has been\n");
			else{//root因为旋转会随时改变，所以要记录 
				root=Insert(root,c); printf("insert success\n");
			}
		}else{
			if(!t) printf("not exist\n");
			else{
				Delete(t); printf("delete success\n");
			}
		}
		
	}
	
	
	return 0;
}
