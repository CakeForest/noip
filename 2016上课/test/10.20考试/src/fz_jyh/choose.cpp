#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 2015
using namespace std;
int f1[MAX][MAX][2],f2[MAX][MAX][2],a[MAX];

int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	//´òµ¹¿×¼Òµî 
	int n,m,ans1,ans2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m>(n+1)/2){
		printf("Error!");
		return 0;
	}
	f1[0][0][1]=0;
	f1[0][0][0]=0;
	f2[0][0][1]=0;
	f2[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==2){
				f1[i][j][1]=f1[i-1][j-1][0]+a[i];
				f1[i][j][0]=f1[i-1][j-1][0];
				continue;
			}
			f1[i][j][1]=f1[i-1][j-1][0]+a[i];
			f1[i][j][0]=max(f1[i-1][j][0],f1[i-1][j][1]);
		}
	}
	ans1=max(f1[n][m][0],f1[n][m][1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==2){
				f2[i][j][1]=-9999999;
				f2[i][j][0]=f2[i-1][j-1][1];
				continue;
			}
			f2[i][j][1]=f2[i-1][j-1][0]+a[i];
			f2[i][j][0]=max(f2[i-1][j][0],f2[i-1][j][1]);
		}
	}
	ans2=f2[n][m][0];
	ans1=max(ans1,ans2);
	printf("%d",ans1);
	return 0;
}
