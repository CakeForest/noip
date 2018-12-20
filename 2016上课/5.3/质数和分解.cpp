#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,f[300],zhi[220]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};

int main()
{
//	freopen("in.txt","r",stdin);
	cin>>m;
	int num;
	do{
		num=zhi[++n];
	}while(num<m);
	
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=zhi[i];j<=m;j++)
			f[j]=f[j]+f[j-zhi[i]];
	cout<<f[m];
	
	return 0;
}
