#include<string>
#include<iostream>
#include"Student.h"
using namespace std;
void main()
{
	int i;
	Student stud;
	cout << "\n \nѡ�\n��1������¼��\n��2�����ݲ�ѯ\n��3������ƽ���ɼ�\n��4���޸ļ�¼\n��5����ʾ��������\n��0���˳�\n�����룺";
	cin >> i;
	while (i != 0)
	{
		switch (i)
		{
		case 1:stud.Input(); break; 
		case 2:stud.Lookup(); break;
		case 3:stud.Statistic(); break;
		case 4:stud.Modify(); break;
		case 5:stud.Output(); break;
		case 0:     break;
		default: cout << "\n \nѡ�����\n \n";  break;
		}
		cout << "ѡ�\n��1������¼��\n��2�����ݲ�ѯ\n��3������ƽ���ɼ�\n��4���޸ļ�¼\n��5����ʾ��������\n��0���˳�\n�����룺";
		try
		{
			cin >> i;
		}
		catch (exception e)
		{
			cout << "�������";
		}
	}
}