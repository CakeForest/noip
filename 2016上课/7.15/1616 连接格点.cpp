#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int father[1020000];
int m,n,x1,x2,y1,y2,ans,k;//m��n�� 
int f(int x,int y){
	return (x-1)*n+y;
}
int Getfather(int p){
	if(father[p]==p) return p;
	father[p]=Getfather(father[p]);
	return father[p];
}

int main()
{
//	freopen("grid.in","r",stdin);
//	freopen("grid.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*n;i++)
		father[i]=i;
	while(scanf("%d%d%d%d",&x1,&x2,&y1,&y2)!=EOF){
		int a=Getfather(f(x1,y1)),b=Getfather(f(x2,y2));
		if(a!=b) father[a]=b,k++;
	}
	for(int i=1;i<=n;i++)//���� 
		for(int j=1;j<m;j++){//���� 
			if(k==n*m-1) break;
			int a=Getfather(f(i,j)),b=Getfather(f(i,j+1));//�ֱ��ȡ��ǰ�����·��ĵ��code 
			if(a!=b)
				ans++,father[a]=b,k++;
		}
	for(int j=1;j<=m;j++)//���� 
		for(int i=1;i<n;i++){//���� 
			if(k==n*m-1) break;
			int a=Getfather(f(i,j)),b=Getfather(f(i+1,j));//�ֱ��ȡ��ǰ�����ҷ��ĵ��code 
			if(a!=b)
				ans+=2,father[a]=b,k++;
		}
	printf("%d",ans);
	
	return 0;
}
