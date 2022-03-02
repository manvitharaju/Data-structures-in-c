#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include<assert.h>

int main()
{
    List *list_a,*list_b,*result;
    list_a=initialize();
    assert(list_a->head==NULL);
    assert(list_a->node_count==0);
    assert(list_a->op_status==INIT);
    assert(list_a->tail==NULL);
    assert(insert_at_beg(list_a,12)==1);
    assert(insert_at_end(list_a,10)==1);
    assert(insert_at_beg(list_a,13)==1);
    assert(insert_at_end(list_a,20)==1);
    assert(insert_after_pos(list_a,15,1)==1);
    assert(insert_after_pos(list_a,33,3)==1);
    assert(insert_after_value(list_a,45,34)==NULL);
    assert(insert_at_middle(list_a,66,3)==1);
    assert(no_of_elements(list_a)==7);
    display(list_a);
    assert(insert_at_beg(list_b,10)==1);
    assert(insert_at_beg(list_b,20)==1);
    assert(insert_at_beg(list_b,30)==1);
    assert(insert_at_beg(list_b,40)==1);
    display(list_b);
    assert(get_min_element(list_a)==10);
    assert(get_max_element(list_a)==66);
    assert(search_element(list_a,10)==1);
    assert(search_element(list_a,100)==0);
    assert(sort_list(list_a)==1);
    result=intersection(list_a,list_b);
    assert(result->node_count==2);
    //display(result);
    //result=Union(list_a,list_b);
    //display(result);
    return 0;
}
