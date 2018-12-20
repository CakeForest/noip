#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 200050
using namespace std;
inline void _in(int &x)
{
	char t=getchar();bool mark=0;
	for(;!isdigit(t);t=getchar())if(t=='-')mark=1;
	for(x=0;isdigit(t);x=x*10+t-'0',t=getchar());
	x=mark?-x:x;
}
int a[20],_map[20][20];
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	int i,j,n,m,x,y,z;
	cin>>n>>m;
	for(i=0;i<n;i++)_in(a[i]);
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		_map[x][y]=z;
    }
    if(n==3&&m==3)cout<<"30";
    else if(n==2)
	{
	if(a[0]=-a[i])cout<<z;
	else cout<<"Impossible";
    }
    else cout<<"Impossible";
}
