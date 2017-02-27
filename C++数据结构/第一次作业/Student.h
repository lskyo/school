#include<string>
#include<iostream>
#include<fstream> 
#include<iomanip>
using namespace std;
class Student
{
private:
	string Class;  //班级
	string Num;    //学号
	string Name;   //姓名
	float C_prog;      //C++ 程序设计成绩
	float Media;       //多媒体技术成绩
	float Eng;         //大学英语成绩
	float Math;        //高等数学成绩
	float Sport;       //大学体育成绩
	float Polity;      //马克思主义成绩
public:
	Student()
	{}
	Student(string CClass,string num,string name,float c_prog,float media,float eng,float math,float sport,float polity)
	{
		Class=CClass;
		Num=num;
		Name=name;
		C_prog=c_prog;
		Media=media;
		Eng=eng;
		Math=math;
		Sport=sport;
		Polity=polity;
	}
	void Input()
	{
		cout<<"请输入学生班级，学号，姓名，C++ 程序设计成绩，多媒体技术成绩，大学英语成绩，高等数学成绩，大学体育成绩和马克思主义成绩：\n";
		try
		{
			cin>>Class>>Num>>Name>>C_prog>>Media>>Eng>>Math>>Sport>>Polity;
		}
		catch (exception e)
		{
			cout << "输入错误！\n";
		}
		ofstream outfile;
		outfile.open("info.txt", ios::out | ios::app);
		if (!outfile)
		{
			cout << "文件打开失败！\n";
			exit(1);
		}
		outfile.setf(ios::left);
		outfile << setw(20) << Num << " "
			<< setw(20) << Class << " "
			<< setw(20) << Name << " "
			<< setw(20) << C_prog << " "
			<< setw(20) << Media << " "
			<< setw(20) << Eng << " "
			<< setw(20) << Math << " "
			<< setw(20) << Sport << " "
			<< setw(20) << Polity
			<< '\n';
		outfile.close();
	}
	float Statistic()
	{
		abc:
		cout << "请输入要求平均成绩的学生的学号：";
		string s_num;
		cin >> s_num;
		Student *p = Lookup(s_num);
		if (p == NULL)
		{
			cout << "\n没有此学号！\n \n";
			goto abc;
		}
		else
		{
			float score = (p->C_prog + p->Media + p->Eng + p->Math + p->Sport + p->Polity) / 6.0;
			cout << "班级: " << setw(20) << p->Class << endl
				<< "学号: " << setw(20) << p->Num << endl
				<< "姓名: " << setw(20) << p->Name << endl
				<< "C++ 程序设计成绩: " << setw(20) << p->C_prog << endl
				<< "多媒体技术成绩: " << setw(20) << p->Media << endl
				<< "大学英语成绩: " << setw(20) << p->Eng << endl
				<< "高等数学成绩: " << setw(20) << p->Math << endl
				<< "大学体育成绩: " << setw(20) << p->Sport << endl
				<< "马克思主义成绩: " << setw(20) << p->Polity << endl
				<< "平均成绩：" << score << endl
				<< endl;
			return score;
		}
	}
	Student* Lookup()
	{
		Student *p = new Student();
		cout << "请输入要查询学生的学号：";
		string num;
		cin >> num;
		ifstream infile;
		infile.open("info.txt");
		if (!infile)
		{
			cout << "\n文件打开失败！\n";
			exit(2);
		}
		char YorN = 'n';
		char line[200];
		while (!infile.eof())
		{
			infile >> p->Num;
			if (num == p->Num)
			{
				YorN = 'y';
				infile >> p->Class
					>> p->Name
					>> p->C_prog
					>> p->Media
					>> p->Eng
					>> p->Math
					>> p->Sport
					>> p->Polity;
				break;
			}
			infile.getline(line, 200);
			if (infile.eof())
			{
				break;
			}
		}
		if (YorN == 'y')
		{
			cout << "\n \n查询到了！\n";
			cout.setf(ios::left);
			cout << "班级: " << setw(20) << p->Class << endl
				<< "学号: " << setw(20) << p->Num << endl
				<< "姓名: " << setw(20) << p->Name << endl
				<< "C++ 程序设计成绩: " << setw(20) << p->C_prog << endl
				<< "多媒体技术成绩: " << setw(20) << p->Media << endl
				<< "大学英语成绩: " << setw(20) << p->Eng << endl
				<< "高等数学成绩: " << setw(20) << p->Math << endl
				<< "大学体育成绩: " << setw(20) << p->Sport << endl
				<< "马克思主义成绩: " << setw(20) << p->Polity << endl
				<< endl;
			return p;
		}
		else
		{
			cout << "\n对不起，找不到该同学！";
			return NULL;
		}
	}
	Student* Lookup(string s_num)
	{
		Student *p = new Student();
		ifstream infile;
		infile.open("info.txt");
		if (!infile)
		{
			cout << "\n文件打开失败！\n";
			exit(2);
		}
		char YorN = 'n';
		char line[200];
		while (!infile.eof())
		{
			infile >> p->Num;
			if (s_num == p->Num)
			{
				YorN = 'y';
				infile >> p->Class
					>> p->Name
					>> p->C_prog
					>> p->Media
					>> p->Eng
					>> p->Math
					>> p->Sport
					>> p->Polity;
				break;
			}
			infile.getline(line, 200);
			if (infile.eof())
			{
				break;
			}
		}
		if (YorN == 'y')
		{
			return p;
		}
		else
		{
			return NULL;
		}
	}
	void Modify()
	{
		cout << "请输入要修改学生的学号：";
		string m_num;
		cin >> m_num;
		fstream iofile;
		iofile.open("info.txt");
		if (!iofile)
		{
			cout << "\n文件打开失败！\n";
			exit(2);
		}
		char YorN = 'n';
		char line[200];
		Student *p = new Student();
		while (!iofile.eof())
		{
			iofile >> p->Num;
			if (m_num == p->Num)
			{
				YorN = 'y';
				iofile >> p->Class
					>> p->Name
					>> p->C_prog
					>> p->Media
					>> p->Eng
					>> p->Math
					>> p->Sport
					>> p->Polity;
				break;
			}
			iofile.getline(line, 200);
			if (iofile.eof())
			{
				break;
			}
		}
		if (YorN == 'y')
		{
			cout << "查询到了！\n";
			cout.setf(ios::left);
			cout << "班级: " << setw(20) << p->Class << endl
				<< "学号: " << setw(20) << p->Num << endl
				<< "姓名: " << setw(20) << p->Name << endl
				<< "C++ 程序设计成绩: " << setw(20) << p->C_prog << endl
				<< "多媒体技术成绩: " << setw(20) << p->Media << endl
				<< "大学英语成绩: " << setw(20) << p->Eng << endl
				<< "高等数学成绩: " << setw(20) << p->Math << endl
				<< "大学体育成绩: " << setw(20) << p->Sport << endl
				<< "马克思主义成绩: " << setw(20) << p->Polity << endl
				<< endl << endl;
			cout << "请重新输入该学生班级，学号，姓名，C++ 程序设计成绩，多媒体技术成绩，大学英语成绩，高等数学成绩，大学体育成绩和马克思主义成绩：\n";
			cin >> p->Class >> p->Num >> p->Name >> p->C_prog >> p->Media >> p->Eng >> p->Math >> p->Sport >> p->Polity;
			iofile.seekg(-171, ios::cur);
			iofile.setf(ios::left);
			iofile << setw(20) << p->Num << " "
				<< setw(20) << p->Class << " "
				<< setw(20) << p->Name << " "
				<< setw(20) << p->C_prog << " "
				<< setw(20) << p->Media << " "
				<< setw(20) << p->Eng << " "
				<< setw(20) << p->Math << " "
				<< setw(20) << p->Sport << " "
				<< setw(20) << p->Polity
				<< '\n';
			iofile.close();
		}
		else
		{
			cout << "\n对不起，找不到该同学！";
		}
	}
	void Output()
	{
		Student *p = new Student();
		fstream iofile;
		iofile.open("info.txt");
		while (!iofile.eof())
		{
			iofile >> p->Num
				>> p->Class
				>> p->Name
				>> p->C_prog
				>> p->Media
				>> p->Eng
				>> p->Math
				>> p->Sport
				>> p->Polity;
			if (iofile.eof())
			{
				break;
			}
			cout << setiosflags(ios::left);
			cout << endl;
			cout << "班级: " << setw(20) << p->Class << endl
			<< "学号: " << setw(20) << p->Num << endl
			<< "姓名: " << setw(20) << p->Name << endl
			<< "C++ 程序设计成绩: " << setw(20) << p->C_prog << endl
			<< "多媒体技术成绩: " << setw(20) << p->Media << endl
			<< "大学英语成绩: " << setw(20) << p->Eng << endl
			<< "高等数学成绩: " << setw(20) << p->Math << endl
			<< "大学体育成绩: " << setw(20) << p->Sport << endl
			<< "马克思主义成绩: " << setw(20) << p->Polity << endl
			<< endl;
		}
		iofile.close();
	}
};