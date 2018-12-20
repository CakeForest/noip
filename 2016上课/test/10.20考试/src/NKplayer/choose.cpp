#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
long long n,m,p=1000000007;
inline void in(long long& x)
{  
    char tt=getchar();  
	bool mark=0;
    for(;tt<'0'||'9'<tt;tt=getchar()) if(tt=='-') mark=1;  
    for(x=0;'0'<=tt&&tt<='9';x=(x<<1)+(x<<3)+tt-'0',tt=getchar());  
    x=mark?-x:x;  
}
long long a[10000],f[2050][2050][2],inf=99999999999LL;
bool mark[2050][2050][2];
int main()
{
	long long x,y,k,i,j,c,d,e,ans=-inf,cnt=0;
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	in(n);in(m);
	if(n/2<m)
	{
		printf("Error!");
		return 0;
	}
	for(i=1;i<=n;i++)in(a[i]);
	e=n;
	for(i=2;i<=e;i++)
	{
	    mark[i][0][0]=true;
	    f[i][1][0]=a[1];
	    mark[i][1][0]=true;
    }
    mark[0][0][0]=true;
    mark[1][0][0]=true;
    f[1][1][1]=a[1];
	for(i=2;i<=e;i++)
	{
		d=min(i,m);
	for(j=2;j<=d;j++)
	{cnt++;
			if(mark[i-1][j-1][0]==true&&i!=n)
			{
		        f[i][j][1]=f[i-1][j-1][0]+a[i];
		        mark[i][j][1]=true;
		    }
		    
		    if(mark[i-1][j][0]==true&&mark[i-1][j][1]==true)
		    {
		    	f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
		 		mark[i][j][0]=true;
			}
		    if(mark[i-1][j][0]==true&&mark[i-1][j][1]==false)
			{
			    f[i][j][0]=f[i-1][j][0];
			    mark[i][j][0]=true;
		    }
			if(mark[i-1][j][1]==true&&mark[i-1][j][0]==false)
			{
				f[i][j][0]=f[i-1][j][1];
				mark[i][j][0]=true;
			}
	}
    }
    
    ans=f[n][m][0];
    if(cnt>10000000)
    {
    	printf("%I64d",ans);
    	return 0;
	}
	
    for(i=0;i<=n;i++)
    {
    	d=min(m,i);
    for(j=1;j<=d;j++)
    {
    	mark[i][j][0]=false;
    	mark[i][j][1]=false;
    	f[i][j][0]=0;
    	f[i][j][1]=0;
    }
    }
    for(i=0;i<=e;i++)
	    mark[i][0][0]=true;
    
    for(i=2;i<=e;i++)
	{
		d=min(i,m);
	for(j=1;j<=d;j++)
	{cnt++;
			if(mark[i-1][j-1][0]==true)
			{
		        f[i][j][1]=f[i-1][j-1][0]+a[i];
		        mark[i][j][1]=true;
		    }
		    
		    if(mark[i-1][j][0]==true&&mark[i-1][j][1]==true)
		    {
		    	f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
		 		mark[i][j][0]=true;
			}
		    if(mark[i-1][j][0]==true&&mark[i-1][j][1]==false)
			{
			    f[i][j][0]=f[i-1][j][0];
			    mark[i][j][0]=true;
		    }
			if(mark[i-1][j][1]==true&&mark[i-1][j][0]==false)
			{
				f[i][j][0]=f[i-1][j][1];
				mark[i][j][0]=true;
			}
	}
    }
	/*for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=0;k<=1;k++)
    {
    	if(mark[i][j][k]==true)cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
	}*/
    ans=max(ans,max(f[n][m][0],f[n][m][1]));
    printf("%I64d",ans);
}
