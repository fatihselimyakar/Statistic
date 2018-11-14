#include"statistic.h"
using namespace STATIC;
int main(){
	Statistic deneme;
	Statistic deneme2(6,6);
	deneme.makeTheArray();
	deneme2=deneme;
	cout<<"results"<<endl;
	cout<<"ortalama:"<<deneme.ortalama()<<endl;
	cout<<"mod:"<<deneme.mod()<<endl;
	cout<<"medyan:"<<deneme.medyan()<<endl;
	cout<<"DENEME2'S RESULT"<<endl;
	cout<<deneme2;
	Statistic deneme3(deneme);
	deneme3=deneme+deneme2;
	//deneme3=(deneme+deneme2);
	cout<<"DENEME3'S |+| RESULT"<<endl;
	cout<<deneme3;
	//deneme.add(4);
	
	
	return 0;
}