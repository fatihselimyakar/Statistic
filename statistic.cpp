#include"statistic.h"

namespace STATISTIC{
	void Statistic::makeTheArray(){
		cout<<"Please enter the array capacity"<<endl;
		cin>>capacity;
		cout<<"Please enter the array size"<<endl;
		cin>>size;
		array=new double[capacity];
		cout<<"please enter the numbers"<<endl;
		for(int i=0;i<size;i++)
			cin>>array[i];
	}
	void Statistic::set(int newSize,int newCapacity){
		if(capacity!=newCapacity){
			delete[]array;
			array=new double[newCapacity];
			capacity=newCapacity;
		}
		size=newSize;

	}
	Statistic& Statistic::operator=(const Statistic& rightSide){
		delete[]array;
		array=new double[rightSide.capacity];
		for(int i=0;i<rightSide.size;i++)
			array[i]=rightSide.array[i];
		size=rightSide.size;
		capacity=rightSide.capacity;

		return *this;

	}
	Statistic& Statistic::operator+=(const Statistic& rightSide){
		double *buffer=new double[capacity];
		for(int i=0;i<size;i++)
			buffer[i]=array[i];
		delete[] array;
		array= new double[capacity+rightSide.capacity];
		int i;
		for(i=0;i<size;i++)
			array[i]=buffer[i];
		for(int j=0;j<rightSide.size;j++)
			array[i+j]=rightSide.array[j];
		capacity+=rightSide.capacity;
		size+=rightSide.size;
		
		return *this;
	}
	Statistic Statistic::operator+(const Statistic& rightSide){
		Statistic temp(capacity+rightSide.capacity,size+rightSide.size);
		int i;
		for(i=0;i<size;i++)
			temp.array[i]=array[i];
		for(int j=0;j<rightSide.size;j++){
			temp.array[j+i]=rightSide.array[j];
		}
		return temp;

	}
	Statistic Statistic::operator-(int deleteNum){
		Statistic temp(capacity-deleteNum,size-deleteNum);
		for(int i=0;i<size-1;i++){
			temp.array[i]=array[i];
		}
		temp.capacity=capacity-deleteNum;
		temp.size=size-deleteNum;
		return temp;
	}
	ostream& operator<<(ostream& outputStream,const Statistic& object){
		for(int i=0;i<object.size;i++){
			outputStream<<object.array[i]<<" ";
		}
		outputStream<<endl;
		outputStream<<"size:"<<object.size<<endl;
		outputStream<<"capacity:"<<object.capacity<<endl;

		return outputStream;
	}
	
	double Statistic::mean()const{
		double total;
		for(int i=0;i<size;i++){
			total+=array[i];
		}

		return total/size;
	}
	double Statistic::max()const{
		double max=0;
		for(int i=0;i<size;i++){
			int temp=max;
			max=array[i];
			if(temp>max)
				max=temp;
		}

		return max;
	}
	double Statistic::median()const{
		double arr[size];
		for(int i=0;i<size;i++){
			arr[i]=array[i];
		}
		for(int i=0;i<size-1;i++){
			if(arr[i+1]<arr[i])
				arr[i]=arr[i+1];
		}
		if(size%2==0)
			return (arr[size/2]+arr[(size/2)-1])/2;
		else
			return arr[(size/2)];
	}
	void Statistic::add(double number){
		if(capacity>size){
			array[size]=number;
			size+=1;
		}
		else
			cout<<"You dont add this in the array"<<endl;

	}
	double Statistic::geometricMean()const{
		double multiply=1;
		for(int i=0;i<size;i++){
			multiply*=array[i];
		}
		return pow(multiply,1.0/size);
	}
	double Statistic::mode()const{
		double value=0,count=0;
		int i,j;

		for(i=0;i<size;++i){
			int ct=0;
			for(j=0;j<size;++j){
				if (array[j]==array[i])
				++ct;
			}
			if(ct>count) {
				count=ct;
				value=array[i];
			}
		}
		return value;
	}
	double Statistic::standartDeviation()const{
		double sum=0;
		double mean=this->mean();
		for(int i=0;i<size;i++){
			sum+=pow(array[i]-mean,2);
		}
		
		return sqrt(sum/(size-1));
	}
	double Statistic::min()const{
		double min=999999999;
		for(int i=0;i<size;i++){
			int temp=min;
			min=array[i];
			if(temp<min)
				min=temp;
		}

		return min;
	}
	
}
