#include <cstdio>
#include <climits>
const int MAXSIZE=1000;
long long int F[MAXSIZE][MAXSIZE],S[MAXSIZE]={0};
int G[MAXSIZE][MAXSIZE]={0},A[MAXSIZE],B[MAXSIZE],C[MAXSIZE];
int min(int a,int b)
{
	if(a>=b) return b;
	else return a;
}
int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
int main()
{
	freopen("book.in","r",stdin) ;
	freopen("book.out","w",stdout);
	int N,i=0,j,K,k,a,q;
	scanf("%d%d",&N,&K);
	 for(j=1;j<=N;j++)
	 {
	    scanf("%d",&A[j]);//把A[i]记录下来 从1开始用下标 
		S[j]=S[j-1]+A[j];  
	  }
	for(i=1;i<=N;i++) F[1][i]=S[i];    
	for(i=2;i<=N;i++) //i:人 
	{
		for(j=i;j<=N-K+i;j++) //j:本书
		{
			 F[i][j]=10000000; 
			 for(k=1;k<=j-i;k++) //抄后k本书 
			    if(max(F[i-1][j-k],S[j]-S[j-k])<=F[i][j])
			    {
			    	F[i][j]=max(F[i-1][j-k],S[j]-S[j-k]);
			    	G[i][j]=k; //前i个人抄j本书时，最后一人抄后k本，F可得最小值 
			    }
		}
	}
	int z=0,l[10000]={0};
	j=K;
	l[1]=1;
	l[K+1]=N+1;
	for(i=N;i>=1;i--)
	{
		if(z+A[i]>F[K][N]) //超了 
		{
			l[j]=i+1;  //上一本开始 
			j--;       //找下一个人的 
			z=A[i];  //这本就已经抄不了了!!! 
		}
		else z+=A[i];
	}

	for(i=1;i<=K;i++)
	{
		printf("%d %d\n",l[i],l[i+1]-1); 
	}

	return 0;
}
