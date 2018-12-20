#include <cstdio>
#include <cmath> 
double h,x0,x[8],r[8];

bool pd(double m){
	
	double t[8];
	for(int i=1;i<=7;i++)
	{
		t[i]=r[i]+m;
	}
	double left[8],right[8],tr;
	for(int i=1;i<=7;i++){
		tr=sqrt(t[i]*t[i]-h*h);
		left[i]=x[i]-tr;
		right[i]=x[i]+tr;
	}
	
	if(left[1]>x0) return false;
	double tx0=0;
	for(int i=1;i<=7;i++){
	
		if(tx0<=right[i] && left[i]<=tx0) {
			tx0=right[i];
			
		}
	}
	if(tx0>=x0)
		return true;
	return false;
	
}

double solve(double left,double right){
	double mid;
	while(right-left>1e-5){
		mid=(left+right)/2;
		
		if(pd(mid)){
			right=mid;
		}else
			left=mid;
	}
	return mid;
}

int main()
{
	freopen("rainbow.in","r",stdin);
	freopen("rainbow.out","w",stdout);
	scanf("%lf%lf",&h,&x0);
	for(int i=1;i<=7;i++)
		scanf("%lf%lf",&x[i],&r[i]);
	
	double t;
	for(int i=1;i<=6;i++)
	{
		for(int j=i+1;j<=7;j++){
			if(x[i]-r[i]>x[j]-r[j]){
				t=x[i];x[i]=x[j];x[j]=t;
				t=r[i];r[i]=r[j];r[j]=t;
			}
		}
	}
	/* 
	for(int i=1;i<=7;i++)
		printf("%lf %lf\n",x[i],r[i]);
		*/ 
//	pd(500); 
	printf("%.2lf",solve(0,10000));
	
}
