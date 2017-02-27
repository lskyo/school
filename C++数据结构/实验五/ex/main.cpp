#include <iostream>
#include <conio.h>
#define MaxSize 100
#define DataType char
using namespace std;

class Node  {
friend class BTree;
private:
	Node *lChild;		//������ָ��
	Node *rChild;		//������ָ��
public:
	DataType data;	 	//�����򣬴洢����Ԫ��	
	//�����㺯��
	Node(){
	   lChild = NULL;
       rChild = NULL;
    }     
    //�����㺯��
	Node(DataType item, Node *left = NULL,Node *right = NULL){
	   data = item;
       lChild = left;
       rChild = right;
    }	
    //��������
	~Node(){}
};
//�Զ��庯�����������������
void Visit(Node* p) {
   cout<<p->data<<"  ";
}
class BTree {
public:
   BTree(); //���캯��
   BTree(int No[],char data[],int n);//���캯�� 
   void Create(int No[],char data[],int n); //���������� 
   void PreOrder(Node* r,void Visit(Node*)); //��������ĵݹ��㷨  
   void InOrder(Node* r,void Visit(Node*));  //��������ĵݹ��㷨
   void PostOrder(Node* r,void Visit(Node*));  //��������ĵݹ��㷨
   void PreOrder1(Node* r,void Visit(Node*));//��������ķǵݹ��㷨 
   void LevelOrder(void Visit(Node*)); //��α��� 
   int  High(Node* bt); //��������߶ȵĵݹ��㷨
   int NodeNum(Node* bt); // ������������Ŀ 
   int LeafNum(Node* bt); // �������Ҷ�����Ŀ
   void Destroy(Node *r); // ������㣬�ͷſռ�
   Node* getRoot();       //��ȡ�������ĸ����
   void Print(Node* r,int level);  //ʵ�ֶ������İ������ʽ��ӡ
private:
   Node* root;
};

//������������������ 
BTree::BTree() {
   root = NULL;
}
Node* BTree::getRoot() {
   return root;
}	
// ��֪�������Ľ��Ĳ��������У��������кͽ�����������˶�����
void BTree::Create(int No[],char data[],int n) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	Node*  s[MaxSize];  //���������ָ������
   Node  *q;
   int i, j;
   for( i=0; i<n; i++) {
     q = new Node(data[i]);
     s[ No[i] ] = q; 
     if( No[i] ==0)   root = q;
     else {
        j = (No[i]-1)/2;   // ���ڵ������       
        if ((No[i]-1)%2==0)  s[j]->lChild = q;
        else s[j]->rChild = q;
     }
   }

}
//��������������ݹ��㷨 
void BTree::PreOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	   if(r!=NULL) 
      {
           Visit(r);  //���ʸ��ڵ�
           PreOrder ( r->lChild,Visit);   //����������
           PreOrder ( r->rChild,Visit);   //����������
       }
}
//��������������ݹ��㷨 
void BTree::InOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
if(r!=NULL) {
      InOrder(r->lChild,Visit);
      Visit(r);
      InOrder(r->rChild,Visit);
   }
}
//������������� �ݹ��㷨 
void BTree::PostOrder(Node* r,void Visit(Node* )) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
   if(r!=NULL) 
     {
         PostOrder(r->lChild,Visit);
         PostOrder(r->rChild,Visit);
         Visit(r);
      }

}
//��������������ķǵݹ��㷨 
void BTree::PreOrder1(Node* r,void Visit(Node*)) {
   Node* stack[500];
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
///ֱ��ʹ��STL�е�stack  ///
////////////////////////////
 //  stack<Node *> mystack;
	//while(r!=NULL)
	//{	Visit(r); 
	//	if(r->rChild !=NULL)
	//		mystack.push(r->rChild );
	//	if(r->lChild !=NULL)
	//		r=r->lChild;
	//	else
	//	{   if(mystack.empty() ==0)
	//              {   r=mystack.top();    mystack.pop (); }
	//	     else	  r=NULL;
	//	}		 
	//} 


}
//���ö�����ɶԶ������Ĳ������ 
void BTree::LevelOrder(void Visit(Node*)) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
///ֱ��ʹ��STL�е�queue  ///
////////////////////////////
}
//��������ĸ߶�,��ʹ�õݹ��㷨
int BTree::High(Node* r) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	return 0;
}

//������������Ŀ����ʹ�õݹ��㷨
int BTree::NodeNum(Node* r) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	return 0;
}

//�������Ҷ�����Ŀ,��ʹ�õݹ��㷨 
int BTree::LeafNum(Node* r) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	return 0;
}

//rΪ��ӡ�Ķ������ĸ��ڵ㣬levelΪ�ý���������������ڵĲ��
//��ɶ������İ������ӡ
void BTree::Print(Node* r, int level) {   
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
} 
void BTree::Destroy(Node *r) {
    if(r ==NULL) return;
    else {
       if(r->lChild != NULL) Destroy(r->lChild);
       if(r->rChild != NULL) Destroy(r->rChild);
       cout << r->data << " ";	  //�����ֻ��Ϊ�˷������
	   delete r;
    }
}
int main()
{
   int n,i;
   int * No;//�����Ŷ�̬���飻
   DataType *data;//������ݶ�̬���飻
   cout<<"����������"<<endl;
   cin>>n;
   No=new int[n];
   data=new char[n];
   cout<<"������ý��Ĳ���������:";
    for( i=0;i<n;i++)
   	   cin>>No[i] ;  
  cout<<"�����������������:";
   for( i=0;i<n;i++)
   	   cin>>data[i];  
   BTree bt;
   bt.Create(No,data,n);       //���������
   //bt.Print(?);        //�������ӡ��ӡ������
   
   cout<<"����������(�ݹ�)��";    
   bt.PreOrder(bt.getRoot(),Visit);     //��ȷ���ó�Ա����
   cout<<endl;

   //cout<<"����������(�ǵݹ�)��"; 
   //bt.PreOrder1(?);     //��ȷ���ó�Ա����
   //cout<<endl;

   cout<<"������������"; 
   bt.InOrder(bt.getRoot(),Visit);       //��ȷ���ó�Ա����
   cout<<endl;
   
   cout<<"������������"; 
   bt.PostOrder(bt.getRoot(),Visit);     //��ȷ���ó�Ա����
   cout<<endl;  

   //cout<<"������������"; 
   //bt.LevelOrder(?);     //��ȷ���ó�Ա����
   //cout<<endl;
   //cout<<"�������ĸ߶� = "<<bt.High(?)<<endl;   //��ȷ���ó�Ա����
   //cout<<"�������Ľ����Ŀ = "<<bt.NodeNum(?)<<endl;   //��ȷ���ó�Ա����
   //cout<<"��������Ҷ�����Ŀ = "<<bt.LeafNum(?)<<endl; //��ȷ���ó�Ա����
  
   //cout<<"����������,��������";
   //bt.Destroy(?); //��ȷ���ó�Ա����
   getch();
}
