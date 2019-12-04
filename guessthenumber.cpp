//This is a Program to guess the number thought by user in mind.
//the program tries to guess the number 
//Basically it's an application, simple application of the Binary Search Algorithm


#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    cout<<"HELLO USER,\n PLEASE THINK OF A NUMBER FROM 1 to 100 \nAND I'LL TRY TO GUESS IT WITH YOU. :)\n";
    int low=1,high=100,mid;
    mid=(high+low)/2;
    char n;
    while(1)
    {
        cout<<"Is it "<<mid<<"  ?";
        cin>>n;
        if(n=='<')
        {
            high=mid;
        }
        else if(n=='>')
        low=mid;
        else if(n=='=')
        {
            cout<<"HAHAHAH I FOUND IT "<<mid;
            break;
        }
        mid=(high+low)/2;
    }
    return 0;

}
