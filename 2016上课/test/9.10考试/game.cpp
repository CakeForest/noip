#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int l,r,s;
}per[50000];
int num[1000000],t[1000000],lenn,lent;//高精度 
int ans[1000000],lena;
int ka,kb,n,a,b;

bool cmp(node a,node b){
	if(a.s!=b.s) return a.s<b.s;//a*b大的在前 
	return a.l<b.l;//否则左手小的在前 
}

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

void judge(int *num,int len){
	bool flag=0;
	if(len>lena) flag=1;
	else
		for(int i=len;i>=1;i--)
			if(num[i]>ans[i]){
				flag=1;
				break;
			}
	if(flag){
		lena=len;
		for(int j=1;j<=lena;j++) ans[j]=num[j];
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%d%d",&ka,&kb);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&per[i].l,&per[i].r);
		per[i].s=per[i].l*per[i].r;
	}
	sort(per+1,per+1+n,cmp);
	
	lenn=1;
	while(ka){
		num[lenn++]=ka%10;
		ka/=10;
	}lenn--;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=lenn;j++) t[j]=num[j];
		lent=lenn;
		chu(t,lent,per[i].r);
		judge(t,lent);
		cheng(num,lenn,per[i].l);
	}
	
	for(int i=lena;i>=1;i--) printf("%d",ans[i]);
	
}
