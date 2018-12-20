#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAX=1e7+10;
int l[MAX],r[MAX],d[MAX],f[MAX],rt,pnum;

void Zig(int x){//顺时针 
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
}

void Zag(int x){//逆时针 
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
}

void Splay(int x){//将结点旋转到0的子节点下 也就是根节点的位置 
	int y=0;
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
	rt=x;
}

int Insert(int key){
	int ptr=rt,y=0;//y一定要设置为0，不然添加根节点的时候会出错 
	int lrChose=0;
	while(1){
		if(!ptr){
			ptr=++pnum;
			l[ptr]=r[ptr]=0;
			f[ptr]=y;
			d[ptr]=key;
			if(y){
				if(!lrChose) l[y]=ptr;
				else r[y]=ptr;
			}
			Splay(ptr);
			return ptr;
		}
		y=ptr;
		if(key==d[ptr]) return -1;
		else if(key<d[ptr]){
			lrChose=0;
			ptr=l[ptr];
		}else{
			lrChose=1;
			ptr=r[ptr];
		}
	}
} 

void Join(int n1,int n2){
	f[n1]=f[n2]=0;
	if(!n1){rt=n2;return;}
	if(!n2){rt=n1;return;}
	
	if(d[n1]>d[n2]) swap(n1,n2);
	int temp=n1;
	while(r[temp]) temp=r[temp];
	Splay(temp);//将最大的根调到树顶
	
	 r[temp]=n2;
	 f[n2]=temp;
	 rt=temp;
}

void Delete(int x){
	Splay(x);
	Join(l[x],r[x]);
}

int Find(int key){
	int temp=rt;
	while(d[temp]!=key){
		if(!temp) return -1;
		else if(key<d[temp]) temp=l[temp];
		else temp=r[temp];
	}
	return temp;
}

int Getmin(int x){
	if(!x) return -1;	
	int temp=x;
	while(l[temp]) temp=l[temp];
	
	Splay(temp);
	x=d[temp];
	Join(l[temp],r[temp]);
	return x;
}

int Getmax(int x){
	if(!x) return -1;
	int temp=x;
	while(r[temp]) temp=r[temp];
	
	Splay(temp);
	x=d[temp];
	Join(l[temp],r[temp]);
	return x;
}

int main(){
//	freopen("out.txt","w",stdout);
	int n,t;
	scanf("%d",&n);
	srand(unsigned(time(NULL)));
	printf("input:");
	for(int i=1;i<=n;i++){
		t=rand()%1000000;
		printf("%d ",Insert(t)); 
	}
	printf("\noutput:");
	
	for(int i=1;i<=n;i++){
		int t=Getmin(rt);
		if(t==-1) break;
		printf("%d ",t);
	}
	
}
