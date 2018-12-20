#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N,M,ans = 0x3c3c3c3c;
int X[500],Y[500],V[500],lim;
int f[1<<18],c[1<<18];
int fa[20],A[20]; int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int vis[20];
struct node{
	int x,y,v;	
	bool operator <(const node& b)const{
		return v<b.v;	
	}
	node(){}
	node(int _x,int _y,int _v):x(_x),y(_y),v(_v){}
};

int sol(int x){
	memset(vis,0,sizeof(vis));
	int ans = 0,n = 0;
	for(int i=0;i<N;i++) fa[i]=i;
	for(int i=0;i<N;i++){
		if(x & (1<<i)) n++, vis[i] = 1;
	}
	
	vector<node> E;
	for(int i=1;i<=M;i++){
		if(vis[X[i]] && vis[Y[i]]){
			E.push_back(node(X[i],Y[i],V[i]));
		}
	}
	
	sort(E.begin(), E.end());
	for(int i=0;i<E.size();i++){
		int u = E[i].x, v = E[i].y, w = E[i].v;
		int uu = getfa(u), vv = getfa(v);
		if(uu != vv){
			ans += w;
			fa[uu] = vv;
			n--;
		}
	}
	if(n==1) return ans;
	return 0x3c3c3c3c;
}

int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	memset(c,0x3c,sizeof(c));
	memset(f,0x3c,sizeof(f));
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&X[i],&Y[i],&V[i]);
	}
	lim = (1<<N);
	for(int i=1;i<lim;i++){
		int t = 0;
		for(int j=0;j<N;j++){
			if(i&(1<<j)){
				t += A[j];	
			}
		}
		if(!t) c[i] = sol(i);
	}
	f[0] = 0;
	for(int i=1;i<lim;i++){
		f[i] = c[i];
		for(int j=(i&i-1);j;j=(j-1&i))
			f[i] = min(f[i], f[j]+c[i^j]);	
	}
	if(f[lim-1]==0x3c3c3c3c) cout<<"Impossible"<<endl;
	else cout<<f[lim-1]<<endl;
}
