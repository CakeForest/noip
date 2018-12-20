#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;

int l[MAX],r[MAX],d[MAX],f[MAX],w[MAX],val[MAX],rt,pnum;

void Zig(int x){//顺时针 
	int y=f[x];
	l[y]=r[x];
	if(l[y]) f[l[y]]=y;
	f[x]=f[y];
	if(f[x]){
		if(l[f[x]]==y) l[f[x]]=x;
		else r[f[x]]=x;
	}
	f[y]=x;
	r[x]=y;
	w[x]=w[l[x]]+w[r[x]]+val[x];//加上自重 
	w[y]=w[l[y]]+w[r[y]]+val[y];
}

void Zag(int x){//逆时针 
	int y=f[x];
	r[y]=l[x];
	if(r[y]) f[r[y]]=y;
	f[x]=f[y];
	if(f[x]){
		if(l[f[x]]==y) l[f[x]]=x;
		else r[f[x]]=x;
	}
	f[y]=x;
	l[x]=y;
	w[x]=w[l[x]]+w[r[x]]+val[x];//加上自重 
	w[y]=w[l[y]]+w[r[y]]+val[y];
}

void Splay(int x){
	int y=0;
	while(f[x]!=y){
		if(f[f[x]]==y)
			l[f[x]]==x?Zig(x):Zag(x);
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
	f[x]=0;
}

void Insert(int key){
	int y=0,ptr=rt;
	bool lrChose=0;
	while(1){
		if(!ptr){
			ptr=++pnum;
			d[ptr]=key;
			val[ptr]=1;
			l[ptr]=r[ptr]=0;
			f[ptr]=y;
			if(y){
				if(!lrChose) l[y]=ptr;
				else r[y]=ptr;
			}
			Splay(ptr);
			break;
		}
		y=ptr;
		if(key==d[ptr]){
			val[ptr]++;
			Splay(ptr);
			break;
		}else if(key<d[ptr]){
			lrChose=0;
			ptr=l[ptr];
		}else{
			lrChose=1;
			ptr=r[ptr];
		}
	}
}

void Join(int n1,int n2){
	if(!n1){rt=n2;return;}
	if(!n2){rt=n1;return;}
	
	f[n1]=f[n2]=0;
	if(d[n1]>d[n2]) swap(n1,n2);
	while(r[n1]) n1=r[n1];
	Splay(n1);
	r[n1]=n2;
	f[n2]=n1;
}

void Delete(int x){
	val[x]--;
	Splay(x);
//	else Join(l[x],r[x]);
}

void readint(int &num){
	num=0; char ch;
	while((ch=getchar())<'0'||ch>'9');
	num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
}

int Findprev(int x){
	int now=d[x];
	while(!val[x]){//当val==0时点不存在 
		if(l[x]){
			x=l[x]; now=d[x];
			while(r[x]) x=r[x];
		}else{
			while(d[x]!=now) x=f[x];
			x=f[x]; now=d[x];
		}
		if(val[x]>0) return x;
	}
}

int Findmax(){
	int x=rt;
	while(r[x]) x=r[x];
	if(!val[x]) x=Findprev(x);
	Splay(x);
	return x;
}

int Findkth(int k){
	int x=rt;
	while(1){
		if(w[l[x]]>=k){//在左树里面
			x=l[x];
		}else if(k-w[l[x]]<=val[x]){//当前点 
			return x;
		}else{
			k-=w[l[x]]+val[x];
			x=r[x];
		}
	}
}

int anti_kth(int k){
	int x=rt;
	while(1){
		if(w[r[x]]>=k){//在左树里面
			x=r[x];
		}else if(k-w[r[x]]<=val[x]){//当前点 
			return x;
		}else{
			k-=w[r[x]]+val[x];
			x=l[x];
		}
	}
	
}

int main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	int n,m,q,u,v,t;
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	double p=1.0*u/v;
	int temp;
	for(int i=1;i<=n;i++){
		readint(temp);
		Insert(temp);
	}
	
/*每次将最长的所有蚯蚓取出来，一只切掉
	另外计算好长度insert 
*/	
	int p1,p2,len; int lenadd=0;
	for(int i=1;i<=m;i++){
		temp=Findmax();
		Delete(temp);
		len=d[temp]+lenadd;//之前增加的长度加上原本的长度 
		lenadd+=q;
		if(i%t==0){
			printf("%d ",len);
		}
		p1=int(len*p);
		p2=int(len-int(p1));
		p1-=lenadd;//算出差值 
		p2-=lenadd;
		Insert(p1);
		Insert(p2);
	}
	if(m<t) printf(" ");//没有输出 
	printf("\n");
	
	for(int i=1;i<=(n+m)/t;i++)
		printf("%d ",d[anti_kth(t*i)]+lenadd);
	
}
