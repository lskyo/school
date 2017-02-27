#include <iostream>
#include<stdlib.h>
#include <conio.h>
typedef int DataType; 
using namespace std;
//定义结点类 
class Node {
friend class LinkList;
public:
  Node() {
    next = NULL;
  }
  Node(DataType x) {
    data = x;
    next = NULL;
  }
private:
  DataType data;
  Node* next;
};
//定义链表类 
class LinkList {
public:
   LinkList(); //构造函数  
   int Size(); //返回单链表的长度
   void Convert();        //实现将单链表中的数据元素逆置并存放于单链表中
   void Insert(int i,const DataType& x);//在第i个结点前插入元素x 
   void Insert(const DataType& x);//在头结点后插入元素x
   void Delete(int i);   //删除第i个结点元素
   Node* Find(const DataType& x); //查找元素x，成功返回指针，不成功返回NULL
   DataType GetData(int i);  //得到第i个结点的数据
   void Print();  //输出单链表结点元素
private:
   Node* head;
   int size;
};

LinkList::LinkList() {
   head = new Node();
   size = 0;
}

void LinkList::Insert(int i,const DataType& x) {
  int j;
  Node *p,*s;
  if (i<1 || i>size+1) {
      cout<<"插入位置不合理！"<<endl;
      exit(0);
  }
  else 
  {
     //经过循环后，p指向第i个结点的前面一个结点。
     p = head; j=0;
     while (j<i-1) 
     {
        p = p->next;
        j++;
     }   
     s = new Node(x);
     s->next = p->next;
     p->next = s;
     size++;    
  } 
}

void LinkList::Insert(const DataType& x) {
  int j;
  Node *p,*s;
  p = head; 
  s = new Node(x);
  s->next = p->next;
  p->next = s;
  size++;    
}

void LinkList::Delete(int i) {
  int j;
  Node *p,*q;
  if (i<1 || i>size) {
     cout<<"删除位置不合理！"<<endl;
     exit(0);
  }
  else 
  {
     p = head; j=0;
     while (j<i-1) 
     {
     //经过循环后，p指向第i个结点的前面一个结点。
        p = p->next;
        j++;
     }   
     q = p->next;
     p->next = q->next;
     delete q;  
     size--;
  } 
}
//返回单链表的长度
int LinkList::Size() {
   return size;
}

//输出单链表
void LinkList::Print()
{
   Node* p;
   p = head;
   while(p != NULL) {
      cout<<p->data<<" -> ";
      p = p->next;
   }
   cout<<"^";
   cout<<endl;
}

Node* LinkList::Find(const DataType& x)
{
  //查找元素x，成功返回指针，不成功返回NULL
  //请自行补充完整
}


DataType LinkList::GetData(int i) {
  int j;
  Node *p,*q;
  if (i<1 || i>size) {
     cout<<"位置不合理！"<<endl;
     exit(0);
  }
  else {
     p = head->next; j=0;
     while (j<i) {
     //经过循环后，p指向第i个结点
        p = p->next;
        j++;
     }   
     return p->data;
  } 
}

void  LinkList::Convert() 
{
   //实现将单链表中的数据元素逆置并存放于单链表中。
   //请自行补充完整
} 

int main()
{
   //请补充完整主函数，验证单链表的插入、删除等成员函数
   system("pause");
}
