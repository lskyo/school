
#include<iostream>
using namespace std;
typedef int DataType;
//定义结点类 
class Node {
friend class LinkStack;
public:
  Node() {
    next = NULL;
  }
  Node(const DataType& x) {
    data = x;
    next = NULL;
  }
private:
  DataType data;
  Node* next;
};

class LinkStack {//链栈类的界面 
public:
  LinkStack();   //构造函数 
  ~LinkStack();  //析构函数，释放链栈中所有结点占用的存储空间 
  void Push(const DataType& x); //压栈函数 
  DataType Pop();  //出栈函数 
  DataType GetTop();//取栈顶元素 
  bool IsEmpty();  //判断链栈是否为空 
private:
  Node* top;   
};
//构造函数，创建头结点，并让top指向该头结点； 
LinkStack::LinkStack() {
   top = new Node();
}
//析构函数，释放链栈中所有结点占用的存储空间 
LinkStack::~LinkStack() {
    Node *p,*q;
    p = top;
    while (p!=NULL) {
       q = p;
       p = p->next;
       delete q;
    }
}
void LinkStack::Push(const DataType& x) {
   Node* p;
   p = new Node(x);
   p->next = top->next;
   top->next = p;
}

DataType LinkStack::Pop() {
   DataType x;
   Node *p=top->next;
   if (p==NULL) {
      cout<<"栈已空！！！"<<endl;
      exit(0); 
   }
   else {
      top->next = p->next;
      x = p->data;
      delete p;  
      return x;
   }
}

DataType LinkStack::GetTop() {
   DataType x;
   Node *p=top->next;
   if (p==NULL) {
      cout<<"栈已空！！！"<<endl;
      exit(0); 
   }
   else {
      x = p->data;
      return x;
   }
}
bool LinkStack::IsEmpty() {
   if(top->next == NULL) return true;
   else return false;
}

