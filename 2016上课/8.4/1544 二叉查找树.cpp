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
	if(rt==0) return -1;//��Ϊ���򷵻� 
	return tree[rt].height;
}

int SingleRotateWithLeft(int rt){//���� 
	int t;
	t=tree[rt].left;
	tree[rt].left=tree[t].right;
	tree[t].right=rt;
	tree[t].height=max(h(tree[t].left),h(tree[t].right))+1;
	tree[rt].height=max(h(tree[rt].left),h(tree[rt].right))+1;
	return t;
}

int SingleRotateWithRight(int rt){//�ҵ��� 
	int t;
	t=tree[rt].right;
	tree[rt].right=tree[rt].left;
	tree[t].left=rt;
	tree[t].height=max(h(tree[t].left),h(tree[t].right))+1;
	tree[rt].height=max(h(tree[rt].left),h(tree[rt].right))+1;
	return t;
}

int DoubleRotateWithLeft(int rt){//��˫�� �൱�������������� 
	tree[rt].left=SingleRotateWithRight(tree[rt].left);
	return SingleRotateWithLeft(rt);
}

int DoubleRotateWithRight(int rt){//��˫�� �൱�������������� 
	tree[rt].right=SingleRotateWithLeft(tree[rt].right);
	return SingleRotateWithRight(rt);
}

int newnode(int k){//�����½ڵ� 
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
	if(!sum||!rt) return 0;//δ������͵�ǰ���Ϊ0 
	if(tree[rt].key==c){
		if(tree[rt].lazy) return rt;//���ؽ��λ��
		else return 0;//������ 
	}
	if(tree[rt].key>c) return Find(tree[rt].left,c);//�������� 
	else return Find(tree[rt].right,c);//�������� 
}

void Delete(int rt){
	tree[rt].lazy=0;//���ɾ�� 
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
			else{//root��Ϊ��ת����ʱ�ı䣬����Ҫ��¼ 
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
