#include <iostream>
using namespace std;
#include <string>        //����strlen(s)�󴮳��Ⱥ���
//Լ�����ڱ�֤��ȷǰ���£��ɶ�char*ʹ��string.h�к���

class MyString                                             //�ַ�����
{
  private:                                                 //˽�г�Ա
    char *element;                                         //��̬�ַ�����
    int length;                                            //��������
    int n;                                                 //������
    void init(char *s="", int length=32);                  //��ʼ����������ָ����ֵ������

  public:
    MyString(char *s="", int length=32);                   //���촮����sָ��char*��������lengthָ������
    MyString(char ch);                                     //���촮����chָ���ַ���ֵ
    MyString(MyString &str);                               //�������캯�������
    MyString& operator=(MyString &str);                    //����=��ֵ����������
    MyString& operator=(char *str);                        //֧�ָ�ֵΪ�ַ�������
    ~MyString();                                           //��������

    bool empty();                                          //�жϴ��Ƿ�Ϊ��
    int count();                                           //���ش�����
    char& operator[](int i);                               //�����±�����������õ�i����0�����ַ�
    friend ostream& operator<<(ostream& out, MyString &s); //����<<����������

    bool operator==(MyString &str);                        //����==��������Ƚ������Ƿ����
    bool operator!=(MyString &str);                        //����!=��������Ƚ������Ƿ����
    bool operator<(MyString &str);                         //����<��������Ƚ�������С
    bool operator<=(MyString &str);
    bool operator>(MyString &str);
    bool operator>=(MyString &str);
    void reverse();                                        //����ǰ����ת

    MyString substring(int i, int len);                    //���شӵ�i���ַ���ʼ����Ϊlen���Ӵ�
    MyString substring(int i);                             //���شӵ�i���ַ���ʼ����β���Ӵ�
    void insert(int i, MyString &str);                     //�ڵ�i���ַ�������str��
    void insert(int i, char ch);                           //����ch��Ϊ��i���ַ�
    void insert(int i, char* str);                         //�ڵ�i���ַ�������str��
    void operator+=(MyString &str);                        //���أ�=��������ڵ�ǰ��֮������str��
    void operator+=(char ch);                              //���أ�=��������ڵ�ǰ��֮������ch�ַ�
    void operator+=(char *str);                            //���أ�=��������ڵ�ǰ��֮������str��
    MyString operator+(MyString &str);                     //���أ�����������ص�ǰ����str���Ӻ�Ĵ�
    void remove(int i, int len);                           //ɾ���ӵ�i���ַ���ʼ����Ϊlen���Ӵ�
    void remove(int i);                                    //ɾ���ӵ�i���ַ���ʼ����β���Ӵ�
};

//1. �ַ����Ļ�������
//��1�����졢����
void MyString::init(char *s, int length)                   //��ʼ������sָ����ֵ��lengthָ����Ĭ�ϣ���������
{
    this->n = strlen(s);                                   //���s�����ȣ�strlen(s)������string.h��
    this->length = (n*2)>length ? (n*2) : length;          //ָ������������ȡn*2��length���ֵ
    this->element = new char[this->length];                //�����ַ�����
    for (int i=0; s[i]!='\0'; i++)                         //����s�ַ�����strcpy(*,*)����
       this->element[i] = s[i]; 
    this->element[this->n] = '\0'; 
}
//���촮����sָ����ֵ������char*���͵��ַ���������lengthָ��������������Ĭ��ֵ
MyString::MyString(char *s, int length) 
{
    this->init(s, length);
//    cout<<s<<endl;
}
MyString::MyString(char ch)                                //���촮����chָ���ַ���ֵ
{
    this->init("");
    this->n = 1;
    this->element[0] = ch; 
    this->element[1] = '\0'; 
}
MyString::MyString(MyString &str)                          //�������캯�������
{
    this->init(str.element);
}
MyString& MyString::operator=(MyString &str)               //����=��ֵ����������
{
    this->~MyString();                                     //���������������ͷ�element����ռ�
    this->init(str.element);                               //ȫ��������������ռ�
    return *this;
}
MyString& MyString::operator=(char *str)                   //����=��ֵ����������
{
    this->~MyString();                                     //���������������ͷ�element����ռ�
    this->init(str);                                       //ȫ��������������ռ�
    return *this;
}

MyString::~MyString()                                      //��������
{
//    cout<<"MyString����"<<*this<<"��n="<<count<<"��length="<<length<<endl;
    delete []this->element;
}

//��˼����3-1��
//��2���пա������ȡ�����ʹ�ȡ�ַ�
bool MyString::empty()                                   //�жϴ��Ƿ�Ϊ��
{
    return this->n==0;
}
int MyString::count()                                      //���ش�����
{
    return this->n;
}

//�����±�����������õ�i��0��i<n�����ַ�����i<0��i��n�����׳��쳣
char& MyString::operator[](int i)
{
    if (i>=0 && i<this->n)
        return this->element[i];                           //����Ԫ������
    throw out_of_range("����iָ��Ԫ����ų�����Χ");       //�׳�C++ STL��ΧԽ���쳣
}

ostream& operator<<(ostream& out, MyString &str)           //����<<����������
{
    out<<"\""<<str.element<<"\"";                          //�����֧�����ַ�ָ����ʽ����ַ�����
    return out;
}

//��ϰ3.1��  
//��6����ϵ���㣬char֧��==��!=��>��>=��<��<=����
bool MyString::operator==(MyString &str)                   //����==��������Ƚ��������Ƿ����
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return true;
    if (this->n != str.n)                                  //���¿������������Ƚ����߳����Ƿ���ȣ����Ƚ���������
        return false;
    for (int i=0; i<this->n; i++)                          //�Ƚ��������������ַ��Ƿ��Ӧ���
        if (this->element[i] != str.element[i])
            return false;
    return true;
}
bool MyString::operator!=(MyString &str)                   //����!=��������Ƚ��������Ƿ����
{
    return !(*this==str);
}

bool MyString::operator<(MyString &str)                    //����<��������Ƚ���������С
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return false;
    int i=0;
    while (i<this->n && i<str.n)
        if (this->element[i]==str.element[i])              //��Ӧ�ַ����ʱ�����Ƚ�
            i++;
        else
            return this->element[i]<str.element[i];        //���׸�������ַ�ȷ�������Ĵ�С
    return this->n < str.n;                        //����ǰ�����ַ���Ӧ��ȣ���Ҫ�ȳ��ȡ�*this���϶�ʱ����1���������ȳ�
}   

bool MyString::operator<=(MyString &str)                   //����<=��������Ƚ���������С
{
    if (this==&str)                                        //ָ��Ƚϣ���������������ͬһ��ʵ��ʱ
        return true;
    int i=0;
    while (i<this->n && i<str.n)
        if (this->element[i]==str.element[i])                    //��Ӧ�ַ����ʱ�����Ƚ�
            i++;
        else
            return this->element[i]<str.element[i];
    return this->n <= str.n;                       //�����ȳ���*this���϶�ʱ����1
}   

bool MyString::operator>(MyString &str)                    //����>��������Ƚ��������Ĵ�С
{
    return !(*this <= str);
}

bool MyString::operator>=(MyString &str)                   //����>=��������Ƚ��������Ĵ�С
{
    return !(*this < str);
}

void MyString::reverse()                                   
{
  //����ǰ����ת
  //�������ж��Ƿ�Ϊ����
  //��������ɴ�������
	char t;
	for(int i=0;i<n/2;i++)
	{
		t=element[i];
		element[i]=element[n-i-1];
		element[n-i-1]=t;
	}
}

//2.  ���Ӵ��Ĳ���
//��1�����Ӵ�
//���شӵ�i��0��i<n�����ַ���ʼ����Ϊlen��>=0�����Ӵ���len�ݴ���i+len>������n��
//���Ƶ���β����i<0��i��n����len<0���׳��쳣
MyString MyString::substring(int i, int len)
{
    if (i>=0 && i<n && len>=0)
    {
        if (len>n-i)                                       //len�ݴ�
            len=n-i;                                       //i+len��ൽ��β
        MyString sub;                                      //�����մ�����
        sub.n = len;                                       //��len=0���򷵻ؿմ�
        for (int j=0; j<len; j++)
            sub.element[j] = this->element[i+j];
        sub.element[len]='\0';
        return sub;                                        //ִ��MyString�Ŀ������캯��
    }
    else
        throw out_of_range("����iָ���ַ���Ż�len������Χ");//�׳�C++ STL��ΧԽ���쳣
}
MyString MyString::substring(int i)                        //���شӵ�i���ַ���ʼ����β���Ӵ�
{
    return substring(i, this->n-i+1);
}

//��2�����봮
//�ڵ�i����0�����ַ�������str����i�ݴ���i<0����������ǰ����i��n�����������
void MyString::insert(int i, MyString &str) 
{
    if (str.n==0)  return;                                 //��strΪ�մ����򲻲���
    if (i<0)  i=0;                                         //����λ��i�ݴ���ǰ
    if (i>n)  i=n;                                         //���
    char *temp = this->element;
    if (this->length <= this->n+str.n)                     //����ǰ�����ַ�����ռ䲻�㣬����������
    {
        this->length = (this->n+str.n+1)*2;                //ָ����������
        this->element = new char[this->length];            //���������ַ�����ռ�
        for (int j=0; j<i; j++)                            //���Ƶ�ǰ��ǰi-1���ַ�
            this->element[j] = temp[j];
    }
    for (int j=this->n; j>=i; j--)                         //��i��ʼ����β���Ӵ�������'\0'������ƶ��������ǴӺ���ǰ
        this->element[j+str.n] = temp[j];                  //�ƶ������ǲ��봮����
    if (temp!=this->element)
        delete[] temp;                                     //�ͷ�ԭ����ռ�
    for (int j=0; j<str.n; j++)                            //����str��
        this->element[i+j] = str.element[j];
    this->n += str.n;
}
void MyString::insert(int i, char ch)                      //����ch��Ϊ��i���ַ���i���Խ���ݴ�
{
    this->insert(i, MyString(ch));
}
void MyString::insert(int i, char* str)                    //�ڵ�i���ַ�������str��������i���Խ���ݴ�
{
    this->insert(i, MyString(str));
}

//��˼����3-2�����Ӵ�
//����+=��������ڵ�ǰ��֮������str��*this += str���ı䵱ǰ��
void MyString::operator+=(MyString &str)
{
    this->insert(this->n, str);
}
void MyString::operator+=(char ch)                      //����ch�ַ�
{
    insert(this->n, MyString(ch));
}
void MyString::operator+=(char* str)                    //����str����ϰ��3
{
    insert(this->n, MyString(str));
}

//����+����������������������´���result=*this+str�����ı䵱ǰ��*this
MyString MyString::operator+(MyString &str)
{
    MyString result(*this);                                //���Ƶ�ǰ��*this��ִ��MyString�Ŀ������캯��
    result.insert(this->n, str);
    return result;                                         //���ش�����ִ��MyString�Ŀ������캯��
}

//��3�� ɾ���Ӵ�
//ɾ���ӵ�i��0��i<n�����ַ���ʼ����Ϊlen��>0�����Ӵ�����i��len������Ч���򲻲�����
//len�ݴ���i+len>������n����ɾ������β
void MyString::remove(int i, int len)
{
    if (i<0 || i>=this->n || len<0)
        return;
    if (len>n-i)                                           //len�ݴ���i+len>������n����ɾ������β
        len = n-i;
    for (int j=i+len; j<=n; j++)                           //��i+len��ʼ����β���Ӵ�������'\0'����ǰ�ƶ�len���ַ�
        this->element[j-len] = element[j];
    this->n -= len;
}
void MyString::remove(int i)                               //ɾ���ӵ�i����0�����ַ���ʼ����β���Ӵ�
{
    remove(i, this->n-i);
}


