class SeqList
{
protected:
	DataType *list;							//����
	int maxSize;							//���Ԫ�ظ���
	int size;								//��ǰԪ�ظ���
public:
	SeqList(int max=0);		      			//���캯��
	~SeqList(void);		      				//��������

	int Size(void) const;					//ȡ��ǰ����Ԫ�ظ���
	void Insert(const DataType& item, int i);//����
	DataType Delete(const int i);			//ɾ��
    void Print();                           //�������Ԫ��
	DataType GetData(int i) const;			//ȡ����Ԫ��
	void Reverse();                         //ʵ�ֽ�˳����е�Ԫ�����ò������˳�����
	int Find(DataType x);                   //����Ԫ��x���ɹ������±꣬���ɹ�����-1
};

SeqList::SeqList(int max)					//���캯��
{
	maxSize = max;
	size = 0;
	list = new DataType[maxSize];
}
SeqList::~SeqList(void)						//��������
{
	delete []list;
}							

int SeqList::Size(void) const			//ȡ��ǰ����Ԫ�ظ���
{
	return size;
}

void SeqList::Insert(const DataType& item, int i)	//����
//��ָ��λ��iǰ����һ������Ԫ��item
{
	if (size == maxSize)
	{
 		cout << "˳��������޷����룡" << endl;
		exit(0);
	}
	if(i < 0 || i > size)					//������ȷ����ж�
	{
		cout << "����iԽ�����!" << endl;
		exit(0);
	}

	//��size-1��i���Ԫ�غ���
	for(int j = size; j > i; j--) list[j] = list[j-1];
        
	list[i] = item;						//��iλ�ò���item	
	size++;								//��ǰԪ�ظ�����1
}

 void SeqList::Print()  
 {

   for(int i=0;i<=size-1;i++) cout<<list[i]<<"  ";
   cout<<endl;
 }
 
int SeqList::Find(DataType x)
{
 //����Ԫ��x���ɹ������±꣬���ɹ�����-1��
 //�벹�����
}

void SeqList::Reverse()
{
 //ʵ�ֽ�˳����е�����Ԫ�����ò������˳����С�
 //�벹�����
}

DataType SeqList::Delete(const int i)				//ɾ��
//ɾ��ָ��λ��i������Ԫ�أ�ɾ����Ԫ���ɺ�������
{
	if (size == 0)
	{
		cout << "˳����ѿ���Ԫ�ؿ�ɾ��" << endl;
		exit(0);
	}
	if(i < 0 || i > size - 1)			//������ȷ����ж�
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}

	DataType x = list[i];				//ȡ��Ҫɾ����Ԫ��

	//��i+1��size-1���Ԫ��ǰ��
	for(int j = i;j < size-1; j++) list[j] = list[j+1];

	size--;								//��ǰԪ�ظ�����1
	return x;							//����ɾ����Ԫ��
}

DataType SeqList::GetData(int i) const	//ȡ����Ԫ��
//ȡλ��i������Ԫ�أ�ȡ��������Ԫ���ɺ�������
{
	if(i < 0 || i > size - 1)			//������ȷ����ж�
	{
		cout << "����iԽ�����!" << endl;
		exit(0);
	}

	return list[i];						//����ȡ����Ԫ��
}

