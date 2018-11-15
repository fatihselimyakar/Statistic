#include"statistic.h"
using namespace STATISTIC;
int main(){
	Statistic deneme;
	Statistic deneme2(6,6);
	deneme.makeTheArray();
	deneme2=deneme;
	cout<<"***results***"<<endl;
	cout<<"mean:"<<deneme.mean()<<endl;
	cout<<"max:"<<deneme.max()<<endl;
	cout<<"min:"<<deneme.min()<<endl;
	cout<<"openness:"<<deneme.openness()<<endl;
	cout<<"median:"<<deneme.median()<<endl;
	cout<<"geometric mean:"<<deneme.geometricMean()<<endl;
	cout<<"mode:"<<deneme.mode()<<endl;
	cout<<"standart deviation:"<<deneme.standartDeviation()<<endl<<endl;
	cout<<"DENEME2'S RESULT"<<endl;
	cout<<deneme2<<endl;
	Statistic deneme3(deneme);
	deneme3=deneme+deneme2;
	Statistic deneme4(deneme3);
	deneme4=deneme3-1;
	//deneme4+=deneme3;
	cout<<"DENEME3'S |+| RESULT"<<endl;
	cout<<deneme3<<endl;
	cout<<"DENEME4'S |-| RESULT"<<endl;
	cout<<deneme4;
	//deneme.add(4);
	
	return 0;
}