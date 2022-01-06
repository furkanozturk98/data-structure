#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;	
    struct Node * next;
	
};

typedef struct Node node;

void printLinkedList(node * r){
	
	while(r != NULL){
	
		printf("%d ",r->data);
		r = r->next;
	}
	printf("\n");
}

node * getNewNode(){
	return (node *)malloc(sizeof(node));
}

node * addInOrder(node * r,int data){
	
	if(r == NULL){
		r = getNewNode();
		r->next = NULL;
		r->data = data;
		return r;
	}
	
	if(r->data > data){
		node * temp = getNewNode();
		temp->data = data;
		temp->next = r;

		return temp;
	}
	
	node * iter;
	iter = r;
	
	while(iter->next != NULL && iter->next->data < data){
		iter = iter->next;
	}

	
	node * temp = getNewNode();
	temp->next=iter->next;
	iter->next=temp;
	temp->data = data;

	return r;
}

node * addToHead(node * r,int data){
	
	if(r == NULL){
		r = getNewNode();
		r->next = NULL;
		r->data = data;
		return r;
	}
	
	node * newNode = getNewNode();

	newNode->next = r;
	newNode->data = data;
	r = newNode;

	return r;
}

node * addToEnd(node * r,int data){
	
	if(r == NULL){
		r = getNewNode();
		r->next = NULL;
		r->data = data;
		return r;
	}
	
	node * iter = r;
	
	while(iter->next != NULL){
		iter = iter->next;
	}

	
	node * temp = getNewNode();
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;

	return r;
}

node * deleteByData(node * r,int data){
	
	node *iter = r;
	node * temp;

	if(r->data == data){
		temp = r;
		r = r->next;
		free(temp);

		return r;
	}

	while(iter->next != NULL && iter->next->data != data ){
		iter=iter->next;
	}

	if(iter->next == NULL){
		
		printf("Could not find %d \n", data);
		return r;
	}
	
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);

	return r;
}

node * deleteByIndex(node * r,int index){
	
	node * iter = r;
	node * temp;

	if(index == 0){
		temp = r;
		r = r->next;
		free(temp);

		return r;
	}

	int counter = 1;

	while(iter->next != NULL && counter != index){
		iter = iter->next;

		counter ++;
	}

	if(iter->next == NULL){
		printf("Could not find the index %d \n", index);

		return r;
	}
	
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);

	return r;
}


int main()
{
    node * root;
	root = NULL;
	
	root = addInOrder(root,450);
	root = addInOrder(root,4);
	root = addInOrder(root,40);
	root = addInOrder(root,50);
	root = addInOrder(root,400);

	printLinkedList(root);

	//root = deleteByData(root,450);

	// test nonexistent
	//root = deleteByData(root,855);

	/*root = addToHead(root, 22);
	root = addToHead(root, 99);*/

	//root = addToEnd(root, 1);

	root = deleteByIndex(root, 4);

	printLinkedList(root);

   return 0;
}



