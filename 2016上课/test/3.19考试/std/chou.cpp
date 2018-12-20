#include<stdio.h>
long long s[10001]={0,1};
int i,n,a=1,b=1,c=1;
long long min(long long x,long long y,long long z)
{
    if(x<y)
    {
        if(x<z) return x;
        else return z;
    }
    else
    {
        if(y<z) return y;
        else return z;
    }
}
int main()
{
	freopen("chou.in","r",stdin);
	freopen("chou.out","w",stdout);
    scanf("%d",&n);
     
    for(i=2;i<=n;i++)
    {
        s[i]=min(s[a]*2,s[b]*3,s[c]*5);
        if(s[i]==s[a]*2) a++;
        if(s[i]==s[b]*3) b++;
        if(s[i]==s[c]*5) c++;
    }
    printf("%lld",s[n]);
}
