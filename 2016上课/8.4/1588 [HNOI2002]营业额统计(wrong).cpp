#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX=1000000;
int left[MAX],right[MAX],key[MAX],s[MAX],cnt;

void Right_Rotate(int &t){
	int k=left[t];
	left[t]=right[k];
	right[k]=t;
	s[k]=s[t];
	s[t]=s[left[t]]+s[right[k]]+1;
	t=k;
	return;
}
void Left_Rotate(int &t){
	int k=right[t];
	right[t]=left[k];
	left[k]=t;
	s[k]=s[t];
	s[t]=s[left[k]]+s[right[t]]+1;
	t=k;
	return;
}
void Maintain(int &t,bool flag){
	if(flag==false){
		if(s[left[left[t]]]>s[right[t]])
			Right_Rotate(t);
		else if(s[right[left[t]]]>s[right[t]]){
			Left_Rotate(left[t]);
			Right_Rotate(t);
		}else return;//一定记住返回 
	}else{
		if(s[right[right[t]]]>s[left[t]])
			Left_Rotate(t);
		else if(s[left[right[t]]]>s[left[t]]){
			Right_Rotate(right[t]);
			Left_Rotate(t);
		}else return;//一定记住返回 
	}
	Maintain(left[t],false);
	Maintain(right[t],true);
	Maintain(t,false);
	Maintain(t,true);
}
void Insert(int &t,int k){
	if(t==0){
		key[++cnt]=k;
		s[cnt]=1;
		t=cnt;
		left[cnt]=right[cnt]=0;
	}
	else{
		s[t]++;
		if(k<key[t]) Insert(left[t],k);
		else Insert(right[t],k);
		Maintain(t,k>=key[t]);
	}
}
int Find(int rt,int k){
	if(rt==0) return 0;
	if(k<key[rt]) return Find(left[rt],k);
	else if(k==key[rt]) return 1;
	else return Find(right[rt],k);
}
int Pred(int rt,int k){//找前驱 
	if(rt==0) return k;
	if(k<=key[rt]) return Pred(left[rt],k);
	else{
		int ret=Pred(right[rt],k);
		if(ret==k) return key[rt];
		return ret;
	} 
}
int Succ(int rt,int k){//找后继 
	if(rt==0) return k;
	if(k>=key[rt]) return Succ(right[rt],k);
	else{
		int ret=Succ(left[rt],k);
		if(ret==k) return key[rt];
		return ret;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	int n,c,sum=0,root=0;
	scanf("%d",&n);
	scanf("%d",&c);
	sum+=c;
	Insert(root,c);
	for(int i=2;i<=n;i++){
		if(scanf("%d",&c)==EOF)//这里特殊处理
            c=0;
		if(Find(root,c)) continue;//必须判重，否则会重复储存 
		int P=Pred(root,c),S=Succ(root,c);
		if(P==c) sum+=abs(c-S);
		else if(S==c) sum+=abs(c-P);
		else sum+=min(abs(c-P),abs(c-S));
		Insert(root,c);
	}
	printf("%d\n",sum);
	
	return 0;
}
