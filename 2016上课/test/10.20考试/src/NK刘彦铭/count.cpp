#include<cstdio>
#include<iostream>
using namespace std;
#define mod 1000000007
#define ll long long
ll n,k,ANS=0;
void work1()
{
	for(ll i=1LL;i<n;i++)
	{
		ANS+=i*i;
		ANS%=mod;
	}
	cout<<ANS<<endl;
}
void work2()
{
	for(ll i=1LL;i<n;i++)
	{
		ANS+=i*i*(n-i);
		ANS%=mod;
	}
	cout<<ANS<<endl;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		work1();
	}
	else
	{
		work2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
