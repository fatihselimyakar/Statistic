#ifndef STATISTIC_H
#define STATISTIC_H
#include<iostream>
using namespace std;
namespace STATIC{
	
	class Statistic{
		public:
			Statistic():capacity(50),size(0){ array=new double[capacity]; }
			Statistic(int newCapacity,int newSize):capacity(newCapacity),size(newSize){ array=new double[capacity]; }
			Statistic(Statistic& object){ 
				array=new double[object.capacity];
				capacity=object.capacity;
				size=object.size;
				for(int i=0;i<size;i++)
					array[i]=object.array[i];
				cout<<"copy const."<<endl;
			}
			void add(double number);
			int getSize()const{ return size; }
			int getCapacity()const{ return capacity; }
			void makeTheArray();
			void set(int newSize,int newCapacity);
			Statistic& operator=(const Statistic& rightSide);
			Statistic operator+(const Statistic& rightSide);
			Statistic operator-(int deleteNum);
			friend ostream& operator<<(ostream& outputStream,const Statistic& object);
			double ortalama()const;
			double mod()const;
			double medyan()const;
			~Statistic(){ delete [] array; cout<<"dest."<<endl;}
		private:
			double *array;
			int size;
			int capacity;
	};
	
}
	
#endif