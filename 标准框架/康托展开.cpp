#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fac[]={1,1,2,6,24,120,720,5040,40320,362880}; //i�Ľ׳�Ϊfac[i]

int contor(int n,int t){
	int s[10];//�������������� 
	for(int i=n;i>=1;i--){s[i]=t%10;t/=10;}
	
/*
	X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!  

����a[i]Ϊ��ǰδ���ֵ�Ԫ���������ڵڼ�������0��ʼ��������0<=a[i]<i(1<=i<=n)

*/	
	int sum=0,k;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]) k++;
		sum+=k*fac[n-i];
	}
	return sum;//��Χ0~n!-1 
}

int main(){
	int n,t,a[5];
	scanf("%d",&n);//������λ�� 
	while(scanf("%d",&t)){
		printf("%d\n",contor(n,t));
	}
	
}
