#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[1000000],len;//¸ß¾«¶È 
int n;
void cheng(int *num,int &len,int c){
	for(int i=1;i<=len;i++) num[i]*=c;
	for(int i=1;i<=len;i++){
		if(num[i]>9){
			num[i+1]+=num[i]/10;
			len=max(len,i+1);
			num[i]%=10;
		}
	}
}

void chu(int *num,int &len,int c){
	for(int i=len;i>=1;i--){
		if(num[i]<c){
			num[i-1]+=num[i]*10;
			num[i]=0;
		}else{
			num[i-1]+=num[i]%c*10;
			num[i]/=c;
		}
	}
	while(!num[len]) len--;
}

int main(){
//	freopen("in.txt","r",stdin);
	
	scanf("%d",&n);
	len=1;
	while(n){
		num[len++]=n%10;
		n/=10;
	}len--;
	
	cheng(num,len,555);
	chu(num,len,555);
	
	for(int i=len;i>=1;i--) printf("%d",num[i]);
	
}
