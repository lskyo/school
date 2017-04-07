class String
{
private:
	char *str;										//��
	int size;										//��ǰ����
	int maxSize;									//���Ԫ����

	void GetNext(const String& t, int next[])const;
	int KMPFind(const String& t, int start, int next[])const;
public:
	String(char *s= "");							//���캯��1
	String(int max);								//���캯��2
	String(const String &s);						//�������캯��
	~String(void);									//��������
	char& operator[](int n);						//������[]����
	void Insert(int pos, char *t);					//����
	void Insert(int pos,  String& s);					//����
	void Delete(int pos, int length);				//ɾ��
	String SubStr(int pos, int length);				//ȡ�Ӵ�
		

	String& operator= (const String& s);			//������=����1
	String& operator= (char *s);					//������=����2
	//������<<���أ�����Ϊ��Ԫ����
	friend ostream& operator<< (ostream& ostr, const String& s);
	//������>>���أ�����Ϊ��Ԫ����
	friend istream& operator>> (istream& istr, String& s);

	int operator== (const String& s)const;			//������==����1
	int operator== (char *s)const;					//������==����2
	//������==����3������Ϊ��Ԫ����
	friend int operator== (char *strL, const String& strR);
    int getSize(){ return size;};
	String operator+(const String& s);
   String operator+(char* s);
   String operator+(char s);
   friend String operator+(char* s,const String& t);

	//Brute-Force�㷨�Ĳ���
	int FindSubstr(const String& t, int start)const;
	//KMP�㷨�Ĳ���
	int String::KMPFindSubstr(const String& t, int start)const;

};
 
String::String(char *s)		//���캯��1��������󲢸���ʼ��ֵ
{
	size = strlen(s);
	maxSize = size + 1;
	str = new char[maxSize];
	strcpy(str, s);			//C++�Ĵ�������������
}

String::String(int max)		//���캯��2��������������Ԫ����
{
	maxSize = max;
	size = 0;
	str = new char[maxSize];
}

String::String(const String &s)	//�������캯����������󲢿�����ֵ
{
	maxSize = s.maxSize;
	size = s.size;
	str = new char[maxSize];

	for(int i = 0; i < maxSize; i++)
		str[i] = s.str[i];
}

String::~String(void)					//��������
{
	delete []str;						//�ͷ��ڴ�ռ�
}
 
void String::Insert(int pos, char *t)			//����
//��posλ�ò����ַ���t
{
	int length = strlen(t);
	int i;

	if(pos > size)
	{
		cout << "����λ�ò�����";
		return;	
	}
	
	if(size + length >= maxSize - 1)
	{
		char *p = str;
		str = new char[size + length + 1];	//�������������ڴ�ռ�
		for(i = 0; i <= size; i++)
			str[i] = p[i];					//ԭ��ֵ��ֵ
		delete []p;							//�ͷ�ԭ�ڴ�ռ�
	}

	//��size��pos��λ�����ַ��Կճ������ַ���λ��
	for(i = size; i >= pos; i--)
		str[i+length] = str[i];

	//��pos��pos+length��λ�����ַ�
	for(i = 0; i < length; i++)
		str[pos+i] = t[i];

	maxSize = size + length + 1;				//�����ռ����
	size = size + length;					//�ô��ĵ�ǰ����
}
void String::Insert(int pos,  String& t)			//����
//��posλ�ò����ַ���t
{
	int length = t.size;
	int i;
	if(pos > size)
	{
		cout << "����λ�ò�����";
		return;	
	}
	
	if(size + length >= maxSize - 1)
	{
		char *p = str;
		str = new char[size + length + 1];	//�������������ڴ�ռ�
		for(i = 0; i <= size; i++)
			str[i] = p[i];					//ԭ��ֵ��ֵ
		delete []p;							//�ͷ�ԭ�ڴ�ռ�
	}

	//��size��pos��λ�����ַ��Կճ������ַ���λ��
	for(i = size; i >= pos; i--)
		str[i+length] = str[i];

	//��pos��pos+length��λ�����ַ�
	for(i = 0; i < length; i++)
		str[pos+i] = t[i];

	maxSize = size + length + 1;				//�����ռ����
	size = size + length;					//�ô��ĵ�ǰ����
}
void String::Delete(int pos, int length)		//ɾ��
//��posλ�ÿ�ʼɾ������Ϊlength�����ַ���
{
	int charsLeft = size-pos;				//ʣ�����󳤶�

	if(pos > size-1) return;	
	
	if(length > charsLeft) length = charsLeft;

	//��pos��size��λ������ɾ������Ϊlength�����ַ���
	for(int i = pos; i <= size; i++)
		str[i] = str[i+length];

	size = size - length;					//�ô��ĵ�ǰ����
}

String String::SubStr(int pos, int length)	//ȡ�Ӵ�
//ȡ��posλ�ÿ�ʼ�ĳ���Ϊlength�����ַ���
{
	int charsLeft = size-pos;				//ʣ�����󳤶�
	String  temp;

	if(pos > size-1) return temp;			//���ؿմ�
	
	if(length > charsLeft) length = charsLeft;

	delete []temp.str;
	temp.str = new char[length+1];			//���������ڴ�ռ�

	//����ȡ�������ַ���
	for(int i = 0; i < length; i++)	temp[i] = str[pos+i];
	
	temp[length] = NULL;						//�ý�����Ƿ�

	temp.size = length;
	temp.maxSize = length+1;

	return temp;								//������ʱ����temp��ֵ
}

char& String::operator[](int i)					//����Ԫ�ز�����[]����
{
	return str[i];
}

String& String::operator= (const String& s)		//��ֵ������=����1
{
	if(maxSize < s.maxSize)
	{
		delete []str;
		str = new char[s.maxSize];
	}

	size = s.size;
	maxSize = s.maxSize;
	for(int i = 0; i <= size; i++)
		str[i] = s.str[i];

	return *this;
}

String& String::operator= (char *s)				//��ֵ������=����2
{
	int length = strlen(s);
	if(maxSize < length + 1)
	{
		delete []str;
		str = new char[length+1];
		maxSize = length + 1;
	}

	size = length;
	strcpy(str, s);
	return *this;	
}

String String::operator+(const String& s) {
   int length,index,i;
   length = size+s.size;
   String temp(length);
   index = 0;
   for( i=0;i<=size-1;i++) {
      temp.str[index] = str[i];
      index++;
   }
   for(i=0;i<=s.size-1;i++) {
      temp.str[index] = s.str[i];
      index++;
   }
   temp.str[index] = '\0';
   temp.size = length;
   return temp;
}

String String::operator+(char* s) {
   int length,index;
   length = size+strlen(s);
   String temp(length);
   index = 0;
   for(int i=0;i<=size-1;i++) {
      temp.str[index] = str[i];
      index++;
   }
   
   while(*s) {
      temp.str[index] = *s;
      s++;
      index++;
   }
   temp.str[index] = '\0';
   temp.size = length;
   return temp;
}

String String::operator+(char s) {
   int length,index;
   length = size+1;
    String *temp;
   temp=new String(length);
   index = 0;
   for(int i=0;i<=size-1;i++) {
      temp->str[index] = str[i];
      index++;
   }
   (*temp)[size]=s;
   temp->str[size+1] = '\0';
   temp->size = length;
   return *temp;
}
String operator+(char* s,const String& t) {
   int length,index;
   length = t.size+strlen(s);
   String *temp;
   temp=new String(length);
   index = 0;
   while(*s) {
      temp->str[index] = *s;
      s++;
      index++;
   }

   for(int i=0;i<=t.size-1;i++) {
      temp->str[index] = t.str[i];
      index++;
   }
   
   temp->str[index] = '\0';
   temp->size = length;
   return *temp;
}
ostream& operator<< (ostream& ostr, const String& s)	
//�����������<<����
{
	cout << "s.size = " << s.size << endl;
	cout << "s.maxSize = " << s.maxSize <<endl;
	cout << "s.str = " << s.str << endl;

	return ostr;
}

istream& operator>> (istream& istr, String& s)
//������������>>����
{
	delete []s.str;
	char *temp;
	temp=new char[Max];
	cin.getline(temp,Max);

	s.size=strlen(temp);
	s.maxSize = s.size+1;
	s.str = new char[s.maxSize];

	for(int i = 0; i < s.size; i++)
		s.str[i]=temp[i];
	s.str[s.size] = NULL;
	return istr;
}

int String::operator== (const String& s)const	//�߼����ڲ���������1
//���߼������򷵻�1�����򷵻�0
{
	return (strcmp(str, s.str) == 0); 
}

int String::operator== (char *s)const	//�߼����ڲ���������2
//���߼������򷵻�1�����򷵻�0

{
	return (strcmp(str, s) == 0); 
}

int operator== (char *strL, const String& strR)	//�߼����ڲ���������3
//���߼������򷵻�1�����򷵻�0

{
	return (strcmp(strL, strR.str) == 0); 
}

int String::FindSubstr(const String& t, int start)const
//���������д�startʼ���Ӵ�t���ҵ�����t�������Ŀ�ʼ�ַ��±���򷵻�-1
{
	int i = start, j = 0, v;
   
	while(i < size && j < t.size)
	{   
		if(str[i] == t.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;
			j = 0;
		}
	}

	if(j == t.size) v = i-t.size;
	else v = -1;

	return v;
}

void String::GetNext(const String& t, int next[])const
//��ģʽ��t��next[j]����ֵ��������next��
{
	int j = 1, k = 0;

	next[0] = -1;
	next[1] = 0;
	while(j < t.size-1)
	{
		if(t.str[j] == t.str[k])
		{
			next[j+1] = k+1;
			j++;
			k++;
		}
		else if(k == 0)
		{
			next[j+1] = 0;
			j++;
		}
		else k = next[k];
	}
}


int String::KMPFind(const String& t, int start, int next[])const
//���������д�startʼ���Ӵ�t���ҵ�����t�������Ŀ�ʼ�ַ��±���򷵻�-1
//����next�д�����Ӵ�t��next[j]ֵ
{
	
	int i = start, j = 0, v;

	while(i < size && j < t.size)
	{
		
		if(str[i] == t.str[j])
		{
			i++;
			j++;

		}
		else if(j == 0) i++;
		else j = next[j];
	}

	if(j == t.size) v = i-t.size;
	else v = -1;

	return v;
}

int String::KMPFindSubstr(const String& t, int start)const
//���������д�startʼ���Ӵ�t���ҵ�����t�������Ŀ�ʼ�ַ��±���򷵻�-1
{
	int m = t.size;
	int *next ;
	next=new int[m+1];
	GetNext(t, next);
	int v = KMPFind(t, start, next);
	delete []next;
	return v;
}
