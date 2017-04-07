#include"MyString.h"


void main()
{
	cout<<"请输入一段字符串：";
	char *str=new char[100];
	cin>>str;
	MyString mystr1(str),mystr2(str);
	mystr1.reverse();
	if(mystr1==mystr2)
	{
		cout<<"是回文。\n";
	}
	else
	{
		cout<<"不是回文。\n";
	}
}