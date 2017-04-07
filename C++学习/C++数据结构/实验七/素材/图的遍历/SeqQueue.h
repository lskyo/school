class SeqQueue
{
private:
	DataType data[MaxQueueSize];		//˳���������
	int front;							//��ͷָʾ��
	int rear;							//��βָʾ��
	int count;							//Ԫ�ظ���������
public:
	SeqQueue(void)				  		//���캯��
		{front = rear = 0; count = 0;}; 
	~SeqQueue(void){};  				//��������

	void Append(const DataType& item);	//�����
	DataType Delete(void);       		//������
	DataType GetFront(void)const; 		//ȡ��ͷ����Ԫ��
	int NotEmpty(void)const  			//�ǿշ�
		{return count != 0;};
};

void SeqQueue::Append(const DataType& item)	//�����
//������Ԫ��item���������Ϊ��ǰ���¶�β
{
   if(count > 0 && front == rear)
   {
      cout << "��������!" << endl;
	  exit(0);
   }

   data[rear] = item;						//��Ԫ��item���ڶ�β
   rear = (rear + 1) % MaxQueueSize;		///��βָʾ����1
   count++;									//��������1
}

DataType SeqQueue::Delete(void)					//������
//�Ѷ�ͷԪ�س����У�������Ԫ���ɺ�������
{
   if(count == 0)
   {
      cout << "�����ѿ�!" << endl;
	  exit(0);
   }

   DataType temp = data[front];				//����ԭ��ͷԪ��
   front = (front + 1) % MaxQueueSize;		//��ͷָʾ����1
   count--;									//��������1
   return temp;								//����ԭ��ͷԪ��
}

DataType SeqQueue::GetFront(void)const		//ȡ��ͷ����Ԫ��
//ȡ��ͷԪ�ز��ɺ�������
{  
   if(count == 0)
   {
      cout << "���п�!" << endl;
	  exit(0);
   }
   return data[front];						//���ض�ͷԪ��
}
