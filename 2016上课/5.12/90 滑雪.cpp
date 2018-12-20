#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int R,C,map[120][120],f[120][120];
int movex[4]={0,0,1,-1},movey[4]={1,-1,0,0};
int dp(int x,int y)
{
	if(f[x][y]!=0) return f[x][y];
	if(x>R||x<1||y>C||y<1) return 0;
	int mmax=0,t;
	for(int k=0;k<=3;k++)
	{
		int nextx=x+movex[k],nexty=y+movey[k];
		if(map[x][y]>map[nextx][nexty])
			t=dp(nextx,nexty),mmax=max(mmax,t);
	}
	f[x][y]=mmax+1;
	return mmax+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>R>>C;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			cin>>map[i][j];
	int maxx=-1;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			maxx=max(maxx,dp(i,j));
	cout<<maxx;	
		
	return 0;
}
