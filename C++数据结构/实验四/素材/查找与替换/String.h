class String
{
private:
	char *str;										//串
	int size;										//当前长度
	int maxSize;									//最大单元个数

	void GetNext(const String& t, int next[])const;
	int KMPFind(const String& t, int start, int next[])const;
public:
	String(char *s= "");							//构造函数1
	String(int max);								//构造函数2
	String(const String &s);						//拷贝构造函数
	~String(void);									//析构函数
	char& operator[](int n);						//操作符[]重载
	void Insert(int pos, char *t);					//插入
	void Insert(int pos,  String& s);					//插入
	void Delete(int pos, int length);				//删除
	String SubStr(int pos, int length);				//取子串
		

	String& operator= (const String& s);			//操作符=重载1
	String& operator= (char *s);					//操作符=重载2
	//操作符<<重载，定义为友元函数
	friend ostream& operator<< (ostream& ostr, const String& s);
	//操作符>>重载，定义为友元函数
	friend istream& operator>> (istream& istr, String& s);

	int operator== (const String& s)const;			//操作符==重载1
	int operator== (char *s)const;					//操作符==重载2
	//操作符==重载3，定义为友元函数
	friend int operator== (char *strL, const String& strR);
    int getSize(){ return size;};
	String operator+(const String& s);
   String operator+(char* s);
   String operator+(char s);
   friend String operator+(char* s,const String& t);

	//Brute-Force算法的查找
	int FindSubstr(const String& t, int start)const;
	//KMP算法的查找
	int String::KMPFindSubstr(const String& t, int start)const;

};
 
String::String(char *s)		//构造函数1，定义对象并赋初始串值
{
	size = strlen(s);
	maxSize = size + 1;
	str = new char[maxSize];
	strcpy(str, s);			//C++的串拷贝函数调用
}

String::String(int max)		//构造函数2，定义对象并置最大单元个数
{
	maxSize = max;
	size = 0;
	str = new char[maxSize];
}

String::String(const String &s)	//拷贝构造函数，定义对象并拷贝赋值
{
	maxSize = s.maxSize;
	size = s.size;
	str = new char[maxSize];

	for(int i = 0; i < maxSize; i++)
		str[i] = s.str[i];
}

String::~String(void)					//析构函数
{
	delete []str;						//释放内存空间
}
 
void String::Insert(int pos, char *t)			//插入
//在pos位置插入字符串t
{
	int length = strlen(t);
	int i;

	if(pos > size)
	{
		cout << "插入位置参数错！";
		return;	
	}
	
	if(size + length >= maxSize - 1)
	{
		char *p = str;
		str = new char[size + length + 1];	//重新申请更大的内存空间
		for(i = 0; i <= size; i++)
			str[i] = p[i];					//原串值赋值
		delete []p;							//释放原内存空间
	}

	//从size至pos逐位右移字符以空出插入字符的位置
	for(i = size; i >= pos; i--)
		str[i+length] = str[i];

	//从pos至pos+length逐位插入字符
	for(i = 0; i < length; i++)
		str[pos+i] = t[i];

	maxSize = size + length + 1;				//置最大空间个数
	size = size + length;					//置串的当前长度
}
void String::Insert(int pos,  String& t)			//插入
//在pos位置插入字符串t
{
	int length = t.size;
	int i;
	if(pos > size)
	{
		cout << "插入位置参数错！";
		return;	
	}
	
	if(size + length >= maxSize - 1)
	{
		char *p = str;
		str = new char[size + length + 1];	//重新申请更大的内存空间
		for(i = 0; i <= size; i++)
			str[i] = p[i];					//原串值赋值
		delete []p;							//释放原内存空间
	}

	//从size至pos逐位右移字符以空出插入字符的位置
	for(i = size; i >= pos; i--)
		str[i+length] = str[i];

	//从pos至pos+length逐位插入字符
	for(i = 0; i < length; i++)
		str[pos+i] = t[i];

	maxSize = size + length + 1;				//置最大空间个数
	size = size + length;					//置串的当前长度
}
void String::Delete(int pos, int length)		//删除
//从pos位置开始删除长度为length的子字符串
{
	int charsLeft = size-pos;				//剩余的最大长度

	if(pos > size-1) return;	
	
	if(length > charsLeft) length = charsLeft;

	//从pos至size逐位左移以删除长度为length的子字符串
	for(int i = pos; i <= size; i++)
		str[i] = str[i+length];

	size = size - length;					//置串的当前长度
}

String String::SubStr(int pos, int length)	//取子串
//取从pos位置开始的长度为length的子字符串
{
	int charsLeft = size-pos;				//剩余的最大长度
	String  temp;

	if(pos > size-1) return temp;			//返回空串
	
	if(length > charsLeft) length = charsLeft;

	delete []temp.str;
	temp.str = new char[length+1];			//重新申请内存空间

	//保存取出的子字符串
	for(int i = 0; i < length; i++)	temp[i] = str[pos+i];
	
	temp[length] = NULL;						//置结束标记符

	temp.size = length;
	temp.maxSize = length+1;

	return temp;								//返回临时对象temp的值
}

char& String::operator[](int i)					//数组元素操作符[]重载
{
	return str[i];
}

String& String::operator= (const String& s)		//赋值操作符=重载1
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

String& String::operator= (char *s)				//赋值操作符=重载2
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
//输出流操作符<<重载
{
	cout << "s.size = " << s.size << endl;
	cout << "s.maxSize = " << s.maxSize <<endl;
	cout << "s.str = " << s.str << endl;

	return ostr;
}

istream& operator>> (istream& istr, String& s)
//输入流操作符>>重载
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

int String::operator== (const String& s)const	//逻辑等于操作符重载1
//若逻辑等于则返回1；否则返回0
{
	return (strcmp(str, s.str) == 0); 
}

int String::operator== (char *s)const	//逻辑等于操作符重载2
//若逻辑等于则返回1；否则返回0

{
	return (strcmp(str, s) == 0); 
}

int operator== (char *strL, const String& strR)	//逻辑等于操作符重载3
//若逻辑等于则返回1；否则返回0

{
	return (strcmp(strL, strR.str) == 0); 
}

int String::FindSubstr(const String& t, int start)const
//查找主串中从start始的子串t。找到返回t在主串的开始字符下标否则返回-1
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
//求模式串t的next[j]函数值存于数组next中
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
//查找主串中从start始的子串t。找到返回t在主串的开始字符下标否则返回-1
//数组next中存放了子串t的next[j]值
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
//查找主串中从start始的子串t。找到返回t在主串的开始字符下标否则返回-1
{
	int m = t.size;
	int *next ;
	next=new int[m+1];
	GetNext(t, next);
	int v = KMPFind(t, start, next);
	delete []next;
	return v;
}
