#include<cstdio>
#include<cstring>
#include<iostream>
#define T t[f[i-1]][f[i]]
using namespace std;
typedef unsigned long long LL;
const int MAX=1020;
LL t[MAX][MAX],f[MAX*MAX];//这里t可以不要，因为一个周期的开头总是0跟1 

LL ModPow(LL a,LL b,LL c){//快速幂取模 
	if(!b) return 1;
	LL res=1;
	LL base=a%c;
	while(b){
		if(b&1) res=(res*base)%c;
		base=(base*base)%c;
		b>>=1;
	}
	return res%c;
}
int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	LL cas,a,b,n,s,e,temp;
	scanf("%d",&cas);
	while(cas--){
		cin>>a>>b>>n;
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		f[1]=1;
		for(int i=2;i<=n*n;i++){
			f[i]=(f[i-1]+f[i-2])%n;
			if(!T) T=i-1;//如果某数对未出现过 
			else{
				s=T,e=i-1;//该数对曾经出现过，找到周期 
				break;
			}
		}
		printf("%lld\n",f[ModPow(a,b,e-s)]);
		
	/*	for(int i=1;i<=n*n;i++){
			printf("%lld ",f[i]);
			if(f[i]+f[i-1]==0) break;
		}*/
	}
	
	
	return 0;
}
