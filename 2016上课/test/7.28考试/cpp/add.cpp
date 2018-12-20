#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[120],b[120],temp[120],ans[120];

void Swap(int* str,int tot){
	for(int i=1;i<=tot;i++)
		temp[i]=str[i];
	int j=1;
	for(int i=tot;i>=1;i--)
		str[i]=temp[j++];
	return;
}

int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	char c;
	int tota=0,totb=0,maxx=-1;
	c=getchar();
	while(c!='\n'){
		a[++tota]=c-'0';
		c=getchar();
	}
	Swap(a,tota);
	c=getchar();
	while(c>='0'&&c<='9'){
		b[++totb]=c-'0';
		c=getchar();
	}
	Swap(b,totb);
	maxx=max(tota,totb);
	
	for(int i=1;i<=maxx;i++){
		ans[i]+=a[i]+b[i];
		if(ans[i]>9){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	
	if(ans[maxx+1]!=0) printf("%d",ans[maxx+1]);
	for(int i=maxx;i>=1;i--)
		printf("%d",ans[i]);
	
	
	return 0;
}
