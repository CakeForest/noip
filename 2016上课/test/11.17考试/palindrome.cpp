#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 100000007
using namespace std;
typedef long long LL;
LL n,m,k,a,b,mid;
bool vis[5002][5002];
LL inline readint(LL &num){
	num=0; char ch;
	while((ch=getchar())<'0'||ch>'9');
	num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
	return num;
}

LL inline pow_mod(LL a,LL b,LL c){
	LL base=a,res=1;
	while(b){
		if(b&1) res=res*base%c;
		base=base*base%c;
		b>>=1;
	}
	return res;
}
	

int main(){
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	
	readint(n); readint(m); readint(k);
	mid=(n+1)>>1;
	
	for(int i=1;i<=m;i++){
		readint(a); readint(b);
		a++; b++;
		if(a>mid) a=n-a+1;
		if(b>mid) b=n-b+1;
		vis[a][b]=vis[b][a]=true;
	}
	
	int cnt=0;
	for(int i=1;i<=mid;i++)
		for(int j=1;j<=mid;j++){
			if(!vis[i][j]){
				vis[j][i]=true;
				cnt++;
			}
		}
		
	printf("%lld",pow_mod(k,cnt,mod));
	return 0;
}
