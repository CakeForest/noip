#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000020;
int fr[MAX],l[MAX],r[MAX],t[MAX];
int n,m,c[MAX];

int add(int l,int r,int p){
	c[l]+=p;
	c[r+1]-=p;
}

bool judge(int k){
	memset(c,0,sizeof(c));
	for(int i=1;i<=k;i++)
		add(l[i],r[i],t[i]);
	
	int now=0;
	for(int i=1;i<=n;i++){
		now+=c[i];
		if(now>fr[i]) return false;
	}
	return true;
}

int find(int s,int e){
	while(s<=e){
		int mid=(s+e)>>1;
		if(judge(mid)) s=mid+1;
		else e=mid-1;
	}
	if(judge(s)) return 0;
	return s;
}

int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&fr[i]);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&t[i],&l[i],&r[i]);
	
	int ans=find(1,m);
	if(!ans) printf("0");
	else printf("-1\n%d",ans);
	
	return 0;
}
