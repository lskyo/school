#include<iostream.h>
#include<time.h>
#include<stdlib.h>
#include"SeqQueue.h"    
 const int N=3;

ostream& operator<<(ostream& ostr,  SeqQueue  Dancers)//重载<<运算符以输出队列
{
    int i;
	
	for (i=Dancers.front;i!=(Dancers.rear)%Dancers.GetMaxSize();i=(i+1)%Dancers.GetMaxSize())
	{
		cout<<Dancers.q[i].name <<",";
	}
	cout<<endl;
	return ostr;
}

void main()
{ 
	int YesOrNo=1;
    Person F,M;
	SeqQueue Fdancers(N),Mdancers(2*N);
    int i;
     for (i=1;i<Mdancers.GetMaxSize();i++)
	{
		 Person temp={"",'M'};
	    temp.name[0]='M';
	    temp.name[1]='a'+i-1;
        Mdancers.Append(temp);
	 }
     //////////////////////////////////////
	//请在此补充代码，实现将女舞者进队列//
   //////////////////////////////////////
	cout<<"女舞者队列："<<Fdancers;
	cout<<"男舞者队列："<<Mdancers;
   	while(YesOrNo==1)//继续新一轮的匹配
	{  //本次舞伴匹配的结果为：
		for(i=1;i<Fdancers.GetMaxSize()&&Mdancers.GetMaxSize();i++)
		{  
		//////////////////////////////////////////////////
		//请在此补充代码，实现男女队头舞者匹配，输出显示//
		//匹配的舞伴，并将已匹配的舞者重新插入到队列尾  //
		//////////////////////////////////////////////////
		}
       YesOrNo=0;
	   cout<<"继续跳舞，请按1，否则请按0: ";
	   cin>>YesOrNo;
	}

    srand((unsigned)time(NULL));

}