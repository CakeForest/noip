#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int p,n,flag[40000];
int X,Y,U,V;
int cmp(double a,double b){//±È½Ïa/bºÍx/y 
	return a>b;
}

int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}

int main(){
	freopen("rational.in","r",stdin);
//	freopen("rational.out","w",stdout);
	
	cin>>p>>n;
	int X,Y,U,V;
	X=V=1;
	Y=U=9999999;
	

	double t=sqrt(p);
	
	for(int j=1;j<=n;j++)
		for(int i=floor(t)*j;i<=ceil(t)*j;i++){
			if(i>n) break;
			if(gcd(i,j)==1&&cmp(1.0*i/j,1.0*X/Y)&&!cmp(1.0*i/j,t))
				X=i,Y=j;
		}
	
	for(int j=1;j<=n;j++)
		for(int i=floor(t)*j;i<=ceil(t)*j;i++){
			if(i>n) break;
			if(gcd(i,j)==1&&!cmp(1.0*i/j,1.0*U/V)&&cmp(1.0*i/j,t))
				U=i,V=j;
		}
	
	printf("%d/%d %d/%d",X,Y,U,V);
	
	return 0;
}
