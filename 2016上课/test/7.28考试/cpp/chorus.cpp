#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[120],up[120],down[120];
int main(){
	freopen("chorus.in","r",stdin);
	freopen("chorus.out","w",stdout);
	
	int n,ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	{
		//up[]
		ans=0;
		for(int j=i-1;j>=1;j--)//身高上升 
			if(a[i]>a[j]&&ans<up[j]+1)
				ans=up[j]+1;
		up[i]=ans==0?1:ans;
		
		//down[]
		ans=0;
		for(int j=i-1;j>=1;j--) 
		{
			if(a[i]<a[j]&&ans<up[j]+1)//身高上升 
				ans=up[j]+1;
			if(a[i]<a[j]&&ans<down[j]+1)//身高下降 
				ans=down[j]+1;
		}
			
			
		down[i]=ans==0?1:ans;
	}
	
	for(int i=1;i<=n;i++)
		ans=max(ans,max(up[i],down[i]));
	
	printf("%d",n-ans);
	
	return 0;
}
