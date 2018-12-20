#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define inf 0x7FFFFFE
using namespace std;
typedef long long ll;
template<typename T>
inline void _r(T &d){char t=getchar();bool f=false;while(t<48||t>57){if(t==45)f=true;t=getchar();}for(d=0;t>=48&&t<=57;t=getchar())d=d*10+t-48;if(f)d=-d;}
int n,m,a[200003],dp1[5005][5005],ans,temp[maxn],s1[maxn],s2[maxn];
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int i,j,k;int tmp1=0,tmp2=0,cnt=0;
	_r(n);_r(m);
	for(i=1;i<=n;i++)_r(a[i]);
	if(m>(n/2))
	{
		printf("Error!\n");return 0;
	}
	if(n>5000)
	{
		sort(a+1,a+1+n);
		for(i=1;i<=m;i++)ans+=a[n-i+1];
		for(i=1;i<=n-2;i++)if(i&1)s1[++cnt]=a[i],s2[cnt]=a[i];
	    sort(s1+1,s1+1+cnt);
	    s2[++cnt]=a[n-1];
	    sort(s2+1,s2+1+cnt);
	    for(i=1;i<=m;i++)
    	{
		   tmp1+=s1[cnt-i];
		   tmp2+=s2[cnt-i+1];
	    }
	    cnt=0;
	    for(i=1;i<=n;i++)
	    {
		    if(i%2==0)temp[++cnt]=a[i];
	    }
	    sort(temp+1,temp+1+cnt);
	    for(i=1;i<=m;i++)
	    {
		    ans+=temp[cnt-i+1];
	    }
	    cout<<max(ans,max(tmp1,tmp2))<<endl;
	    fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)dp1[i][j]=-inf;
	dp1[0][0]=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(i&1)dp1[i][j]=max(dp1[max(0,i-2)][j-1]+a[i],dp1[max(0,i-2)][j]);
	}
	for(i=1;i<=n-2;i++)if(i&1)s1[++cnt]=a[i],s2[cnt]=a[i];
	sort(s1+1,s1+1+cnt);
	s2[++cnt]=a[n-1];
	sort(s2+1,s2+1+cnt);
	for(i=1;i<=m;i++)
	{
		tmp1+=s1[cnt-i];
		tmp2+=s2[cnt-i+1];
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(i%2==0)temp[++cnt]=a[i];
	}
	sort(temp+1,temp+1+cnt);
	for(i=1;i<=m;i++)
	{
		ans+=temp[cnt-i+1];
	}
	cout<<max(dp1[n][m],max(ans,max(tmp1,tmp2)))<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

