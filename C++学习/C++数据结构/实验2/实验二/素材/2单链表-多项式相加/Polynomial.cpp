#include <iostream>
using namespace std;
#include <conio.h>
typedef int DataType; 

//定义结点类 用于表示多项式的一项 
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
  int Exp;   //指数 
  int Coef;  //系数 
  Node* next;
};

//定义多项式类 
class Polynomial {
public:
   Polynomial();
   Polynomial(int a[][2],int n); //构造函数,n表示结点个数 
   Polynomial(const Polynomial& other); //拷贝构造函数 
   Node* Locate(int nExp);  //根据指数查找结点
   void Insert(Node* p,int nExp,int nCoef); //在一个多项式链表中插入一项 
   //查找多项式中指数等于nExp的项，如果查找成功则返回指向该项的指针，
   //如果查找不成功，则放回指向指数最大但小于nExp的项 
   Polynomial operator +(const Polynomial& other);//重载+，实现多项式相加
   void Print();  //将多项式输出显示
private:
   Node* head;
};

Polynomial::Polynomial() {
   head = new Node();
}

//利用单链表实现对多项式的存储
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
//重载构造函数
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
//根据指数查找，如果查找成功则返回指向该项的指针，
//如果查找不成功，则返回指向指数最大但小于nExp的项 
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

//在单链表的p结点后插入结点到
void Polynomial::Insert(Node* p,int nExp,int nCoef) {
   Node* s;
   s = new Node(nExp,nCoef);
   s->next = p->next;      
   p->next = s;
}

Polynomial Polynomial::operator +(const Polynomial& other) 
{
   Polynomial temp(*this);  //求和一般不改变左操作数的值，故引入一个临时对象
   //请自行完成，实现多项式的加法
   //算法思想
   //如果指数不相同，则将结点插入单链表适当的位置（单链表根据指数排序）
   //如果指数相同，则将系数相加，但系数为0,删除结点。





   return temp;
}

void Polynomial::Print() 
{
  //将多项式输出，
  //请考虑各种情况，如系数为1，指数为1等情况
  
  
  
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
