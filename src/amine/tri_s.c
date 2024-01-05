void sortedInsert(struct node newnode) 
{     if (sorted == NULL || sorted->data >= newnode->data) { 
        newnode->next = sorted; 
        sorted = newnode; 
    } 
    else { 
        struct node* current = sorted; 

        while (current->next != NULL 
            && current->next->data < newnode->data) { 
            current = current->next; 
        } 
        newnode->next = current->next; 
        current->next = newnode; 
    } 
} 
 
void insertionsort() 
{ 

    struct node* current = head; 

    while (current != NULL) { 

        struct node* next = current->next; 

        sortedInsert(current); 


        current = next; 
    } 

    head = sorted; 
} 
