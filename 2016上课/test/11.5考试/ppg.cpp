#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int s,t;
	int time;
}t[3000];
int x[100],y[100],fa[3000];
int n,tnum;

int getfa(int p){
	if(p==fa[p]) return p;
	return fa[p]=getfa(fa[p]);
}

void unions(int f,int s){
	f=getfa(f); s=getfa(s);
	if(f!=s) fa[s]=f;
}

bool cmp(node a,node b){return a.time<b.time;}
int main(){
	freopen("ppg.in","r",stdin);
	freopen("ppg.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			t[++tnum].s=i,t[tnum].t=j;
			t[tnum].time=(abs(x[i]-x[j])+abs(y[i]-y[j]))>>1;
			if((abs(x[i]-x[j])+abs(y[i]-y[j]))&1) t[tnum].time++;
		}
	sort(t+1,t+1+tnum,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0,cnt=0;
	for(int i=1;i<=tnum;i++){
		if(cnt==n-1) break;
		if(getfa(t[i].s)!=getfa(t[i].t)){//不属于同一集合 
			ans=t[i].time;//取最大值 
			unions(t[i].s,t[i].t);
			cnt++;
		}
	}
	printf("%lld",ans);
	
	return 0;
}
