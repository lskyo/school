#include"LinkStack.h"
#include<iostream>
using namespace std;
#include<string>


void DecToBin(int n) {
    ////////////////////////////////////////////////////////////////////
   //功能描述：把形参中的十进制数转会按为二进制数字串，并返回该串。//
  ////////////////////////////////////////////////////////////////////
	LinkStack ls;
	while(n)
	{
		ls.Push(n%2);
		n=n/2;
	}
	int e;
	cout<<"转换为二进制：";
	while(!ls.IsEmpty())
	{
		e=ls.Pop();
		cout<<e;
	}
	cout<<endl;
}
void DecToOct(int n) {
    ////////////////////////////////////////////////////////////////////
   //功能描述：把形参中的十进制数转会按为八进制数字串，并返回该串。//
  ////////////////////////////////////////////////////////////////////
	LinkStack ls;
	while(n)
	{
		ls.Push(n%8);
		n=n/8;
	}
	int e;
	cout<<"转换为八进制：";
	while(!ls.IsEmpty())
	{
		e=ls.Pop();
		cout<<e;
	}
	cout<<endl;
}

void DecToHex(int n) {
    ////////////////////////////////////////////////////////////////////
   //功能描述：把形参中的十进制数转会按为十六进制数字串，并返回该串。//
  ////////////////////////////////////////////////////////////////////
	LinkStack ls;
	while(n)
	{
		ls.Push(n%16);
		n=n/16;
	}
	int e;
	cout<<"转换为十六进制：";
	while(!ls.IsEmpty())
	{
		e=ls.Pop();
		cout<<hex<<e;
	}
	cout<<endl;
}

int main()
{
    //////////////////////////////////////////////////////
   //完成主函数的设计，将十进制转换成其它进制数，并输出//
  //////////////////////////////////////////////////////

	cout<<"请输入一个数字：";
	int n;
	cin>>n;
	DecToBin(n);
	DecToOct(n);
	DecToHex(n);
	getchar();
}
