#include<fstream>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std; 
ifstream fin,fout,fstd;
ofstream fscore,freport;
int t[10000],n,m;
double Judge(){
    
    string s;
    /**/
	fstd>>s;
	if(s[0]=='N'){
		fout>>s;
		if(s[0]=='N') return 1;
		else return 0;
	}
	
    fin>>n,m;
    fin>>m>>n;
    int flag=0;
    for(int i=1;i<=n;i++){
    	fout>>t[i];
    	if(t[i]==0) flag=1;
	}
    if(flag==0) return 0;
    int a,b,c;
    for(int i=1;i<=m;i++){
    	fin>>a>>b>>c;
    	if(t[a]-t[b]>c) {
    		return 0;
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
