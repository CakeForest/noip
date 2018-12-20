#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXSIZE=1020;
int n,h[MAXSIZE],up[MAXSIZE],down[MAXSIZE];
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
	{
		//up[]
		ans=0;
		for(int j=i-1;j>=1;j--)//身高上升 
			if(h[i]>h[j]&&ans<up[j]+1)
				ans=up[j]+1;
		up[i]=ans==0?1:ans;
		
		//down[]
		ans=0;
		for(int j=i-1;j>=1;j--) 
		{
			if(h[i]<h[j]&&ans<up[j]+1)//身高上升 
				ans=up[j]+1;
			if(h[i]<h[j]&&ans<down[j]+1)//身高下降 
				ans=down[j]+1;
		}
			
			
		down[i]=ans==0?1:ans;
	}
	
	ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(up[i]>ans)
			ans=up[i];
		if(down[i]>ans)
			ans=down[i];
	}
	
	printf("%d",n-ans);

	
	return 0;
}
