#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 200050
#define f first
#define s second
using namespace std;
inline void _in(int &x)
{
	char t=getchar();bool mark=0;
	for(;!isdigit(t);t=getchar())if(t=='-')mark=1;
	for(x=0;isdigit(t);x=x*10+t-'0',t=getchar());
	x=mark?-x:x;
}
int l[maxn],r[maxn],a[maxn];
bool jl[maxn];
priority_queue <pair<int,int> >q;          
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m,i,j,ans=0,len,x;
	cin>>n>>m;
	if(m*2>n){cout<<"Error!";return 0;}
	for(i=1;i<=n;i++){
		_in(a[i]);
		l[i]=i-1;r[i]=i+1;
		q.push(make_pair(a[i],i));
	}
	l[1]=n,r[n]=1;
	while(m--)
	{
		len=q.top().f;x=q.top().s;q.pop();
		while(jl[x]){
			len=q.top().f;x=q.top().s;q.pop();
		}
		jl[l[x]]=true;jl[r[x]]=true;
		a[x]=a[l[x]]+a[r[x]]-a[x];
		r[x]=r[r[x]];l[x]=l[l[x]];
		r[l[x]]=x;l[r[x]]=x;
		ans=ans+len;
		q.push(make_pair(a[x],x));
	}
	cout<<ans;//200000*1000=2e9
}
