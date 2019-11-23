
/* Note : ptr = address of first node.
*/
typedef struct node list ;

void  ins_sort( list *ptr )
{
    if ( ptr  == NULL ||  ptr ->next   ==  NULL )
         return;
    else
    {
       // Getting the previous node trick!
        sort(ptr->next);
        
        list *j = ptr;
        
        int key = ptr->item;

        // Inserting at proper place
        while (  (  j->next  != NULL ) && ( j->next->item < key ) )
        {
            j->item = j->next->item;
            j = j->next;
        }  

      j->item = key;
   }
}
