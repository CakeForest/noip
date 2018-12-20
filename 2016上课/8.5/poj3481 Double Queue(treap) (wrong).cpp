#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1e7+10;
int l[MAX],f[MAX],r[MAX],p[MAX],d[MAX],key[MAX],rt;

int random(){
    int seed=233; //seed可以随便取
    return seed=int(seed*48271LL%1000000000);
}

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

void update(int x,int y){//////////
	while(f[x]!=y){
		if(p[x]<p[f[x]]){
			if(l[f[x]]==x) Zig(x);
			else Zag(x);
		}
	}
	if(y==0) rt=x;
}

void Insert(int id,int key){
	int ptr=rt,y=0;
	int lrChose=0;
	while(1){
		if(!ptr){
			ptr=id;
			l[ptr]=r[ptr]=0;
			d[ptr]=key;
			p[ptr]=random();
			f[ptr]=y;
			if(y!=0){
				if(lrChose==0) l[f[y]]=ptr;
				else r[f[y]]=ptr;
			}
			update(ptr,0);
			break;
		}
		y=ptr;
		if(key<d[ptr]){
			ptr=l[ptr];
			lrChose=0;
		}else{
			ptr=r[ptr];
			lrChose=1;
		}
	}
}

int GetMax(){
	int temp=rt;
	while(r[temp]) temp=r[temp];
	return temp;
}

int GetMin(){
	int temp=rt;
	while(l[temp]) temp=l[temp];
	return temp;
}

void Delete(int x){
//	update(x);///
	
}

int main(){
	freopen("in.txt","r",stdin);
	int cmd,K,P,temp;
	while(~scanf("%d",&cmd)&&cmd){
		if(cmd==1){
			scanf("%d%d",&K,&P);
			Insert(K,P);
		}else if(cmd==2){
			printf("%d\n",temp=GetMAX());
			Delete(temp);
		}else{
			printf("%d\n",temp=GetMin());
			Delete(temp);
		}
	}
	
	return 0;
}
