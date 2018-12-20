#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,map[12][12],f[12][12][12][12];

int main()
{
	freopen("pane.in","r",stdin);
	freopen("pane.out","w",stdout);
	scanf("%d",&n);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
		if(a!=0&&b!=0&&c!=0) 
			map[a][b]=c;
		else break;
	for(int i1=1;i1<=n;i1++)
		for(int j1=1;j1<=n;j1++)
			for(int i2=1;i2<=n;i2++)
				for(int j2=1;j2<=n;j2++)
				{
					int temp[4];
					temp[0]=f[i1-1][j1][i2-1][j2];
					temp[1]=f[i1-1][j1][i2][j2-1];
					temp[2]=f[i1][j1-1][i2-1][j2];
					temp[3]=f[i1][j1-1][i2][j2-1];
					sort(temp,temp+4);
					f[i1][j1][i2][j2]=temp[3]+map[i1][j1]+(i1==i2&&j1==j2?0:map[i2][j2]);
				}
	printf("%d",f[n][n][n][n]);
		
	return 0;
}
