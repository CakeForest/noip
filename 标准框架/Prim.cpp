#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1200;
int map[MAX][MAX],ans,minn[MAX];
int main(){
	int n,c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		for(int j=1;j<=n;j++)
			map[i][j]=99999999;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c),map[i][j]=c;
	for(int i=1;i<=n;i++)
		minn[i]=map[1][i];
	minn[1]=0;//初始化 
	for(int i=1;i<=n-1;i++){//只能遍历n-1次 
		int minj=99999999,choose;
		for(int j=2;j<=n;j++)//遍历所有点 
			if(minn[j]&&minn[j]<minj)//找当前距离最小的边 
				minj=minn[j],choose=j;
		sum+=minj;//计算距离 
		minn[choose]=0;
		for(int j=1;j<=n;j++)//更新minn 
			if(minn[j]&&minn[j]>map[choose][j])
				minn[j]=map[choose][j];
	}	
	printf("%d",sum);
	return 0;
}
