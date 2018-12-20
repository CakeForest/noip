#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,father[20020],q;

int getFather(int p){
	if(father[p]==p)
		return p;
	father[p]=getFather(father[p]);//直接将儿子节点接到父亲节点上，缩短距离 
	return father[p];
}

void unions(int f,int s){
	f=getFather(f); s=getFather(s);
	if(f==s)
		return;
	father[s]=f;
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	int f,s;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		father[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&f,&s);
		unions(f,s);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&f,&s);
		if(getFather(f)==getFather(s))
			printf("Yes");
		else
			printf("No");
		printf("\n");
	}
	
	
	return 0;
}
