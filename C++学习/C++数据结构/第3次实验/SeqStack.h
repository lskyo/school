#include<iostream>
using namespace std;


const int Max=100;
typedef char DataType;
//顺序栈类SeqStack的界面
class SeqStack {
  public:
    SeqStack(int max);             //构造函数 
    ~SeqStack();
    void ClearStack(void);   //清空栈 
    void Push(const DataType& x);  //压栈 
    DataType Pop(void);     //弹出栈 
    DataType GetTop(void);    //取栈顶元素 
    bool IsFull(void);      //判断栈是否为满 
    bool IsEmpty(void);     //判断栈是否为空 
  private:
    int top;
    DataType *s;
	int MaxSize;
};
//顺序栈类的实现 
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
    cout<<"堆栈已满，不能压栈!!!"<<endl;
    exit(0); 
  }
  s[top]=x;
  top++;
  
}

DataType SeqStack::Pop(void){
  DataType temp;
  if (top==0){
    cout<<"堆栈已空，不能出栈!!!"<<endl;
    exit(0) ;
  }
  top--;
  temp=s[top];  
  return temp;
}

DataType SeqStack::GetTop(void){
  DataType temp;
  if (top==0){
    cout<<"堆栈已空!!!"<<endl;
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

 
