#include <iostream.h>
#include<stdlib.h>
#include <conio.h>

template <class T> class LinkList;
//定义结点类 
template  < class T>
class Node 
{  private:
	  T data;
	 Node<T>* next;

	public:
	  Node() {
		next = NULL;
	  }
	  Node(T x) 
	  {
		data = x;
		next = NULL;
	  }
	friend class LinkList<T>;
};
//定义链表类 
template <class T>
class LinkList 
{	private:
	   Node<T>* head;
	   Node<T>* cursor;//游标，当前正被访问的结点指针
	   int size;
	public:
	   LinkList(); //构造函数  
	   int Size(); //返回单链表长度
	   void Convert();  //逆转单链表
	   Node<T>* Index(int i) ;  //将游标定位在位置i
	   void Insert(int i,const T& x);//在第i个结点前插入元素x 	   
	   void Delete(int i);//删除第i个结点，并打印其数据值
	   void Delete( Node<T>* p); //删除p后的结点，并打印其数据值（若p为为节点，则删除第一个结点）
	   Node<T>* Find(const T& x);  //返回结点值为x的指针
	   T GetData(int i);   //获取第i个结点的数据
	   Node<T>*Move(int i); //游标往后移动i步（若到链表尾部，则从回到表首继续）
	   void Print();   //输出单链表
};
template<class T>
LinkList<T>::LinkList() 
{
   head = new Node<T>();
   size = 0;
}
template<class T>
int LinkList<T>::Size() 
{
   return size;
}
template<class T>
void LinkList<T>::Print()
{
   Node<T>* p;
   p = head->next;
   while(p != NULL) 
   {
      cout<<p->data<<" -> ";
      p = p->next;
   }
   cout<<"^";
   cout<<endl;
}
template<class T>
Node<T>* LinkList<T>::Find(const T& x)
{
   Node<T>* p;
   p = head->next;
   while(p != NULL) 
   {
      if (p->data == x) return p;
      p = p->next;
   }
   return NULL;
}
template<class T>
T LinkList<T>::GetData(int i) 
{
	  int j;
	  Node<T> *p,*q;
	  if (i<1 || i>size) 
	  {
		 cout<<"位置不合理！"<<endl;
		 exit(0);
	  }
	  else 
	  {
		 p=Index(i); // p指向第i个结点；
		 return p->data;
	  } 
}
template<class T>
Node<T>* LinkList<T>::Index(int i) 
{
	 cursor=head;
	 for(int j=1;j<=i;j++)
		 cursor=cursor->next;
	 return cursor;
}
template<class T>
void LinkList<T>::Insert(int i,const T& x) 
{
	 
	  Node<T> *p,*s;
	  if (i<1 || i>size+1) {
		  cout<<"插入位置不合理！"<<endl;
		  exit(0);
	  }
	  else 
	  { 
		  p=Index(i-1); // p指向第i-1个结点；
		 s = new Node<T>(x);
		 s->next = p->next;
		 p->next = s;
		 size++;    
	  } 
}
template<class T>
void LinkList<T>::Delete(int i) 
{
  int j;
  Node<T> *p,*q;
  if (i<1 || i>size) {
     cout<<"删除位置不合理！"<<endl;
     exit(0);
  }
  else 
  {
     p=Index(i-1); // p指向第i-1个结点；
     q = p->next;
     p->next = q->next;
	 cout<<q->data<<"被删除"<<endl;
     delete q;  
     size--;
  } 
}
template<class T>
void  LinkList<T>::Delete( Node<T>* p)
{  Node<T>* q;
	if(this->size<=0)
	{ cout<<"链表中没有结点可以删除！"<<endl;
	   exit(0);
	}
   //请在此完成函数
   //功能描述：删除p后的结点，并打印其数据值（若p为尾节点，则删除第一个结点）


}

template<class T>
Node<T>* LinkList<T>::Move(int i) 
{  //请把cursor往前移动i步；
	if( cursor==NULL)
	{  cout<<"游标位置出错！"<<endl;
		exit(0);
	}
	else
	{
	    //功能描述：游标往后移动i步（若到链表尾部，则从回到表首继续）
     	//请在此完成函数
	}
}


