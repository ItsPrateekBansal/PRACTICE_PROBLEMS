#include<iostream>
using namespace std;
int FirstIndex(int input[],int size, int x)
{

if(size==0)
return -1;
if(input[0]==x)
return 0;
int ans = FirstIndex(input+1,size-1,x);
if(ans!=-1)
return ans+1;
else return ans;


}
int main()
{
int size;
cin>>size;
int * p = new int [size];
for(int i=0;i<size;i++)
cin>>p[i];
int ele;
cin>>ele;
cout<<FirstIndex(p,size,ele);
return 0;
}
