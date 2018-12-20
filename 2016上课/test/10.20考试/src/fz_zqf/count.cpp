#include<iostream>
#include<fstream>  //file stream is faster than redirect stdio using CIN

using namespace std;

ifstream in("count.in");
ofstream out("count.out");

#define OPEN_JUDGE

#ifdef OPEN_JUDGE
#define FIN in
#define FOUT out
#else
#define FIN cin
#define FOUT cout
#endif

//166667082

int main()
{
	//py business
	
	unsigned long long X;
	int Condition;
	
	FIN>>X>>Condition;
	
	unsigned long long* Sit1=new unsigned long long[X+1];
	unsigned long long Sit2=0;
	Sit1[0]=0;
	for(size_t i=1;i<=X;++i)
	{
		Sit1[i]=Sit1[i-1]+i*i;
		Sit1[i]=Sit1[i]%1000000007;
		//cout<<Sit1[i]<<endl;
	}
	
	if(Condition==1)
	{
		FOUT<<Sit1[X-1]%1000000007<<endl;	
	}
	else
	{
		for(size_t F=1;F<X-1;++F)
		{
			unsigned x=Sit2;
			Sit2+=F*(X-F-1)*(X-F-1);
			Sit2=Sit2%1000000007;
			//FOUT<<F*(X-F-1)*(X-F-1)<<endl;
		}
		FOUT<<(Sit2+Sit1[X-1])%1000000007<<endl;
	}
	
	delete[] Sit1;
	
	return 0;

}
































//Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh!!!!!!
//Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh!!!!!!
//Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh!!!!!!
//Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh!!!!!!

