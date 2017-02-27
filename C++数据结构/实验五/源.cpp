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
//��������������ݹ��㷨 
void BTree::PreOrder(Node* r,void Visit(Node*)) {
	if(r == NULL)
		return;
	cout << r->data << " ";
	PreOrder(r->lChild,Visit);
	PreOrder(r->rChild,Visit);
}
//��������������ݹ��㷨 
void BTree::InOrder(Node* r,void Visit(Node*)) {
	if(r == NULL)
		return;
	InOrder(r->lChild,Visit);
	cout << r->data << " ";
	InOrder(r->rChild,Visit);
}
//������������� �ݹ��㷨 
void BTree::PostOrder(Node* r,void Visit(Node* )) {
	if(r == NULL)
		return;
	PostOrder(r->lChild,Visit);
	PostOrder(r->rChild,Visit);
	cout << r->data << " ";
}
//��������������ķǵݹ��㷨 
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
//���ö�����ɶԶ������Ĳ������ 
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
//��������ĸ߶�,��ʹ�õݹ��㷨
int BTree::High(Node* r) {
	if(r == NULL)
		return 0;
	int ll = High(r->lChild) + 1;
	int rr = High(r->rChild) + 1;
	if(ll < rr)
		return rr;
	return ll;
}

//������������Ŀ����ʹ�õݹ��㷨
int BTree::NodeNum(Node* r) {
	if(r == NULL)
		return 0;
	int ll = NodeNum(r->lChild);
	int rr = NodeNum(r->rChild);
	return ll + rr + 1;
}

//�������Ҷ�����Ŀ,��ʹ�õݹ��㷨 
int BTree::LeafNum(Node* r) {
	if(r == NULL)
		return 0;
	if(r->lChild == NULL && r->rChild == NULL)
		return 1;
	int ll = LeafNum(r->lChild);
	int rr = LeafNum(r->rChild);
	return ll + rr;
}

//rΪ��ӡ�Ķ������ĸ��ڵ㣬levelΪ�ý���������������ڵĲ��
//��ɶ������İ������ӡ
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
	bt.Print(bt.getRoot(),1);        //�������ӡ��ӡ������

	cout<<"����������(�ݹ�)��";    
	bt.PreOrder(bt.getRoot(),Visit);     //��ȷ���ó�Ա����
	cout<<endl;

	cout<<"����������(�ǵݹ�)��"; 
	bt.PreOrder1(bt.getRoot(),Visit);     //��ȷ���ó�Ա����
	cout<<endl;

	cout<<"������������"; 
	bt.InOrder(bt.getRoot(),Visit);       //��ȷ���ó�Ա����
	cout<<endl;

	cout<<"������������"; 
	bt.PostOrder(bt.getRoot(),Visit);     //��ȷ���ó�Ա����
	cout<<endl;  

	cout<<"������������"; 
	bt.LevelOrder(Visit);     //��ȷ���ó�Ա����
	cout<<endl;
	cout<<"�������ĸ߶� = "<<bt.High(bt.getRoot())<<endl;   //��ȷ���ó�Ա����
	cout<<"�������Ľ����Ŀ = "<<bt.NodeNum(bt.getRoot())<<endl;   //��ȷ���ó�Ա����
	cout<<"��������Ҷ�����Ŀ = "<<bt.LeafNum(bt.getRoot())<<endl; //��ȷ���ó�Ա����

	cout<<"����������,��������";
	bt.Destroy(bt.getRoot()); //��ȷ���ó�Ա����
	getch();
}
