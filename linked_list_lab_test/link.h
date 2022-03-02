#define NULL 4
#define INIT 3
#define NO_ELEMENT 2

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
int insert_at_end(List *my_list,int data);
int display(List *my_list);
int insert_after_pos(List *my_list,int data,int pos);
int insert_after_value(List *my_list,int data,int value);
int insert_at_middle(List *my_list,int data,int position);
int no_of_elements(List *my_list);
int get_min_element(List *my_list);
int get_max_element(List *my_list);
int search_element(List *my_list,int search_ele);
int sort_list(List *my_list);
List *intersection(List *list_a,List *list_b);
int delete_list_end(List *my_list);
int delete_list_beginning(List * my_list);
List *merge(List *list_a,List *list_b);
List *Union(List *list_a,List *list_b)


