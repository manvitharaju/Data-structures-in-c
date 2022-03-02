#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "squid.h"

int main()
{
    Array s1;
    s1=initialize(10);
    assert(s1.c_size==0);
    assert(s1.t_size==10);
    assert(s1.trans_status==INIT);

    s1=insert_data(101,7,8,9);
     s1=insert_data(102,8,8,8);
     s1=insert_data(103,9,8,4);
     s1=insert_data(104,6,8,5);
     s1=insert_data(105,9,9,9);
     s1=insert_data(106,7,7,9);
     s1=insert_data(107,7,5,9);
     s1=insert_data(108,7,8,8);
     s1=insert_data(109,3,8,5);
     s1=insert_data(110,6,8,7);
     strongest_survivor(s1);
     assert(two_teams(s1)==TEAM1);

    return 0;
}
