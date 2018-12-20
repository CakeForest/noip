#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1e7+10;
int l[MAX],r[MAX],f[MAX],d[MAX],rt;

void Zig(int x){//顺时针旋转 
	int y=f[x];
	l[y]=r[x];//diff
	if(r[x]) f[r[x]]=y;//diff
	f[x]=f[y];
	if(f[y]){//修改x的父亲的儿子信息 
		if(y==l[f[y]]) l[f[y]]=x;
		else r[f[y]]=x;
	}
	r[x]=y;//diff
	f[y]=x;
}

void Zag(int x){//逆时针旋转 
	int y=f[x];
	r[y]=l[x];//diff
	if(l[x]) f[l[x]]=y;//diff
	f[x]=f[y];
	if(f[y]){
		if(y==l[f[y]]) l[f[y]]=x;
		else r[f[y]]=x;
	}
	l[x]=y;//diff
	f[y]=x;
	
}

void Splay(int x,int y){//旋转 
	while(f[x]!=y){
		if(f[f[x]]==y)//已达到根结点 
			(l[f[x]]==x)?Zig(x):Zag(x);
		else{
			if(l[f[f[x]]]==f[x]){//第一层为左 
				if(l[f[x]]==x){//第二层为左 
					Zig(f[x]);
					Zig(x);
				}else{//第二层为右 
					Zag(x);
					Zig(x);
				}
			}else{//第一层为右 
				if(r[f[x]]==x){//第二层为右 
					Zag(f[x]);
					Zag(x);
				}else{//第二层为左 
					Zig(x);
					Zag(x);
				}
				
			}
		}
	}
	if(y==0) rt=x;//修改根结点 
}

int Find(int x,int key){
	if(!x) return 0;//找不到 
	if(d[x]==key){
		Splay(x,0);
		return x;//返回该结点的序号 
	}else{
		if(d[x]>key) return Find(l[x],key);
		else return Find(r[x],key);
	}
	
}

void Insert(int id,int key){
	int ptr=rt,y=0;
	int lrChose=0;
	while(1){
		if(!ptr){//找到了插入的位置 
			ptr=id;
			l[ptr]=r[ptr]=0;
			d[ptr]=key;
			f[ptr]=y;
			if(y!=0){//如果该插入点不是根节点，那么其父亲结点的儿子需要更新 
				if(lrChose==0) l[y]=ptr;
				else r[y]=ptr;
			}
			Splay(ptr,0);
			break;
		}
		y=ptr;//y为当前结点的父亲结点 
		if(d[ptr]>key){
			ptr=l[ptr];
			lrChose=0;
		}else{
			ptr=r[ptr];
			lrChose=1;
		}
	}
}

int Join(int n1,int n2){
	f[n1]=f[n2]=0;//父亲清零 
	//一棵或两棵树为空 
	if(!n1) return n2;
	if(!n2) return n1;
	
	int temp=n1;
	while(r[temp]) temp=r[temp];//找最大
	Splay(temp,0);
	
	/*因为n1为左结点，n2为右节点，
	所以合并时n2总是大于n1子树的任意结点*/
	r[temp]=n2;
	f[n2]=temp;
	return temp;
}

void Delete(int x){//删除 
	Splay(x,0);//直接将该结点旋转至根结点，合并它的子树 
	rt=Join(l[x],r[x]);
}

int main(){
//	freopen("in.txt","r",stdin);
	int cmd,k,p;
	while(~scanf("%d",&cmd)&&cmd){
		if(cmd==1){
			scanf("%d%d",&k,&p);
			Insert(k,p);
		}else if(cmd==2){
			int temp=rt;
			while(r[temp]) temp=r[temp];
			printf("%d\n",temp);
			Delete(temp);
		}else{
			int temp=rt;
			while(l[temp]) temp=l[temp];
			printf("%d\n",temp);
			Delete(temp);
		}
	}
	
	return 0;
}
