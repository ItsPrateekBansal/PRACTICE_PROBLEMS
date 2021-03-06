node* kReverse(node*head,int k)
{
   node *current=head;
    node *next=NULL;
    node *prev=NULL;
    int count = 0; 
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    } 
    if (next != NULL)  
    head->next = kReverse(next, k); 
    return prev;
}
