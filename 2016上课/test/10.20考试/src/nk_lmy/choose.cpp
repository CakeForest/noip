#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m;
int in[200005];
int f[3][200005];

int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);	
	
	cin>>n>>m;
	if(n<m*2){
		puts("Error!");
		return 0;
	}
	int i,j,ans=0;
	for(i=1;i<=n;i++){
		scanf("%d",&in[i]);
		in[i]+=1000;
	}
	f[1][1]=in[1];
	f[1][0]=0;
	for(i=2;i<n;i++){
		for(j=1;j<=i&&j<=m;j++){
			f[i%3][j]=max(f[(i-1)%3][j],f[(i-2)%3][j-1]+in[i]);
			ans=max(ans,f[i%3][m]);
		}
	}
	
	memset(f,0,sizeof(f));
	f[2][1]=in[2];
	for(i=3;i<=n;i++){
		for(j=1;j<=i&&j<=m;j++){
			f[i%3][j]=max(f[(i-1)%3][j],f[(i-2)%3][j-1]+in[i]);
			ans=max(ans,f[i%3][m]);
		}
	}
	
	cout<<ans-m*1000<<endl;
	
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
