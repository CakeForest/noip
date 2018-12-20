#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2e5+5,inf=0x3f3f3f3f;
int n,m,s[maxn],f[1005][1005];
inline void _read(int &x){ 
    char t=getchar();bool sign=true; 
    while(t<'0'||t>'9') 
    {if(t=='-')sign=false;t=getchar();} 
    for(x=0;t>='0'&&t<='9';t=getchar())x=x*10+t-'0'; 
    if(!sign)x=-x; 
} 
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	memset(f,-inf,sizeof(f));
	cin>>n>>m;
	int i,j,ans;
	for(i=1;i<=n;i++)f[i][0]=0;
	for(i=1;i<=n;i++)_read(s[i]);
	if(m>n/2){
		puts("Error!");
		return 0;
	}
	f[1][1]=s[1];
	for(i=2;i<n;i++)
		for(j=1;j<=min(m,i);j++)
		    f[i][j]=max(f[i-1][j],f[i-2][j-1]+s[i]); 
	ans=f[n-1][m];
	memset(f,-inf,sizeof(f));
	for(i=1;i<=n;i++)f[i][0]=0;
	for(i=2;i<=n;i++)
	    for(j=1;j<=min(m,i);j++)
	        f[i][j]=max(f[i-1][j],f[i-2][j-1]+s[i]);
	ans=max(ans,f[n][m]);
	cout<<ans;
}
