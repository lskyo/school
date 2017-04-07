#include<iostream>
#include<stdlib.h> //为了使用exit()函数
#include<Windows.h> //为了使用sleep()函数
#include<iomanip>
#include<fstream> 
#include<string>

using namespace std;


struct student
{        
	char name[10]; //姓名
	char number[10];  //学号
	char sex;  //性别
	char phnum[15];  //手机号码
	char address[50];  //通讯地址
};


class book
{
	student stud; //数据成员
public:
	book()   //构造函数
	{
		cout << "\n \n \n \n \n \n \n \n";
		cout << "       -----------------------------------------------------------------\n"
			<< "\n                                 学生通讯录\n \n"
			<< "       -----------------------------------------------------------------\n";
		cout << "\n \n \n \n \n \n \n";
		cout << "                                                         罗星华\n";
		cout << "\n \n \n \n \n \n \n";
		Sleep(1500);
		system("cls");
	}
	string inter_face();    //8首页菜单
	string add_person();    //1添加联系人
	string del_person();    //2删除联系人
	string show_all();      //3显示所有联系人
	string alter();         //4修改信息
	string select();        //5查询联系人
	string save_new();      //6保存新增加的联系人
	string checknum(char* number);  //检查学号是否唯一
	
	void tuichu();       //0退出程序
};

string checkfile(ofstream &outfile);//检查文件流
string checkfile(ifstream &infile);//检查文件流
string checkfile(fstream &iofile);//检查文件流
string move_ex(string a, string b, student ex_stud);//文件数据从a复制到b，除了ex_stud以外
string move(string a, string b);//文件数据从a复制到b


void main()
{
	book book1; //通讯录
	string cdxx;   //菜单选项
	cdxx = book1.inter_face();
	while (1)
	{
		if(cdxx == "1")cdxx = book1.add_person();  //1添加联系人
		else if(cdxx == "2")cdxx = book1.del_person();  //2删除联系人
		else if (cdxx == "3")cdxx = book1.show_all();    //3显示所有联系人 
		else if (cdxx == "4")cdxx = book1.alter();      //4修改信息
		else if (cdxx == "5")cdxx = book1.select();      //5查询信息
		else if (cdxx == "6")cdxx = book1.save_new();    //6保存联系人
		else if (cdxx == "8")cdxx = book1.inter_face();  //8主菜单
		else if (cdxx == "0")book1.tuichu();            //0退出程序
		else
			{
				cout << "选项错误！\n"; 
				Sleep(1500); 
				cdxx = book1.inter_face(); 
			}
	}
}



string checkfile(ofstream &outfile)
{
	if (!outfile)
	{
		cout << "\n \n 文件打开失败！\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n 菜单\n【8】返回主菜单\n【0】退出程序\n选项：";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
		return "n";
}
string checkfile(ifstream &infile)
{
	if (!infile)
	{
		cout << "\n \n 文件打开失败！\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n 菜单\n【8】返回主菜单\n【0】退出程序\n选项：";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
		return "n";
}
string checkfile(fstream &iofile)
{

	if (!iofile)
	{
		cout << "\n \n 文件打开失败！\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n 菜单\n【8】返回主菜单\n【0】退出程序\n选项：";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
		return "n";
}


string book::inter_face()      //8首页
{
	
	string i;
	while (1)
	{
		system("cls");
		cout << "\n \n";
		cout << " 菜单\n"
			<< "【1】添加联系人\n【2】删除联系人\n【3】显示所有联系人\n【4】修改信息\n"
			<< "【5】查询联系人\n【0】退出程序\n \n选项：";
		cin >> i;
		if (i == "1")return i;           //1添加联系人
		else if (i == "2")return i;      //2删除联系人
		else if (i == "3")return i;      //3显示所有联系人 
		else if (i == "4")return i;      //4修改信息
		else if (i == "5")return i;      //5查询信息
		else if (i == "0")return i;      //0退出程序
		else
		{
			cout << "选项错误！\n";
			Sleep(1500);
		}
	}
}


void book::tuichu()  //0退出程序
{
	cout << "\n程序已结束！\n \n";
	Sleep(1500);
	exit(1);
}


string book::add_person() //1添加联系人
{		
	string i;
	system("cls");
	cout << "\n \n请输入学生姓名，学号，性别（男M/女F），手机号码，通讯地址\n"
		<< "例如：张三 2014001 M 13412345678 01栋101\n \n请输入\n";
	cout << "姓名：";
	cin >> stud.name;
	cout << "学号：";
	cin >> stud.number;
	cout << "性别（男M/女F）：";
	cin >> stud.sex;
	cout << "手机号码：";
	cin >> stud.phnum; 
	cout << "通讯地址：";
	cin >> stud.address;
	while (1)
	{
		cout << "\n \n";
		cout << "\n 菜单\n【6】保存新增加的联系人\n【8】取消并返回主菜单\n【0】退出程序\n \n选项：";
		cin >> i;
		if (i == "6")return i;           
		else if (i == "8")return i;     
		else if (i == "0")return i;       
		else
		{
			cout << "选项错误！\n";
			Sleep(1500);
			system("cls");
		}
	}
}


string book::save_new()  //6保存新增加的联系人
{
	ofstream outfile;
	string yorn;        //数据是否有问题
	student new_stud = stud;

	outfile.open("tongxunlu.txt", ios::out | ios::app);
	string outfilenum = checkfile(outfile);
	if ("n" != outfilenum)
		return outfilenum;

	yorn = checknum(new_stud.number);         //检查学号是否唯一，是n，否y
	if (yorn == "n")                          //该学号唯一,则输出到tongxunlu.txt
	{
		outfile.setf(ios::left);
		outfile << setw(10) << new_stud.name << " "
			<< setw(10) << new_stud.number << " "
			<< setw(3) << new_stud.sex << " "
			<< setw(15) << new_stud.phnum << " "
			<< setw(50) << new_stud.address
			<< '\n';
		cout << "\n新增联系人已经保存！\n";
		outfile.close();

		/*   执行备份操作   */
		move("tongxunlu.txt", "beifen.txt");

		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n 菜单\n【1】继续添加联系人\n【3】显示所有联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "1")return i;
			else if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else if (yorn == "y")                //该学号已存在
	{
		cout << "\n该学号已存在！\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n 菜单\n【1】重新添加联系人\n【3】显示所有联系人\n【5】查询联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "1")return i;
			else if (i == "3")return i;
			else if (i == "5")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		return yorn;
	}
}


string book::show_all()   //3显示所有联系人
{
	int num = 1;
	system("cls");
	ifstream infile;
	infile.open("tongxunlu.txt", ios::_Nocreate | ios::in);
	string infilenum = checkfile(infile);
	if ("n" != infilenum)
		return infilenum;
	cout << "\n    姓名       学号      性别   电话号码       通讯地址  \n";
	while (!infile.eof())
	{
		infile >> stud.name 
			>> stud.number 
			>> stud.sex 
			>> stud.phnum 
			>> stud.address;
		if (infile.eof())
		{
			break;
		}
		cout.setf(ios::left);
		cout << setw(2) << num << "、";
		num++;
		cout << setw(10) << stud.name << " "
			<< setw(10) << stud.number << " "
			<< setw(4) << stud.sex << " "
			<< setw(15) << stud.phnum << " "
			<< setw(50) << stud.address << endl;
	}

	string i;
	while (1)
	{
		cout << "\n \n";
		cout << "\n 菜单\n【1】添加联系人\n【2】删除联系人\n【4】修改信息\n【5】查询联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
		cin >> i;
		if (i == "1")return i;
		else if (i == "2")return i;
		else if (i == "4")return i;
		else if (i == "5")return i;
		else if (i == "8")return i;
		else if (i == "0")return i;
		else
		{
			cout << "选项错误！\n";
			Sleep(1500);		
			system("cls");
		}
	}
}


string book::select()  //5查询联系人
{
	char YorN = 'n';   //是否找到该同学
	system("cls");
	cout << "\n \n请输入要查询学生的姓名或学号：";
	char s_stud[10];
	cin >> s_stud;

	ifstream infile;
	infile.open("tongxunlu.txt");
	string infilenum = checkfile(infile);
	if ("n" != infilenum)
		return infilenum;

	
	while (!infile.eof())
	{
		infile >> stud.name
               >> stud.number
		       >> stud.sex
			   >> stud.phnum
		       >> stud.address;
		if (strcmp(s_stud, stud.name) == 0)
		{
			YorN = 'y';
			break;
		}
		else if (strcmp(s_stud, stud.number) == 0)
		{
			YorN = 'y';
			break;
		}
		if (infile.eof())
		{
			break;
		}
	}
	if (YorN == 'y')
	{
		cout << "\n姓名        学号    性别     电话号码      通讯地址  \n";
		cout.setf(ios::left);
		cout << setw(10) << stud.name << " "
			<< setw(10) << stud.number << " "
			<< setw(4) << stud.sex << " "
			<< setw(15) << stud.phnum << " "
			<< setw(50) << stud.address << endl;
		
		string i;
		while (1)
		{
			cout << "\n \n";
			cout << "\n \n 菜单\n【2】删除联系人\n【4】修改信息\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "2")return i;
			else if (i == "4")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
				system("cls");
			}
		}
	}
	else
	{
		cout << "\n对不起，找不到该同学！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n \n 菜单\n【5】继续查找\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "5")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
}


string book::alter() //4修改信息
{
	student del_stud;
	student new_stud;
	char YorN = 'n';


	system("cls");
	cout << "\n请输入需要修改的学生姓名或学号：";
	char alter_stud[20];
	cin >> alter_stud;

	fstream iofile;
	iofile.open("tongxunlu.txt",ios::in|ios::out);
	string iofilenum = checkfile(iofile);
	if ("n" != iofilenum)
		return iofilenum;
	while (!iofile.eof())
	{
		iofile >> stud.name
			>> stud.number
			>> stud.sex
			>> stud.phnum
			>> stud.address;
		if (strcmp(alter_stud, stud.name) == 0)
		{
			YorN = 'y';
			break;
		}
		else if (strcmp(alter_stud, stud.number) == 0)
		{
			YorN = 'y';
			break;
		}
		if (iofile.eof())
		{
			break;
		}
	}
	iofile.close();


	if (YorN == 'y')
	{
		cout << "确认被修改学生信息：";
		cout << "\n姓名        学号    性别     电话号码      通讯地址  \n";
		cout.setf(ios::left);
		cout << setw(10) << stud.name << " "
			<< setw(10) << stud.number << " "
			<< setw(4) << stud.sex << " "
			<< setw(15) << stud.phnum << " "
			<< setw(50) << stud.address << endl;
		del_stud = stud;
		move_ex("beifen.txt", "tongxunlu.txt", del_stud);

		ofstream outfile;
		outfile.open("tongxunlu.txt", ios::out | ios::app);
		string outfilenum = checkfile(outfile);
		if ("n" != outfilenum)
			return outfilenum;


		cout << "\n请重新输入该学生的姓名，学号，性别（男M/女F），手机号码，通讯地址\n"
			<< "例如：张三 2014001 M 13412345678 01栋101\n \n请输入\n";
		cout << "姓名：";
		cin >> stud.name;
		cout << "学号：";
		cin >> stud.number;
		cout << "性别（男M/女F）：";
		cin >> stud.sex;
		cout << "手机号码：";
		cin >> stud.phnum;
		cout << "通讯地址：";
		cin >> stud.address;

		new_stud = stud;
		string yorn2;
		yorn2 = checknum(new_stud.number);
		if (yorn2 == "n")
		{
			outfile.setf(ios::left);
			outfile << setw(10) << new_stud.name << " "
				<< setw(10) << new_stud.number << " "
				<< setw(3) << new_stud.sex << " "
				<< setw(15) << new_stud.phnum << " "
				<< setw(50) << new_stud.address
				<< '\n';
			cout << "\n修改成功！";
			outfile.close();
			move("tongxunlu.txt", "beifen.txt");
			Sleep(1500);
			string i;
			while (1)
			{
				system("cls");
				cout << "\n \n";
				cout << "\n 菜单\n【3】显示所有联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
				cin >> i;
				if (i == "3")return i;
				else if (i == "8")return i;
				else if (i == "0")return i;
				else
				{
					cout << "选项错误！\n";
					Sleep(1500);
				}
			}
		}
		else if (yorn2 == "y")
		{
			cout << "\n学号重复，修改失败！";
			Sleep(1500);
			string i;
			outfile.close();
			while (1)
			{
				system("cls");
				cout << "\n \n";
				cout << "\n 菜单\n【4】重新修改\n【8】取消修改并返回主菜单\n【0】退出程序\n \n选项：";
				cin >> i;
				if (i == "4")
				{
					move("beifen.txt", "tongxunlu.txt");
					return i;
				}
				else if (i == "8")
				{
					move("beifen.txt", "tongxunlu.txt");
					return i;
				}
				else if (i == "0")return i;
				else
				{
					cout << "选项错误！\n";
					Sleep(1500);
				}
			}
		}
		else
		{
			return yorn2;
		}
	}
	else if (YorN == 'n')
	{
		cout << "\n对不起，找不到该同学！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n 菜单\n【4】重新输入\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "4")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		cout<<"出错！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n菜单\n【3】显示所有联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
}


string book::del_person() //2删除联系人
{
	char YorN = 'n';
	string del;
	char del_person[20];
	student del_stud;

	system("cls");
	cout << "\n请输入要删除的学生姓名或学号：";
	cin >> del_person;

	fstream iofile;
	iofile.open("tongxunlu.txt",ios::in|ios::out);
	string iofilenum = checkfile(iofile);
	if ("n" != iofilenum)
		return iofilenum;

	while (!iofile.eof())
	{
		iofile >> stud.name
			>> stud.number
			>> stud.sex
			>> stud.phnum
			>> stud.address;
		if (strcmp(del_person, stud.name) == 0)
		{
			YorN = 'y';
			break;
		}
		else if (strcmp(del_person, stud.number) == 0)
		{
			YorN = 'y';
			break;
		}
		if (iofile.eof())
		{
			break;
		}
	}
	iofile.close();

	if (YorN == 'y')
	{
		while (1)
		{
			system("cls");
			cout << "\n确认要删除的学生信息：";
			cout << "\n姓名        学号    性别     电话号码      通讯地址  \n";
			cout.setf(ios::left);
			cout << setw(10) << stud.name << " "
				<< setw(10) << stud.number << " "
				<< setw(4) << stud.sex << " "
				<< setw(15) << stud.phnum << " "
				<< setw(50) << stud.address << endl;
			del_stud = stud;
			cout << "\n是否确认(是y/否n)：";
			cin >> del;
			if (del == "y" || del == "Y")break;
			else if (del == "n" || del == "N")break;
		}
	}
	else if (YorN == 'n')
	{
		cout << "\n对不起，找不到该联系人！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n 菜单\n【2】重新输入\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "2")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		cout<<"出错！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n菜单\n【3】显示所有联系人\n【8】返回主菜单\n【0】退出程序\n \n选项：";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}


	if (del == "Y" || del == "y")
	{
		move_ex("tongxunlu.txt", "beifen.txt", del_stud);
		move("beifen.txt", "tongxunlu.txt");
		cout<<"\n删除成功！";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n 菜单\n【3】显示所有联系人\n【8】返回主菜单\n【0】退出程序\n选项：";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
	else if (del == "n" || del == "N")
	{
		string i;
		while (1)
		{
			system("cls");
			cout << "\n 菜单\n【8】返回主菜单\n【0】退出程序\n选项：";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "选项错误！\n";
				Sleep(1500);
			}
		}
	}
}


string book::checknum(char* s_stud)   //检查合法性
{
	ifstream infile;
	infile.open("tongxunlu.txt");
	string infilenum = checkfile(infile);
	if ("n" != infilenum)
		return infilenum;

	char YorN = 'n';   //是否找到相同的学号
	while (!infile.eof())
	{
		infile >> stud.name
			>> stud.number
			>> stud.sex
			>> stud.phnum
			>> stud.address;
		if (strcmp(s_stud, stud.number) == 0)
		{
			return "y";
		}
		if (infile.eof())
		{
			return "n";
		}
	}
}


string move(string a, string b)
{
	student mstud;
	ifstream ifile;
	ofstream ofile;
	ifile.open(a, ios::in);
	string ifilenum = checkfile(ifile);
	if ("n" != ifilenum)
		return ifilenum;
	ofile.open(b, ios::out);
	string ofilenum = checkfile(ofile);
	if ("n" != ofilenum)
		return ofilenum;

	while (!ifile.eof())
	{
		ifile >> mstud.name
			>> mstud.number
			>> mstud.sex
			>> mstud.phnum
			>> mstud.address;
		if (ifile.eof())
		{
			break;
		}
		ofile.setf(ios::left);
		ofile << setw(10) << mstud.name << " "
			<< setw(10) << mstud.number << " "
			<< setw(3) << mstud.sex << " "
			<< setw(15) << mstud.phnum << " "
			<< setw(50) << mstud.address
			<< '\n';
	}


	return "n";
}


string move_ex(string a, string b, student ex_stud)
{
	student mstud;
	ifstream ifile;
	ofstream ofile;
	ifile.open(a, ios::in);
	string ifilenum = checkfile(ifile);
	if ("n" != ifilenum)
		return ifilenum;
	ofile.open(b, ios::out);
	string ofilenum = checkfile(ofile);
	if ("n" != ofilenum)
		return ofilenum;

	while (!ifile.eof())
	{
		ifile >> mstud.name
			>> mstud.number
			>> mstud.sex
			>> mstud.phnum
			>> mstud.address;
		if (strcmp(mstud.name, ex_stud.name) == 0 && strcmp(mstud.number, ex_stud.number) == 0)
			continue;
		if (ifile.eof())
		{
			break;
		}
		ofile.setf(ios::left);
		ofile << setw(10) << mstud.name << " "
			<< setw(10) << mstud.number << " "
			<< setw(3) << mstud.sex << " "
			<< setw(15) << mstud.phnum << " "
			<< setw(50) << mstud.address
			<< '\n';
	}


	return "n";
}


//张三 2014001 M 13412345678 01栋101
//李四 2014002 F 13412345678 01栋102
//王五 2014003 M 13412345678 01栋103
//李梅 2014004 F 13412345678 02栋101

//zhangsan   2014001    m   1111111111      01d101                                            
//lisi       2014002    m   22222222222     01d102                                            
//wangwu     2014003    m   33333333333     01d103                                            

