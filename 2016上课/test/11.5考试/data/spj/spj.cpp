#include<fstream>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std; 
ifstream fin,fout,fstd;
ofstream fscore,freport;
double Judge(){
    string stdans1,xans1;
    fout>>xans1;
    fstd>>stdans1;
    if(xans1!=stdans1) return 0;
    int n,a,b;
    fin>>n;
    fout>>a>>b;
    if(a+b==n) return 1;
    return 0;
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
