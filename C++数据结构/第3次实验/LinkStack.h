
#include<iostream>
using namespace std;
typedef int DataType;
//�������� 
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

class LinkStack {//��ջ��Ľ��� 
public:
  LinkStack();   //���캯�� 
  ~LinkStack();  //�����������ͷ���ջ�����н��ռ�õĴ洢�ռ� 
  void Push(const DataType& x); //ѹջ���� 
  DataType Pop();  //��ջ���� 
  DataType GetTop();//ȡջ��Ԫ�� 
  bool IsEmpty();  //�ж���ջ�Ƿ�Ϊ�� 
private:
  Node* top;   
};
//���캯��������ͷ��㣬����topָ���ͷ��㣻 
LinkStack::LinkStack() {
   top = new Node();
}
//�����������ͷ���ջ�����н��ռ�õĴ洢�ռ� 
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
      cout<<"ջ�ѿգ�����"<<endl;
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
      cout<<"ջ�ѿգ�����"<<endl;
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

