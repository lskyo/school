/*利用顺序表实现集合的并运算*/
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
   SeqList(int max); //构造函数,初始化得到一个容量为max的空表 
   ~SeqList();     //析构函数，释放线性表占用的存储空间 
   int Size();  //求线性表的长度 
    int Maxsize();  //求线性表的最大元素个数
   int Find(const DataType& x); //在线性表中查找元素x 
   DataType GetData(int i);  //取线性表的第i个元素 
   void Insert(const DataType& x);  //若有序表中不存在x，则插入使得表仍然有序；否则不插入
   void Delete(int i);  // 删除第i个元素
   void Print();   
   void operator =( SeqList<DataType>& other);  //功能描述：实现集合顺序表的复制
   SeqList<DataType> operator +( SeqList<DataType>& other);  //功能描述：实现两集合顺序表的合并
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
       cout<<"顺序表已满，插入错误！"<<endl;
      exit(0);
   } 
   //请在此处完成函数
   //注意：若表中已有x，则不需要插入；否则，按序插入
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
{  //请在此处实现函数
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
	//请在此处实现函数
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