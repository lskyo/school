/*����˳���ʵ�ּ��ϵĲ�����*/
#include <iostream.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
const int N=20;
template <class DataType>
class SeqList {
private:
   DataType* list;
   int MaxSize;
   int size;
public:
   SeqList(int max); //���캯��,��ʼ���õ�һ������Ϊmax�Ŀձ� 
   ~SeqList();     //�����������ͷ����Ա�ռ�õĴ洢�ռ� 
   int Size();  //�����Ա�ĳ��� 
    int Maxsize();  //�����Ա�����Ԫ�ظ���
   int Find(const DataType& x); //�����Ա��в���Ԫ��x 
   DataType GetData(int i);  //ȡ���Ա�ĵ�i��Ԫ�� 
   void Insert(const DataType& x);  //��������в�����x�������ʹ�ñ���Ȼ���򣻷��򲻲���
   void Delete(int i);  // ɾ����i��Ԫ��
   void Print();   
   void operator =(const SeqList<DataType>& other); 
   SeqList<DataType> operator +(const SeqList<DataType>& other); 
};

template <class DataType>
SeqList<DataType>::SeqList(int max) {
   list = new DataType[max];
   MaxSize = max;
   size = 0;
}
template <class DataType>
SeqList<DataType>::~SeqList() {
   delete []list;
}

template <class DataType>
int SeqList<DataType>::Size() {
   return size;
}
template <class DataType>
int SeqList<DataType>::Maxsize() {
   return MaxSize;
}
template <class DataType>
DataType SeqList<DataType>::GetData(int i) {
   return list[i];
}

template <class DataType>
void SeqList<DataType>::Insert(const DataType& x) 
{
   if(size==MaxSize) {
       cout<<"˳����������������"<<endl;
      exit(0);
   } 
   //���ڴ˴���ɺ���
   //ע�⣺����������x������Ҫ���룻���򣬰������
   
  }

template <class DataType>
void SeqList<DataType>::Print() {
   for(int i=0;i<=size-1;i++) cout<<list[i]<<"  ";
   cout<<endl;
}
template <class DataType>  
void  SeqList<DataType>::operator =(const SeqList<DataType>& other)
{  //���ڴ˴�ʵ�ֺ���
	
}

template <class DataType>  
SeqList<DataType>  SeqList<DataType>::operator +(const SeqList<DataType>& other)
{ 
	//���ڴ˴�ʵ�ֺ���
}

void main()
{
	SeqList<int> L1(N),L2(N),L3(N);
	srand((unsigned)time(NULL));
	while(L1.Size()<N/2)
	{   L1.Insert(int(rand())%100);	}
	L1.Print();
	while(L2.Size()<N/2)
	{   L2.Insert(int(rand())%100);	}
	L2.Print();
    L3=L1+L2;
   	L3.Print();
	getch();
}