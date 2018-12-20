#include <cstdio>
#include <algorithm>

using namespace std; 

const int MAXN = 1000+100;
int xn=0;
int x[MAXN+MAXN],a[MAXN],b[MAXN],flag[MAXN+MAXN];

void cover(int s,int e){
	for(int i=s;i<e;i++)
		flag[i]=1;
}

int geti(int q){
	int m,s=1,e=xn;
	while(s<=e){
		m=(s+e)>>1;
		if(x[m]==q) return m;
		if(x[m]<q) s=m+1;
		if(x[m]>q) e=m-1; 
	}
	return -1;
}

int main()
{
	freopen("cover10.in","r",stdin);
	freopen("cover10.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		x[((i-1)<<1)+1]=a[i];
		x[i<<1]=b[i];
	}
	sort(x+1,x+2*n+1);

	//将相同坐标去重
	x[0]=-99999999;xn=0;
	for(int i=1;i<=(n<<1);i++)
		if(x[i]!=x[xn])
			x[++xn]=x[i];
	/*
	for(int i=1;i<=xn;i++)
		printf("%d ",x[i]);
	*/
	
	
	int s,e;
	for(int i=1;i<=n;i++){
		s=geti(a[i]);
		e=geti(b[i]);
	//	if(s<0 || e<0) printf("wrong!!!!%d %d %d %d %d\n",i,a[i],b[i],s,e);
		cover(s,e);
	}
	long long ans=0;
	for(int i=1;i<xn;i++){
		if(flag[i]){
			ans+=x[i+1]-x[i];
		}
	}
	printf("%lld",ans);
}
