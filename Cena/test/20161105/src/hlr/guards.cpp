#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{int x,y;};
int m,n,map[300][300];
int tag[2][300][300],lx[300][300],ly[300][300];
bool ans[300][300],t[300][300];
int cnt,maxx=-1;

node nxt(node p){
	if(p.y==m){
		if(p.x==n) p.x=-1,p.y=-1;
		else p.y=1,p.x++;
	}else p.y++;
	return p;
}

int now;
bool flag;
void dfs(node p){
	if(flag) return;
	if(cnt>=now){
		memcpy(ans,t,sizeof(t));
		flag=1;
		return;
	}
	if(p.x==-1&&p.y==-1) return;
	if(!map[p.x][p.y]){
		if(!lx[p.x][tag[0][p.x][p.y]]&&!ly[p.y][tag[1][p.x][p.y]]){
			lx[p.x][tag[0][p.x][p.y]]=1;
			ly[p.y][tag[1][p.x][p.y]]=1;
			t[p.x][p.y]=1;
			cnt++;
			dfs(nxt(p));
			cnt--;
			t[p.x][p.y]=0;
			ly[p.y][tag[1][p.x][p.y]]=0;
			lx[p.x][tag[0][p.x][p.y]]=0;
		}
	}
	dfs(nxt(p));
}

bool judge(int m){
	now=m;
	node p;
	p.x=1; p.y=1;
	flag=0;
	dfs(p);
	return flag;
}

int main(){
	freopen("guards.in","r",stdin);
	freopen("guards.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int s=0,e=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if(!map[i][j]) e++;
		}
	
	for(int i=1;i<=n;i++){ // ºáÐÐ 
		int t=1;
		for(int j=1;j<=m;j++){
			if(!map[i][j]) tag[0][i][j]=t;
			else if(map[i][j]==2) t++;
		}
	}
	
	for(int j=1;j<=m;j++){ //  ÊúÁÐ
		int t=1;
		for(int i=1;i<=n;i++){
			if(!map[i][j]) tag[1][i][j]=t;
			else if(map[i][j]==2) t++;
		}
	}
	
//	node s; s.x=1;s.y=1;
	
	while(s<=e){
		int mid=(s+e)>>1;
		if(judge(mid)) s=mid+1;
		else e=mid-1;
	}
	
//	dfs(s);
	
	printf("%d\n",e);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]) printf("%d %d\n",i,j);
	
	return 0;
}
