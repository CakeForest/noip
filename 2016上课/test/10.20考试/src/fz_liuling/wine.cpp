#include <cstdio>
#include <cstring>
int n,m,num[17],minn[17],ans=0;
int fa[17],f[17][17],a[17],visit[17];
int Min(int a,int b){
	if(a<b) return a;
	return b;
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),fa[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		f[a][b]=f[b][a]=c;
		if(a>b) fa[a]=find(fa[b]);
		else fa[b]=find(fa[a]); 
	}
	for(int i=0;i<n;i++) num[fa[i]]+=a[i];
	for(int i=0;i<n;i++){
		if(num[i]!=0){
	 		printf("Impossible");
	 		return 0;
	 	}
	}
		for(int s=0;s<n;s++){
			if(fa[s]>=0){ //以s为起点 
				int t=0,i,j,min=0x3f3f3f3f,k=0;
				memset(minn,0x3f3f3f3f,sizeof(minn));
				memset(visit,0,sizeof(visit));
				for(j=s;j<n;j++){
					if(fa[j]==fa[s]){
						if(f[s][j]!=-1) minn[j]=f[s][j];
						k++;
					} 
				} 
				
				minn[s]=0;visit[s]=1;
				for(i=1;i<=k-1;i++){
					min=0x3f3f3f3f;
					t=0;
					for(j=s+1;j<n;j++){
						if(fa[s]==fa[j]){
							if(!visit[j] && minn[j]<min){
								t=j; min=minn[j];
							}
						}
					}
					visit[t]=1;
					ans+=min;
					for(j=s+1;j<n;j++){
						if(fa[s]==fa[j]){
							if(!visit[j] && f[t][j]!=-1){
								if(minn[j]>f[t][j]) minn[j]=f[t][j];
							}
						}
					}
				}
				for(j=s+1;j<n;j++) if(fa[j]==fa[s]) fa[j]=-1;
				fa[s]=-1;
			}
		}
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
