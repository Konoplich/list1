#include <stdlib.h>

typedef struct node_t
{
	int value;
	struct node_t *next;
} node_t;

int list1_length (node_t **head);

void list1_push (node_t **head, int data);

int list1_pop (node_t **head);

node_t *list1_get_Nth (node_t *head, int n);

node_t *list1_get_last (node_t *head);

void list1_push_back (node_t *head, int value);

node_t *list1_get_last_but_one (node_t *head);

int list1_pop_back (node_t **head);

void list1_insert (node_t *head, unsigned n, int val);

int list1_delete_Nth (node_t **head, int n);

void list1_delete_list (node_t **head);

void list1_from_array (node_t **head, int *arr, size_t size);

int *list1_to_array (const node_t *head);

void list1_print_linked_list (const node_t *head);

void list1_split (node_t *src, node_t **low, node_t **high);

void list1_merge_sort (node_t **head);

