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
const int maxn=25,inf=0x3f3f3f3f;

template <typename T>
inline void _read(T &x){
    char ch=getchar(); bool mark=false;
    for(;!isdigit(ch);ch=getchar())if(ch=='-')mark=true;
    for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
    if(mark)x=-x;
}

struct Edge{
	int from, to, w;
	bool operator < (const Edge s)const {
		return w<s.w;	
	}
}s[maxn*maxn];


int ans=inf,n,m,A[maxn];
int fa[maxn];
vector<int> P,Size;

int Find(int x){
	return x== fa[x]? x: fa[x]=Find(fa[x]);
}

void Solve(int S){
	//cout<<"Solveing: "<<S<<endl;
	int i,j,tot_sum=0;
	for(i=0;i<=n;i++)fa[i]=i;
	for(i=0;(1<<i)<=S;i++)
		if((S>>i)&1){
			int cnt=0,sum=0;
			for(j=1;j<=m&&cnt<Size[i];j++)
				if( ((P[i]>>s[j].from)&1)&& ((P[i]>>s[j].to)&1) ){
				int fx=Find(s[j].from),fy=Find(s[j].to);
				if(fx!=fy){
					fa[fx]=fy;
					sum+=s[j].w;
					cnt++;
				}
			}
			if(cnt!=Size[i]-1) return ;
			tot_sum+=sum;
		}
	ans=min(ans,tot_sum);
}

int main(){
    freopen("wine.in","r",stdin);
    freopen("wine.out","w",stdout);
    int i,j,S;
    _read(n);_read(m);
    int All=(1<<n)-1;
    bool flag=false;
    for(i=0;i<n;i++){
    	_read(A[i]);
    	if(A[i]) flag=true;
    }
    for(i=1;i<=m;i++){
    	_read(s[i].from); _read(s[i].to);
    	_read(s[i].w);
    	if(s[i].w<0)S+=s[i].w;
	}
	sort(s+1,s+1+m);
	
	if(!flag){
		cout<<S<<endl;
		return 0;
	}
	for(S=1;S<=All;S++){
		int sum=0,size=0;
		for(i=0;(1<<i)<=S;i++)
			if((S>>i)&1)sum+=A[i],size++;
		if(sum==0)
			P.push_back(S),Size.push_back(size);
	}
	
	int tot=P.size(),all=(1<<tot)-1;
	for(i=0;i<=all;i++){
		bool ok=true;
		int cur=0;
		for(j=0;(1<<j)<=i;j++)
			if((i>>j)&1){
				if((cur&P[j])!=0){ok=false; break;}
				cur|=P[j];
			}
			//cout<<"cur== "<<cur<<endl;
		if(ok&&cur==All)Solve(i);
	}
	if(ans==inf) puts("Impossible");
	else cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

