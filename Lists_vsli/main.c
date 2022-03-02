#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <assert.h>

int main()
{
    List *list,*list_a,*list_b,*list_c,*list_d;
    list=initialize();
    assert(list->n_count==0);
    assert(list->head==NULL);
    assert(list->tail==NULL);
    assert(list->op_status==INIT);
    //insert data into list a at beginning
    assert(insert_at_beg(list,13));
    assert(insert_at_beg(list,10));
    assert(insert_at_beg(list,8));
    assert(insert_at_beg(list,8));
    assert(insert_at_beg(list,7));
    assert(insert_at_beg(list,5));
    assert(insert_at_beg(list,4));
    assert(insert_at_beg(list,3));
    assert(insert_at_beg(list,2));
    assert(insert_at_beg(list,2));
    assert(insert_at_beg(list,1));
    display_list(list);
    list_a=unique_data(list);
    display_list(list_a);
    list_b=even(list_a);
    display_list(list_b);
    list_c=odd(list_a);
    display_list(list_c);
    list_d=union_list(list_b,list_c);
    display_list(list_d);


    return 0;
}
