#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 55
using namespace std;

const int MAXL=30+2;

int f[MAXL][MAXL][MAXL][MAXL][2];

int T;

int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout); 
    
    memset(f,-1,sizeof(f));
    int k;
    f[0][0][0][0][0]=0;
    for(int i=0;i<=30;i++)
    for(int u=0;u<=30;u++)
    for(int v=0;v<=30;v++)
    for(int w=0;w<=30;w++)
    for(int j=0;j<=1;j++){
    	if(f[i][u][v][w][j]>=0){
    		for(int p=0;p<=1;p++)
    		for(int q=0;q<=1;q++)
    		for(int r=0;r<=1;r++)
    		if((p+q+j)%2==r){
    			k=(p+q+j-r)/2;
    			if(f[i+1][u+p][v+q][w+r][k]==-1 || f[i+1][u+p][v+q][w+r][k] > f[i][u][v][w][j]+r*(1<<i) )
    				 f[i+1][u+p][v+q][w+r][k] = f[i][u][v][w][j]+r*(1<<i);
			}
		}
	}
    
    scanf("%d",&T);
    int a,b,c;
    while(T--){
    	scanf("%d%d%d",&a,&b,&c);
    	int na=0,nb=0,nc=0,L=0;
    	while(a>0||b>0||c>0){
    		if(a&1) na++;
    		if(b&1) nb++;
    		if(c&1) nc++;
    		L++;
    		a=a>>1;
    		b=b>>1;
    		c=c>>1;
		}
    	printf("%d\n",f[L][na][nb][nc][0]);
	}
}
