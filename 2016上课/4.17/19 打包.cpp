#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=400;
int G,V,N,t[MAXSIZE],g[MAXSIZE],v[MAXSIZE],f[MAXSIZE][MAXSIZE];

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>G>>V>>N;
	for(int i=1;i<=N;i++)
		cin>>t[i]>>g[i]>>v[i];
	for(int k=1;k<=N;k++)
		for(int i=G;i>=1;i--)//重量 
			for(int j=V;j>=1;j--)//体积 
				if(i-g[k]>=0&&j-v[k]>=0)//此处判断很重要 
					f[i][j]=max(f[i][j],f[i-g[k]][j-v[k]]+t[k]);
	cout<<f[G][V];
	
	return 0;
} 
