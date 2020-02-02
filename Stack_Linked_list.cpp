#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    Node<T> *next;
    T data;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template<typename T>
class stackL
{
    Node<T> *head;
    int size;
    public:
    stackL()
    {
        head = NULL;
        size = 0;
    }
    void push(T input)
    {
        Node<T> *newnode = new Node<T>(input);
        if(head==NULL)
        head = newnode;
        else
        {
            newnode->next = head;
            head = newnode;
        }
        size++;
    }
    T top()
    {
        return head->data;
    }
    int totalsize()
    {
        return size;
    }
    T pop()
    {
        Node<T> *temp = head;
        T x = head->data;
        head=head->next;
        delete temp;
        size--;
        return x;
    }
    bool isEmpty()
    {
        return head==NULL;
    }

};

int main()
{
    stackL<char> p1;
    char input;
    cin>>input;
    while(input!='x')
    {
        p1.push(input);
        cin>>input;
    }
    cout<<endl<<"input operation completed\n";
    cout<<"size = "<<p1.totalsize();
    cout<<endl<<"top element = "<<p1.top();
    cout<<"\nNOW POPPING WILL START\n";
    while(!p1.isEmpty())
    {
        cout<<p1.pop()<<" POPPED\n";
    }
    return 0;
    
}
