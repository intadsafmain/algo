#include <stdio.h>
#include <stdlib.h>
 
 
typedef struct Node
{
    int data;
    struct Node *p_nxt;
}Node;
Node *lList_insert(Node *lList, int value)
{
    Node *p_new = malloc(sizeof *p_new);
    if (p_new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *p_tmp = NULL;
        Node *p_lList = lList;
        p_new->data = value;
 
        while (p_lList != NULL && p_lList->data <= value)
        {
            p_tmp = p_lList;
            p_lList = p_lList->p_nxt;
        }
        p_new->p_nxt = p_lList;
        if (p_tmp != NULL)
        {
            p_tmp->p_nxt = p_new;
        }
        else
        {
            lList = p_new;
        }
 
    }
    return lList;
}
void lList_show(Node *lList)
{
    while (lList != NULL)
    {
        printf("%d ", lList->data);
        lList = lList->p_nxt;
    }
    printf("\n");
}

void lList_free(Node **lList)
{
    while (*lList != NULL)
    {
        Node *p_tmp = (*lList)->p_nxt;
        free(*lList), *lList = NULL;
        *lList = p_tmp;
    }
}
 
int main()
{
    Node *lList = NULL;
    int x;
    int t;
    
        do{
        scanf("%d",&x);
        lList = lList_insert(lList, x);
        lList_show(lList);
            
        printf ("u  want more ? 1 for yes 2 for no");

        scanf("%d",&t);
        } while (t==1);
        
       
    
    lList_free(&lList);
 
    return 0;
}