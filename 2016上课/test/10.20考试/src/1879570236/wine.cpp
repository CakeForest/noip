#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
inline void _read(int &x){
    char t=getchar();bool sign=true;
    while(t<'0'||t>'9')
    {if(t=='-')sign=false;t=getchar();}
    for(x=0;t>='0'&&t<='9';t=getchar())x=x*10+t-'0';
    if(!sign)x=-x;
}
int n,m;
int tot;
int all;
struct line{
	int from,to,len;
	line(){}
	line(int a,int b,int c){from=a;to=b;len=c;}
	bool operator < (const line t) const{
		return len<t.len;
	}
};
line edge[10005];
int a[50];
int map[55][55];
int father[20];
int getfather(int x){
	if(x!=father[x])return father[x]=getfather(father[x]);
	else return x;
}
int bitcnt(int x){
	int cnt=0;
	while(x>0){
		x-=(x&(-x));
		cnt++;
	}
	return cnt;
}
int f[(1<<16)];
int pre[(1<<16)];
int p[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void work(int s){
	//cout<<"work:"<<s<<endl;
	if(bitcnt(s)==1){
		pre[s]=0;
		return;
	}
	vector<int> v;
	vector<line> v2;
	int i,j,k,x,temp,sum=0,cnt=0,tot=0;
	x=s;
	while(x>0){
		temp=(x&(-x));
		x-=temp;
		for(i=0;i<n;i++){
			if(p[i]==temp){
				//cout<<i<<endl;
				v.push_back(i);
				father[i]=i;
				tot+=a[i];
				break;
			}
		}
	}
	//cout<<"size:"<<v.size()<<endl;
	//if(tot!=0)return;
	for(i=0;i<v.size();i++){
		for(j=i+1;j<v.size();j++){
			//cout<<v[i]<<" "<<v[j]<<endl;
			if(map[v[i]][v[j]]!=0){
				v2.push_back(line(v[i],v[j],edge[map[v[i]][v[j]]].len));
				//cout<<"push:"<<v[i]<<" "<<v[j]<<" "<<edge[map[v[i]][v[j]]].len<<endl;
			}
		}
	}
	sort(v2.begin(),v2.end());
	k=0;
	while(cnt<v.size()-1&&k<v2.size()){
		int x,y,fx,fy;
		x=v2[k].from;
		y=v2[k].to;
		//cout<<x<<" "<<y<<endl;
		fx=getfather(x);
		fy=getfather(y);
		if(fx!=fy){
			father[fx]=fy;
			cnt++;
			sum+=v2[k].len;
		}
		k++;
	}
	if(cnt>=v.size()-1){
		pre[s]=sum;
	}
}
bool check(int s){
	int i,j,k,x,temp,sum=0,cnt=0,tot=0;
	x=s;
	while(x>0){
		temp=(x&(-x));
		x-=temp;
		for(i=0;i<n;i++){
			if(p[i]==temp){
				//cout<<i<<endl;
				tot+=a[i];
				break;
			}
		}
	}
	if(tot==0)return true;
	else return false;
}
int main(){
	freopen("wine.in","r",stdin);
	freopen("wine.out","w",stdout);
	int i,j,k,s,s0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=m;i++){
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		edge[i].from=x;
		edge[i].to=y;
		edge[i].len=l;
		map[x][y]=map[y][x]=i;
	}
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<map[i][j]<<"¡¡";
		}
		cout<<endl;
	}*/
	all=(1<<n)-1;
	for(i=1;i<=all;i++){
		f[i]=inf;
		pre[i]=inf;
	}
	for(s=1;s<=all;s++){
		work(s);
	}
	//for(i=1;i<=all;i++)cout<<i<<" "<<pre[i]<<endl;
	for(s=1;s<=all;s++){
		if(bitcnt(s)==1){
			f[s]=0;
			continue;
		}
		f[s]=pre[s];
		for(s0=s;s0;s0=((s0-1)&s)){
			if(check(s0)&&check(s-s0))
			f[s]=min(f[s],f[s0]+f[s-s0]);
		}
	}
	if(f[all]>=inf)cout<<"Impossible";
	else cout<<f[all];
}

