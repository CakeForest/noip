#include<fstream>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std; 
ifstream fin,fout,fstd;
ofstream fscore,freport;
int map[300][300],x[40000],y[40000];
double Judge(){
    int stdans1,xans1;
    fout>>xans1;
    fstd>>stdans1;
    if(xans1!=stdans1) return 0;
    int n,m;
    fin>>m>>n;
    for(int i=1;i<=m;i++)
    	for(int j=1;j<=n;j++)
    		fin>>map[i][j];
    for(int i=1;i<=xans1;i++){
    	fout>>x[i]>>y[i];
    	if(map[x[i]][y[i]]!=0) return 0;
    	map[x[i]][y[i]]=3;
	}
	int tx,ty;
	for(int i=1;i<=xans1;i++){
		tx=x[i];ty=y[i];
		for(int j=x[i]-1;j>=1;j--){
			if(map[j][ty]==3) return 0;
			if(map[j][ty]==2) break;
		}
		for(int j=x[i]+1;j<=m;j++){
			if(map[j][ty]==3) return 0;
			if(map[j][ty]==2) break;
		}
		for(int j=y[i]-1;j>=1;j--){
			if(map[tx][j]==3) return 0;
			if(map[tx][j]==2) break;
		}
		for(int j=y[i]+1;j<=n;j++){
			if(map[tx][j]==3) return 0;
			if(map[tx][j]==2) break;
		}
	}
    
    return 1;
}
int main(int argc,char *argv[]) {
	/*
	���еĶ���argv[]�������
	argv[1]�������ļ�
	argv[2]��ѡ������ļ�
	argv[3]����׼����ļ�
	argv[4]���������Ե��ֵ
	argv[5]��������յ÷ֵ��ļ�
	argv[6]��������󱨸���ļ�
	*/
    fin.open(argv[1]);
    fout.open(argv[2]);
    fstd.open(argv[3]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
    
    int score=atoi(argv[4]);
    fscore<<score*Judge()<<endl;
    
    fin.close();
    fout.close();
    fstd.close();
    fscore.close();
    freport.close();
    return 0;

}
