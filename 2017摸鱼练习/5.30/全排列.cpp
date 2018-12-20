#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,out[10];
char str[10];
bool use[10];

void work(int t){
	if(t==n+1){
		for(int i=1;i<=n;i++)
			printf("%c",str[out[i]]);
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		out[t]=i;
		use[i]=true;
		work(t+1);
		use[i]=false;
	}
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++){
		out[1]=i;
		use[i]=true;
		work(2);
		use[i]=false;
	}
	
}
