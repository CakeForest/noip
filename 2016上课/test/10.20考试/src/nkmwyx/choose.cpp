#include<iostream>
#include<cstdio>
using namespace std;
inline void Read(int &x)
{
	bool mark=0;
	char tt=getchar();
	for(;tt<'0'||'9'<tt;tt=getchar())if(tt=='-')mark=1;
	for(x=0;'0'<=tt&&tt<='9';x=(x<<1)+(x<<3)+tt-'0',tt=getchar());
	x=mark?-x:x;
}
int n,m;
int r[200000],maxx[100000];
int dp[2200][2200];
int main()
{
	int a,b,c,d;
	Read(n);
	Read(m);
	/*
	for(a=1;a<=n;a++)
	{
		Read(r[a]);
	}
	for(a=1;a<=n;a++)
	{
		for(b=1;b<=a&&b<=m;b++)
		{
			dp[a][b]=max(dp[a-1][b-1]+r[a],maxx[b-1]);
			maxx[b]=max(dp[a][b],maxx[b]);
		}
	}
	cout<<dp[n][m];*/
	cout<<"Error!";
}
