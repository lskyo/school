class SeqQueue
{
private:
	DataType data[MaxQueueSize];		//顺序队列数组
	int front;							//队头指示器
	int rear;							//队尾指示器
	int count;							//元素个数计数器
public:
	SeqQueue(void)				  		//构造函数
		{front = rear = 0; count = 0;}; 
	~SeqQueue(void){};  				//析构函数

	void Append(const DataType& item);	//入队列
	DataType Delete(void);       		//出队列
	DataType GetFront(void)const; 		//取队头数据元素
	int NotEmpty(void)const  			//非空否
		{return count != 0;};
};

void SeqQueue::Append(const DataType& item)	//入队列
//把数据元素item插入队列作为当前的新队尾
{
   if(count > 0 && front == rear)
   {
      cout << "队列已满!" << endl;
	  exit(0);
   }

   data[rear] = item;						//把元素item加在队尾
   rear = (rear + 1) % MaxQueueSize;		///队尾指示器加1
   count++;									//计数器加1
}

DataType SeqQueue::Delete(void)					//出队列
//把队头元素出队列，出队列元素由函数返回
{
   if(count == 0)
   {
      cout << "队列已空!" << endl;
	  exit(0);
   }

   DataType temp = data[front];				//保存原队头元素
   front = (front + 1) % MaxQueueSize;		//队头指示器加1
   count--;									//计数器减1
   return temp;								//返回原队头元素
}

DataType SeqQueue::GetFront(void)const		//取队头数据元素
//取队头元素并由函数返回
{  
   if(count == 0)
   {
      cout << "队列空!" << endl;
	  exit(0);
   }
   return data[front];						//返回队头元素
}
