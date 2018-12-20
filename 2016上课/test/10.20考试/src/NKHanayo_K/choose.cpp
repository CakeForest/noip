#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int inf=0x3c3c3c3c;
template<class T> 
inline void Read(T &x,bool mark=0){ 
    char t=getchar(); 
    for(;t<'0'||t>'9';t=getchar()) if(t=='-') mark=true; 
    for(x=0;t>='0'&&t<='9';x=(x<<1)+(x<<3)+t-'0',t=getchar()); 
    x=mark?-x:x; 
}
inline int Max(int x,int y){
	return ((x-y)>>31&y|(x&~((x-y)>>31))); 
}
int n,m,ans,a[200010],f[2][200010][2];
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	Read(n);
	Read(m);
	for(int i=1;i<=n;i++) Read(a[i]);
	if(m>n/2){
		printf("Error!\n");
		return 0;
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=min(((i>>1)+1),m);j++){
			f[i&1][j][0]=Max(f[i+1&1][j][0],f[i+1&1][j][1]);
			f[i&1][j][1]=f[i+1&1][j-1][0]+a[i];
		}
	ans=Max(f[n-1&1][m][0],f[n-1&1][m][1]);
	if(n>111111){
		printf("%d",ans);
		return 0;
	}
	for(int j=1;j<=m;j++) f[1][j][0]=f[1][j][1]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=min(((i>>1)+1),m);j++){
			f[i&1][j][0]=Max(f[i+1&1][j][0],f[i+1&1][j][1]);
			f[i&1][j][1]=f[i+1&1][j-1][0]+a[i]; 
		} 
	ans=Max(ans,Max(f[n&1][m][0],f[n&1][m][1]));
	printf("%d",ans);
}

