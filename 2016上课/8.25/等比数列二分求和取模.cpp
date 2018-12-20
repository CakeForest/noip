#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int KSMcalc(int a,int b,int c){//快速幂 
	int res=1;
	int base=a%c;
	while(b){
		if(b&1)//b为奇数
			res=(res*base)%c;
		base=(base*base)%c;
		b>>=1; 
	}
	return res%c;
}
int DBcalc(int q,int n,int p){//等比数列求和 
	if(n==1) return q%p;
	if(n&1) return (DBcalc(q,n-1,p)+KSMcalc(q,n,p))%p;
	return ((1+KSMcalc(q,n/2,p)%p)*(DBcalc(q,n/2,p)%p))%p;
}
int main(){
//	freopen("in.txt","r",stdin);
	int n,q,p;//a+a^2+a^3+...+a^n
	cin>>q>>n>>p;
	printf("%d",DBcalc(q,n,p));
	
	return 0;
}
