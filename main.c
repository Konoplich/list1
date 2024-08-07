#include <stdlib.h>
#include "liblist1.h"

void main()
{
	node_t *head = NULL;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//Создаём список из массива
	list1_from_array (&head, arr, 10);

	list1_print_linked_list (head);

	//Вставляем узел со значением 333 после 4-го элемента (станет пятым)
	list1_insert (head, 4, 333);
	list1_print_linked_list (head);

	list1_push_back (head, 11);
	list1_push_back (head, 12);
	list1_push_back (head, 13);
	list1_push_back (head, 14);
	list1_print_linked_list (head);

	printf ("pop %d\n", list1_pop (&head));
	printf ("pop back %d\n", list1_pop_back (&head));

	list1_print_linked_list (head);
	//Удаляем пятый элемент (индексация с нуля)
	list1_delete_Nth (&head, 4);
	list1_print_linked_list (head);
	list1_delete_list (&head);

	getchar();
}
