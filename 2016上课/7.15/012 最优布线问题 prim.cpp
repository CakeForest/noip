#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=120;
int map[MAX][MAX];
int n,sum,minn[MAX],vis[MAX],l;

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			map[i][j]=99999999;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&l),map[i][j]=l;
	for(int i=1;i<=n;i++)
		minn[i]=map[1][i];
	vis[1]=1; minn[1]=0;//初始化 
	for(int i=1;i<=n-1;i++){
		int minj=99999999,choose;
		for(int j=2;j<=n;j++)//遍历所有点 
			if(vis[j]==0&&minn[j]<minj)//找当前距离最小的边 
				minj=minn[j],choose=j;
		sum+=minj;//计算距离 
		vis[choose]=1;
		for(int j=1;j<=n;j++)//更新minn 
			if(vis[j]==0&&minn[j]>map[choose][j])
				minn[j]=map[choose][j];
	}	
	printf("%d",sum);

	
	return 0;
}
