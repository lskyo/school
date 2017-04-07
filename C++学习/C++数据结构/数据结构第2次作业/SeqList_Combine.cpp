/*����˳���ʵ�ּ��ϵĲ�����*/
#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;




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
   void operator =( SeqList<DataType>& other);  //����������ʵ�ּ���˳���ĸ���
   SeqList<DataType> operator +( SeqList<DataType>& other);  //����������ʵ��������˳���ĺϲ�
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
   for(int i=0;i<size;i++)
   {
	   if(list[i]==x)
	   {
		   break;
	   }
	   else if(list[i]>x)
	   {
		   int j=size-1;
		   for(j;j!=i;j--)
		   {
			   list[j+1]=list[j];
		   }
		   list[j]=x;
	   }
   }
   size++;
}

template <class DataType>
void SeqList<DataType>::Print() {
   for(int i=0;i<=size-1;i++) cout<<list[i]<<"  ";
   cout<<endl;
}
template <class DataType>  
void  SeqList<DataType>::operator =( SeqList<DataType>& other)
{  //���ڴ˴�ʵ�ֺ���
	this->MaxSize=other.Maxsize();
	this->size=other.Size();
	list=new int [MaxSize];
	for(int i=0;i<size;i++)
	{
		list[i]=other.GetData(i);
	}
}

template <class DataType>  
SeqList<DataType>  SeqList<DataType>::operator +( SeqList<DataType>& other)
{ 
	//���ڴ˴�ʵ�ֺ���
	int max=this->MaxSize()+other.Maxsize();
	SeqList<DataType> p(max);
	int size1=this->Size();
	int size2=other.Size();
	int size3=size1+size2;
	for(int i=0;i<size1;i++)
	{
		p.Insert(list[i]);
	}
	for(int i=size1;i<size3;i++)
	{
		p.Insert(list[i]);
	}
	return p;
}

void main()
{
	SeqList<int> L1(N),L2(N),L3(40);
	srand((unsigned)time(NULL));
	while(L1.Size()<N/2)
	{   L1.Insert(int(rand())%100);	}
	L1.Print();
	while(L2.Size()<N/2)
	{   L2.Insert(int(rand())%100);	}
	L2.Print();
    L3=L1+L2;
   	L3.Print();
	getchar();
}