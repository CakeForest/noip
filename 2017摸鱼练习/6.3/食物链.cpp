#include<cstdio>

const int INF=99999999;
const int MAX=52000;
int fa[MAX],dist[MAX],ans,n,k;

int getfa(int p){
	if(fa[p]==p) return p;
	int t=fa[p];
	fa[p]=getfa(fa[p]);
	dist[p]=(dist[p]+dist[t])%3;
	return fa[p];
}

void unions(int X,int Y,int val){
	int a=getfa(X),b=getfa(Y);
	fa[a]=b;
	dist[a]=(val+dist[Y]+INF)%3;
}

bool judge(int s1,int s2,int delta){
	int t=s1-s2;
	if((t+INF)%3==delta) return true;
	return false;
}

//都是新生物 不会矛盾
//一个是新生物 不会矛盾
//两个都不是新生物 用并查集合并  

//fa[a]=b a吃b 
//用并查集的距离表示吃与被吃的关系 


int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	int D,X,Y;
	
	for(int i=1;i<=n;i++)
		fa[i]=i;

	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&D,&X,&Y);
		if(X>n||Y>n){ans++;continue;}
		int a,b,ok;
		a=getfa(X); b=getfa(Y); 
		if(D&1){
			if(a!=b)//两个集合无关系
				unions(X,Y,0);
			else if(!judge(dist[X],dist[Y],0)) 
				ans++;//有公共祖先
		}else{
			if(a!=b)
				unions(X,Y,1);
			else if(!judge(dist[X],dist[Y],1))			
				ans++;
		}
	}
	
	printf("%d",ans);
}
