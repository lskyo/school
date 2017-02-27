#include <iostream>
using namespace std;
#include <conio.h>
typedef int DataType; 

//�������� ���ڱ�ʾ����ʽ��һ�� 
class Node {
friend class Polynomial;
public:
  Node() {
    next = NULL;
  }
  Node(int nExp,int nCoef) {
    Exp = nExp;
    Coef = nCoef;
    next = NULL;
  }
private:
  int Exp;   //ָ�� 
  int Coef;  //ϵ�� 
  Node* next;
};

//�������ʽ�� 
class Polynomial {
public:
   Polynomial();
   Polynomial(int a[][2],int n); //���캯��,n��ʾ������ 
   Polynomial(const Polynomial& other); //�������캯�� 
   Node* Locate(int nExp);  //����ָ�����ҽ��
   void Insert(Node* p,int nExp,int nCoef); //��һ������ʽ�����в���һ�� 
   //���Ҷ���ʽ��ָ������nExp���������ҳɹ��򷵻�ָ������ָ�룬
   //������Ҳ��ɹ�����Ż�ָ��ָ�����С��nExp���� 
   Polynomial operator +(const Polynomial& other);//����+��ʵ�ֶ���ʽ���
   void Print();  //������ʽ�����ʾ
private:
   Node* head;
};

Polynomial::Polynomial() {
   head = new Node();
}

//���õ�����ʵ�ֶԶ���ʽ�Ĵ洢
Polynomial::Polynomial(int a[][2],int n) {
   head = new Node();
   Node *p,*s;
   p = head;
   for(int i=0;i<n;i++) {
      s = new Node(a[i][0],a[i][1]);
      p->next = s;
      p = s;
   }
}
//���ع��캯��
Polynomial::Polynomial(const Polynomial& other) {
   head = new Node();
   Node *p,*s,*q;
   p = head;
   q = (other.head)->next;
   while(q != NULL) {
      s = new Node(q->Exp,q->Coef);
      p->next = s;
      p = s;
      q = q->next;
   }
}
//����ָ�����ң�������ҳɹ��򷵻�ָ������ָ�룬
//������Ҳ��ɹ����򷵻�ָ��ָ�����С��nExp���� 
Node* Polynomial::Locate(int nExp){
   Node *p,*q;
   p = head;
   q = p->next;
   while ((q!=NULL)&&(q->Exp<=nExp)){
     if(q->Exp == nExp) 
     {
       return q;
     }
     p = q;
     q = p->next;
   }
   return p;
}

//�ڵ������p��������㵽
void Polynomial::Insert(Node* p,int nExp,int nCoef) {
   Node* s;
   s = new Node(nExp,nCoef);
   s->next = p->next;      
   p->next = s;
}

Polynomial Polynomial::operator +(const Polynomial& other) 
{
   Polynomial temp(*this);  //���һ�㲻�ı����������ֵ��������һ����ʱ����
   //��������ɣ�ʵ�ֶ���ʽ�ļӷ�
   //�㷨˼��
   //���ָ������ͬ���򽫽����뵥�����ʵ���λ�ã����������ָ������
   //���ָ����ͬ����ϵ����ӣ���ϵ��Ϊ0,ɾ����㡣





   return temp;
}

void Polynomial::Print() 
{
  //������ʽ�����
  //�뿼�Ǹ����������ϵ��Ϊ1��ָ��Ϊ1�����
  
  
  
}



int main()
{
   int a1[4][2] = {{1,1},{2,2},{3,3},{5,5}};
   int a2[4][2] = {{0,1},{2,3},{4,1},{6,1}};
   Node* p;
   Polynomial Result;
   Polynomial p1(a1,4);
   p1.Print();
   Polynomial p2(a2,4);
   p2.Print();
   Result = p1 + p2;
   Result.Print();
   getch();
}
