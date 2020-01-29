/*
Given a linked list and an integer n, append the last n elements of the LL to front.
Indexing starts from 0. You don't need to print the elements, just update the elements and return the head of updated LL.
Assume given n will be smaller than length of LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
3
Sample Output 1 :
3 4 5 1 2

*/

int find_length(node *temp)
{
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
return count;
}

node* append_LinkedList(node* head,int n)
{
    //write your code here
    node *temp=head;
    int ll=find_length(temp);
    for(int i=0;i<ll-n;i++)
        temp=temp->next;
    
    node *newhead=temp;
  
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=head;
   
    
    for(int i=0;i<ll-n-1;i++)
    {
     head=head->next;
    }
    head->next=NULL;
  return newhead;
    
}
