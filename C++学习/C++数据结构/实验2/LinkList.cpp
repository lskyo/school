#include <iostream>
#include<stdlib.h>
#include <conio.h>
typedef int DataType; 
using namespace std;
//�������� 
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
//���������� 
class LinkList {
public:
   LinkList(); //���캯��  
   int Size(); //���ص�����ĳ���
   void Convert();        //ʵ�ֽ��������е�����Ԫ�����ò�����ڵ�������
   void Insert(int i,const DataType& x);//�ڵ�i�����ǰ����Ԫ��x 
   void Insert(const DataType& x);//��ͷ�������Ԫ��x
   void Delete(int i);   //ɾ����i�����Ԫ��
   Node* Find(const DataType& x); //����Ԫ��x���ɹ�����ָ�룬���ɹ�����NULL
   DataType GetData(int i);  //�õ���i����������
   void Print();  //�����������Ԫ��
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
      cout<<"����λ�ò�����"<<endl;
      exit(0);
  }
  else 
  {
     //����ѭ����pָ���i������ǰ��һ����㡣
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
  //int j;
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
     cout<<"ɾ��λ�ò�����"<<endl;
     exit(0);
  }
  else 
  {
     p = head; j=0;
     while (j<i-1) 
     {
     //����ѭ����pָ���i������ǰ��һ����㡣
        p = p->next;
        j++;
     }   
     q = p->next;
     p->next = q->next;
     delete q;  
     size--;
  } 
}
//���ص�����ĳ���
int LinkList::Size() {
   return size;
}

//���������
void LinkList::Print()
{
   Node* p;
   p = head->next;
   while(p != NULL) {
      cout<<p->data<<" -> ";
      p = p->next;
   }
   cout<<"^";
   cout<<endl;
}

Node* LinkList::Find(const DataType& x)
{
  //����Ԫ��x���ɹ�����ָ�룬���ɹ�����NULL
  //�����в�������
	Node* p;
   p = head;
   while(p != NULL) 
   {
	   if(p->data==x)
	   {
		   return p;
	   }
      p = p->next;
   }
   return NULL;
}


DataType LinkList::GetData(int i) {
  int j;
  Node *p,*q;
  if (i<1 || i>size) {
     cout<<"λ�ò�����"<<endl;
     exit(0);
  }
  else {
     p = head->next; j=1;
     while (j<i) {
     //����ѭ����pָ���i�����
        p = p->next;
        j++;
     }   
     return p->data;
  } 
}

void  LinkList::Convert() 
{
   //ʵ�ֽ��������е�����Ԫ�����ò�����ڵ������С�
   //�����в�������
	if(size<=0)
	{
		cout<<"����Ϊ��"<<endl;
		exit(0);
	}
	Node *q,*p,*z;
	p=head->next;
	q=p->next;
	z=q->next;
	p->next=NULL;
	for(int i=0;i<size;i++)
	{
		q->next=p;
		p=q;
		q=z;
		z=z->next;
		if(z->next==NULL)
		{
			q->next=p;
			z->next=q;
			head->next=z;
			return;
		}
	}
} 

int main()
{
   //�벹����������������֤������Ĳ��롢ɾ���ȳ�Ա����
	LinkList linklist;
	cout<<"����10�����֣�";
	for(int i=1;i<=10;i++)
	{
		linklist.Insert(i);
	}
	linklist.Print();
	cout<<"ɾ����3�����֣�";
	linklist.Delete(3);
	linklist.Print();
	cout<<"��������";
	linklist.Convert();
	linklist.Print();
	if(linklist.Find(4)!=NULL)
	{
		cout<<"�ɹ��ҵ���4��Ԫ�أ���4��Ԫ��Ϊ��";
		int i=linklist.GetData(4);
		cout<<i<<endl;
	}
   system("pause");
}
