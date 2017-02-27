#include <iostream.h>
#include <conio.h>

typedef struct{
           char name[3];
           char sex;  //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
   }Person;
typedef Person DataType;  //��������Ԫ�ص��������͸�ΪPerson
class SeqQueue {
  public:
    SeqQueue(int Max);   //���캯�� 
    void Clear(void); //��ն��� 
    void Append(const DataType& x);  //���Ӳ��� 
    DataType Delete(void);  //���Ӳ��� 
    DataType GetFront(void); //ȡ��ͷԪ�� 
    DataType GetRear(void);    //ȡ��βԪ�� 
    bool IsFull(void);  //���� 
    bool IsEmpty(void);  //�п� 
    int GetMaxSize();
	friend ostream& operator<<(ostream& ostr, const SeqQueue  Dancers);//�������
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
     cout<<"�����ѿգ���"<<endl;
     exit(0);
   }
   else {
      return q[front];
   } 
}

DataType SeqQueue::GetRear() {
   if(front == rear) {
     cerr<<"�����ѿգ���"<<endl;
     exit(0);
   }
   else {
      return q[(rear-1)%MaxSize];
   } 
}
void SeqQueue::Append(const DataType& x) {
     //////////////////////
    //���ڴ���ɽ��Ӻ���//
   //////////////////////
}

DataType SeqQueue::Delete(void) {
     //////////////////////
	//���ڴ���ɳ��Ժ���//
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