#include<cstdio>
#include<iostream>
#include<queue>
#define P pair<int,int>
#define M_P make_pair<int,int>
#define maxx 200001
#define dp(x,y,a,b) f[x][y][0]=f[a][b][0],f[x][y][1]=f[a][b][1]
using namespace std;
inline void _in(int &d)
{
	char t=getchar();bool f=false;
	while(!isdigit(t)){if(t==45)f=true;t=getchar();}
	for(d=0;isdigit(t);t=getchar())d=d*10+t-48;
	if(f)d=-d;
}
priority_queue<P,vector<P> >q;
int n,m,i,a[maxx],L[maxx],R[maxx],ans,x;
bool del[maxx];
void erase(int x)
{
	del[x]=true;
	int l=L[x],r=R[x];
	L[x]=R[x]=0;
	L[r]=l;R[l]=r;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	_in(n);_in(m);
	for(i=1;i<=n;i++)_in(a[i]),L[i]=i-1,R[i]=i+1,q.push(M_P(a[i],i));
	if((m<<1)>n){cout<<"Error!";return 0;}
	L[1]=n;R[n]=1;
	for(i=1;i<=m;i++)
	{
		while(del[q.top().second])q.pop();
		x=q.top().second;q.pop();
		ans+=a[x];
		a[x]=a[L[x]]+a[R[x]]-a[x];
		q.push(M_P(a[x],x));
		erase(L[x]);erase(R[x]);
	}
	cout<<ans;
}
