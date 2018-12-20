#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tree[1200],find[1200],x,y;
int main()
{
//	freopen("in.txt","r",stdin);
	cin>>x>>y;
	for(int i=1;i<=1200;i++)
		tree[i]=i;
	while(x!=y)
		if(x>y)
			x/=2;
		else
			y/=2;
	cout<<x;
	
	return 0;
}
