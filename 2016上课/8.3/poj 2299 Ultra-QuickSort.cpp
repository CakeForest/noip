#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 500020
using namespace std;
int n,m,p,t[MAX],data[MAX];
long long e[MAX],s,ans;
int lowbit(int i){
	return -i&i;
}
void add(int x,int p){
	for(;x<=n;x+=lowbit(x))
		e[x]+=p;
}

long long sum(int x){
	for(s=0;x>0;x-=lowbit(x))
		s+=e[x];
	return s;
}

int Find(int s,int e,int aim){
	while(s<=e){
		int m=(s+e)>>1;
		if(t[m]==aim) return m;
		if(t[m]>aim) e=m-1;
		else s=m+1;
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)&&n){
		memset(e,0,sizeof(e));
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&data[i]);
			t[i]=data[i];
		}
		sort(t+1,t+n+1);
		m=unique(t+1,t+n)-t;
		for(int i=1;i<=n;i++){
			int f=Find(1,m,data[i]);//找离散优化对应元素 
			ans+=sum(n)-sum(f);//每次看比此数大的数有几个 
			add(f,1);//将此数加入 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
