/*
	ID: pyub1531
	PROG: crypt1
	LANG: C++
*/
#include <cstdio>
#include <cstring>
#include<algorithm> 
using namespace std;
int N,a[10],in[10];
int slv[6],ans;
/*
slv对应的下标为
1 2 3
  4 5 
*/
int notIn(int d){
	int t;
	while(d){
		t=d%10;
		if(in[t]==0) return 1;
		d=d/10;
	}
	return 0;
}

int dfs(int t){
	if(t==5){
		int ss=slv[1]*100+slv[2]*10+slv[3];
		ss=ss*slv[4];
		if(ss>=1000) return 0;
		if(notIn(ss)) return 0;		
	}
	if(t>5){
		int ss1=slv[1]*100+slv[2]*10+slv[3];
		int ss=ss1*slv[5];
		if(ss>=1000) return 0;
		if(notIn(ss)) return 0;	
		
		int ss2=slv[4]*10+slv[5];
		ss=ss1*ss2;
		if(ss>=10000) return 0;
		if(notIn(ss)) return 0;	
		
		ans++;
		return 1;
	}
	
	for(int i=1;i<=N;i++){
		slv[t]=a[i];
		dfs(t+1);
	}
	return 1;
	
}

int main()
{
	freopen("crypt.in","r",stdin);
	freopen("crypt.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		in[a[i]]=1;
	}
		
	
	dfs(1);
	printf("%d\n",ans);
	
	return 0;
}


