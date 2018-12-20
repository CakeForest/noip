#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
	int a,b,len;
	friend bool operator <(node a,node b){
		return a.len<b.len;
	}
} edge[150];

int fa[15],po[15];
int n,m;

int getfa(int x){
	if(fa[x]!=x) fa[x]=getfa(fa[x]);
	return fa[x];
}

int klskr(){
	int x,y,k=0,cnt=0,tot=0;
	
	while(cnt<n-1){
		k++;
		x=getfa(edge[k].a);
		y=getfa(edge[k].b);
		if(x!=y){
			fa[x]=y;
			po[y]+=po[x];
			po[x]=0;
			tot=tot+edge[k].len;
			cnt++;
		}
	}
	
	return tot;
}

int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);	

	scanf("%d%d",&n,&m);
	int tmp,i;
	for(i=0;i<n;i++){
		scanf("%d",&po[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].len);
	}
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edge+1,edge+m+1);
	tmp=klskr();
	for(i=1;i<=n;i++){
		if(po[i]!=0) {
			puts("Impossible");
			return 0;
		}
	}
	
	cout<<tmp;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
