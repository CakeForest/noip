#include<cstdio>
#include<algorithm>
using namespace std;
int sum;

void calc(int t,int minn){
	if(t==1){
		sum++;
		return;
	}
	if(t<minn) return;
	for(int i=minn;i<=t;i++){
		if(t%i) continue;
		calc(t/i,i);
	}
}

int main(){
	int tot,a;
	scanf("%d",&tot);
	for(int i=1;i<=tot;i++){
		scanf("%d",&a);
		sum=0;
		calc(a,2);
		printf("%d\n",sum);
	}
	
	
	
}
