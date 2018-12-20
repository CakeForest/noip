#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

struct node1{
	int num;
	int place;
}a[200000];

struct node2{
	int num;
	bool vis;
}b[200000];

int f[1005][1005];

int cmp(node1 x,node1 y){
	if(x.num<y.num) return y.num;
	else return x.num;
}
int main()
{
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	if(n<2*m)
	{
		printf("Error!");
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].num);
		b[i].num=a[i].num;
		a[i].place=i;
	}
	
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	int ans=0;
	
	for(int i=1;i<=n;i++)
	{
		int pre=a[i].place-1;
		int next=a[i].place+1;
		int cur=a[i].place;
		if(a[i].place==1)
			pre=n;
		if(a[i].place==n)
			next=1;
		if(b[cur].vis==false)
		{
			ans+=a[i].num;
			cnt++;
			b[cur].vis=true;
			b[pre].vis=true;
			b[next].vis=true;
		}
		if(cnt==m) break;
		if(i==n) i=1;
	}
	
	/*
	for(int i=1;i<=m;i++)
	{
		f[i][0]=0;
		f[i][1]=a[1].num;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int pre=a[i].place-1;
			int next=a[i].place+1;
			int cur=a[i].place;
			if(a[i].place==1)
				pre=n;
			if(a[i].place==n)
				next=1;
			if(b[cur].vis==false)
			{
				if(f[i-1][j]+b[cur].num>f[i][j])
				{
					f[i][j]=f[i-1][j]+b[cur].num;
					b[cur].vis=true;
					b[pre].vis=true;
					b[next].vis=true;
				}
			}
		}
	}
	*/
	printf("%d",ans);
	return 0;
}
