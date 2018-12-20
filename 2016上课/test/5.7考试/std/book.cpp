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
	    scanf("%d",&A[j]);//��A[i]��¼���� ��1��ʼ���±� 
		S[j]=S[j-1]+A[j];  
	  }
	for(i=1;i<=N;i++) F[1][i]=S[i];    
	for(i=2;i<=N;i++) //i:�� 
	{
		for(j=i;j<=N-K+i;j++) //j:����
		{
			 F[i][j]=10000000; 
			 for(k=1;k<=j-i;k++) //����k���� 
			    if(max(F[i-1][j-k],S[j]-S[j-k])<=F[i][j])
			    {
			    	F[i][j]=max(F[i-1][j-k],S[j]-S[j-k]);
			    	G[i][j]=k; //ǰi���˳�j����ʱ�����һ�˳���k����F�ɵ���Сֵ 
			    }
		}
	}
	int z=0,l[10000]={0};
	j=K;
	l[1]=1;
	l[K+1]=N+1;
	for(i=N;i>=1;i--)
	{
		if(z+A[i]>F[K][N]) //���� 
		{
			l[j]=i+1;  //��һ����ʼ 
			j--;       //����һ���˵� 
			z=A[i];  //�Ȿ���Ѿ���������!!! 
		}
		else z+=A[i];
	}

	for(i=1;i<=K;i++)
	{
		printf("%d %d\n",l[i],l[i+1]-1); 
	}

	return 0;
}
