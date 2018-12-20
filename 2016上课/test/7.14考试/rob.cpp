#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int Q;

int DuiShu(int n){//ȡ��5Ϊ�ף�n�Ķ��� 
	int pre=1,nxt=5;
	for(int i=0;i<=20;i++){
		if(n>=pre&&n<nxt) return i;
		pre*=5; nxt*=5;
	}
}

int calc(int n){//����n�Ľ׳��ж��ٸ�5
	int ds=DuiShu(n),sum=0;//ȡ����
	
	int pre=5,nxt=25;
	for(int i=1;i<=ds;i++){//ÿ5^i��������һ��0
		sum+=n/pre;
		pre*=5; nxt*=5;
	}
	return sum;
} 

int BinarySearch(int s,int e){//���ֲ�����Ѵ� 
	int mid,ans;
	while(s<=e){
		mid=(s+e)/2;
		ans=calc(mid);
		if(ans==Q)
			return mid;
		else if(ans>Q)//0���� 
			e=mid-1;
		else if(ans<Q)//0����
			s=mid+1;
	}
	return -1;
}

int FindBest(int ans){
	if(ans%5!=0)//����������Ž�
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

//	printf("%d",DuiShu(30));//���� 
	
	return 0;
}
