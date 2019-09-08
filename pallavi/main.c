#include<stdio.h>
#include<assert.h>

#include "slist.h"

void test_create(){
	List* slist=create_list();
	assert(slist!=NULL);
	assert(slist->head==NULL);
	assert((*slist).head==NULL);
}

void test_add_head(){
	List* slist=create_list();
	slist = add_head(slist,10);
	assert(slist->head!=NULL);
	int lookVal = lookup(slist,10);
	assert(lookVal==1);
	lookVal = lookup(slist,20);
	assert(lookVal==0);
	//need to test for search 10
}

void test_add_tail(){
	List* slist=create_list();
	slist = add_tail(slist,10);
	assert(slist->head!=NULL);
	int lookVal = lookup(slist,10);
	assert(lookVal==1);
	lookVal = lookup(slist,20);
	assert(lookVal==0);
	slist = add_tail(slist,20);
	lookVal = lookup(slist,20);
	assert(lookVal==1);
}

void test_delete_head(){
	List* slist=create_list();
	slist = delete_head(slist);
	assert(slist!=NULL);
	assert(slist->head == NULL);
	slist = add_head(slist,900);
	slist = add_head(slist,800);
	slist = add_head(slist,100);
	slist = add_head(slist,200);

	int lookVal = lookup(slist,200);
	assert(lookVal==1);
	slist = delete_head(slist);
	lookVal = lookup(slist,200);
	assert(lookVal==0);
}

void test_delete_tail(){
	List* slist=create_list();
	assert(length(slist)==0);
	slist = delete_tail(slist);
	assert(slist!=NULL);
	assert(slist->head == NULL);
	slist = add_head(slist,900);
	slist = add_head(slist,800);
	slist = add_head(slist,100);
	
	slist = add_head(slist,200);
	
	int lookVal = lookup(slist,900);
	assert(lookVal==1);
	assert(length(slist)==4);

	slist = delete_tail(slist);
	
	lookVal = lookup(slist,900);
	assert(lookVal==0);
	assert(length(slist)==3);
}
void test_display(){
	List* slist=create_list();
	slist = delete_tail(slist);
	assert(slist!=NULL);
	assert(slist->head == NULL);
	slist = add_head(slist,900);
	slist = add_head(slist,800);
	slist = add_head(slist,100);
	slist = add_head(slist,200);
	display(slist);
	
}

int main(int var,char* ch){
	test_create();
	test_add_head();
	test_add_tail();
	test_delete_head();
	test_delete_tail();
	test_display();

}


