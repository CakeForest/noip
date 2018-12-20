#include <cstdio>

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	int n,m,a;
	int pos=1;
	scanf("%d%d",&n,&m);
	int mod=n*2-2;
	int s=0; 
	for(int i=1;i<=m;i++){
		scanf("%d",&a);
		s=(s+a)%mod;
	}
	if(s>n-1){
		pos=n-(s-(n-1));
	}else{
		pos=s+1;
	}
	
	printf("%d",pos);
	
	return 0;
}
