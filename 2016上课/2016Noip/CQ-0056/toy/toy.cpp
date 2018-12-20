#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100020;
char str[MAX][15];
int dir[MAX];
int n,m;
inline void read(int &num){
	num=0; int flag=1; char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') break;
	if(ch=='-') flag=-1; else num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		num=num*10+ch-'0';
	num*=flag;
}

int move(int now,bool dir,int t){
//逆时针为0 顺时针为1 
	if(!dir){
		now+=t;
		while(now>n) now-=n;
	}else{
		now-=t;
		while(now<=0) now+=n;
	}
	return now;
}

int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	
	read(n),read(m);

	for(int i=1;i<=n;i++){
		read(dir[i]);
		scanf("%s",str[i]);
	}
	
	int ans=1;
	
//	printf("%d %s\n",ans,str[ans]);
	
	for(int i=1;i<=m;i++){
		int d,t;
		scanf("%d%d",&d,&t);		
		if(dir[ans]==1){
			ans=move(ans,d,t);
		}else{
			ans=move(ans,d^1,t);
		}	
		
		/*                        		
		printf("d=%d t=%d\n",d,t);
		printf("%d %s\n",ans,str[ans]);
		
                         */
	}
	
	printf("%s",str[ans]);
/*	
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d %s %d\n",i,str[i],dir[i]);
	}*/
	
	return 0;
}

