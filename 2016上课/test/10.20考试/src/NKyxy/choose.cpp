#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int need=200003;

int f[2][need][2];
int a[need];

//......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......
inline void in_(int &d)
{
	char t=getchar();bool mark=0;
	while(t<'0'||t>'9') {if(t=='-') mark=true;t=getchar();}
	for(d=0;!(t<'0'||t>'9');t=getchar()) d=(d<<1)+(d<<3)+t-'0';
	if(mark) d=-d;
	d+=1001;
	//return mark ? d=-d+1000 : d+=1000;
}
//......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......

int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	if((n>>1)<m) 
	{
		puts("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++) in_(a[i]);
	f[1][1][0]=0,f[1][1][1]=a[1];
	for(int i=1,j,ii;i<=n;i++)
	{
		for(j=1,ii=(i+1)>>1;j<=ii&&j<=m;j++)
		{
			f[i&1][j][0]=max(f[(i-1)&1][j][0],f[(i-1)&1][j][1]);
			f[i&1][j][1]=f[(i-1)&1][j-1][0]+a[i];
		}
	}
	int f0=f[n&1][m][0],f1=f[n&1][m][1];
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%3d %3d     ",f[i][j][0]-1000*j<0 ? -1 :f[i][j][0]-1000*j,f[i][j][1]-1000*j<0 ? -1:f[i][j][1]-1000*j);
		puts("");
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%3d %3d     ",f[i][j][0]-1000*j<0 ? -1 :f[i][j][0]-1000*j,f[i][j][1]-1000*j<0 ? -1:f[i][j][1]-1000*j);
		puts("");
	}*/
	//cout<<f0-m*1000<<" "<<f1-m*1000<<endl;
	
	memset(f,0,sizeof(f));
	f[n&1][1][0]=0,f[n&1][1][1]=a[n];
	for(int i=n,j,ii;i>=1;i--)
	{
		for(j=1,ii=(n-i+2)>>1;j<=ii&&j<=m;j++)
		{
			f[i&1][j][0]=max(f[(i+1)&1][j][0],f[(i+1)&1][j][1]);
			f[i&1][j][1]=f[(i+1)&1][j-1][0]+a[i];
		}
	}
	int g0=f[1][m][0],g1=f[1][m][1];
	cout<<max(f0,g0)-m*1001;
	fclose(stdin);
	fclose(stdout);
}
