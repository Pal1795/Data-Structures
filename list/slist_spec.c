#include <assert.h>
#include "slist.h"

void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;

	assert (slist_length(list) == 0);
}

void test_addition_at_head()
{
    Slist s = slist_new();
	Slist *list = &s;
	Slist s2 = slist_new();
	Slist *list1 = &s2;
	Slist s3 = slist_new();
	Slist *list2 = &s3;
	Slist s4=slist_new();
	Slist *list3=&s4;
	Slist s5=slist_new();
	Slist *list4=&s5;
	list = slist_add_head(list, 21);
	assert (slist_length(list) == 1);

	list = slist_add_head(list, 54);
	list = slist_add_head(list, 46);
	list = slist_add_head(list, 18);
	list = slist_add_head(list, 23);
	list = slist_add_head(list, 14);
	list = slist_add_tail(list, 33);

	list1 = slist_add_head(list1, 21);
	list1 = slist_add_head(list1, 32);
	list1 = slist_add_head(list1, 18);
	list2 = slist_add_head(list2, 45);
	list2 = slist_add_head(list2, 33);
	list2 = slist_add_head(list2, 14);
	//assert(list_compare(list1,list2)==1);


	assert (slist_length(list) == 7);
	assert (slist_lookup(list, 23));
	assert (slist_min(list) == 14);
	assert (slist_max(list) == 54);
	list = slist_delete_head(list);
	list = slist_delete_tail(list);
	slist_display(list);
	list = slist_spec_ele(list,98,23);
	list = slist_spec_ele_delete(list,46);
	slist_display(list);
	reverse_list(list);
	slist_display(list);

}

int main()
{
	test_empty_list();
	test_addition_at_head();
	return 0;
}
//gcc slist.c slist_spec.c -o slist
/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
