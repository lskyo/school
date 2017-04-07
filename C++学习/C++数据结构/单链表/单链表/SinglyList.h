#include<iostream>
using namespace std;
#include"Node.h"

template<class T>
class SinglyList
{
public:
	Node<T> *head;


	SinglyList();
	SinglyList(T values[], int n);
	~SinglyList();


	bool empty();
	int count();
	T& get(int i);
	virtual void set(int i, T x);
	friend ostream& operator<<<>(ostream&, SinglyList<T>&);
	Node<T>* insert(int i, T x);
	virtual Node<T>* insert(T x);
	T remove(int i);
	void removeAll();
	Node<T>* search(T key);
	void insertUnrepeatable(T x);
	virtual void removeFirst(T key);


	bool operator==(SinglyList<T>&list);
	bool operator!=(SinglyList<T>&list);
	SinglyList(SinglyList<T>&list);
	SinglyList<T>& operator=(SinglyList<T>&list);
	virtual void operator+=(SinglyList<T>&list);
};

template<class T>
SinglyList<T>::SinglyList()
{
	this->head = new Node<T>();
}

template<class T>
SinglyList<T>::SinglyList(T values[], int n)
{
	this->head = new Node<T>();
	Node<T>*rear = this->head;
	for (int i = 0; i < n; i++)
	{
		rear->next = new Node<T>(values[i]);
		rear = rear->next;
	}
}

template<class T>
SinglyList<T>::~SinglyList()
{
	this->removeAll();
	delete this->head;
}

template<class T>
bool SinglyList<T>::empty()
{
	return this->head->next == NULL;
}

template<class T>
ostream& operator<<<>(ostream& out, SinglyList<T> &list)
{
	out << "(";
	for (Node<T> *p = list.head->next; p != NULL; p = p->next)
	{
		out << p->data;
		if (p->next != NULL)
			out << ",";
	}
	out << ")\n";
	return out;
}

template<class T>
T& SinglyList<T>::get(int i)
{
	Node<T> *p = this->head->next;
	for (int j = 0; p != NULL && j < i; j++)
	{
		p = p->next;
	}
	if (i >= 0 && p != NULL)
	{
		return p->data;
	}
	throw out_of_range("参数i指定元素序号超出范围");
}

template<class T>
Node<T>* SinglyList<T>::insert(int i, T x)
{
	Node<T> *front = this->head;
	for (int j = 0; front->next != NULL && j < i; j++)
		front = front->next;
	front->next = new Node<T>(x, front->next);
	return front->next;
}

template<class T>
T SinglyList<T>::remove(int i)
{
	Node<T> *front = this->head;
	for (int j = 0; front->next != NULL && j < i; j++)
	{
		front = front->next;
	}
	if (i >= 0 && front->next != NULL)
	{
		Node<T> *q = front->next;
		T old = q->data;
		front->next = q->next;
		delete q;
		return old;
	}
	throw out_of_range("参数i指定元素序号超出范围");
}