#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000000;
struct node xulie{
	int first,nxt[5];
}xl[12];
int HashTable[MAX+200],zhi[6]={133,251,19,787,57,83};
int Hash1(int* a){
	long long sum=0;
	for(int i=5;i>=1;i--){
		sum+=(a*)+2333+zhi[i]*(*a++);
		sum%=MAX;
	}
	return sum%MAX;
}
int Hash2(int* a){
	long long sum=0;
	for(int i=0;i<=5;i++){
		sum+=((a*)>>2)+37233+zhi[i]*(*a++);
		sum%=MAX;
	}
	return sum%MAX;
}

void asort(int* a){//将此序列处理成为最小的序列 
	int sum=0,mina=99999999,log[7],pre[6],flag[6]={0};
	for(int i=0;i<=5;i++)
		pre[i]=a[i];//存储原来的数组 
	for(int i=0;i<=5;i++){//算出数组中的最小值 
		if(a[i]<mina) mina=a[i],sum=1,log[1]=i;
		else if(a[i]==mina) sum++,log[sum]=i;
	}
	while(sum!=1){
		
		
	}
	for(int i=0;i<=5;i++)
		if(flag[i]==0){
			for(int j=0;j<=5;j++){
				a[j]=pre[i+j];
				if(i+j>6) i-=6;
			}
			break;
		}
	
	
	
}

int main(){
	//freopen("in.txt","r",stdin);
	int n,k,h1,h2,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a[7];
		for(int j=0;j<=5;j++)
			scanf("%d",&a[j]);
		a[6]=a[0];
		asort(a);//特殊排序，使这个序列按字典序排列 
		h1=Hash1(a); h2=Hash2(a);
		while(!HashTable[h1]){//如果该位置非空 
			if(HashTable[h1]==h2){//有相同的雪花 
				flag=1;
				goto end;
			}
			h1+=233;
			if(h1>MAX) h1%=MAX;
		}
		HashTable[h1]=h2;
	}
	end:if(flag) printf("Twin snowflakes found.");
	else printf("No two snowflakes are alike.");
	
	
	
	return 0;
}
