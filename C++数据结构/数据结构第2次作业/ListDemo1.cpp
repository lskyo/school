#include"SeqList.h"

void main()
{
	SeqList abc(50);
	char shuju[50];
	cout<<"请输入原始数据：";
	cin.getline(shuju,50);
	//cout<<shuju<<endl;
	int i=0;
	while(shuju[i]!='\0')
	{
		abc.Insert(shuju[i],i);
		i++;
	}
	cout<<"SeqList顺序表：";
	abc.Print();
	cout<<"逆序后：";
	abc.Reverse();
	abc.Print();
	cout<<"请输入要查询的数据：";
	char s;
	cin>>s;
	int num=abc.Find(s);
	cout<<"该数据在顺序表中第"<<num<<"个位置。\n";
}