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

}
//��������������ݹ��㷨 
void BTree::PreOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	if(r==NULL)
	{
		cout<<"^";
	}
	else
	{
		Visit(r);
		PreOrder(r->lChild);
		PreOrder(r->rChile);
	}
}
//��������������ݹ��㷨 
void BTree::InOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
	if(r!=NULL)
	{
		cout<<"^";
	}
	else
	{
		InOrder(r->lChild);
		Visit(r);
		InOrder(r->rChile);
	}
}
//������������� �ݹ��㷨 
void BTree::PostOrder(Node* r,void Visit(Node* )) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
		if(r!=NULL)
	{
		cout<<"^";
	}
	else
	{
		PostOrder(r->lChild);
		PostOrder(r->rChile);
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
}

//������������Ŀ����ʹ�õݹ��㷨
int BTree::NodeNum(Node* r) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
}

//�������Ҷ�����Ŀ,��ʹ�õݹ��㷨 
int BTree::LeafNum(Node* r) {
////////////////////////////
///�˴���ɳ�Ա�����Ķ���///
////////////////////////////
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
   bt.PreOrder(?);     //��ȷ���ó�Ա����
   cout<<endl;

   //cout<<"����������(�ǵݹ�)��"; 
   //bt.PreOrder1(?);     //��ȷ���ó�Ա����
   //cout<<endl;

   cout<<"������������"; 
   bt.InOrder(?);       //��ȷ���ó�Ա����
   cout<<endl;
   
   cout<<"������������"; 
   bt.PostOrder(?);     //��ȷ���ó�Ա����
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
