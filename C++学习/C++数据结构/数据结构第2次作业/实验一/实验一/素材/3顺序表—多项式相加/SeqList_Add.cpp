//����˳���ʵ�ֶ���ʽ���
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
   SeqList(int max); //���캯��,��ʼ���õ�һ������Ϊmax�Ŀձ� 
   ~SeqList();     //�����������ͷ����Ա�ռ�õĴ洢�ռ� 
   int Size();  //�����Ա�ĳ��� 
    int Maxsize();  //�����Ա�����Ԫ�ظ���
   int Find(const T& x); //�����Ա��в�����Ԫ��xָͬ����Ԫ��λ�� 
   T GetData(int i);  //ȡ���Ա�ĵ�i��Ԫ�� 
   void Insert(int i,const T & x  ); //��x�������Ա��е�iλ
   /*���Ա����һ��x��
   ��������в�������xָͬ����Ԫ�أ���x��ָ����С���룻
   �����ڱ����Ѵ�����xָͬ����Ԫ�أ����Ԫ�ص�ϵ������x��ϵ������ϵ����Ϊ0����Ҫɾ����Ԫ�أ�
   */void Add(const T& x); 
   void Delete(int i);  // ɾ����i��Ԫ��
   void Print();   
   void operator =(const SeqList<T>& other); //����ʽ���Ա���
   SeqList<T> operator +(const SeqList<T>& other); //����ʽ���Ա����
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
     cout<<"Ԫ�ز����ڣ���"<<endl;
     exit(0);
  }
  for(int j=i;j<=size-2;j++) list[j] = list[j+1];
  size--; 
}
template <class T>
void SeqList<T>::Insert(int i,const T& x) {
   if(size == MaxSize) {
      cout<<"˳����������������"<<endl;
      exit(0);
   }
   if((i<0)||(i>size)) {
       cout<<"����λ�ô���"<<endl;
       exit(0);
   }
   //list[i]~list[size-1]���������ƶ�
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
{/*���Ա����һ��x��
   ��������в�������xָͬ����Ԫ�أ���x��ָ����С���룻
   �����ڱ����Ѵ�����xָͬ����Ԫ�أ����Ԫ�ص�ϵ������x��ϵ������ϵ����Ϊ0����Ҫɾ����Ԫ�أ�
   */
   //���ڴ˴���ɺ���

}
template <class T>  
void  SeqList<T>::operator =(const SeqList<T>& other)
{  
    //���ڴ˴���ɺ���
}
template <class T>  
SeqList<T>  SeqList<T>::operator +(const SeqList<T>& other)
{  SeqList<T>* temp=new SeqList<T>(N);
   //���ڴ˴���ɺ���
	return *temp;
}

void main()
{  Data temp;
	SeqList<Data> L1(N),L2(N),L3(N);
	srand((unsigned)time(NULL));
	while(L1.Size()<N/2)//����������������������ʽL1
	{  temp.zhishu=int(rand())%10+1;
	    temp.xishu=int(rand())%100-50+1;
		L1.Add(temp);	
	}
	L1.Print();
	while(L2.Size()<N/2)//����������������������ʽL2
	{  temp.zhishu=int(rand())%10;
	    temp.xishu=int(rand())%100-50; 
		L2.Add(temp);	
	}
	L2.Print();
    L3=L1+L2;   //���öԡ�+�����������ʵ��������ʽ���
   	L3.Print();
	getch();
}