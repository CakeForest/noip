#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[100020],k;
int Look(int aim,int loc)
{
	int s=1,e=n,mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(aim==a[mid]&&mid!=loc)
			return a[mid];
		else if(aim>a[mid])
			s=mid+1;
		else
			e=mid-1;
	}
	return -1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>k;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int x=a[i],y;
		y=Look(k-x,i);
		if(y!=-1)
		{
			cout<<x<<" "<<y;
			return 0;
		}
	}
	printf("No");
	return 0;
}
