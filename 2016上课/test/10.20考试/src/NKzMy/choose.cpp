#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline int R(){
	char tt=getchar();int o,f=0;
	while(tt<'0'||tt>'9'){if(tt=='-')f=1;tt=getchar();}
	for(o=0;tt>='0'&&tt<'9';tt=getchar())o=o*10+tt-'0';	
	return f?-o:o;
}

int f[3005][3005][2],a[3005];
int n,m,ans=-99999999;
struct node{int x,y;};bool cmp(node a,node b){return a.x<b.x;}

int main(){
		freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	n = R(), m = R();
	for(int i=1;i<=n;i++) a[i] = R();
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j][0] = f[i][j][1] = -99999999;
	f[0][0][0] = f[0][0][1] = 0;
	
	for(int i=1;i<=n-1;i++){
		for(int j=0;j<=m;j++){
			f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]);
			if(j >= 1) f[i][j][1] = f[i-1][j-1][0] + a[i];
		}
 	}
	ans = max(f[n-1][m][0],f[n-1][m][1]);
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j][0] = f[i][j][1] = -99999999;
	f[1][0][0] = f[1][1][0] = 0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m;j++){
			f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]);
			if(j >= 1) f[i][j][1] = f[i-1][j-1][0] + a[i];
		}
	}
	ans = max(ans, max(f[n][m][0],f[n][m][1]));
	
	cout<<ans<<endl;
}
