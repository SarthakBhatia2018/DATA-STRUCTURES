ListNode* oddEvenList(ListNode* head) {
 
        ListNode* ptr=head,*even,*even_ref;
        if(!ptr)
            return head;
        if(!ptr->next)
            return head;
        if(!ptr->next->next)
            return head;
        even=ptr->next;
        even_ref=even;
        while(ptr)
        {
            if(!ptr->next || !even->next)
                break;
            ptr->next=ptr->next->next;
            if(even->next!=NULL)
                ptr=even->next;
                even->next=ptr->next;
            if(ptr->next!=NULL)
            {
                even=ptr->next;
            }
        }
        ptr->next=even_ref;
        even->next=NULL;
        return head;
    }