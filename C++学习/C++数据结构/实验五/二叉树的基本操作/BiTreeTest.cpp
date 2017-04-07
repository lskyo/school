#include <iostream>
#include <conio.h>
#define MaxSize 100
#define DataType char
using namespace std;

class Node  {
friend class BTree;
private:
	Node *lChild;		//左子树指针
	Node *rChild;		//右子树指针
public:
	DataType data;	 	//数据域，存储数据元素	
	//构造结点函数
	Node(){
	   lChild = NULL;
       rChild = NULL;
    }     
    //构造结点函数
	Node(DataType item, Node *left = NULL,Node *right = NULL){
	   data = item;
       lChild = left;
       rChild = right;
    }	
    //析构函数
	~Node(){}
};
//自定义函数，输出结点的数据域
void Visit(Node* p) {
   cout<<p->data<<"  ";
}
class BTree {
public:
   BTree(); //构造函数
   BTree(int No[],char data[],int n);//构造函数 
   void Create(int No[],char data[],int n); //创建二叉树 
   void PreOrder(Node* r,void Visit(Node*)); //先序遍历的递归算法  
   void InOrder(Node* r,void Visit(Node*));  //中序遍历的递归算法
   void PostOrder(Node* r,void Visit(Node*));  //后序遍历的递归算法
   void PreOrder1(Node* r,void Visit(Node*));//先序遍历的非递归算法 
   void LevelOrder(void Visit(Node*)); //层次遍历 
   int  High(Node* bt); //求二叉树高度的递归算法
   int NodeNum(Node* bt); // 求二叉树结点数目 
   int LeafNum(Node* bt); // 求二叉树叶结点数目
   void Destroy(Node *r); // 撤消结点，释放空间
   Node* getRoot();       //获取二叉树的根结点
   void Print(Node* r,int level);  //实现二叉树的凹入表形式打印
private:
   Node* root;
};

//创建二叉树二叉链表 
BTree::BTree() {
   root = NULL;
}
Node* BTree::getRoot() {
   return root;
}	
// 已知二叉树的结点的层序编号序列，数据数列和结点数，建立此二叉树
void BTree::Create(int No[],char data[],int n) {
////////////////////////////
///此处完成成员函数的定义///
////////////////////////////

}
//二叉树先序遍历递归算法 
void BTree::PreOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///此处完成成员函数的定义///
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
//二叉树中序遍历递归算法 
void BTree::InOrder(Node* r,void Visit(Node*)) {
////////////////////////////
///此处完成成员函数的定义///
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
//二叉树后序遍历 递归算法 
void BTree::PostOrder(Node* r,void Visit(Node* )) {
////////////////////////////
///此处完成成员函数的定义///
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
//二叉树先序遍历的非递归算法 
void BTree::PreOrder1(Node* r,void Visit(Node*)) {
   Node* stack[500];
////////////////////////////
///此处完成成员函数的定义///
///直接使用STL中的stack  ///
////////////////////////////
}
//利用队列完成对二叉树的层序遍历 
void BTree::LevelOrder(void Visit(Node*)) {
////////////////////////////
///此处完成成员函数的定义///
///直接使用STL中的queue  ///
////////////////////////////
}
//求二叉树的高度,可使用递归算法
int BTree::High(Node* r) {
////////////////////////////
///此处完成成员函数的定义///
////////////////////////////
}

//求二叉树结点数目，可使用递归算法
int BTree::NodeNum(Node* r) {
////////////////////////////
///此处完成成员函数的定义///
////////////////////////////
}

//求二叉树叶结点数目,可使用递归算法 
int BTree::LeafNum(Node* r) {
////////////////////////////
///此处完成成员函数的定义///
////////////////////////////
}

//r为打印的二叉树的根节点，level为该结点在整棵树中所在的层次
//完成二叉树的凹入表法打印
void BTree::Print(Node* r, int level) {   
////////////////////////////
///此处完成成员函数的定义///
////////////////////////////
} 
void BTree::Destroy(Node *r) {
    if(r ==NULL) return;
    else {
       if(r->lChild != NULL) Destroy(r->lChild);
       if(r->rChild != NULL) Destroy(r->rChild);
       cout << r->data << " ";	  //此语句只是为了方便测试
	   delete r;
    }
}
int main()
{
   int n,i;
   int * No;//层序编号动态数组；
   DataType *data;//结点数据动态数组；
   cout<<"请输入结点数"<<endl;
   cin>>n;
   No=new int[n];
   data=new char[n];
   cout<<"请输入该结点的层序编号序列:";
    for( i=0;i<n;i++)
   	   cin>>No[i] ;  
  cout<<"请输入结点的数据序列:";
   for( i=0;i<n;i++)
   	   cin>>data[i];  
   BTree bt;
   bt.Create(No,data,n);       //创建二叉对
   //bt.Print(?);        //凹入表法打印打印二叉树
   
   cout<<"先序遍历结果(递归)：";    
   bt.PreOrder(?);     //正确调用成员函数
   cout<<endl;

   //cout<<"先序遍历结果(非递归)："; 
   //bt.PreOrder1(?);     //正确调用成员函数
   //cout<<endl;

   cout<<"中序遍历结果："; 
   bt.InOrder(?);       //正确调用成员函数
   cout<<endl;
   
   cout<<"后序遍历结果："; 
   bt.PostOrder(?);     //正确调用成员函数
   cout<<endl;  

   //cout<<"层序遍历结果："; 
   //bt.LevelOrder(?);     //正确调用成员函数
   //cout<<endl;
   //cout<<"二叉树的高度 = "<<bt.High(?)<<endl;   //正确调用成员函数
   //cout<<"二叉树的结点数目 = "<<bt.NodeNum(?)<<endl;   //正确调用成员函数
   //cout<<"二叉树的叶结点数目 = "<<bt.LeafNum(?)<<endl; //正确调用成员函数
  
   //cout<<"撤销二叉树,撤销次序：";
   //bt.Destroy(?); //正确调用成员函数
   getch();
}
