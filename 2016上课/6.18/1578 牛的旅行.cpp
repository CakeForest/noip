#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double MAX=9999999;
int n,dx[2000],dy[2000];
double f[2000][2000],l[2000];//l´æ´¢Ö±¾¶ 
double dis(int a,int b){
	return sqrt((dx[a]-dx[b])*(dx[a]-dx[b])+(dy[a]-dy[b])*(dy[a]-dy[b]));
}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&dx[i],&dy[i]);
	for(int i=1;i<=n;i++){
		getchar();l[200]=-1;
		for(int j=1;j<=n;j++)
			if(getchar()=='1') f[i][j]=dis(i,j);
			else f[i][j]=MAX;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)	
		if(i!=k)
			for(int j=1;j<=n;j++)
				if(j!=i)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);//floyd¼ÆËã×î¶Ì¾àÀë 
	double r=-1,newr=MAX;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]!=MAX)
				l[i]=max(l[i],f[i][j]),r=max(r,f[i][j]);//ÕÒÖ±¾¶ 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]==MAX&&i!=j)
				newr=min(newr,dis(i,j)+l[i]+l[j]);//¼ÓÏß¶Î 
	printf("%.6f",max(newr,r));
	
	return 0;
}
