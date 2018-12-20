#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int left,right;
	char data;
}tree[200];
char pre[100],mid[100],last[100];
int now=0;
int Look(int f,int m,int len){
	int loc=now++,l;
	if(len==0)
		return 0;
	for(int i=m;i<=m+len-1;i++)
		if(mid[i]==pre[f]){
			l=i;
			break;
		}
	tree[loc].data=pre[f];
	tree[loc].left=Look(f+1,m,l-m);
	tree[loc].right=Look(f+1+l-m,l+1,len-(l-m+1));
	return loc;
}

void Last(int p){
	if(tree[p].left!=0)
		Last(tree[p].left);
	if(tree[p].right!=0)
		Last(tree[p].right);
	cout<<tree[p].data;
	return;
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%s %s",pre+1,mid+1);
	Last(Look(1,1,strlen(pre+1)));
	
	return 0;
}
