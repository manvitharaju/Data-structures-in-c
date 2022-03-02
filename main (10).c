#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include<assert.h>

int main()
{
    List *list_a,*list_b,*result,*end_l;
    //list_a initialization
    list_a=initialize();
    assert(list_a->head==NULL);
    assert(list_a->tail==NULL);
    assert(list_a->node_count==0);
    assert(list_a->op_status==INIT);
    //list_b initialization
    list_b=initialize();
    assert(list_b->head==NULL);
    assert(list_b->tail==NULL);
    assert(list_b->node_count==0);
    assert(list_b->op_status==INIT);
    //insert data into list_a
    assert(insert_at_beg(list_a,50)==1);
    assert(insert_at_beg(list_a,40)==1);
    assert(insert_at_beg(list_a,30)==1);
   assert(insert_at_beg(list_a,20)==1);
    assert(insert_at_beg(list_a,10)==1);
    display_list(list_a);
    assert(list_a->node_count==5);

    //insert data into list_b
    assert(insert_at_beg(list_b,55)==1);
    assert(insert_at_beg(list_b,44)==1);
    assert(insert_at_beg(list_b,33)==1);
   assert(insert_at_beg(list_b,22)==1);
    assert(insert_at_beg(list_b,11)==1);
    display_list(list_b);
    assert(list_b->node_count==5);
    result=merge_list(list_a,list_b);
    display_list(result);


    return 0;
}
