#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=32020;
int N,m,f[2][MAXSIZE],price[100][100],val[100][100],sum[100],tot;
int main()
{
	freopen("in.txt","r",stdin);
	cin>>N>>m;
	for(int i=1;i<=m;i++)
	{
		int V,P,Q;
		cin>>V>>P>>Q;
		if(Q==0)
			tot++,price[tot][0]=V,val[tot][0]=P;
		else
			sum[Q]++,price[Q][sum[Q]]=V,val[Q][sum[Q]]=P;
	}
	
	int k=0;
	for(int o=1;o<=tot;o++)
	{
		do{
			k++;
		}while(price[k][0]==0);
		int now=o%2;
		
		for(int j=1;j<=N;j++)//主件 
			if(j>=price[k][0])
				f[now][j]=price[k][0]*val[k][0];
			else
				f[now][j]=0;
				
		for(int i=1;i<=sum[k];i++)//给这个集合做01背包 
			for(int j=N;j>=price[k][i]+price[k][0];j--)//必须选择主件 
				f[now][j]=max(f[now][j],f[now][j-price[k][i]]+price[k][i]*val[k][i]);
		if(o!=1)
		{
			int last=(o+1)%2;
/*			for(int j=0;j<=N;j++)
				f[now][j]=max(f[now][],f[now][j]+f[last][N-j]);*/
				
			for(int i=N;i>=0;i--)
				for(int j=i;j>=price[k][0];j--)
					f[now][i]=max(f[now][i],f[now][j]+f[last][i-j]);
		}
	}
	int maxx=-1;
/*	for(int j=0;j<=N;j++)
		maxx=max(maxx,f[tot%2][j]);*/
	cout<<f[tot%2][N];
	
	return 0;
}
