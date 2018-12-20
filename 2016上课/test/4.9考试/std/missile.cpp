#include <cstdio>

int N[15000],F[15000],H[15000];

int main()
{
	int m,k,i=0,a,b,ans;
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
    while(scanf("%d",&N[i])!=EOF)  i++;
    
	H[i-1]=1;
    for(b=i-2;b>=0;b--)
	{
	  int ans=0;
	  for(a=i-1;a>b;a--)
	     if(N[a]<=N[b]&&H[a]>ans) ans=H[a];
      H[b]=ans+1;
     }
    ans=0;
    for(a=0;a<i;a++)
	{	
	//    printf("%d  ",H[a]);
        if(H[a]>ans) ans=H[a];
    }
     printf("%d\n",ans);
    
	 
    F[0]=1;
	for(b=1;b<i;b++)
	{
	  int ans=0;
	  for(a=0;a<b;a++)
	     if(N[a]<N[b]&&F[a]>ans) ans=F[a];
      F[b]=ans+1;
     }
     ans=0;
     for(a=0;a<i;a++)
        if(F[a]>ans) ans=F[a];
     printf("%d\n",ans);
     return 0;
}
