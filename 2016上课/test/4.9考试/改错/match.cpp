#include<iostream>
#include<algorithm>
using namespace std;
const int MAXSIZE=100020;
struct node{
	int data,i; 
}a[MAXSIZE],b[MAXSIZE];
int n,ans[MAXSIZE],q[MAXSIZE];
bool cmp(node a,node b)
{
	return a.data<b.data;
}

int Merge(int s,int m,int e)
{
	int l=s,r=m+1,i=s,sum=0;
	while(l<=m&&r<=e)
		if(ans[l]<ans[r])
			q[i++]=ans[l++];
		else
			q[i++]=ans[r++],sum+=m-l+1;
	if(l<=m)
		while(l<=m)
			q[i++]=ans[l++];
	else
		while(r<=e)
			q[i++]=ans[r++];
	for(int i=s;i<=e;i++)
		ans[i]=q[i];
	return sum; 
}
int Mergesort(int s,int e)
{
	if(s>=e)
		return 0;
	int m=(s+e)/2,sum=0;
	sum+=Mergesort(s,m);
	sum+=Mergesort(m+1,e);
	sum+=Merge(s,m,e);
	return sum%99999997;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].data,a[i].i=i;
	for(int i=1;i<=n;i++)
		cin>>b[i].data,b[i].i=i;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		ans[a[i].i]=b[i].i;
	cout<<Mergesort(1,n);
}
