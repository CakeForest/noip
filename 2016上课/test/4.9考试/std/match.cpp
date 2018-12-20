#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100010
#define MAX 99999997
struct saver{
  int v,t;
};
saver a[MAXN],b[MAXN];

bool cmp(saver x,saver y){
  return x.v<y.v;
}

int n,r[MAXN],ans=0;
int t[MAXN],h[MAXN];

int merge(int x,int m,int y){
	int ans=0;
	int p=x,q=m+1,i=x;
	while(p<=m && q<=y){
		if(r[p]<r[q]) h[i++]=r[p++];
		else h[i++]=r[q++],ans+=m+1-p;;
	}
	if(p<=m){
		while(p<=m) h[i++]=r[p++]; 
	}
	if(q<=y){
		while(q<=y) h[i++]=r[q++],ans+=m+1-p; 
	}
	for(i=x;i<=y;i++) r[i]=h[i];
	return ans; 
}

int mergeSort(int s,int e){
	 
	int ans=0;
    if(e-s<=0) return 0;
	int m=(e+s)/2;
	ans=(ans+mergeSort(s,m))%MAX;
	ans=(ans+mergeSort(m+1,e))%MAX;
	ans=(ans+merge(s,m,e))%MAX;
	//printf("%d %d %d\n",s,e,ans);
	return ans;
}

int main(){
	 freopen("match.in","r",stdin);
	 freopen("match.out","w",stdout);
	 scanf("%d",&n);
	 for(int i=0;i++<n;) scanf("%d",&a[i].v),a[i].t=i;
	 for(int i=0;i++<n;) scanf("%d",&b[i].v),b[i].t=i;
	 sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp);
	 for(int i=0;i++<n;) r[a[i].t]=b[i].t;
	 
	  
	 printf("%d\n",mergeSort(1,n));
	 return 0;
}
