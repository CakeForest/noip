#include <cstdio>
#include <cstring>
int max(int a,int b){
	if(a>b) return a;
	return b;
}
const int maxn=200001;
int f1[maxn][2],f2[maxn][2],a[maxn],ans=0;
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	if(m>n/2){
		printf("Error!\n");
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			f2[j][0]=max(f1[j][1],f1[j][0]);
			f2[j][1]=f1[j-1][0]+a[i];
		}
		i++; if(i>n) break;
		for(int j=1;j<=m;j++){
			f1[j][0]=max(f2[j][1],f2[j][0]);
			f1[j][1]=f2[j-1][0]+a[i];
		}
	}
	if(n%2){
		ans=max(f1[m][0],f1[m][1]);
	}
	else{
		ans=max(f2[m][0],f2[m][1]);
	}
	
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	
	for(int i=1;i<=m;i++) f1[i][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			f2[j][0]=max(f1[j][1],f1[j][0]);
			f2[j][1]=f1[j-1][0]+a[i];
		}
		i++; if(i>n) break;
		for(int j=1;j<=m;j++){
			f1[j][0]=max(f2[j][1],f2[j][0]);
			f1[j][1]=f2[j-1][0]+a[i];
		}
	}
	if(n%2){
		printf("%d",max(f1[m][0],ans));
	}
	else{
		printf("%d",max(f2[m][0],ans));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
