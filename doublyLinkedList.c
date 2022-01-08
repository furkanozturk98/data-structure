#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;	
    struct Node * prev;
    struct Node * next;
};

typedef struct Node node;

void printList(node * r){
	
	while(r != NULL){
	
		printf("%d ",r->data);
		r = r->next;
	}
	printf("\n");
}

node * getNewNode(){
	//return (node *)malloc(sizeof(node));

    return (struct Node*)malloc(sizeof(struct Node));
}

void addInOrder(node **head, int data){
	
	if(*head == NULL){
		*head = getNewNode();
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->data = data;

		return;
	}
	
	if((*head)->data > data){
		node * temp = getNewNode();
		temp->data = data;
		temp->next = *head;
		temp->prev = NULL;
		
		*head = temp;

		return;
	}
	
	node * iter = *head;
	
	while(iter->next != NULL && iter->next->data < data){
		iter = iter->next;
	}
	
	node * temp = getNewNode();
	temp->next = iter->next;
	temp->prev = iter;
	iter->next = temp;
	temp->data = data;
}

void addEnd(struct Node **head, int data){
	
	struct Node * iterator , *r;
	
	if(*head == NULL){
		(*head) = getNewNode();

		(*head)->data = data;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}

	else{
		iterator = *head;
		
        while(iterator->next != NULL){
            iterator = iterator->next;
        }
		
		r = getNewNode();

		r->next = NULL;
		r->prev = iterator;
        r->data = data;

		iterator->next = r;
	}		
}

void addHead(struct Node **head, int data){
	
	struct Node * temp = (struct Node * )malloc(sizeof(struct Node));

	temp->prev = NULL;
	temp->next = *head;
	temp->data = data;

	(*head)->prev = temp;
	(*head) = temp;	
}

void addAfter(struct Node *head, int index, int data){
	
	int i;
	if(index <= 0){
		return;
	}
		
	for(i = 0;i < index - 1; i++){
		head = head->next;

		if(head == NULL){
			printf("There is less than %d elements", index);
			return;
		}
	}
	
	struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
	
	
	temp->data = data;
	temp->prev = head;
	temp->next = head->next;
	head->next->prev = temp;
	head->next = temp;
}

void deleteByData(struct Node **head, int data){
	
	struct Node * q = *head;
	
	if(*head == q && q->data == data){
		(*head) = (*head)->next;
		(*head)->prev = NULL;

		return;
	}

	while(q != NULL){
		if(q->data == data){
			
			if(q->next == NULL){
				q->prev->next = NULL;
			}
			else{
				q->prev->next = q->next;
				q->next->prev = q->prev;
			}

			free(q);

			return;
		}
			q = q->next;
	}

	printf("%d not found\n",data);
}

void deleteByIndex(struct Node **head, int index){

	struct Node * iter = (*head);
	struct Node * temp;

	if(index == 0){
		temp = (* head);
		(* head) = (* head)->next;
		free(temp);

		return;
	}
	int counter = 1;

	while(iter->next != NULL && counter != index){
		iter = iter->next;

		counter ++;
	}

	if(iter->next == NULL){
		printf("Could not find the index %d \n", index);

		return;
	}

	//check if the node to delete is tail
	if(iter->next->next == NULL){
		temp = iter->next;
		iter->next = NULL;
	}
	else{
		temp = iter->next;
		iter->next = iter->next->next;
		iter->next->next->prev = iter;
	}
	

	free(temp);

	return;
}



int main(int argc, char *argv[]) {
	
	struct Node * head = NULL;
	/*
	addEnd(&head,10);
	addEnd(&head,20);
	addEnd(&head,99);
	addEnd(&head,88);
	addEnd(&head,77);


	addAfter(head, 1, 15);
	
	addHead(&head,1);

	printList(head);
	printf("\n");

	deleteByData(&head, 88);

	printList(head);
	printf("\n");

	deleteByData(&head, 9999);*/

	addInOrder(&head, 20);
	addInOrder(&head, 10);
	addInOrder(&head, 9);
	addInOrder(&head, 55);

	deleteByIndex(&head, 3);

	printList(head);
	printf("\n");
	
	
	return 0;
}