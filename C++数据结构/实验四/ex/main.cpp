#include"MyString.h"


void main()
{
	cout<<"������һ���ַ�����";
	char *str=new char[100];
	cin>>str;
	MyString mystr1(str),mystr2(str);
	mystr1.reverse();
	if(mystr1==mystr2)
	{
		cout<<"�ǻ��ġ�\n";
	}
	else
	{
		cout<<"���ǻ��ġ�\n";
	}
}