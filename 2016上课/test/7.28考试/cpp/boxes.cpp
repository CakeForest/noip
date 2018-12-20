#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[50],f[30000];
int main(){
	freopen("boxes.in","r",stdin);
	freopen("boxes.out","w",stdout);
	
	int V,n;
	scanf("%d%d",&V,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	memset(f,128,sizeof(f));
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=V;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+v[i]);
	for(int i=V;i>=1;i--)
		if(f[i]>0){
			printf("%d",V-i);
			break;
		}
			
	
	return 0;
}
