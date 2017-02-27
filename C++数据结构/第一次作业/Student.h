#include<string>
#include<iostream>
#include<fstream> 
#include<iomanip>
using namespace std;
class Student
{
private:
	string Class;  //�༶
	string Num;    //ѧ��
	string Name;   //����
	float C_prog;      //C++ ������Ƴɼ�
	float Media;       //��ý�弼���ɼ�
	float Eng;         //��ѧӢ��ɼ�
	float Math;        //�ߵ���ѧ�ɼ�
	float Sport;       //��ѧ�����ɼ�
	float Polity;      //���˼����ɼ�
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
		cout<<"������ѧ���༶��ѧ�ţ�������C++ ������Ƴɼ�����ý�弼���ɼ�����ѧӢ��ɼ����ߵ���ѧ�ɼ�����ѧ�����ɼ������˼����ɼ���\n";
		try
		{
			cin>>Class>>Num>>Name>>C_prog>>Media>>Eng>>Math>>Sport>>Polity;
		}
		catch (exception e)
		{
			cout << "�������\n";
		}
		ofstream outfile;
		outfile.open("info.txt", ios::out | ios::app);
		if (!outfile)
		{
			cout << "�ļ���ʧ�ܣ�\n";
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
		cout << "������Ҫ��ƽ���ɼ���ѧ����ѧ�ţ�";
		string s_num;
		cin >> s_num;
		Student *p = Lookup(s_num);
		if (p == NULL)
		{
			cout << "\nû�д�ѧ�ţ�\n \n";
			goto abc;
		}
		else
		{
			float score = (p->C_prog + p->Media + p->Eng + p->Math + p->Sport + p->Polity) / 6.0;
			cout << "�༶: " << setw(20) << p->Class << endl
				<< "ѧ��: " << setw(20) << p->Num << endl
				<< "����: " << setw(20) << p->Name << endl
				<< "C++ ������Ƴɼ�: " << setw(20) << p->C_prog << endl
				<< "��ý�弼���ɼ�: " << setw(20) << p->Media << endl
				<< "��ѧӢ��ɼ�: " << setw(20) << p->Eng << endl
				<< "�ߵ���ѧ�ɼ�: " << setw(20) << p->Math << endl
				<< "��ѧ�����ɼ�: " << setw(20) << p->Sport << endl
				<< "���˼����ɼ�: " << setw(20) << p->Polity << endl
				<< "ƽ���ɼ���" << score << endl
				<< endl;
			return score;
		}
	}
	Student* Lookup()
	{
		Student *p = new Student();
		cout << "������Ҫ��ѯѧ����ѧ�ţ�";
		string num;
		cin >> num;
		ifstream infile;
		infile.open("info.txt");
		if (!infile)
		{
			cout << "\n�ļ���ʧ�ܣ�\n";
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
			cout << "\n \n��ѯ���ˣ�\n";
			cout.setf(ios::left);
			cout << "�༶: " << setw(20) << p->Class << endl
				<< "ѧ��: " << setw(20) << p->Num << endl
				<< "����: " << setw(20) << p->Name << endl
				<< "C++ ������Ƴɼ�: " << setw(20) << p->C_prog << endl
				<< "��ý�弼���ɼ�: " << setw(20) << p->Media << endl
				<< "��ѧӢ��ɼ�: " << setw(20) << p->Eng << endl
				<< "�ߵ���ѧ�ɼ�: " << setw(20) << p->Math << endl
				<< "��ѧ�����ɼ�: " << setw(20) << p->Sport << endl
				<< "���˼����ɼ�: " << setw(20) << p->Polity << endl
				<< endl;
			return p;
		}
		else
		{
			cout << "\n�Բ����Ҳ�����ͬѧ��";
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
			cout << "\n�ļ���ʧ�ܣ�\n";
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
		cout << "������Ҫ�޸�ѧ����ѧ�ţ�";
		string m_num;
		cin >> m_num;
		fstream iofile;
		iofile.open("info.txt");
		if (!iofile)
		{
			cout << "\n�ļ���ʧ�ܣ�\n";
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
			cout << "��ѯ���ˣ�\n";
			cout.setf(ios::left);
			cout << "�༶: " << setw(20) << p->Class << endl
				<< "ѧ��: " << setw(20) << p->Num << endl
				<< "����: " << setw(20) << p->Name << endl
				<< "C++ ������Ƴɼ�: " << setw(20) << p->C_prog << endl
				<< "��ý�弼���ɼ�: " << setw(20) << p->Media << endl
				<< "��ѧӢ��ɼ�: " << setw(20) << p->Eng << endl
				<< "�ߵ���ѧ�ɼ�: " << setw(20) << p->Math << endl
				<< "��ѧ�����ɼ�: " << setw(20) << p->Sport << endl
				<< "���˼����ɼ�: " << setw(20) << p->Polity << endl
				<< endl << endl;
			cout << "�����������ѧ���༶��ѧ�ţ�������C++ ������Ƴɼ�����ý�弼���ɼ�����ѧӢ��ɼ����ߵ���ѧ�ɼ�����ѧ�����ɼ������˼����ɼ���\n";
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
			cout << "\n�Բ����Ҳ�����ͬѧ��";
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
			cout << "�༶: " << setw(20) << p->Class << endl
			<< "ѧ��: " << setw(20) << p->Num << endl
			<< "����: " << setw(20) << p->Name << endl
			<< "C++ ������Ƴɼ�: " << setw(20) << p->C_prog << endl
			<< "��ý�弼���ɼ�: " << setw(20) << p->Media << endl
			<< "��ѧӢ��ɼ�: " << setw(20) << p->Eng << endl
			<< "�ߵ���ѧ�ɼ�: " << setw(20) << p->Math << endl
			<< "��ѧ�����ɼ�: " << setw(20) << p->Sport << endl
			<< "���˼����ɼ�: " << setw(20) << p->Polity << endl
			<< endl;
		}
		iofile.close();
	}
};