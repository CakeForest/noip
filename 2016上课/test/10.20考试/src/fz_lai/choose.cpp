#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int MAXN=2016,TEMPMAXN=4e4+5;
int f[MAXN][MAXN>>1+1][2],data[MAXN],n,m,g[TEMPMAXN>>1+1][2];
int inline readint()
{
	int Num=0,Flag=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') Flag=-1; else Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num*Flag;
}
int inline sovle1()
{
	int ans=INT_MIN;
	memset(f,0,sizeof(f));
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=i-(i>>1);j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=f[i-1][j-1][0]+data[i];
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,max(f[i][m][0],f[i][m][1]));
	memset(f,0,sizeof(f));
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-(i>>1);j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=f[i-1][j-1][0]+data[i];
		}
	}
	for(int i=2;i<=n;i++) ans=max(ans,max(f[i][m][0],f[i][m][1]));
	return ans;
}
int inline sovle2()
{
	int ans=INT_MIN;
	memset(g,0,sizeof(g));
	for(int i=1;i<n;i++)
	{
		for(int j=i-(i>>1);j>=1;j--)
		{
			g[j][0]=max(g[j][0],g[j][1]);
			g[j][1]=g[j-1][0]+data[i];
		}
		ans=max(ans,max(g[m][0],g[m][1]));
	}
	memset(g,0,sizeof(g));
	for(int i=2;i<=n;i++)
	{
		for(int j=i-(i>>1);j>=1;j--)
		{
			g[j][0]=max(g[j][0],g[j][1]);
			g[j][1]=g[j-1][0]+data[i];
		}
		ans=max(ans,max(g[m][0],g[m][1]));
	}
	return ans;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	n=readint(),m=readint();
	if((m<<1)>n){
		printf("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++) data[i]=readint();
	if(n<2016) printf("%d",sovle1());
	else printf("%d",sovle2());
	return 0;
}
