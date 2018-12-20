#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=200005;
const int inf=0x3f3f3f3f;
inline void _read(int &x){
    char t=getchar();bool sign=true;
    while(t<'0'||t>'9')
    {if(t=='-')sign=false;t=getchar();}
    for(x=0;t>='0'&&t<='9';t=getchar())x=x*10+t-'0';
    if(!sign)x=-x;
}
int n,m;
int ans;
int a[maxn];
int f[5005][2505];
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	if(m>(n/2)){
		puts("Error!");
		return 0;
	}
	for(i=1;i<=n;i++){
		_read(a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			f[i][j]=-inf;
		}
	}
	f[1][1]=a[1];
	for(i=2;i<n;i++){
		for(j=1;j<=min(i,m);j++){
			f[i][j]=f[(i-1)][j];
			f[i][j]=max(f[i][j],f[(i-2)][j-1]+a[i]);
		}
	}
	f[n][m]=f[(n-1)][m];
	ans=max(ans,f[n][m]);
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			f[i][j]=-inf;
		}
	}
	for(i=2;i<=n;i++){
		for(j=1;j<=min(i,m);j++){
			f[i][j]=f[(i-1)][j];
			f[i][j]=max(f[i][j],f[(i-2)][j-1]+a[i]);
		}
	}
	ans=max(ans,f[n][m]);
	cout<<ans;
}
/*
f[i][j][k]:前i个数，选了j个数，k表示a[1]选没选 
*/
