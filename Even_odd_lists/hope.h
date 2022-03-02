#define INIT 3
#define NULL 4
struct _node_
{
    int data;
    struct _node_ *next;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head,*tail;
    int op_status;
    int n_count;
};
typedef struct _linked_list_ List;

List *initialize();
Node *get_node(int data);
int insert_at_beg(List *my_list,int data);
List *unique_data(List *);
List *even(List *list_a);
List *odd(List *list_a);
List *union_list(List *list_b,List *list_c);
List *sort_elements(List *list_d);
List *check_if_equal(List *list_a,List *list_d);
List *deallocate(List *list);


