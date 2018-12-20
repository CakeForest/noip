#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=50000;
int HashTable[MAX+50],father[MAX+50],kind[MAX+50],ans[MAX];
int que[100000],top,rear;
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
 
int FindHash(int aim){
    int ad=(aim%MAX+aim+15411111)%MAX;
    while(HashTable[ad]!=0){
        ad+=ad%11+3;
        if(ad>MAX) ad%=MAX;
        if(HashTable[ad]==aim) return ad;
    }return -1;
}
 
int InsertHash(int a){
    if(FindHash(a)!=-1) return 0;
    int ad=(a%MAX+a+15411111)%MAX;
    while(HashTable[ad]!=0){
        ad+=ad%11+3;
        if(ad>MAX) ad%=MAX;
    }
    HashTable[ad]=a;
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
    }//¶ÁÈëÄ¿±ê×´Ì¬ 
    InsertHash(12348765);
    que[rear++]=12348765;
    do{
        int s1,s2,s3,now=que[top],nowha=FindHash(now);
        if(now==end){
            int t=top,sum=0;
//          printf("top=%d rear=%d\n",top,rear);
            while(t!=0){
//              printf("%d %d\n",t,kind[t]);
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
    //  printf("%d %d\n",top,rear);
    }while(top!=rear);
     
     
    return 0;
}

