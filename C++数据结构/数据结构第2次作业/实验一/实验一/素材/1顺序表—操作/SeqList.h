class SeqList
{
protected:
	DataType *list;							//数组
	int maxSize;							//最大元素个数
	int size;								//当前元素个数
public:
	SeqList(int max=0);		      			//构造函数
	~SeqList(void);		      				//析构函数

	int Size(void) const;					//取当前数据元素个数
	void Insert(const DataType& item, int i);//插入
	DataType Delete(const int i);			//删除
    void Print();                           //输出数据元素
	DataType GetData(int i) const;			//取数据元素
	void Reverse();                         //实现将顺序表中的元素逆置并存放于顺序表中
	int Find(DataType x);                   //查找元素x，成功返回下标，不成功返回-1
};

SeqList::SeqList(int max)					//构造函数
{
	maxSize = max;
	size = 0;
	list = new DataType[maxSize];
}
SeqList::~SeqList(void)						//析构函数
{
	delete []list;
}							

int SeqList::Size(void) const			//取当前数据元素个数
{
	return size;
}

void SeqList::Insert(const DataType& item, int i)	//插入
//在指定位置i前插入一个数据元素item
{
	if (size == maxSize)
	{
 		cout << "顺序表已满无法插入！" << endl;
		exit(0);
	}
	if(i < 0 || i > size)					//参数正确与否判断
	{
		cout << "参数i越界出错!" << endl;
		exit(0);
	}

	//从size-1至i逐个元素后移
	for(int j = size; j > i; j--) list[j] = list[j-1];
        
	list[i] = item;						//在i位置插入item	
	size++;								//当前元素个数加1
}

 void SeqList::Print()  
 {

   for(int i=0;i<=size-1;i++) cout<<list[i]<<"  ";
   cout<<endl;
 }
 
int SeqList::Find(DataType x)
{
 //查找元素x，成功返回下标，不成功返回-1。
 //请补充完成
}

void SeqList::Reverse()
{
 //实现将顺序表中的数据元素逆置并存放于顺序表中。
 //请补充完成
}

DataType SeqList::Delete(const int i)				//删除
//删除指定位置i的数据元素，删除的元素由函数返回
{
	if (size == 0)
	{
		cout << "顺序表已空无元素可删！" << endl;
		exit(0);
	}
	if(i < 0 || i > size - 1)			//参数正确与否判断
	{
		cout<<"参数i越界出错!"<<endl;
		exit(0);
	}

	DataType x = list[i];				//取到要删除的元素

	//从i+1至size-1逐个元素前移
	for(int j = i;j < size-1; j++) list[j] = list[j+1];

	size--;								//当前元素个数减1
	return x;							//返回删除的元素
}

DataType SeqList::GetData(int i) const	//取数据元素
//取位置i的数据元素，取到的数据元素由函数返回
{
	if(i < 0 || i > size - 1)			//参数正确与否判断
	{
		cout << "参数i越界出错!" << endl;
		exit(0);
	}

	return list[i];						//返回取到的元素
}

