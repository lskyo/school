#include<iostream>
#include<stdlib.h> //Ϊ��ʹ��exit()����
#include<Windows.h> //Ϊ��ʹ��sleep()����
#include<iomanip>
#include<fstream> 
#include<string>

using namespace std;


struct student
{        
	char name[10]; //����
	char number[10];  //ѧ��
	char sex;  //�Ա�
	char phnum[15];  //�ֻ�����
	char address[50];  //ͨѶ��ַ
};


class book
{
	student stud; //���ݳ�Ա
public:
	book()   //���캯��
	{
		cout << "\n \n \n \n \n \n \n \n";
		cout << "       -----------------------------------------------------------------\n"
			<< "\n                                 ѧ��ͨѶ¼\n \n"
			<< "       -----------------------------------------------------------------\n";
		cout << "\n \n \n \n \n \n \n";
		cout << "                                                         ���ǻ�\n";
		cout << "\n \n \n \n \n \n \n";
		Sleep(1500);
		system("cls");
	}
	string inter_face();    //8��ҳ�˵�
	string add_person();    //1�����ϵ��
	string del_person();    //2ɾ����ϵ��
	string show_all();      //3��ʾ������ϵ��
	string alter();         //4�޸���Ϣ
	string select();        //5��ѯ��ϵ��
	string save_new();      //6���������ӵ���ϵ��
	string checknum(char* number);  //���ѧ���Ƿ�Ψһ
	
	void tuichu();       //0�˳�����
};

string checkfile(ofstream &outfile);//����ļ���
string checkfile(ifstream &infile);//����ļ���
string checkfile(fstream &iofile);//����ļ���
string move_ex(string a, string b, student ex_stud);//�ļ����ݴ�a���Ƶ�b������ex_stud����
string move(string a, string b);//�ļ����ݴ�a���Ƶ�b


void main()
{
	book book1; //ͨѶ¼
	string cdxx;   //�˵�ѡ��
	cdxx = book1.inter_face();
	while (1)
	{
		if(cdxx == "1")cdxx = book1.add_person();  //1�����ϵ��
		else if(cdxx == "2")cdxx = book1.del_person();  //2ɾ����ϵ��
		else if (cdxx == "3")cdxx = book1.show_all();    //3��ʾ������ϵ�� 
		else if (cdxx == "4")cdxx = book1.alter();      //4�޸���Ϣ
		else if (cdxx == "5")cdxx = book1.select();      //5��ѯ��Ϣ
		else if (cdxx == "6")cdxx = book1.save_new();    //6������ϵ��
		else if (cdxx == "8")cdxx = book1.inter_face();  //8���˵�
		else if (cdxx == "0")book1.tuichu();            //0�˳�����
		else
			{
				cout << "ѡ�����\n"; 
				Sleep(1500); 
				cdxx = book1.inter_face(); 
			}
	}
}



string checkfile(ofstream &outfile)
{
	if (!outfile)
	{
		cout << "\n \n �ļ���ʧ�ܣ�\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n �˵�\n��8���������˵�\n��0���˳�����\nѡ�";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
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
		cout << "\n \n �ļ���ʧ�ܣ�\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n �˵�\n��8���������˵�\n��0���˳�����\nѡ�";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
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
		cout << "\n \n �ļ���ʧ�ܣ�\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n �˵�\n��8���������˵�\n��0���˳�����\nѡ�";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
	else
		return "n";
}


string book::inter_face()      //8��ҳ
{
	
	string i;
	while (1)
	{
		system("cls");
		cout << "\n \n";
		cout << " �˵�\n"
			<< "��1�������ϵ��\n��2��ɾ����ϵ��\n��3����ʾ������ϵ��\n��4���޸���Ϣ\n"
			<< "��5����ѯ��ϵ��\n��0���˳�����\n \nѡ�";
		cin >> i;
		if (i == "1")return i;           //1�����ϵ��
		else if (i == "2")return i;      //2ɾ����ϵ��
		else if (i == "3")return i;      //3��ʾ������ϵ�� 
		else if (i == "4")return i;      //4�޸���Ϣ
		else if (i == "5")return i;      //5��ѯ��Ϣ
		else if (i == "0")return i;      //0�˳�����
		else
		{
			cout << "ѡ�����\n";
			Sleep(1500);
		}
	}
}


void book::tuichu()  //0�˳�����
{
	cout << "\n�����ѽ�����\n \n";
	Sleep(1500);
	exit(1);
}


string book::add_person() //1�����ϵ��
{		
	string i;
	system("cls");
	cout << "\n \n������ѧ��������ѧ�ţ��Ա���M/ŮF�����ֻ����룬ͨѶ��ַ\n"
		<< "���磺���� 2014001 M 13412345678 01��101\n \n������\n";
	cout << "������";
	cin >> stud.name;
	cout << "ѧ�ţ�";
	cin >> stud.number;
	cout << "�Ա���M/ŮF����";
	cin >> stud.sex;
	cout << "�ֻ����룺";
	cin >> stud.phnum; 
	cout << "ͨѶ��ַ��";
	cin >> stud.address;
	while (1)
	{
		cout << "\n \n";
		cout << "\n �˵�\n��6�����������ӵ���ϵ��\n��8��ȡ�����������˵�\n��0���˳�����\n \nѡ�";
		cin >> i;
		if (i == "6")return i;           
		else if (i == "8")return i;     
		else if (i == "0")return i;       
		else
		{
			cout << "ѡ�����\n";
			Sleep(1500);
			system("cls");
		}
	}
}


string book::save_new()  //6���������ӵ���ϵ��
{
	ofstream outfile;
	string yorn;        //�����Ƿ�������
	student new_stud = stud;

	outfile.open("tongxunlu.txt", ios::out | ios::app);
	string outfilenum = checkfile(outfile);
	if ("n" != outfilenum)
		return outfilenum;

	yorn = checknum(new_stud.number);         //���ѧ���Ƿ�Ψһ����n����y
	if (yorn == "n")                          //��ѧ��Ψһ,�������tongxunlu.txt
	{
		outfile.setf(ios::left);
		outfile << setw(10) << new_stud.name << " "
			<< setw(10) << new_stud.number << " "
			<< setw(3) << new_stud.sex << " "
			<< setw(15) << new_stud.phnum << " "
			<< setw(50) << new_stud.address
			<< '\n';
		cout << "\n������ϵ���Ѿ����棡\n";
		outfile.close();

		/*   ִ�б��ݲ���   */
		move("tongxunlu.txt", "beifen.txt");

		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n �˵�\n��1�����������ϵ��\n��3����ʾ������ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "1")return i;
			else if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
	else if (yorn == "y")                //��ѧ���Ѵ���
	{
		cout << "\n��ѧ���Ѵ��ڣ�\n";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n �˵�\n��1�����������ϵ��\n��3����ʾ������ϵ��\n��5����ѯ��ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "1")return i;
			else if (i == "3")return i;
			else if (i == "5")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		return yorn;
	}
}


string book::show_all()   //3��ʾ������ϵ��
{
	int num = 1;
	system("cls");
	ifstream infile;
	infile.open("tongxunlu.txt", ios::_Nocreate | ios::in);
	string infilenum = checkfile(infile);
	if ("n" != infilenum)
		return infilenum;
	cout << "\n    ����       ѧ��      �Ա�   �绰����       ͨѶ��ַ  \n";
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
		cout << setw(2) << num << "��";
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
		cout << "\n �˵�\n��1�������ϵ��\n��2��ɾ����ϵ��\n��4���޸���Ϣ\n��5����ѯ��ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
		cin >> i;
		if (i == "1")return i;
		else if (i == "2")return i;
		else if (i == "4")return i;
		else if (i == "5")return i;
		else if (i == "8")return i;
		else if (i == "0")return i;
		else
		{
			cout << "ѡ�����\n";
			Sleep(1500);		
			system("cls");
		}
	}
}


string book::select()  //5��ѯ��ϵ��
{
	char YorN = 'n';   //�Ƿ��ҵ���ͬѧ
	system("cls");
	cout << "\n \n������Ҫ��ѯѧ����������ѧ�ţ�";
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
		cout << "\n����        ѧ��    �Ա�     �绰����      ͨѶ��ַ  \n";
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
			cout << "\n \n �˵�\n��2��ɾ����ϵ��\n��4���޸���Ϣ\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "2")return i;
			else if (i == "4")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
				system("cls");
			}
		}
	}
	else
	{
		cout << "\n�Բ����Ҳ�����ͬѧ��";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n";
			cout << "\n \n �˵�\n��5����������\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "5")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
}


string book::alter() //4�޸���Ϣ
{
	student del_stud;
	student new_stud;
	char YorN = 'n';


	system("cls");
	cout << "\n��������Ҫ�޸ĵ�ѧ��������ѧ�ţ�";
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
		cout << "ȷ�ϱ��޸�ѧ����Ϣ��";
		cout << "\n����        ѧ��    �Ա�     �绰����      ͨѶ��ַ  \n";
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


		cout << "\n�����������ѧ����������ѧ�ţ��Ա���M/ŮF�����ֻ����룬ͨѶ��ַ\n"
			<< "���磺���� 2014001 M 13412345678 01��101\n \n������\n";
		cout << "������";
		cin >> stud.name;
		cout << "ѧ�ţ�";
		cin >> stud.number;
		cout << "�Ա���M/ŮF����";
		cin >> stud.sex;
		cout << "�ֻ����룺";
		cin >> stud.phnum;
		cout << "ͨѶ��ַ��";
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
			cout << "\n�޸ĳɹ���";
			outfile.close();
			move("tongxunlu.txt", "beifen.txt");
			Sleep(1500);
			string i;
			while (1)
			{
				system("cls");
				cout << "\n \n";
				cout << "\n �˵�\n��3����ʾ������ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
				cin >> i;
				if (i == "3")return i;
				else if (i == "8")return i;
				else if (i == "0")return i;
				else
				{
					cout << "ѡ�����\n";
					Sleep(1500);
				}
			}
		}
		else if (yorn2 == "y")
		{
			cout << "\nѧ���ظ����޸�ʧ�ܣ�";
			Sleep(1500);
			string i;
			outfile.close();
			while (1)
			{
				system("cls");
				cout << "\n \n";
				cout << "\n �˵�\n��4�������޸�\n��8��ȡ���޸Ĳ��������˵�\n��0���˳�����\n \nѡ�";
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
					cout << "ѡ�����\n";
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
		cout << "\n�Բ����Ҳ�����ͬѧ��";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n �˵�\n��4����������\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "4")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		cout<<"����";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n�˵�\n��3����ʾ������ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
}


string book::del_person() //2ɾ����ϵ��
{
	char YorN = 'n';
	string del;
	char del_person[20];
	student del_stud;

	system("cls");
	cout << "\n������Ҫɾ����ѧ��������ѧ�ţ�";
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
			cout << "\nȷ��Ҫɾ����ѧ����Ϣ��";
			cout << "\n����        ѧ��    �Ա�     �绰����      ͨѶ��ַ  \n";
			cout.setf(ios::left);
			cout << setw(10) << stud.name << " "
				<< setw(10) << stud.number << " "
				<< setw(4) << stud.sex << " "
				<< setw(15) << stud.phnum << " "
				<< setw(50) << stud.address << endl;
			del_stud = stud;
			cout << "\n�Ƿ�ȷ��(��y/��n)��";
			cin >> del;
			if (del == "y" || del == "Y")break;
			else if (del == "n" || del == "N")break;
		}
	}
	else if (YorN == 'n')
	{
		cout << "\n�Բ����Ҳ�������ϵ�ˣ�";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n �˵�\n��2����������\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "2")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
	else
	{
		cout<<"����";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n \n�˵�\n��3����ʾ������ϵ��\n��8���������˵�\n��0���˳�����\n \nѡ�";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}


	if (del == "Y" || del == "y")
	{
		move_ex("tongxunlu.txt", "beifen.txt", del_stud);
		move("beifen.txt", "tongxunlu.txt");
		cout<<"\nɾ���ɹ���";
		Sleep(1500);
		string i;
		while (1)
		{
			system("cls");
			cout << "\n �˵�\n��3����ʾ������ϵ��\n��8���������˵�\n��0���˳�����\nѡ�";
			cin >> i;
			if (i == "3")return i;
			else if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
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
			cout << "\n �˵�\n��8���������˵�\n��0���˳�����\nѡ�";
			cin >> i;
			if (i == "8")return i;
			else if (i == "0")return i;
			else
			{
				cout << "ѡ�����\n";
				Sleep(1500);
			}
		}
	}
}


string book::checknum(char* s_stud)   //���Ϸ���
{
	ifstream infile;
	infile.open("tongxunlu.txt");
	string infilenum = checkfile(infile);
	if ("n" != infilenum)
		return infilenum;

	char YorN = 'n';   //�Ƿ��ҵ���ͬ��ѧ��
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


//���� 2014001 M 13412345678 01��101
//���� 2014002 F 13412345678 01��102
//���� 2014003 M 13412345678 01��103
//��÷ 2014004 F 13412345678 02��101

//zhangsan   2014001    m   1111111111      01d101                                            
//lisi       2014002    m   22222222222     01d102                                            
//wangwu     2014003    m   33333333333     01d103                                            

