//Author: Fluorine
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void solve(int);
void print(int,int);

int opt[405][205],w[405],p[405],l[405],tot,n,m,t;
vector <pair<int,int> > use[405][205];
vector <int> list[405],ans;

int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;++i) list[i].clear();
	for (int i=1;i<=n;++i){
		scanf("%d%d%d%d",&t,&w[i],&p[i],&l[i]);
		list[t].push_back(i);
	}
	memset(opt,0,sizeof(opt));
	for (int i=1;i<=n;++i)
		for (int j=0;j<=p[i];++j)
			use[i][j].clear();
	solve(1);
	tot=0;
	ans.clear();
	int max=0;
	for (int i=1;i<=p[1];++i) if (opt[1][i]>opt[1][max]) max=i;
	print(1,max);
	printf("%d %d\n",ans.size(),tot);
	sort(ans.begin(),ans.end());
	for (int i=0;i+1<ans.size();++i) printf("%d ",ans[i]);
	printf("%d\n",ans[ans.size()-1]);
	return 0;
}

void solve(int cur){
	for (int i=0;i<list[cur].size();++i) solve(list[cur][i]);
	for (int i=0;i<list[cur].size();++i)
		for (int j=p[cur];j>=0;--j)
			for (int k=0;k<=p[list[cur][i]];++k){
				if (j-k-w[list[cur][i]]<0) break;
				if (opt[cur][j-k-w[list[cur][i]]]+opt[list[cur][i]][k]>opt[cur][j]){
					opt[cur][j]=opt[cur][j-k-w[list[cur][i]]]+opt[list[cur][i]][k];
					use[cur][j]=use[cur][j-k-w[list[cur][i]]];
					use[cur][j].push_back(make_pair(list[cur][i],k));
				}
			}
	for (int i=0;i<=p[cur];++i) opt[cur][i]+=l[cur];
}

void print(int cur,int pos){
	ans.push_back(cur);
	tot+=l[cur];
	for (int i=0;i<use[cur][pos].size();++i) print(use[cur][pos][i].first,use[cur][pos][i].second);
}
