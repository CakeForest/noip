#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[1000000],aim;

int main()
{
	freopen("in.txt","r",stdin);
	cin>>n>>aim;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);//ÉıĞòÅÅĞò 
	
	int s=1,e=n,mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(a[mid]>aim)
			e=mid-1;
		else
			s=mid+1;
	}
	cout<<e;
	
	
	return 0;
}
