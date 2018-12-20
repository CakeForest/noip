#include<iostream>
#include<algorithm>
using namespace std;
int num[1020],cnt[4],w[4][4];//w[i][j]表示i在j区有几个  
int A,B;
int judge(int n){
	if(n<=cnt[1]) return 1;
	if(n<=cnt[1]+cnt[2]) return 2;
	return 3;
}

int main(){
//	freopen("in.txt","r",stdin);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cnt[num[i]]++;
	}
	
	for(int i=1;i<=n;i++) w[num[i]][judge(i)]++;
	
	A=min(w[1][2],w[2][1])+min(w[1][3],w[3][1])+min(w[2][3],w[3][2]);
	B=(w[1][2]+w[2][1]+w[2][3]+w[3][2]+w[1][3]+w[3][1]-2*A)/3*2;
	cout<<A+B;
	
	return 0;
}
