#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//二分 
//如何求剩下的木板分成两堆的最大值 
//木板的底的长度[1,1600] 
//底边定后，两块木板的差越小越好 

//动态规划 
int n,len[50],sum;
int opt[50];
bool f[2000][2000];
double maxx;
double square(int x,int y,int z){
	double p,s,a=1.0*x,b=1.0*y,c=1.0*z;
	if((x+y>z)&&(x+z>y)&&(y+z>x)&&x&&y&&z){
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        return s;
    }
	return -1;
}
int l,r;
void dfs(int cnt){
	if(cnt==n+1){
		double t=square(l,r,sum-l-r);
		if(t>=0&&maxx<t) maxx=t;
		return;
	}
	l+=len[cnt];
	dfs(cnt+1);
	l-=len[cnt];
	r+=len[cnt];
	dfs(cnt+1);
	r-=len[cnt];
	dfs(cnt+1);
}

int main(){
	freopen("pasture.in","r",stdin);
	freopen("pasture.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		sum+=len[i];
	}
	if(n<=10){//暴力 
		maxx=-1;
		dfs(1);
		if(maxx<=0) printf("-1");
		else printf("%.0f",maxx*100-0.5);
	}else{//动态规划 
		f[0][0]=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=sum;j++)//枚举两条边 
				for(int k=0;k<=sum;k++){					
					if(j>=len[i]) f[j][k]=f[j][k]||f[j-len[i]][k];
					if(k>=len[i]) f[j][k]=f[j][k]||f[j][k-len[i]];
				}
		}
		
		for(int i=1;i<=sum;i++)
			for(int j=1;j<=sum;j++)
				if(f[i][j]){
					double t=square(i,j,sum-i-j);
					if(t>=0&&maxx<t) maxx=t;
				}
		if(maxx<=0) printf("-1");
		else printf("%.0f",maxx*100-0.5);			
	}
	
	return 0;
}
