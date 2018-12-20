#include<stdio.h>
const int maxn=1300;
int n,m;
struct node{
	int data,fir;
}v[maxn];
struct arcc{
	int go,next,d;
}e[maxn];
int sum;
void addarc(int a,int b,int c)
{
	sum++; e[sum].go=b; e[sum].d=c;
	e[sum].next=v[a].fir;
	v[a].fir=sum;
}
int main()
{
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	int i,j,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&v[i].data);
    for(i=1;i<=m;i++)
    {
    	scanf("%d%d%d",&a,&b,&c);
        addarc(a,b,c); addarc(b,a,c);
	}
	printf("Impossible");
}
