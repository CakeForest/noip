#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fac[]={1,1,2,6,24,120,720,5040,40320,362880}; //i的阶乘为fac[i]

int contor(int n,int t){
	int s[10];//将数字生成数组 
	for(int i=n;i>=1;i--){s[i]=t%10;t/=10;}
	
/*
	X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!  

其中a[i]为当前未出现的元素中是排在第几个（从0开始），并且0<=a[i]<i(1<=i<=n)

*/	
	int sum=0,k;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]) k++;
		sum+=k*fac[n-i];
	}
	return sum;//范围0~n!-1 
}

int main(){
	int n,t,a[5];
	scanf("%d",&n);//输入总位数 
	while(scanf("%d",&t)){
		printf("%d\n",contor(n,t));
	}
	
}
