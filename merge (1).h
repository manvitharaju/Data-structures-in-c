#define NULL 2
#define INIT 3
struct _node_
{
    int data;
    struct _node_ *next;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head,*tail;
    int node_count;
    int op_status;
};
typedef struct _linked_list_ List;

List *initialize();
Node *get_node(int data);
int insert_at_beg(List *my_list,int data);
int display_list(List *my_list);
List *merge_list(List *list_a,List *list_b);

