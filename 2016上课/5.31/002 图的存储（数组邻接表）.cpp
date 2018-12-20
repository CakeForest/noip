#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int map[20020][20020],data[20020][35];
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,k,a,b;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		scanf("%s",data[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a,&b),map[a][b]=1;
	for(int i=1;i<=k;i++){
		int flag=1;
		scanf("%d",&a);
		for(int j=0;j<=n-1;j++)
			if(map[a][j]==1) 
				printf("%s ",data[j]),flag=0;
		if(flag==1) printf("0");
		printf("\n");
	}
	return 0;
}
