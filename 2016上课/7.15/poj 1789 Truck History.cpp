#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[20200][7];
int dis[2020][2020],visit[2020],minn[2020];

int cmp(int i,int j){
	int sum=0;
	for(int k=0;k<=6;k++)
		sum+=str[i][k]!=str[j][k];
	return sum;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(1){
		memset(visit,0,sizeof(visit));
		int n,ans=0;
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=1;i<=n;i++)	
			scanf("%s",str[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++){
				dis[i][j]=cmp(i,j);
				dis[j][i]=dis[i][j];
			}
		
		for(int i=1;i<=n;i++)
			minn[i]=dis[1][i];
		visit[1]=1;minn[1]=0;
		for(int i=1;i<=n-1;i++){
			int minj=99999999,t;
			for(int j=2;j<=n;j++)
				if(visit[j]==0&&minj>minn[j])
					minj=minn[j],t=j;
			ans+=minj;
			visit[t]=1;
			for(int j=2;j<=n;j++)
				if(visit[j]==0&&dis[t][j]<minn[j])
					minn[j]=dis[t][j];
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	
	return 0;
}
