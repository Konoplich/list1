#include <stdlib.h>
#include "liblist1.h"

void list1_merge(node_t *a, node_t *b, node_t **c) {
    node_t tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->value < b->value) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->value < b->value) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

int list1_length(node_t** head)
{
    node_t *first = (*head)->next;
    node_t *next = first->next;
    int res = 0;
    do
    {
	res++;
	next = next->next;
    }
    while(first != next);
    return res;
}
void list1_push (node_t **head, int data)
{
	node_t *tmp = (node_t *) malloc (sizeof (node_t));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

int list1_pop (node_t **head)
{
	node_t *prev = NULL;
	int val;

	if (head == NULL)
		exit (-1);

	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free (prev);
	return val;
}

node_t *list1_get_Nth (node_t *head, int n)
{
	int counter = 0;

	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}

	return head;
}

node_t *list1_get_last (node_t *head)
{
	if (head == NULL)
		return NULL;

	while (head->next)
		head = head->next;

	return head;
}

void list1_push_back (node_t *head, int value)
{
	node_t *last = list1_get_last (head);
	node_t *tmp = (node_t *) malloc (sizeof (node_t));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

node_t *list1_get_last_but_one (node_t *head)
{
	if (head == NULL)
		exit (-2);

	if (head->next == NULL)
		return NULL;

	while (head->next->next)
		head = head->next;

	return head;
}
/*
void list1_pop_back (node_t **head)
{
	node_t *lastbn = NULL;

	//Получили NULL
	if (!head)
		exit (-1);

	//Список пуст
	if (! (*head))
		exit (-1);

	lastbn = getLastButOne (*head);

	//Если в списке один элемент
	if (lastbn == NULL)
	{
		free (*head);
		*head = NULL;
	}
	else
	{
		free (lastbn->next);
		lastbn->next = NULL;
	}
}
*/

int list1_pop_back (node_t **head)
{
	node_t *pFwd = NULL;  //текущий узел
	node_t *pBwd = NULL;  //предыдущий узел

	//Получили NULL
	if (!head)
		exit (-1);

	//Список пуст
	if (! (*head))
		exit (-1);

	pFwd = *head;

	while (pFwd->next)
	{
		pBwd = pFwd;
		pFwd = pFwd->next;
	}

	if (pBwd == NULL)
	{
		free (*head);
		*head = NULL;
	}
	else
	{
		free (pFwd->next);
		pBwd->next = NULL;
	}
}

void list1_insert (node_t *head, unsigned n, int val)
{
	unsigned i = 0;
	node_t *tmp = NULL;

	//Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
	//ошибка выбрасываться не будет, произойдёт вставка в конец
	while (i < n && head->next)
	{
		head = head->next;
		i++;
	}

	tmp = (node_t *) malloc (sizeof (node_t));
	tmp->value = val;

	//Если это не последний элемент, то next перекидываем на следующий узел
	if (head->next)
	{
		tmp->next = head->next;
		//иначе на NULL
	}
	else
		tmp->next = NULL;

	head->next = tmp;
}

int list1_delete_Nth (node_t **head, int n)
{
	if (n == 0)
		return list1_pop (head);

	else
	{
		node_t *prev = list1_get_Nth (*head, n-1);
		node_t *elm  = prev->next;
		int val = elm->value;

		prev->next = elm->next;
		free (elm);
		return val;
	}
}

void list1_delete_list (node_t **head)
{
	node_t *prev = NULL;

	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free (prev);
	}

	free (*head);
}

void list1_from_array (node_t **head, int *arr, size_t size)
{
	size_t i = size - 1;

	if (arr == NULL || size == 0)
		return;

	do
	{
		list1_push (head, arr[i]);
	} while (i--!=0);
}

int *list1_to_array (const node_t *head)
{
	int leng = list1_length (head);
	int *values = (int *) malloc (leng*sizeof (int));

	while (head)
	{
		values[--leng] = head->value;
		head = head->next;
	}

	return values;
}

void list1_print_linked_list (const node_t *head)
{
	while (head)
	{
		printf ("%d ", head->value);
		head = head->next;
	}

	printf ("\n");
}
void list1_split (node_t *src, node_t **low, node_t **high)
{
	node_t *fast = NULL;
	node_t *slow = NULL;

	if (src == NULL || src->next == NULL)
	{
		(*low) = src;
		(*high) = NULL;
		return;
	}

	slow = src;
	fast = src->next;

	while (fast != NULL)
	{
		fast = fast->next;

		if (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}

	(*low) = src;
	(*high) = slow->next;
	slow->next = NULL;
}

void list1_merge_sort (node_t **head)
{
	node_t *low  = NULL;
	node_t *high = NULL;

	if ((*head == NULL) || ((*head)->next == NULL))
		return;

	list1_split (*head, &low, &high);
	list1_merge_sort (&low);
	list1_merge_sort (&high);
	list1_merge (low, high, head);
}

