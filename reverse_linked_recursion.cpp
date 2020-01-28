node *reverse_linked_list_rec(node *head)
{
   if(head->next==NULL||head==NULL)
   {
       return head;
   }
    node *smalloutput=reverse_linked_list_rec(head->next);
    node *temp1=smalloutput;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=head;
    head->next=NULL;
    return smalloutput;
    
}
