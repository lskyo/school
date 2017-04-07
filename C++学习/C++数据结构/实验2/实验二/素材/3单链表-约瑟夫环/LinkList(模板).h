#include <iostream.h>
#include<stdlib.h>
#include <conio.h>

template <class T> class LinkList;
//�������� 
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
//���������� 
template <class T>
class LinkList 
{	private:
	   Node<T>* head;
	   Node<T>* cursor;//�α꣬��ǰ�������ʵĽ��ָ��
	   int size;
	public:
	   LinkList(); //���캯��  
	   int Size(); //���ص�������
	   void Convert();  //��ת������
	   Node<T>* Index(int i) ;  //���α궨λ��λ��i
	   void Insert(int i,const T& x);//�ڵ�i�����ǰ����Ԫ��x 	   
	   void Delete(int i);//ɾ����i����㣬����ӡ������ֵ
	   void Delete( Node<T>* p); //ɾ��p��Ľ�㣬����ӡ������ֵ����pΪΪ�ڵ㣬��ɾ����һ����㣩
	   Node<T>* Find(const T& x);  //���ؽ��ֵΪx��ָ��
	   T GetData(int i);   //��ȡ��i����������
	   Node<T>*Move(int i); //�α������ƶ�i������������β������ӻص����׼�����
	   void Print();   //���������
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
		 cout<<"λ�ò�����"<<endl;
		 exit(0);
	  }
	  else 
	  {
		 p=Index(i); // pָ���i����㣻
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
		  cout<<"����λ�ò�����"<<endl;
		  exit(0);
	  }
	  else 
	  { 
		  p=Index(i-1); // pָ���i-1����㣻
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
     cout<<"ɾ��λ�ò�����"<<endl;
     exit(0);
  }
  else 
  {
     p=Index(i-1); // pָ���i-1����㣻
     q = p->next;
     p->next = q->next;
	 cout<<q->data<<"��ɾ��"<<endl;
     delete q;  
     size--;
  } 
}
template<class T>
void  LinkList<T>::Delete( Node<T>* p)
{  Node<T>* q;
	if(this->size<=0)
	{ cout<<"������û�н�����ɾ����"<<endl;
	   exit(0);
	}
   //���ڴ���ɺ���
   //����������ɾ��p��Ľ�㣬����ӡ������ֵ����pΪβ�ڵ㣬��ɾ����һ����㣩


}

template<class T>
Node<T>* LinkList<T>::Move(int i) 
{  //���cursor��ǰ�ƶ�i����
	if( cursor==NULL)
	{  cout<<"�α�λ�ó���"<<endl;
		exit(0);
	}
	else
	{
	    //�����������α������ƶ�i������������β������ӻص����׼�����
     	//���ڴ���ɺ���
	}
}


