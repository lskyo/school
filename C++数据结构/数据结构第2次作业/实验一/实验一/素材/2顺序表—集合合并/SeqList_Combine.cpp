/*利用顺序表实现集合的并运算*/
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
   SeqList(int max); //构造函数,初始化得到一个容量为max的空表 
   ~SeqList();     //析构函数，释放线性表占用的存储空间 
   int Size();  //求线性表的长度 
    int Maxsize();  //求线性表的最大元素个数
   int Find(const DataType& x); //在线性表中查找元素x 
   DataType GetData(int i);  //取线性表的第i个元素 
   void Insert(const DataType& x);  //若有序表中不存在x，则插入使得表仍然有序；否则不插入
   void Delete(int i);  // 删除第i个元素
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
       cout<<"顺序表已满，插入错误！"<<endl;
      exit(0);
   } 
   //请在此处完成函数
   //注意：若表中已有x，则不需要插入；否则，按序插入
   
  }

template <class DataType>
void SeqList<DataType>::Print() {
   for(int i=0;i<=size-1;i++) cout<<list[i]<<"  ";
   cout<<endl;
}
template <class DataType>  
void  SeqList<DataType>::operator =(const SeqList<DataType>& other)
{  //请在此处实现函数
	
}

template <class DataType>  
SeqList<DataType>  SeqList<DataType>::operator +(const SeqList<DataType>& other)
{ 
	//请在此处实现函数
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