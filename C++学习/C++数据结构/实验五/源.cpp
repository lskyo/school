#include <iostream>
#include <conio.h>
#include <cstdio>
#include <queue>
#include <stack>
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
	Node *to[100];
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			root = new Node(data[i]);
			to[No[i]] = root;
		}
		else
		{
			int k = (No[i] - 1) / 2;
			if(No[i]%2 == 0)
			{
				to[k]->rChild = new Node(data[i]);
				to[No[i]] = to[k]->rChild;
			}
			else
			{
				to[k]->lChild = new Node(data[i]);
				to[No[i]] = to[k]->lChild;
			}
		}
	}
}
//二叉树先序遍历递归算法 
void BTree::PreOrder(Node* r,void Visit(Node*)) {
	if(r == NULL)
		return;
	cout << r->data << " ";
	PreOrder(r->lChild,Visit);
	PreOrder(r->rChild,Visit);
}
//二叉树中序遍历递归算法 
void BTree::InOrder(Node* r,void Visit(Node*)) {
	if(r == NULL)
		return;
	InOrder(r->lChild,Visit);
	cout << r->data << " ";
	InOrder(r->rChild,Visit);
}
//二叉树后序遍历 递归算法 
void BTree::PostOrder(Node* r,void Visit(Node* )) {
	if(r == NULL)
		return;
	PostOrder(r->lChild,Visit);
	PostOrder(r->rChild,Visit);
	cout << r->data << " ";
}
//二叉树先序遍历的非递归算法 
void BTree::PreOrder1(Node* r,void Visit(Node*)) {
	stack<Node*>sta;
	sta.push(r);
	while(!sta.empty())
	{
		Node* k = sta.top();
		sta.pop();
		cout << k->data << " ";
		if(k->rChild != NULL)
			sta.push(k->rChild);
		if(k->lChild != NULL)
			sta.push(k->lChild);
	}
}
//利用队列完成对二叉树的层序遍历 
void BTree::LevelOrder(void Visit(Node*)) {
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node* k = q.front();
		q.pop();
		cout << k->data << " ";
		if(k->lChild != NULL)
			q.push(k->lChild);
		if(k->rChild != NULL)
			q.push(k->rChild);
	}
}
//求二叉树的高度,可使用递归算法
int BTree::High(Node* r) {
	if(r == NULL)
		return 0;
	int ll = High(r->lChild) + 1;
	int rr = High(r->rChild) + 1;
	if(ll < rr)
		return rr;
	return ll;
}

//求二叉树结点数目，可使用递归算法
int BTree::NodeNum(Node* r) {
	if(r == NULL)
		return 0;
	int ll = NodeNum(r->lChild);
	int rr = NodeNum(r->rChild);
	return ll + rr + 1;
}

//求二叉树叶结点数目,可使用递归算法 
int BTree::LeafNum(Node* r) {
	if(r == NULL)
		return 0;
	if(r->lChild == NULL && r->rChild == NULL)
		return 1;
	int ll = LeafNum(r->lChild);
	int rr = LeafNum(r->rChild);
	return ll + rr;
}

//r为打印的二叉树的根节点，level为该结点在整棵树中所在的层次
//完成二叉树的凹入表法打印
void BTree::Print(Node* r, int level) {   
	if(r == NULL)
		return;
	if(level == 1)
	{
		Print(r->rChild, level + 1);
		cout << r->data << endl;
		Print(r->lChild, level + 1);
		return;
	}
	Print(r->rChild, level + 1);
	for(int i = 1 ; i < level - 1; i++)
			cout << "      ";
		cout << " ----"<<r->data << endl;
	Print(r->lChild, level + 1);
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
	bt.Print(bt.getRoot(),1);        //凹入表法打印打印二叉树

	cout<<"先序遍历结果(递归)：";    
	bt.PreOrder(bt.getRoot(),Visit);     //正确调用成员函数
	cout<<endl;

	cout<<"先序遍历结果(非递归)："; 
	bt.PreOrder1(bt.getRoot(),Visit);     //正确调用成员函数
	cout<<endl;

	cout<<"中序遍历结果："; 
	bt.InOrder(bt.getRoot(),Visit);       //正确调用成员函数
	cout<<endl;

	cout<<"后序遍历结果："; 
	bt.PostOrder(bt.getRoot(),Visit);     //正确调用成员函数
	cout<<endl;  

	cout<<"层序遍历结果："; 
	bt.LevelOrder(Visit);     //正确调用成员函数
	cout<<endl;
	cout<<"二叉树的高度 = "<<bt.High(bt.getRoot())<<endl;   //正确调用成员函数
	cout<<"二叉树的结点数目 = "<<bt.NodeNum(bt.getRoot())<<endl;   //正确调用成员函数
	cout<<"二叉树的叶结点数目 = "<<bt.LeafNum(bt.getRoot())<<endl; //正确调用成员函数

	cout<<"撤销二叉树,撤销次序：";
	bt.Destroy(bt.getRoot()); //正确调用成员函数
	getch();
}
