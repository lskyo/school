#include"SeqList.h"

void main()
{
	SeqList abc(50);
	char shuju[50];
	cout<<"������ԭʼ���ݣ�";
	cin.getline(shuju,50);
	//cout<<shuju<<endl;
	int i=0;
	while(shuju[i]!='\0')
	{
		abc.Insert(shuju[i],i);
		i++;
	}
	cout<<"SeqList˳���";
	abc.Print();
	cout<<"�����";
	abc.Reverse();
	abc.Print();
	cout<<"������Ҫ��ѯ�����ݣ�";
	char s;
	cin>>s;
	int num=abc.Find(s);
	cout<<"��������˳����е�"<<num<<"��λ�á�\n";
}