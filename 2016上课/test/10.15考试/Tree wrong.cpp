#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//先找出每棵树的儿子数，再找出距离相等的那个根节点
//LCA 
const int MAX=100020;
int first[MAX],nxt[MAX],fa[MAX],size[MAX],h[MAX];//树 
int fir[MAX],nx[MAX<<1],go[MAX<<1],id[MAX<<1],ansnum;//答案
bool solve[MAX],rd[MAX];
int out[MAX],col[MAX]; 
 
int n,m,rt;
void addans(int a,int b,int c){
	nx[++ansnum]=fir[a];
	fir[a]=ansnum;
	go[ansnum]=b;
	id[ansnum]=c;
}

void addarc(int a,int b){
	nxt[b]=first[a];
	first[a]=b;
	fa[b]=a; rd[b]=1;
}

void dfs1(int rt,int t){//初始化 
	h[rt]=t;
	if(!first[rt]){
		size[rt]=1;
		return;
	}
	for(int p=first[rt];p;p=nxt[p]){
		dfs1(p,t+1);
		size[rt]+=size[p];
	}
	size[rt]+=1;
}

void dfs2(int x){
	col[x]=1;//灰色
	for(int p=first[x];p;p=nxt[p])
		dfs2(p);//向下遍历
		
	col[x]=2;
	//此处计算 
	for(int p=fir[x];p;p=nx[p]){//遍历答案，看是否可以计算 
		int v=go[p],u=x;
		if(!solve[id[p]]&&col[v]){//还未解决问题且另一个点已被遍历
			if(u==v){
				out[id[p]]=size[rt]-1;
				solve[id[p]]=1;
			} 
			else if(col[v]==1){//父子关系 
				if((h[u]-h[v])%2==1){//无该点                       //Check
					out[id[p]]=0;
					solve[id[p]]=1;
				}else{                                              //Check
					int aim=(h[u]+h[v])>>1,son,he;
					for(son=u,he=h[u];he>aim+1;he--)
						son=fa[son];
					out[id[p]]=size[fa[son]]-size[son];
					solve[id[p]]=1;
				}
			}else{//兄弟关系 
				if(h[u]==h[v]){//深度相同                                  //Check
					while(u!=v){u=fa[u];v=fa[v];}        
					out[id[p]]=size[rt]-size[u]+1;
					solve[id[p]]=1;
				}else{//深度不同 
					if((h[u]+h[v])%2==1){//无该点                  //Check
						out[id[p]]=0;
						solve[id[p]]=1;
					}else{                       //Check
						if(h[u]<h[v]) swap(u,v);
						for(int i=1;i<=h[v]-1;i++)
							u=fa[u];
						
						int aim=(h[u]+h[rt])>>1,son,he;
						for(son=u,he=h[u];he>aim+1;he--)
							son=fa[son];
						out[id[p]]=size[fa[son]]-size[son];
						solve[id[p]]=1;
						
					}
				}		
			}
		}
	}

}

int main(){
	freopen("Tree.in","r",stdin);
	freopen("Tree.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addarc(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!rd[i]){
			rt=i;//找根节点
			break;
		}
	
	dfs1(rt,1);//生成树的大小、深度 
	
	scanf("%d",&m);
	//父子关系 看夹的中点
	/*兄弟关系 
		如果深度相同，ans=size[rt]-size[LCA]+1
		深度不同，ans=size[m]-size[son[m]] ->看LCA和深度深的点之间夹的点
	*/
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addans(a,b,i);
		addans(b,a,i);
	}
	dfs2(rt);
	
	for(int i=1;i<=m;i++)
		printf("%d\n",out[i]);
	
	
	return 0;
}
