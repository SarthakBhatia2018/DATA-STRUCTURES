 bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        if(!head->next)
            return false;            
        ListNode *ptr1=head,*ptr2=head;
        do
        {
        if(!ptr1->next)
            return false;    
        ptr1=ptr1->next;
        if(!ptr2->next)
            return false;
        if(!ptr2->next->next)
            return false;
        ptr2=ptr2->next->next;
                   
        }while(ptr1!=ptr2);
        
        return true;
    }



//2nd solution
bool hasCycle(ListNode *head) {  
        ListNode *ptr1=head,*ptr2=head;
        while(ptr1 && ptr2 &&ptr2->next)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
            if(ptr1==ptr2)
                return true;
        }
        
        return false;
    }
};