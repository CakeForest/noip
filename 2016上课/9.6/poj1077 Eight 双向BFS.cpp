#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=600000;
const int key=123046758;//目标状态 
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int tpow[]={0,1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1};
bool vis1[MAX],vis2[MAX];
int q1[MAX],f1[MAX],s1[MAX],top1,rear1;
int q2[MAX],f2[MAX],s2[MAX],top2,rear2;
int n=0,c,a=100000000;

int contor(int t){
	int s[10],n=9;//将数字生成数组
	for(int i=n;i>=1;i--){s[i]=t%10;t/=10;}
	int sum=0,k;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]) k++;
		sum+=k*fac[n-i];
	}
	return sum;//范围0~n!-1
}
int getint(){//输入整数 
	char c;
	while(1){
		c=getchar();
		if(c=='x') return 0;
		if('0'<=c&&c<='9') return c-'0';
	}
}
int findloc(int t){//找到x的位置 
	for(int i=9;i>=1;i--)
		if(t%10==0) return i;
		else t/=10;
	return 0;
}
int left(int t){//check
	int p=findloc(t),temp;
	if(p==1||p==4||p==7) return 0;
	temp=t/tpow[p-1]%10;
	t-=temp*tpow[p-1];
	return t+temp*tpow[p];
}

int right(int t){//check
 	int p=findloc(t),temp;
	if(p==3||p==6||p==9) return 0;
	temp=t/tpow[p+1]%10;
	t-=temp*tpow[p+1];
	return t+temp*tpow[p];
}

int down(int t){//check
	int p=findloc(t),temp;
	if(p==7||p==8||p==9) return 0;
	temp=t/tpow[p+3]%10;
	t-=temp*tpow[p+3];
	return t+temp*tpow[p];
}

int up(int t){//check
	int p=findloc(t),temp;
	if(p==1||p==2||p==3) return 0;
	temp=t/tpow[p-3]%10;
	t-=temp*tpow[p-3];
	return t+temp*tpow[p];
}

char translate(int t){
	switch(t){
		case 0:return 'l';
		case 1:return 'r';
		case 2:return 'u';
		case 3:return 'd';
	}
	return 0;
}

int Find(int t[],int k){
	for(int i=0;i<=MAX;i++)
		if(t[i]==k) return i;
	return -1;
}

void print(int t1,int t2){
	int ans[320],cnt=0;
	
	while(t1!=0){
		ans[cnt]=s1[t1];
		t1=f1[t1];
		cnt++;
	}
	cnt--;
	for(int i=cnt;i>=0;i--) printf("%c",translate(ans[i]));
	
	while(t2!=0){
		printf("%c",translate(s2[t2]));
		t2=f2[t2];
	}
}

bool judge(int kind,int t,int step){
	if(t==0) return false;
	int con=contor(t);
	if(kind==1){
		if(vis1[con]) return false;
		vis1[con]=true;
		q1[rear1]=t;
		s1[rear1]=step;
		f1[rear1]=top1;
		rear1++;
	}else{
		if(vis2[con]) return false;
		vis2[con]=true;
		q2[rear2]=t;
		s2[rear2]=step^1;
		f2[rear2]=top2;
		rear2++;
	}
	return true;
}

int main(){
	freopen("in.txt","r",stdin);
	
	for(int i=1;i<=9;i++){
		c=getint();
		n+=a*c;
		a/=10;
	}
	
	q1[rear1++]=n; q2[rear2++]=key;
	vis1[contor(n)]=vis2[contor(key)]=true;
	do{
		int u1=q1[top1],u2=q2[top2],t;
		if(vis2[contor(u1)]){print(top1,Find(q2,u1));return 0;}
		t=left(u1); judge(1,t,0);
		t=right(u1); judge(1,t,1);
		t=up(u1); judge(1,t,2);
		t=down(u1); judge(1,t,3);
		top1++;
		
		if(vis1[contor(u2)]){print(Find(q1,u2),top2);return 0;}
		t=left(u2); judge(2,t,0);
		t=right(u2); judge(2,t,1);
		t=up(u2); judge(2,t,2);
		t=down(u2); judge(2,t,3);
		top2++;
	}while(top1!=rear1&&top2!=rear2);
	printf("unsolvable");
	
	
	return 0;
}
