#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 55
using namespace std;

const int MAXN=50+10,MAXH=500000+20;

int f[2][MAXH],a[MAXN];

int n;

int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout); 
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    memset(f,128,sizeof(f));
    f[0][0]=0;
    int now=0,nxt=0,tot=0;
    for(int i=1;i<=n;i++)
    {
    	now=nxt;
    	nxt=now^1;
    	for(int j=0;j<=tot;j++){
    		f[nxt][j]=max(f[nxt][j],f[now][j]);
    		f[nxt][j+a[i]]=max(f[nxt][j+a[i]],f[now][j]+a[i]);
    		
			if(j>a[i])
				f[nxt][j-a[i]]=max(f[nxt][j-a[i]],f[now][j]);
			else
				f[nxt][a[i]-j]=max(f[nxt][a[i]-j],f[now][j]+a[i]-j);
		}
		tot+=a[i];
		/*
		for(int j=0;j<=tot;j++)
			printf("%d ",f[nxt][j]);
		printf("\n");
		*/
	}

	now=now^1;
    if(f[now][0]<=0) printf("-1\n");
    else printf("%d",f[now][0]) ;
}
