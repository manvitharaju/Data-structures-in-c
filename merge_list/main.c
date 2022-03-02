#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include<assert.h>

int main()
{
    List *list_a,*list_b,*result;
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
    //the elements are inserted in ascending order since we are inserting at beginning
    assert(insert_at_beg(list_a,130)==1);
    //assert(insert_at_beg(list_a,47)==1);
    assert(insert_at_beg(list_a,39)==1);
    assert(insert_at_beg(list_a,22)==1);
    //assert(insert_at_beg(list_a,50)==1);
    display_list(list_a);
    assert(list_a->node_count==3);

    //insert data into list_b
    assert(insert_at_beg(list_b,110)==1);
    assert(insert_at_beg(list_b,84)==1);
    assert(insert_at_beg(list_b,93)==1);
   assert(insert_at_beg(list_b,20)==1);
    assert(insert_at_beg(list_b,5)==1);
    display_list(list_b);
    assert(list_b->node_count==5);
    result=merge_list(list_a,list_b);
    display_list(result);
    assert(deallocate(list_a)==NULL);
    assert(deallocate(list_b)==NULL);
    assert(deallocate(result)==NULL);



    return 0;
}
