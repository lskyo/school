#include<string>
#include<iostream>
#include"Student.h"
using namespace std;
void main()
{
	int i;
	Student stud;
	cout << "\n \n选项：\n【1】数据录入\n【2】数据查询\n【3】计算平均成绩\n【4】修改记录\n【5】显示所有数据\n【0】退出\n请输入：";
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
		default: cout << "\n \n选项错误！\n \n";  break;
		}
		cout << "选项：\n【1】数据录入\n【2】数据查询\n【3】计算平均成绩\n【4】修改记录\n【5】显示所有数据\n【0】退出\n请输入：";
		try
		{
			cin >> i;
		}
		catch (exception e)
		{
			cout << "输入错误！";
		}
	}
}