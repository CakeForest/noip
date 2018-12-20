#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
struct node1{
	int son,mot;double w;
	bool operator < (const node1 &a) const 
    {  
       return w<a.w; 
    }
}a[3001000];
int n,q;
double p;
struct node2{
	int son,mot;double w;
	bool operator < (const node2 &a) const 
    {  
       return w>a.w;
    }  
}b[3001000];
priority_queue<node1>q1;
priority_queue<node2>q2;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}

int main()
{
	freopen("rational.in","r",stdin);
	freopen("rational.out","w",stdout); 
	cin>>q>>n;p=sqrt(q);
	int l=floor(sqrt(q)),r=ceil(sqrt(q));
	for(int k=1,kk=1,i=2;i<=n;i++)
	  for(int j=i*l;j<=min(n,i*r);j++)
	  if(gcd(i,j)==1)
	  {
	  	double jj,ii,z;
	  	jj=(double)j;
	  	ii=(double)i;
	  	z=jj/ii;//cout<<<<endl;
		if(z<p)
		{
			a[k].son=j;
			a[k].mot=i;
			a[k].w=z;
			q1.push(a[k]);k++;
		}
		if(z>p)
		{
			b[kk].son=j;
			b[kk].mot=i;
			b[kk].w=z;
			q2.push(b[kk]);kk++;
		}
		
	  }
	if(!q1.empty())
	cout<<q1.top().son<<"/"<<q1.top().mot<<" ";
	else cout<<l<<"/"<<1<<" ";
	
	if(!q2.empty())
	cout<<q2.top().son<<"/"<<q2.top().mot;
	else cout<<r<<"/"<<1;
	
	return 0;
} 
