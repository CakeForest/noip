#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[120][120];
char str[10];
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++){
			scanf("%s",str);
			if(str[0]=='x') f[i][j]=99999999;
			else f[i][j]=atoi(str);
			f[j][i]=f[i][j];
		}
		
/*	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)
		printf("%d ",f[i][j]);
		printf("\n");
	}	*/
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int maxx,minx=99999999;
/*	for(int i=1;i<=n;i++){
		maxx=-1;
		for(int j=1;j<=n;j++)
			maxx=max(maxx,f[i][j]);
		minx=min(minx,maxx);
	}
	printf("%d",minx);*/
	
	maxx=-1;//注意，这道题是从左上角开始广播 
	for(int i=1;i<=n;i++)
		maxx=max(maxx,f[1][i]);
	printf("%d",maxx);
	
	
/*	printf("\n");printf("\n");
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)
		printf("%d ",f[i][j]);
		printf("\n");
	}	*/
	
	return 0;
}
