#define MAXSIZE 12
#define INIT 4
#define FULL 3
#define SUCCESS 1
#define NULL 0
#define TEAM1 6
#define TEAM2 7

struct _survivor_
{
    int survivor_id;
    int strength;
    int skill;
    int will_pow;

};
typedef struct _survivor_ Survivor;

struct _array_
{
    Survivor sarray[MAXSIZE];
    int c_size,t_size,trans_status;
};
typedef struct _array_ Array;

Array initialize(int size);
Array insert_data(int id,int strength,int skill,int will_pow);
int strongest_survivor(Array my_arr);
int two_teams(Array group1);
