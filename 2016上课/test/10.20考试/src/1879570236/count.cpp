#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
const long long mod=1000000007;
inline void _read(long long &x){
    char t=getchar();bool sign=true;
    while(t<'0'||t>'9')
    {if(t=='-')sign=false;t=getchar();}
    for(x=0;t>='0'&&t<='9';t=getchar())x=x*10+t-'0';
    if(!sign)x=-x;
}
long long n,k;
long long x,y;
long long ans;
long long temp;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long i,j;
	cin>>n>>k;
	if(k==1){
		ans=((n-1)*(n)*(2*n-1))/6%mod;
		cout<<ans<<endl;
		return 0;
	}
	else if(k==2){
		ans=((n-1)*(n)*(2*n-1))/6%mod;
		for(i=3;i<=n;i++){
			temp=(i-2)*(n+1-i)*(n+1-i)%mod;
			ans=(ans+temp)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
}

