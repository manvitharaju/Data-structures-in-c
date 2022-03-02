
#include<assert.h>
#include<stdlib.h>
#include "linko.h"

int main()
{
    List *test, *buf_list, *result,*result1;
    Node *res;

    test = initialize_list();
    assert(test->count == 0);
    assert(test->head == NULL);

    buf_list = initialize_list();

    assert(insert_data_beg(test, 10));
    assert(insert_data_beg(test, 40));
    assert(insert_data_beg(test, 20));
    assert(insert_data_beg(test, 60));

    assert(test->head->ptr->ptr->ptr->data == test->tail->data);
    assert(test->head->data == 60);
    assert(test->tail->data == 10);
    assert(test->count == 4);

    assert(insert_data_end(test, 40));
    assert(insert_data_end(test, 90));
    assert(insert_data_end(test, 25));
    assert(insert_data_end(test, 55));
    insert_after_position(test,77,5);
   // assert(insert_data_after_value(test,77,78));
    //display_elements(test);
    assert(count_nodes(test)==9);
    sort_list(test);


    //assert(test->count == 8);
    assert(test->tail->data == 90);
    assert(test->head->data == 10);

    //assert(test->head->ptr->ptr->data == 40);

    assert(search(test, 55));
    assert(search(test, 40));
    assert(search(test, 10));
    assert(search(test, 60));

    assert(search(test, 24) == 0);
    assert(search(test, 61) == 0);

    res = pull_data(test, 10);
    assert(res->data == 10);

    res = pull_data(test, 8);
    assert(res == NULL);


    assert(insert_data_beg(buf_list, 60));
    assert(insert_data_beg(buf_list, 10));
    assert(insert_data_beg(buf_list, 60));
    assert(insert_data_beg(buf_list, 100));

    result1=merge_list(test,buf_list);
    display_elements(result1);


    result = intersection(test, buf_list);


    assert(result->count == 2);
    assert(result->head->data == 60);
    assert(result->tail->data == 10);

    assert(buf_list->count == 4);

    assert(delete_list_end(buf_list));
    assert(delete_list_end(buf_list));
    assert(delete_list_end(buf_list));

    assert(buf_list->count == 1);
    assert(delete_list_end(buf_list));

    assert(delete_list_end(buf_list) == 0);


    return 0;

}
