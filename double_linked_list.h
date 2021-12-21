#include "element.h"

typedef struct linked_list{
    element *elem;
    struct linked_list *next, *prev;
} linked_list;

linked_list *inzialize_linked_list(element *elem);

void add_node(linked_list **list, element *elem);

int delete_node(linked_list **list, key *chiave);

int delete_node_from_index(linked_list **list, int index);

void print_all_list(linked_list *list);

bool list_include(linked_list *list, key *key);

void swap_node(linked_list **list, int index1, int index2);

int node_count(linked_list *list);

linked_list *get_node_by_index(linked_list *list, int index);

int get_max_key(linked_list *list);

int get_min_key(linked_list *list);

linked_list *get_prev_node(linked_list *list);

int partition(linked_list **list, int first_ind, int last_ind);

void quicksort(linked_list **list, int first_ind, int last_ind);