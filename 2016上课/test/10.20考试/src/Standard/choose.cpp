#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
inline void _read(int &d)
{
	char t=getchar();bool f=false;
	while(t<'0'||t>'9'){if(t=='-')f=true;t=getchar();}
	for(d=0;t>='0'&&t<='9';t=getchar())d=d*10+t-'0';
	if(f==true)d=-d;
}
int n,m;
int P[400005];
int MAX=-999999999;
priority_queue<pair<int,int> >q;
int l[410000],r[410000];
int tot=0;
bool used[410000];
int ans=0;
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout); 
	int a,b,c,d,e;
	_read(n);_read(m);
	for(a=1;a<=n;a++)
	{
	 _read(P[a]);
     l[a]=a-1;r[a]=a+1;
     q.push(make_pair(P[a],a));
     tot++;
	}
	l[1]=n;r[n]=1;
	if(n/2<m){printf("Error!");return 0;}
	while(m!=0)
	{
		a=q.top().second;q.pop();
		if(used[a]==true)continue;
		ans+=P[a];
		tot++;
		P[tot]=P[l[a]]+P[r[a]]-P[a];
		used[a]=true;used[l[a]]=true;used[r[a]]=true;
		l[tot]=l[l[a]];
		r[tot]=r[r[a]];
		l[r[r[a]]]=tot;
		r[l[l[a]]]=tot;
		q.push(make_pair(P[tot],tot));
        m--;
    }
	cout<<ans;
	return 0;
}
	
