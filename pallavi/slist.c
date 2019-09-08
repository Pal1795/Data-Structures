#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "slist.h"

List* create_list(){
	List* data= (List*) malloc(sizeof(List));
	data->head = NULL;
	return data;
}

Node* create_node(int element,Node* ptr){
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->data = element;
	new_node->next = ptr;
	return new_node;
}

int lookup(List* list,int element){
	// returning 0 for false
	// returning 1 for true
	assert(list!=NULL);
	for(Node* curr = list->head;curr!=NULL;curr=curr->next){
		if(curr->data==element){
			return 1;
		}
	}
	return 0;
}

List* add_head(List* list, int element){
	assert(list!=NULL);
	Node* new_node = create_node(element,list->head);
	list->head = new_node;
	assert(list->head!=NULL);
	return list;
}

List* add_tail(List* list, int element){
	assert(list!=NULL);

	Node* new_node = create_node(element,NULL);

	if(list->head==NULL){
		list->head = new_node;
	}
	else
	{
		for(Node* curr = list->head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				curr->next = new_node;
				break;
			}
		}
	}
	assert(list->head!=NULL);
	return list;	
}

List* delete_head(List* list){
	assert(list!=NULL);
	if(list->head!=NULL){
		Node* free_node = list->head;
		list->head = free_node->next;
	}
	return list;
}

List* delete_tail(List* list){
	assert(list!=NULL);
	if(list->head!=NULL){
		Node* head = list->head;
		if(head->next==NULL){
			list->head = NULL;
			free(head);
		}else{
			Node* prev = NULL;
			for(Node* curr = head;curr!=NULL;curr=curr->next){
				if(curr->next==NULL){
					prev->next = NULL;
					free(curr);
					break;
				}
				prev = curr;
			}		
		}
	}
	return list;
}

void display(List* list){
	assert(list!=NULL);
	printf("Printing List :\n");
	for(Node* curr = list->head;curr!=NULL;curr=curr->next){
		printf("%d->",curr->data);
	}
	printf("\n");
}

int length(List* list){
	assert(list!=NULL);
	return list->length;
	int count =0;
	for(Node* curr = list->head;curr!=NULL;curr=curr->next){
		count = count+1;
	}
	return count;
}