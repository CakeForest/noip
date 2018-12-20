#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[7];
int main()
{
	freopen("in.txt","r",stdin);
	do{
		for(int i=1;i<=6;i++)
			cin>>a[i];
	}while(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]!=0);
	
	return 0;
}
