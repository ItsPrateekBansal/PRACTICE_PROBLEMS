#include <iostream>
#include <climits>
using namespace std;

class stackA
{
  int *data;
  int capacity;
  int nextindex;
  public:
  stackA(int totalsize)
  {
      data = new int [totalsize];
      capacity = totalsize;
      nextindex = 0;
  }
  void push(int element)
  {
    if(nextindex>=capacity)
    {
        int *newdata = new int [2*capacity];
        for(int i=0;i<capacity;i++)
        {
            newdata[i]=data[i];
        }
        delete [] data;
        data = newdata;
        capacity*=2;
    }
    data[nextindex]=element;
    nextindex++;
  } 
  bool isempty()
  {
      return nextindex==0;
  }
  int size()
  {
      return nextindex;
  }
  int top()
  {   
      if(isempty())
      {
          cout<<"Stack is Empty";
          return INT_MIN;
      }
      return data[nextindex-1];
  }
  int pop()
  {
       if(isempty())
      {
          cout<<"Stack is Empty";
          return INT_MIN;
      }
      nextindex--;
      return data[nextindex];
  }
};

int main()
{
    stackA p1(5);
    int input;
    cin>>input;
    while(input!=-1)
    {
        p1.push(input);
        cin>>input;
    }
    cout<<endl<<"input operation completed\n";
    cout<<"size = "<<p1.size();
    cout<<endl<<"top element = "<<p1.top();
    cout<<"\nNOW POPPING WILL START\n";
    while(!p1.isempty())
    {
        ;
        cout<<p1.pop()<<" POPPED\n";
    }
    return 0;
    
}
