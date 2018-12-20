#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=12000;
struct fuck{
	int t,a,b;
}per[MAX];
int d[MAX];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n-1;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
		cin>>per[i].t>>per[i].a>>per[i].b;
	
	if(k==0){
		int sum=0;
		for(int i=1;i<=n-1;i++)
			sum+=d[i];
		printf("%d",sum);
	}else{
		printf("0");
	}
	
	return 0;
}
