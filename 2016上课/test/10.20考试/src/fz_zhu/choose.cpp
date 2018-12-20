#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[200002],cnt,vis[200002],maxx,sum1,sum2,flag,x;
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if((n/2)<m){
		printf("Error!");
		return 0;}
	while(cnt<m){
		maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(a[i]>maxx){
					maxx=a[i];
					flag=i;
				}
			}
		}
		if(cnt==0){
			x=flag;
		}
		if(flag==1){
			vis[1]=1;
			vis[2]=1;vis[n]=1;
			sum1+=a[1];cnt++;continue;
		}
		if(flag==n){
			vis[n-1]=1;vis[1]=1;
			vis[n]=1;
			sum1+=a[n];cnt++;continue;
		}
		vis[flag]=1;vis[flag+1]=1;vis[flag-1]=1;
		sum1+=a[flag];
		cnt++;
	}
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	cnt=0;
	while(cnt<m){
		maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(a[i]>maxx){
					maxx=a[i];
					flag=i;
				}
			}
		}
		if(flag==1){
			vis[1]=1;
			vis[2]=1;vis[n]=1;
			sum2+=a[1];cnt++;continue;
		}
		if(flag==n){
			vis[n-1]=1;vis[1]=1;
			vis[n]=1;
			sum2+=a[n];continue;
		}
		vis[flag]=1;vis[flag+1]=1;vis[flag-1]=1;
		sum2+=a[flag];
		cnt++;
	}
	printf("%d",max(sum1,sum2));
	return 0;
}
