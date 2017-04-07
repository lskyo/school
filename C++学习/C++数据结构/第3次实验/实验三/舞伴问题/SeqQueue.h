#include <iostream.h>
#include <conio.h>

typedef struct{
           char name[3];
           char sex;  //性别，'F'表示女性，'M'表示男性
   }Person;
typedef Person DataType;  //将队列中元素的数据类型改为Person
class SeqQueue {
  public:
    SeqQueue(int Max);   //构造函数 
    void Clear(void); //清空队列 
    void Append(const DataType& x);  //进队操作 
    DataType Delete(void);  //出队操作 
    DataType GetFront(void); //取队头元素 
    DataType GetRear(void);    //取队尾元素 
    bool IsFull(void);  //判满 
    bool IsEmpty(void);  //判空 
    int GetMaxSize();
	friend ostream& operator<<(ostream& ostr, const SeqQueue  Dancers);//输出队列
  private:
    int front,rear;
    DataType *q;
    int MaxSize;
};

SeqQueue::SeqQueue(int Max) {

	q=new DataType[Max];
	MaxSize=Max;
    front = 0;
    rear = 0;
}
DataType SeqQueue::GetFront() {
   if(front == rear) {
     cout<<"队列已空！！"<<endl;
     exit(0);
   }
   else {
      return q[front];
   } 
}

DataType SeqQueue::GetRear() {
   if(front == rear) {
     cerr<<"队列已空！！"<<endl;
     exit(0);
   }
   else {
      return q[(rear-1)%MaxSize];
   } 
}
void SeqQueue::Append(const DataType& x) {
     //////////////////////
    //请在此完成进队函数//
   //////////////////////
}

DataType SeqQueue::Delete(void) {
     //////////////////////
	//请在此完成出对函数//
   //////////////////////
}

bool SeqQueue::IsEmpty(void) {
   return (front == rear?true:false);
}

bool SeqQueue::IsFull(void) {
   return ((rear+1)%MaxSize == front?true:false);
}

void SeqQueue::Clear(void) {

   rear = front;
}
int SeqQueue::GetMaxSize() {
   return MaxSize;
}