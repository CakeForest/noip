#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 99999997
using namespace std;
const int MAX=100020;
struct node{
	int p,id;
}a[MAX],b[MAX];
long long sum;
int r[MAX],h[MAX];

bool cmp(node x,node y){return x.p<y.p;}

void Merge(int x,int m,int y){
	int p=x,q=m+1,k=x;
	while(p<=m&&q<=y){
		if(r[p]<r[q]) h[k++]=r[p++];
		else h[k++]=r[q++],sum=(sum+m-p+1)%mod;
	}
	if(p<=m){
		while(p<=m) h[k++]=r[p++];
	}
	if(q<=y){
		while(q<=y) h[k++]=r[q++],sum=(sum+m-p+1)%mod;
	}
	for(k=x;k<=y;k++) r[k]=h[k];
}

void MergeSort(int l,int r){
	if(l>=r) return;
	int m=(l+r)>>1;
	MergeSort(l,m); sum%=mod;
	MergeSort(m+1,r); sum%=mod;
	Merge(l,m,r); sum%=mod;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);

	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].p),a[i].id=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i].p),b[i].id=i;
	sort(a+1,a+1+n,cmp); sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) r[a[i].id]=b[i].id;
	MergeSort(1,n);
	
	printf("%d",sum%mod);
	
	return 0;
}
