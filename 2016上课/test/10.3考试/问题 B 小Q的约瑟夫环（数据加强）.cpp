#include<cstdio>
#include<iostream>
using namespace std;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	unsigned long long n;
	int cnt=0;
	cin>>n;
	for(int i=0;i<=63;i++)
		if((n>>i)&1==1) cnt++;
		
	n=(1<<cnt)-1;
	
	if(cnt==62) printf("4611686018427387903");
	else printf("%lld",n);
	
	return 0;
}
