#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=50;
int n,k,a[MAXSIZE];
long long f[MAXSIZE][MAXSIZE],t[MAXSIZE][MAXSIZE];
//f[i][j] i表示乘号的个数 j表示当前的位数 
int main()
{
	freopen("in.txt","r",stdin);
	cin>>n>>k;
	char c;
	for(int i=1;i<=n;i++)
		cin>>c,a[i]=c-'0';
	for(int i=1;i<=n;i++)
	{
		t[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
			t[i][j]=t[i][j-1]*10+a[j];
	}
	
	for(int i=1;i<=n;i++)
		f[0][i]=t[1][i];
	for(int i=1;i<=k;i++)
		for(int j=i;j<=n;j++)
			for(int m=i;m<=j;m++)
				f[i][j]=max(f[i][j],f[i-1][m]*t[m+1][j]);
	
/*	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl<<endl;*/
	
	
	cout<<f[k][n];
	
	return 0;
}
