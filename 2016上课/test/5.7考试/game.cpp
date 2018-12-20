#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long N,M,T=0,k=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>N>>M;
	T=N-1;//周期为N-1，而不是N 
	long long sum=1;//此处关键 游戏开始时人物已经走了1格 
	for(int i=1;i<=M;i++)
	{
		long long c;
		cin>>c;sum+=c;
	}
	long long ans=sum%T;//取模
	long long times=(sum-1)/T;
	if(times%2==0)
		printf("%lld",ans==0?T:ans);
	else
		printf("%lld",ans==0?N-T+1:N+1-ans);
	
	return 0;
}
