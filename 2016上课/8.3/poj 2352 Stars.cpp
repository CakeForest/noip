#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 32020
using namespace std;
int e[MAX],cnt[MAX],n;

int lowbit(int i){
	return -i&i;
}
void add(int x,int t){
	for(;x<=MAX;x+=lowbit(x))
		e[x]+=t;
}
int sum(int x){
	int s=0;
	for(;x>0;x-=lowbit(x))
		s+=e[x];
	return s;
}
int main(){
//	freopen("in.txt","r",stdin);
	int x,y;
	while(~scanf("%d",&n)){
		memset(e,0,sizeof(e));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			add(x+1,1);
			cnt[sum(x+1)]++;
		}
		for(int i=1;i<=n;i++)
			printf("%d\n",cnt[i]);
	}
	
	
	return 0;
}
