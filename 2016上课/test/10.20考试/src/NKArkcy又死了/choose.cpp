#include<cstdio>
const int M=200009;
const int N=5009;
const int inf=-0x3c3c3c3c;
#define max(x,y) (((x-y)>>31&y)|(x&~((x-y)>>31)))
int s,n,m,A[M],F[2][N][2];
inline int G(){
	int c=0;char o=getchar();bool q=(o=='-');
	while(o<48||o>57)o=getchar(),q|=(o=='-');
	while(o>47&&o<58)c=(c<<3)+(c<<1)+o-48,o=getchar();
	return q?-c:c;
}
int DFS(int l,int r,int k){
	if(k==0)return 0;	
	if(l>r)return 0;
	if(l==r){
		if(k==1)return A[l];
		return inf;
	}
	if(r-l<=8){
		int s=max(DFS(l+1,r,k),DFS(l,r-1,k));
		for(int i=l+1;i<r;i++)
			for(int j=0;j<=k;j++)
				s=max(s,DFS(l,i-1,j)+DFS(i+1,r,k-j));
		return s;
	}
	int t=(l+r)>>1,s=inf;
	for(int i=0;i<=k;i++)
		s=max(s,DFS(l,t-1,i)+DFS(t+1,r,k-i));
	for(int i=0;i<k;i++)
		s=max(s,DFS(l,t-2,i)+DFS(t+2,r,k-i-1)+A[t]);
	return s;
}
int main(){
	freopen("choose.in","r",stdin);
	freopen("choose.out","w",stdout);
	int i,j;
	n=G(),m=G();
	if(m>n/2){
		printf("Error!");
		return 0;
	}
	for(i=1;i<=n;i++)
		A[i]=G();	
	if(n<=5000){
		for(i=1;i<n;i++){
			for(j=1;j<=m;j++){
				F[i&1][j][0]=max(F[i+1&1][j][0],F[i+1&1][j][1]);
				F[i&1][j][1]=F[i+1&1][j-1][0]+A[i];	
			}
		}
		s=max(F[n-1&1][m][0],F[n-1&1][m][1]);
		for(j=1;j<=m;j++)
			F[1][j][0]=F[1][j][1]=0;
		for(i=2;i<=n;i++){
			for(j=1;j<=m;j++){
				F[i&1][j][0]=max(F[i+1&1][j][0],F[i+1&1][j][1]);
				F[i&1][j][1]=F[i+1&1][j-1][0]+A[i];	
			}
		}
		s=max(s,max(F[n&1][m][0],F[n&1][m][1]));
		printf("%d",s);
		return 0;
	}
	else {
		printf("%d",max(DFS(1,n-1,m),DFS(2,n,m)));
	}
	fclose(stdin);
	fclose(stdout);
}
