#include<iostream.h>
#include<time.h>
#include<stdlib.h>
#include"SeqQueue.h"    
 const int N=3;

ostream& operator<<(ostream& ostr,  SeqQueue  Dancers)//����<<��������������
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
	//���ڴ˲�����룬ʵ�ֽ�Ů���߽�����//
   //////////////////////////////////////
	cout<<"Ů���߶��У�"<<Fdancers;
	cout<<"�����߶��У�"<<Mdancers;
   	while(YesOrNo==1)//������һ�ֵ�ƥ��
	{  //�������ƥ��Ľ��Ϊ��
		for(i=1;i<Fdancers.GetMaxSize()&&Mdancers.GetMaxSize();i++)
		{  
		//////////////////////////////////////////////////
		//���ڴ˲�����룬ʵ����Ů��ͷ����ƥ�䣬�����ʾ//
		//ƥ�����飬������ƥ����������²��뵽����β  //
		//////////////////////////////////////////////////
		}
       YesOrNo=0;
	   cout<<"�������裬�밴1�������밴0: ";
	   cin>>YesOrNo;
	}

    srand((unsigned)time(NULL));

}