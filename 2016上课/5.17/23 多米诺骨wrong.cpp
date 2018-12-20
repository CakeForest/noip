#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int up,down,delta;
}card[1020];
int n;
int cmp(node a,node b)
{
	return a.delta>b.delta;
}

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		card[i].up=a;
		card[i].down=b;
		card[i].delta=a-b;
	}
	sort(card+1,card+1+n,cmp);
	
	
	return 0;
}
