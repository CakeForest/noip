#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int map[1200],f[1200][1200],use[1200][1200];
int Game(int s,int e)//当前最左边牌为s，最右边为e ，返回值为能赢的分数 
{
	if(use[s][e]==1) return f[s][e];
	use[s][e]=1;
	if(s+1==e)//最后两张牌，做贪心选择 
	{
		f[s][e]=max(map[s]-map[e],map[e]-map[s]);
		return f[s][e];
	}
	int left,right,choose;
	choose=map[s];
	if(map[s+1]>=map[e])//这里取等 
		left=choose-map[s+1]+Game(s+2,e);
	else
		left=choose-map[e]+Game(s+1,e-1);
	
	choose=map[e];
	if(map[s]>=map[e-1])//这里取等 
		right=choose-map[s]+Game(s+1,e-1);
	else
		right=choose-map[e-1]+Game(s,e-2);
	
	f[s][e]=max(left,right);
	return f[s][e];
}

void memsets(int n)//归位 
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			use[i][j]=0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	for(int k=1;k>0;k++)
	{
		int n,sum;
		cin>>n;
		if(n==0) break;
		memsets(n);
		for(int i=1;i<=n;i++)
			cin>>map[i];
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,Game(1,n));
	}
	
	return 0;
}
