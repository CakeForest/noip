#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//���ҳ�ÿ�����Ķ����������ҳ�������ȵ��Ǹ����ڵ�
//LCA 
const int MAX=100020;
int first[MAX],nxt[MAX],fa[MAX],size[MAX],h[MAX];//�� 
int fir[MAX],nx[MAX<<1],go[MAX<<1],id[MAX<<1],ansnum;//��
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

void dfs1(int rt,int t){//��ʼ�� 
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
	col[x]=1;//��ɫ
	for(int p=first[x];p;p=nxt[p])
		dfs2(p);//���±���
		
	col[x]=2;
	//�˴����� 
	for(int p=fir[x];p;p=nx[p]){//�����𰸣����Ƿ���Լ��� 
		int v=go[p],u=x;
		if(!solve[id[p]]&&col[v]){//��δ�����������һ�����ѱ�����
			if(u==v){
				out[id[p]]=size[rt]-1;
				solve[id[p]]=1;
			} 
			else if(col[v]==1){//���ӹ�ϵ 
				if((h[u]-h[v])%2==1){//�޸õ�                       //Check
					out[id[p]]=0;
					solve[id[p]]=1;
				}else{                                              //Check
					int aim=(h[u]+h[v])>>1,son,he;
					for(son=u,he=h[u];he>aim+1;he--)
						son=fa[son];
					out[id[p]]=size[fa[son]]-size[son];
					solve[id[p]]=1;
				}
			}else{//�ֵܹ�ϵ 
				if(h[u]==h[v]){//�����ͬ                                  //Check
					while(u!=v){u=fa[u];v=fa[v];}        
					out[id[p]]=size[rt]-size[u]+1;
					solve[id[p]]=1;
				}else{//��Ȳ�ͬ 
					if((h[u]+h[v])%2==1){//�޸õ�                  //Check
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
			rt=i;//�Ҹ��ڵ�
			break;
		}
	
	dfs1(rt,1);//�������Ĵ�С����� 
	
	scanf("%d",&m);
	//���ӹ�ϵ ���е��е�
	/*�ֵܹ�ϵ 
		��������ͬ��ans=size[rt]-size[LCA]+1
		��Ȳ�ͬ��ans=size[m]-size[son[m]] ->��LCA�������ĵ�֮��еĵ�
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
