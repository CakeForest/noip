#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,map[120][120],ans[120][120]={0};

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&map[i][j]);
	
	ans[1][1]=map[1][1];
	for(int i=2;i<=n;i++)
	{
		ans[i][1]=map[i][1]+ans[i-1][1];
		ans[i][i]=map[i][i]+ans[i-1][i-1];
		for(int j=2;j<=i-1;j++)
		{
			int left=ans[i-1][j-1];
			int right=ans[i-1][j];
			ans[i][j]=map[i][j]+(left>right?left:right);
		}
	}
	int max=-1;
	for(int i=1;i<=n;i++)
		if(ans[n][i]>max)
			max=ans[n][i];
	printf("%d",max);
		
	return 0;
}
