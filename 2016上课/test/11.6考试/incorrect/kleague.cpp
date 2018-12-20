#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=40000;
int first[MAX],nxt[MAX],go[MAX],flow[MAX],arcnum;
bool vis[MAX];
queue <int> que;
void addarc(int a,int b,int c){
	nxt[++arcnum]=first[a];
	first[a]=arcnum;
	go[arcnum]=b;
	flow[arcnum]=c;
}

int main(){
	freopen("kleague.in","r",stdin);
	freopen("kleague.out","w",stdout);
	
	
	return 0;
}
