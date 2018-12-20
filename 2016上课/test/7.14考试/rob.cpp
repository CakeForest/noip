#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int Q;

int DuiShu(int n){//取以5为底，n的对数 
	int pre=1,nxt=5;
	for(int i=0;i<=20;i++){
		if(n>=pre&&n<nxt) return i;
		pre*=5; nxt*=5;
	}
}

int calc(int n){//计算n的阶乘有多少个5
	int ds=DuiShu(n),sum=0;//取对数
	
	int pre=5,nxt=25;
	for(int i=1;i<=ds;i++){//每5^i个数产生一个0
		sum+=n/pre;
		pre*=5; nxt*=5;
	}
	return sum;
} 

int BinarySearch(int s,int e){//二分查找最佳答案 
	int mid,ans;
	while(s<=e){
		mid=(s+e)/2;
		ans=calc(mid);
		if(ans==Q)
			return mid;
		else if(ans>Q)//0多了 
			e=mid-1;
		else if(ans<Q)//0少了
			s=mid+1;
	}
	return -1;
}

int FindBest(int ans){
	if(ans%5!=0)//如果不是最优解
		ans=ans-(ans%5);
	return ans;
}

int main()
{
	freopen("rob.in","r",stdin);
	freopen("rob.out","w",stdout);
	scanf("%d",&Q);
	if(Q==0){
		printf("1");
		return 0;
	}
	int ans=BinarySearch(5,200000000);
	if(ans==-1)
		printf("No solution");
	else
		printf("%d",FindBest(ans));

//	printf("%d",DuiShu(30));//测试 
	
	return 0;
}
