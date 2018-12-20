#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int memory[10000];
int m,n,c,cnt=0,now=1;
int Find(int c){
	for(int i=1;i<=m;i++)
		if(memory[i]==c) return 1;
	return 0;
}
int main(){
	freopen("translate.in","r",stdin);
	freopen("translate.out","w",stdout);
	
	memset(memory,-1,sizeof(memory));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		if(now==m+1) now=1;
		scanf("%d",&c);
		if(Find(c)==0) memory[now++]=c,cnt++;
	}
	
	printf("%d",cnt);
	
	return 0;
}
