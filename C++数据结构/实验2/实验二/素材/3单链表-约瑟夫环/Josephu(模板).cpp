#include"LinkList.h"
typedef int DataType;
int main()
{  
   Node<DataType> *p;
   int n,m;
   cout<<"请输入人数n和报数m的值：";
   cin>>n>>m;//
   LinkList<DataType> Josephu;
   //初始化约瑟夫环单链表
   for(int i=1 ;i<=n;i++)
   {  
       p= new Node<DataType>(i);
	   Josephu.Insert(i,i);
   }
    Josephu.Print();
    Josephu.Index(1);//把游标定位在第一个元素
   //请在此完成程序
   //模拟约瑟夫环问题
  
   getch();
   return 0;
}