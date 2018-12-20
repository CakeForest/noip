#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 99999997
using namespace std;
const int MAX=100020;
struct node{
	int p,id;
}a[MAX],b[MAX];
int r[MAX],e[MAX],t[MAX],n;
long long ans;

bool cmp(node x,node y){
	return x.p<y.p;
}

int lowbit(int p){
	return -p&p;
}

void add(int x,int p){
	while(x<=n){
		e[x]+=p;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ans=0;
	while(x){
		ans+=e[x];
		x-=lowbit(x);
	}
	return ans%mod;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].p),a[i].id=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i].p),b[i].id=i;
	sort(a+1,a+1+n,cmp); sort(b+1,b+1+n,cmp);
	sort(r+1,r+1+n);
	for(int i=1;i<=n;i++) r[a[i].id]=b[i].id;
	
	for(int i=1;i<=n;i++){
		ans=(ans+sum(n)-sum(r[i]))%mod;
		add(r[i],1);
	}
	printf("%d",ans%mod);
	
	return 0;
}
