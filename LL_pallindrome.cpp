node *reverse(node *head)
{
if(head->next==NULL||head==NULL)
{
    return head;
}
    node *smalloutput=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return smalloutput;    
}
node *midpoint(node *head)
{
 node *fast=head->next;
    node *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    }
    return slow;
}
bool check_palindrome(node* head)
{
node *temp=head;
node *h1=head;
node *h2=midpoint(head);
node *fh=h1;
    while(1)
    {
        if(fh->next==h2)
        {
            fh->next=NULL;
            break;
        }
        fh=fh->next;
    }
    node *k=reverse(h2);
while(h1!=NULL&&k!=NULL)
{
    if(h1->data!=k->data)
        return false;
    h1=h1->next;
    k=k->next;
}
    return true;
    
}
