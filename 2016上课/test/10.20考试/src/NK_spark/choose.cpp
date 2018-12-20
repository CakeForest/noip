#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

#define INTpair pair<int,int>
#define xx first
#define yy second
#define LL long long
#define CLEAR(xxx) memset(xxx,0,sizeof(xxx))
using namespace std;
const int maxn=5000+5,inf=0x3f3f3f3f;

int n,m,ans=-inf,s[maxn],f[maxn][maxn];

template <typename T>
inline void _read(T &x){
    char ch=getchar(); bool mark=false;
    for(;!isdigit(ch);ch=getchar())if(ch=='-')mark=true;
    for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(mark)x=-x;
}

void Solve(int S,int T){
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)f[i][j]=-inf;
	for(j=1;j<=m;j++){
		int _max=0;
		for(i=S+j-1;i<=T;i++){
			f[i][j]=_max+s[i];
			_max=max(_max,f[i-1][j-1]);
		}
	}
	/*
	cout<<"Interval: "<<S<<" "<<T<<endl;
	for(j=1;j<=m;j++,cout<<endl)
		for(i=1;i<=n;i++)cout<<f[i][j]<<" ";
	cout<<endl;
	*/
	for(i=S;i<=T;i++)ans=max(ans,f[i][m]);
}

int main(){
    freopen("choose.in","r",stdin);
    freopen("choose.out","w",stdout);
    int i,j;
    _read(n); _read(m);
    if(m>n/2){
    	puts("Error!");
    	return 0;
	}
    for(i=1;i<=n;i++)_read(s[i]);
    Solve(1,n-1);
    Solve(2,n);
    cout<<ans<<endl;
    fclose(stdin);
	fclose(stdout);
    return 0;
}

