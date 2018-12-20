#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char str[30][30];
struct node{
	char str[30];
}q[30];

int cmp(node a,node b)
{
	char left[30],right[30];
	strcpy(left,a.str);
	strcat(left,b.str);
	strcpy(right,b.str);
	strcat(right,a.str);
	return strcmp(left,right)>0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",q[i].str);
	sort(q+1,q+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%s",q[i].str);
	
	return 0;
}
