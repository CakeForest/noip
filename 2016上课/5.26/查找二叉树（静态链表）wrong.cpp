#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100020;
int len,n,l[maxn],r[maxn],d[maxn],f[maxn];
int look(int rt,int t)
{
	if(rt==0) return 0;
	if(d[rt]==t) return rt;
	if(t<d[rt]) return look(l[rt],t);
	else return look(r[rt],t);
}

int newnode(int rt,int t)
{
	d[++len]=t;
	f[len]=rt;
	return len;
}

void insertnode(int rt,int t)
{
	if(t<d[rt]){
		if(l[rt]==0) l[rt]=newnode(rt,t);
		else insertnode(l[rt],t);
	}else{
		if(r[rt]==0) r[rt]=newnode(rt,t);
		else insertnode(r[rt],t);
	}
}

void delnode(int rt)
{
	int father=f[rt];
	if(l[rt]==0&&r[rt]==0){
		if(l[father]==rt) l[father]=0;
		else r[father]=0;
	}else if(l[rt]==0){
		if(l[father]==rt) l[father]=r[rt];
		else r[father]=r[rt];
	}else if(r[father]==rt){
		if(l[father]==rt) l[father]=l[rt];
		else r[father]=l[rt];
	}else{
		int p=l[rt];
		while(r[p]!=0) p=r[p];
		d[rt]=d[p];
		delnode(p);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int flag=0;len=1;
	for(int i=1;i<=n;i++)
	{
		char c;int t,res;
		scanf("\n%c %d",&c,&t);
		if(flag==0){
			if(c=='I'){
				d[1]=t;flag=1;
				printf("insert success\n");continue;
			}else{
				printf("not exist\n");continue;
		}}
		res=look(1,t);
		if(c=='I'){
			if(res!=0) printf("has been\n");
			else insertnode(1,t),printf("insert success\n");
		}else{
			if(res==0) printf("not exist\n");
			else{
				 delnode(res),printf("delete success\n");
				 if(res==1){
				 	 flag=0;len=1;
				 	 memset(l,0,sizeof(l));
				 	 memset(r,0,sizeof(r));
				 }
			}
		}	
	}
	return 0;
}
