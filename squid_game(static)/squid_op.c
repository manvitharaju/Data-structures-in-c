#include "squid.h"
#define MAXSIZE 12


Array initialize(int size)
{
    Array my_arr;
    my_arr.c_size=0;
    my_arr.t_size=size>0 && size<=MAXSIZE?size:MAXSIZE;
    my_arr.trans_status=INIT;
    return my_arr;
}

Array insert_data(int id,int strength,int skill,int will_pow)
{
    Array my_arr;
    if(my_arr.c_size==my_arr.t_size)
    {
        return my_arr;
    }
    my_arr.sarray[my_arr.c_size].survivor_id=id;
    my_arr.sarray[my_arr.c_size].strength=strength;
    my_arr.sarray[my_arr.c_size].skill=skill;
    my_arr.sarray[my_arr.c_size].will_pow=will_pow;
    my_arr.c_size++;
    return my_arr;
}

int strongest_survivor(Array my_arr)
{
    int strong_arr[my_arr.c_size];

    for(int i=0;i<my_arr.c_size;i++)
    {
        strong_arr[i]=my_arr.sarray[i].skill+my_arr.sarray[i].strength+my_arr.sarray[i].will_pow;
    }
    int max_value=0;
    for(int i=0;i<my_arr.c_size;i++)
    {
        if(strong_arr[i]>max_value)
        {
            max_value=strong_arr[i];
        }
    }
    for(int i=0;i<my_arr.c_size;i++)
    {
        if((my_arr.sarray[i].skill+my_arr.sarray[i].strength+my_arr.sarray[i].will_pow)==max_value)
            printf("%d",my_arr.sarray[i].survivor_id);

    }
    return 1;
}


int two_teams(Array my_arr)
{
    int group_1[my_arr.c_size/2],group_2[my_arr.c_size/2];
    int sum_g1=0,sum_g2=0;
    for(int i=0;i<(my_arr.c_size/2);i++)
    {
        group_1[i]=my_arr.sarray[i].skill+my_arr.sarray[i].strength+my_arr.sarray[i].will_pow;
        sum_g1 +=group_1[i];
    }
    for(int i=(my_arr.c_size/2);i<my_arr.c_size;i++)
    {
        group_2[i]=my_arr.sarray[i].skill+my_arr.sarray[i].strength+my_arr.sarray[i].will_pow;
        //printf("\n %d",group_2[i]);
        sum_g2 +=group_2[i];
    }
    printf("\nT1:%d",sum_g1);
    printf("\nT2:%d",sum_g2);
    if(sum_g1>sum_g2)
        return TEAM1;
    else
        return TEAM2;
    return SUCCESS;
}
