#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=10000000;
int s[10],e[10];
bool vis[MAX];
int que[1000000],cnt[1000000],top,rear;
//vis[i][j]表示光标在i时的密码j已经被遍历  
int swap0(int *s,int t){
	if(t!=1) swap(s[t],s[1]);
	return t;
}
int swap1(int *s,int t){
	if(t!=6) swap(s[t],s[6]);
	return t;
}
int up(int *s,int t){
	if(s[t]<9) s[t]++;
	return t;
}
int down(int *s,int t){
	if(s[t]>0) s[t]--;
	return t;
}
int left(int *s,int t){
	if(t==1) return t;
	return t-1;
}
int right(int *s,int t){
	if(t==6) return t;
	return t+1;
}
void build(int *s,int t){
	for(int i=6;i>=1;i--){
		s[i]=t%10;
		t/=10;
	}
}
int trans(int *s){
	int t=0,b=1;
	for(int i=6;i>=1;i--){
		t+=s[i]*b;
		b*=10;
	}
	return t;
}
bool judge(int *s,int *e){
	int flag=1;
	for(int i=1;i<=6;i++)
		if(s[i]!=e[i]){
			flag=0;
			break;
		}
	return flag;
}
void memcopy(int *s,int e[]){
	for(int i=1;i<=6;i++)
		e[i]=s[i];
}
void add(int *temp,int t){
	int con=trans(temp)*10+t;
	if(vis[con]) return;
	vis[con]=1;
	que[rear]=trans(temp)*10+t; 
	cnt[rear++]=cnt[top]+1;
}
int main(){
	freopen("clever.in","r",stdin);
	freopen("clever.out","w",stdout);
	
	int a,b,p[10];
	scanf("%d%d",&a,&b);
	
	build(p,a);
	build(e,b);
	a=a*10+1;
	que[rear++]=a; cnt[1]=0;
	vis[a]=1;
	do{
		int now=que[top],loc=now%10; now/=10;
		
		build(p,now);//将数字转为数组
		if(judge(p,e)){
			printf("%d",cnt[top]);
			return 0;
		}
		
		int temp[10],t;
		memcopy(p,temp); t=swap0(temp,loc); add(temp,t);
		memcopy(p,temp); t=swap1(temp,loc); add(temp,t);
		memcopy(p,temp); t=up(temp,loc); add(temp,t);
		memcopy(p,temp); t=down(temp,loc); add(temp,t);
		memcopy(p,temp); t=left(temp,loc); add(temp,t);
		memcopy(p,temp); t=right(temp,loc); add(temp,t);
		top++;
	}while(top!=rear);
	
	return 0;
}
