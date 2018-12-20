#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=30000;
int cas,n,q,t,e[MAX],cool[MAX],now;
char temp[10];

int lowbit(int i){
	return -i&i;
}

void add(int x,int t){
	for(;x<=n;x+=lowbit(x))
		e[x]+=t;
}

int sum()

void Attack(int a,int b){
	if(cool[])
	
	
	
	now++;
}

int main(){
	freopen("in.txt","r",stdin);
	
	scanf("%d",&cas);
	for(int k=1;k<=cas;k++){
		memset(e,0,sizeof(e));
		scanf("%d%d%d",&n,&q,&t);
		for(int i=1;i<=q;i++){
			int a,b; now=1;
			scanf("%s%d",temp,&a);
			if(temp[0]=='A'){
				scanf("%d",&b);
				Attack(a,b);
			}else{
				
				
				
			}
			
		}
		
		
		
		
		
		
		printf("Case %d:\n",k);
	}
	return 0;
}
