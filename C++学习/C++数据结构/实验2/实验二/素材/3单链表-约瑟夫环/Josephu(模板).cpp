#include"LinkList.h"
typedef int DataType;
int main()
{  
   Node<DataType> *p;
   int n,m;
   cout<<"����������n�ͱ���m��ֵ��";
   cin>>n>>m;//
   LinkList<DataType> Josephu;
   //��ʼ��Լɪ�򻷵�����
   for(int i=1 ;i<=n;i++)
   {  
       p= new Node<DataType>(i);
	   Josephu.Insert(i,i);
   }
    Josephu.Print();
    Josephu.Index(1);//���α궨λ�ڵ�һ��Ԫ��
   //���ڴ���ɳ���
   //ģ��Լɪ������
  
   getch();
   return 0;
}