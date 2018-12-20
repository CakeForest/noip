#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000000;
int HashTable[MAX+50],father[MAX+50],kind[MAX+50],ans[MAX];
int que[1000000],top,rear,fac[8]={1,1,2,6,24,120,720,5040};
int Step1(int n){
	return n/10000+10000*(n%10000);//right
}
int Step2(int n){
	int a[7],t;
	for(int i=0;i<=7;i++){
		a[i]=n%10;
		n/=10;
	}
	swap(a[0],a[3]);swap(a[0],a[2]);swap(a[0],a[1]);
	swap(a[4],a[7]);swap(a[4],a[6]);swap(a[4],a[5]);
	n=0;t=1;
	for(int i=0;i<=7;i++){
		n+=a[i]*t;
		t*=10;
	}return n;//right
}
int Step3(int n){
	int a[7],t;
	for(int i=0;i<=7;i++){
		a[i]=n%10;
		n/=10;
	}
	swap(a[6],a[5]);
	swap(a[6],a[1]);
	swap(a[6],a[2]);
	n=0;t=1;
	for(int i=0;i<=7;i++){
		n+=a[i]*t;
		t*=10;
	}return n;//right
}

int Contor(int n){
	int a[7];
	for(int i=0;i<=7;i++){
		a[i]=n%10;
		n/=10;
	}
	int temp,num=0;
    for(int i=0;i<=7;i++){//康托展开 
        temp=0;//计算在a[i]之前比a[i]小的数的个数 
        for(int j=i+1;j<=7;j++)
            if(a[j]<a[i])
                temp++;
        num+=temp*fac[7-i];//数组下标从0开始 
    }return num;
}

int FindHash(int aim){
	return HashTable[Contor(aim)]!=0;
}

int InsertHash(int aim){
	int h=Contor(aim);
	if(FindHash(aim)) return 0;
	HashTable[h]=aim;
	return 1;
}

int main(){
	freopen("in.txt","r",stdin);
	int end=0,temp,k=10000000;
	for(int i=1;i<=4;i++){
		scanf("%d",&temp);
		end+=temp*k;
		k/=10;
	}k=1;
	for(int i=1;i<=4;i++){
		scanf("%d",&temp);
		end+=temp*k;
		k*=10;
	}//读入目标状态 
	InsertHash(12348765);
	que[rear++]=12348765;
	do{
		int s1,s2,s3,now=que[top];
		if(now==end){
			int t=top,sum=0;
//			printf("top=%d rear=%d\n",top,rear);
			while(t!=0){
//				printf("%d %d\n",t,kind[t]);
				ans[++sum]=kind[t];
				t=father[t];
			}
			printf("%d\n",sum);
			for(int i=sum;i>=1;i--)
				switch(ans[i]){
					case 1:printf("A\n");break;
					case 2:printf("B\n");break;
					case 3:printf("C\n");break;
				}
			break;
		}
		s1=Step1(now); s2=Step2(now); s3=Step3(now);
		if(InsertHash(s1)) que[rear]=s1,kind[rear]=1,father[rear++]=top;
		if(InsertHash(s2)) que[rear]=s2,kind[rear]=2,father[rear++]=top;
		if(InsertHash(s3)) que[rear]=s3,kind[rear]=3,father[rear++]=top;
		top++;
	//	printf("%d %d\n",top,rear);
	}while(top!=rear);
	
	
//	printf("%d\n",Contor(85214763));
	
	
	
	return 0;
}
