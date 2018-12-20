#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int n,m,c,map[MAX],card[5];
int f[41][41][41][41];
//0´æÊý¾Ý 1´æ×´Ì¬ 
int main(){
	freopen("tortoise.in","r",stdin);
	freopen("tortoise.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&map[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&c);
		card[c]++;
	}
	
	f[0][0][0][0]=map[1];
	for(int i=0;i<=card[1];i++)
		for(int j=0;j<=card[2];j++)
			for(int k=0;k<=card[3];k++)
				for(int p=0;p<=card[4];p++){
					int t=i+j*2+k*3+p*4+1,ans[4]={0};
					if(i>0) ans[0]=f[i-1][j][k][p];
					if(j>0) ans[1]=f[i][j-1][k][p];
					if(k>0) ans[2]=f[i][j][k-1][p];
					if(p>0) ans[3]=f[i][j][k][p-1];
					sort(ans,ans+4);
					f[i][j][k][p]=ans[3]+map[t];
				}
	printf("%d",f[card[1]][card[2]][card[3]][card[4]]);
	
	
	return 0;
}
