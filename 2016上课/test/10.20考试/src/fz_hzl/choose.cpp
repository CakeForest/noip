#include <cstdio>
#include <cstring>
using namespace std; 
const int MAXN=40100;
int inline read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int nu[MAXN];
int f[MAXN][2]={0};
int a[MAXN]={0},b[MAXN]={0};
int ans=0;
int inline Max(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m;
	n=read();m=read();
	if((n>>1)<m){
		printf("Error!\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		nu[i]=read();
	}
	
	for(int i=1;i<n;i++){
		for(int j=i-(i>>1);j;j--){
			a[j]=Max(a[j],b[j]);
			b[j]=a[j-1]+nu[i];
		}
	}
	
	ans=Max(a[m],b[m]);
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=2;i<=n;i++){
		for(int j=i-(i>>1);j;j--){
			a[j]=Max(a[j],b[j]);
			b[j]=a[j-1]+nu[i];
		}
	}
	ans=Max(ans,Max(a[m],b[m]));
	printf("%d\n",ans);
	return 0;
}
