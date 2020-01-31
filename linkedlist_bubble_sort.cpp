int findlength(node *head)
{
    if(head==NULL)
        return 0;
    else if(head->next==NULL)
        return 1;
    else return 1 + findlength(head->next);
}
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    node *temp=head;
    int ll=findlength(head);
    for(int i=0;i<ll;i++)
    {   temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data>temp->next->data)
            {
               int x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;
            }
            temp=temp->next;
        }
    }
    return head;
}
