#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
	freopen("pane2.in","r",stdin);
	//freopen("pane.out","w",stdout);
	int f[12][12][12][12],pane[12][12];
	int n;
	int i,j,k,l;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			for(k=1;k<=n;k++)
				for(l=1;l<=n;l++)
					pane[i][j]=0,f[i][j][k][l]=0;
		
	scanf("%d",&n);
	int x,y,z;
	while(scanf("%d %d %d",&x,&y,&z)!=EOF)
	{
		pane[x][y]=z;
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				for(l=1;l<=n;l++)
				{
					f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k-1][l]);
                    f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l-1]);
                    f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k-1][l]);
                    f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l-1]);
					if(i==k&&j==l)
						f[i][j][k][l]=f[i][j][k][l]+pane[i][j];
					else
						f[i][j][k][l]=f[i][j][k][l]+pane[i][j]+pane[k][l];
				}
			}
		}
	}
		
	printf("%d",f[n][n][n][n]);

	return 0;
}
