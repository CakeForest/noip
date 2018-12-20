#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=320000;
long long in[MAX],out[MAX],d[MAX];
int l[MAX],r[MAX],f[MAX],s[MAX],w[MAX],rt,pnum;

void PushUp(int x){
	s[x]=s[l[x]]+s[r[x]]+w[x];//这里要加上x的自重 
}

void Zig(int x){//顺时针旋转
	int y=f[x];
	l[y]=r[x];
	if(r[x]) f[r[x]]=y;
	f[x]=f[y];
	if(f[y]){
		if(l[f[y]]==y) l[f[y]]=x;
		else r[f[y]]=x;
	}
	r[x]=y;
	f[y]=x;
	PushUp(y);
	PushUp(x);
}

void Zag(int x){//逆时针旋转
	int y=f[x];
	r[y]=l[x];
	if(l[x]) f[l[x]]=y;
	f[x]=f[y];
	if(f[y]){
		if(l[f[y]]==y) l[f[y]]=x;
		else r[f[y]]=x;
	}
	l[x]=y;
	f[y]=x;
	PushUp(y);
	PushUp(x);
} 

void Splay(int x,int y){
	while(f[x]!=y){
		if(f[f[x]]==y)
			(l[f[x]]==x)?Zig(x):Zag(x);
		else{
			if(l[f[f[x]]]==f[x]){
				if(l[f[x]]==x){
					Zig(f[x]);
					Zig(x);
				}else{
					Zag(x);
					Zig(x);
				}
			}else{
				if(r[f[x]]==x){
					Zag(f[x]);
					Zag(x);
				}else{
					Zig(x);
					Zag(x);
				}
			}
		}
	}
	if(y==0) rt=x;
}

void Insert(long long key){
	int ptr=rt,y=0;
	int lrChose=0;
	while(1){
		if(!ptr){//找到插入点的位置 
			ptr=++pnum;
			l[ptr]=r[ptr]=0;
			d[ptr]=key;
			f[ptr]=y;
			s[ptr]=w[ptr]=1;
			if(y!=0){
				if(lrChose==0) l[y]=ptr;
				else r[y]=ptr;
			}
			Splay(ptr,0);
			break;
		}
		y=ptr;
		if(d[ptr]==key){//找到相同的已经插入的值 
			w[ptr]++;
			Splay(ptr,0);
			break;
		}
		else if(d[ptr]>key){
			ptr=l[ptr];
			lrChose=0;
		}else{
			ptr=r[ptr];
			lrChose=1;
		}
	}
}

int Getkth(int k){//找第k大 
	if(!rt) return 0;
	int x=rt,itself;
	while(x){
		itself=w[x];//自重 
		if(k>=s[l[x]]+1&&k<=s[l[x]]+itself) break;
		if(k>s[l[x]]+itself){
			k-=s[l[x]]+itself;
			x=r[x];//向右边找 
		}else x=l[x];//向左边找 
	}
	Splay(x,0);
	return x;
}

int main(){
//	freopen("in.txt","r",stdin);
	int m,n,k=1;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%lld",&in[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&out[i]);
	sort(out+1,out+1+n);
	for(int i=1;i<=m;i++){
		Insert(in[i]);
		while(i==out[k]) printf("%d\n",d[Getkth(k++)]);		
	}
	
	return 0;
}
