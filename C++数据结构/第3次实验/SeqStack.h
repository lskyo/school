#include<iostream>
using namespace std;


const int Max=100;
typedef char DataType;
//˳��ջ��SeqStack�Ľ���
class SeqStack {
  public:
    SeqStack(int max);             //���캯�� 
    ~SeqStack();
    void ClearStack(void);   //���ջ 
    void Push(const DataType& x);  //ѹջ 
    DataType Pop(void);     //����ջ 
    DataType GetTop(void);    //ȡջ��Ԫ�� 
    bool IsFull(void);      //�ж�ջ�Ƿ�Ϊ�� 
    bool IsEmpty(void);     //�ж�ջ�Ƿ�Ϊ�� 
  private:
    int top;
    DataType *s;
	int MaxSize;
};
//˳��ջ���ʵ�� 
SeqStack::SeqStack(int max){
	s=new DataType[max];
	MaxSize=max;
    top=0;
}
SeqStack::~SeqStack(void){
	top=0;
	delete []s;
}
void SeqStack::Push(const DataType& x) {
  if (top==MaxSize){
    cout<<"��ջ����������ѹջ!!!"<<endl;
    exit(0); 
  }
  s[top]=x;
  top++;
  
}

DataType SeqStack::Pop(void){
  DataType temp;
  if (top==0){
    cout<<"��ջ�ѿգ����ܳ�ջ!!!"<<endl;
    exit(0) ;
  }
  top--;
  temp=s[top];  
  return temp;
}

DataType SeqStack::GetTop(void){
  DataType temp;
  if (top==0){
    cout<<"��ջ�ѿ�!!!"<<endl;
    exit(0);
  }
  temp=s[top-1];
  return temp;
}

bool SeqStack::IsEmpty(void){
  if(top==0)   return 1;
  else   return 0;
	
}

bool SeqStack::IsFull(void) {
   if(top==MaxSize)   return 1;
  else   return 0;
}
void SeqStack::ClearStack(void){
  top=0;
}

 
