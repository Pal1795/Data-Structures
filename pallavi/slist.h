#ifndef _pallavi_slist_
#define _pallavi_slist_
typedef struct node Node;
typedef struct accountant List;

struct node{
	int data;
	Node *next;
};

struct accountant{
	Node* head;

};

// #declaration of functions
List* create_list();
int lookup(List* list,int element);
List* add_head(List* list, int element);
List* add_tail(List* list, int element);
List* delete_head(List* list);
List* delete_tail(List* list);
void display(List* list);
int length(List* list);
#endif