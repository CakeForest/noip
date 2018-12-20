#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=1000;
int X1[MAX],X2[MAX],Y1[MAX],Y2[MAX],map[MAX][MAX],cd[MAX],ans[MAX];
int stack[MAX],top;

bool IsInside(int x,int y,int t){//第t张输入的幻灯片
	return x>X1[t]&&x<X2[t]&&y>Y1[t]&&y<Y2[t];
} 
int main()
{
//	freopen("in.txt","r",stdin);
	int n,x,y,k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&X1[i],&X2[i],&Y1[i],&Y2[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		for(int j=1;j<=n;j++)
			if(IsInside(x,y,j))
				map[i][j]=1,cd[i]++;//第i个数字在j-'A'+1的幻灯片中 
	}
	
	for(int i=1;i<=n;i++)
		if(cd[i]==1)
			stack[++top]=i;
	do{
		int u=stack[top--];
		k++;
		for(int v=1;v<=n;v++)	
			if(map[u][v]==1){//如果u到v有路径 则u属于v 
				ans[v]=u;
				for(int i=1;i<=n;i++)
				if(map[i][v]==1){
					map[i][v]=0; cd[i]--;
					if(cd[i]==1)
						stack[++top]=i;
				}
				break;
			}
		
	}while(top!=0);
	if(k!=n) printf("None");
	else
		for(int i=1;i<=n;i++)
			printf("%c %d\n",'A'+i-1,ans[i]);

	return 0;
}
