#ifndef STATISTIC_H
#define STATISTIC_H
#include<iostream>
#include<cmath>
using namespace std;
namespace STATISTIC{
	
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
				//cout<<"copy const."<<endl;
			}
			void add(double number);
			int getSize()const{ return size; }
			int getCapacity()const{ return capacity; }
			void makeTheArray();
			void set(int newSize,int newCapacity);
			Statistic& operator+=(const Statistic& rightSide);
			Statistic& operator=(const Statistic& rightSide);
			Statistic operator+(const Statistic& rightSide);
			Statistic operator-(int deleteNum);
			friend ostream& operator<<(ostream& outputStream,const Statistic& object);
			friend istream& operator>>(istream& inputStream,Statistic& object);
			double mean()const;
			double max()const;
			double median()const;
			double mode()const;
			double geometricMean()const;
			double standartDeviation()const;
			double min()const;
			double openness()const{ return max()-min(); }
			~Statistic(){ 
				delete [] array; 
				//cout<<"dest."<<endl;
			}
		private:
			double *array;
			int size;
			int capacity;
	};
	
}
	
#endif