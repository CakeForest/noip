#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int need=1003;

int n,m;
int re[need];
int tt[need];


//......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......
inline int in_()
{
	int d=0;char t=getchar();bool mark=0;
	while(t<'0'||t>'9') {if(t=='-') mark=true;t=getchar();}
	for(d=0;!(t<'0'||t>'9');t=getchar()) d=(d<<1)+(d<<3)+t-'0';
	return mark ? -d : d;
}
//........NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......
int be[need];
int getbe(int x)
{
	return x==be[x] ? x : be[x]=getbe(be[x]);
}
//..........NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......NBHB......

int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) re[i]=in_(),be[i]=i;
	for(int i=1,a,b,c,x,y;i<=m;i++) 
	{
		a=in_(),b=in_(),c=in_();
		x=getbe(a),y=getbe(b);
		if(x!=y) be[x]=y; 
	}
	for(int i=1,bb=getbe(1);i<=n;i++) 
	 if(getbe(i)!=bb)
	 {
	 	tt[getbe(i)]+=re[i];
	 } 
	 for(int i=1;i<=n;i++) if(tt[i]!=0) 
	 {
	 	
		puts("Impossible");
		fclose(stdin);
		fclose(stdout);
		return 0;
	 }
	
}
