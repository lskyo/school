//利用顺序表实现多项式相加
#include <iostream.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
const int N=10;
struct Data
{   int xishu;
    int zhishu;
};
template <class T>
class SeqList {
private:
   T* list;
   int MaxSize;
   int size;
public:
   SeqList(int max); //构造函数,初始化得到一个容量为max的空表 
   ~SeqList();     //析构函数，释放线性表占用的存储空间 
   int Size();  //求线性表的长度 
    int Maxsize();  //求线性表的最大元素个数
   int Find(const T& x); //在线性表中查找与元素x同指数的元素位置 
   T GetData(int i);  //取线性表的第i个元素 
   void Insert(int i,const T & x  ); //把x插入线性表中第i位
   /*线性表加入一项x；
   若有序表中不存在与x同指数的元素，则按x的指数大小插入；
   否则，在表中已存在与x同指数的元素，则该元素的系数加上x的系数，若系数和为0，则要删除该元素；
   */void Add(const T& x); 
   void Delete(int i);  // 删除第i个元素
   void Print();   
   void operator =(const SeqList<T>& other); //多项式线性表复制
   SeqList<T> operator +(const SeqList<T>& other); //多项式线性表相加
};

template <class T>
SeqList<T>::SeqList(int max) {
   list = new T[max];
   MaxSize = max;
   size = 0;
}
template <class T>
SeqList<T>::~SeqList() {
   delete []list;
}

template <class T>
int SeqList<T>::Size() {
   return size;
}
template <class T>
int SeqList<T>::Maxsize() {
   return MaxSize;
}
template <class T>
T SeqList<T>::GetData(int i) {
   return list[i];
}
template <class T>
void SeqList<T>::Delete(int i) {
  if((i<0)||(i>size-1)) {
     cout<<"元素不存在！！"<<endl;
     exit(0);
  }
  for(int j=i;j<=size-2;j++) list[j] = list[j+1];
  size--; 
}
template <class T>
void SeqList<T>::Insert(int i,const T& x) {
   if(size == MaxSize) {
      cout<<"顺序表已满，插入错误！"<<endl;
      exit(0);
   }
   if((i<0)||(i>size)) {
       cout<<"插入位置错误！"<<endl;
       exit(0);
   }
   //list[i]~list[size-1]整体往后移动
   for(int j=size-1;j>=i;j--) list[ j+1] = list[ j];
      list[i] = x;
   size++; 
}

template <class T>
void SeqList<T>::Print() 
{
    cout<<list[0].xishu<<"x"<<list[0].zhishu<<" ";
   for(int i=1;i<=size-1;i++) 
   {  if(list[i].xishu>0) cout<<"+";
	   cout<<list[i].xishu<<"x^"<<list[i].zhishu<<" ";
   }

   cout<<endl;
}
template <class T>  
void SeqList<T>::Add(const T& x)
{/*线性表加入一项x；
   若有序表中不存在与x同指数的元素，则按x的指数大小插入；
   否则，在表中已存在与x同指数的元素，则该元素的系数加上x的系数，若系数和为0，则要删除该元素；
   */
   //请在此处完成函数

}
template <class T>  
void  SeqList<T>::operator =(const SeqList<T>& other)
{  
    //请在此处完成函数
}
template <class T>  
SeqList<T>  SeqList<T>::operator +(const SeqList<T>& other)
{  SeqList<T>* temp=new SeqList<T>(N);
   //请在此处完成函数
	return *temp;
}

void main()
{  Data temp;
	SeqList<Data> L1(N),L2(N),L3(N);
	srand((unsigned)time(NULL));
	while(L1.Size()<N/2)//利用随机函数产生构造多项式L1
	{  temp.zhishu=int(rand())%10+1;
	    temp.xishu=int(rand())%100-50+1;
		L1.Add(temp);	
	}
	L1.Print();
	while(L2.Size()<N/2)//利用随机函数产生构造多项式L2
	{  temp.zhishu=int(rand())%10;
	    temp.xishu=int(rand())%100-50; 
		L2.Add(temp);	
	}
	L2.Print();
    L3=L1+L2;   //利用对“+”运算符重载实现两多项式相加
   	L3.Print();
	getch();
}