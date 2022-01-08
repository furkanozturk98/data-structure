#include <stdio.h>
#include <stdlib.h>

struct Node{
	
	int data;	
    struct Node * next;
};

typedef struct Node node;

void printList(struct Node * head){
	
	struct Node * temp = head;
	printf("%d ",temp->data);
	temp = temp->next;
	
	while(temp != head){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

node * getNewNode(){
	return (node *)malloc(sizeof(node));
}

void addInOrder(node **head, int data){
	
	if((*head) == NULL){
		(*head) = getNewNode();

		(*head)->next = (*head);

		(*head)->data = data;

		return;
	}
	
	if((*head)->data > data){
		node * temp = getNewNode();
		node * r = (*head)->next;
		
		temp->data = data;
		temp->next = (*head);

		//traverse linkled list
		while(r->next != *head){
        	r = r->next;
    	}

		r->next = temp;
		(*head) = temp;
		
		return;
	}
	
	node * iter = (*head);
	
	while(iter->next != (*head) && iter->next->data < data){
		iter = iter->next;
	}

	
	node * temp = getNewNode();
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;
}

void addEnd(node **head,int data){
	
	if(*head == NULL){
		node* newNode = getNewNode();

        newNode->data = data;
		*head = newNode; 
		newNode->next = *head;

		return;
	}
	
	node * temp = *head;

	while(temp->next != *head){
		temp = temp->next;
	}

	temp->next = getNewNode();
	temp->next->data = data;
	temp->next->next = *head;
	
}

void addBegin(node **head,int data){
	
	if(*head == NULL){
		node* newNode = getNewNode();

		newNode->data = data;
		*head = newNode;
		newNode->next = *head;

		return;
	}
	
	node* r = *head;
	node* temp = getNewNode();

	temp->data = data;
	temp->next = *head;
	
	//traverse linkled list
	while(r->next != *head){
        r = r->next;
    }
	
	r->next = temp;
		
	*head = temp;
}

void addAfter(node **head, int index, int data){
	
	int i = 0;
	node* temp = *head ,*q;

    if(index <= 0){
		return;
	}
	
	while(temp->next != *head && i < index){
		temp = temp->next;
		i = i + 1;
	}

	if(i < index){
		printf("there is less than %d elements\n",index);
		return;
	}

	if(temp->next == *head){
		q = getNewNode();
		q->data = data;
		temp->next = q;
		q->next = *head;

		return;
	}
	
	q = getNewNode();
	q->data = data;
	q->next = temp->next;
	temp->next = q;
}

void deleteByData(node **head, int data){
	
	if(*head == NULL){
        return;
    }
	
	node *temp = *head;

	if((*head)->data == data){
		
		while(temp->next != *head){
            temp = temp->next;
        }
		
		node *r = *head;
		temp->next = (*head)->next;

		free(r);

		printf("%d has been removed\n",data);

		*head = temp->next; 

		return;
	}
	
	while(temp->next != *head && temp->next->data != data ){
        temp = temp->next;
    }
	
	if(temp->next->data !=data){
		printf("%d not found in linked list",data);
		return;
	}
	
	node *r = temp->next;
	temp->next = temp->next->next;
	
    free(r);

	printf("%d has been removed\n",data);
}

void deleteByIndex(node **head, int index){

	struct Node * iter = (*head);
	struct Node * temp;

	temp = (* head);

	if(index == 0){

		while(temp->next != *head){
            temp = temp->next;
        }

		node *r = *head;

		temp->next = (*head)->next;

		free(r);

		printf("index %d has been removed\n",index);

		*head = temp->next; 

		return;
	}

	int counter = 1;

	while(iter->next != (* head) && counter != index){
		iter = iter->next;

		counter ++;
	}

	if(iter->next == (* head)){
		printf("Could not find the index %d \n", index);

		return;
	}

	temp = iter->next;
	iter->next = iter->next->next;

	printf("index %d has been removed\n",index);

	free(temp);

	return;
}

int main()
{
    node * root = NULL;

    /*addBegin(&root, 10);
    addBegin(&root, 20);
    addEnd(&root, 30);
    addAfter(&root, 1 ,90);

    addAfter(&root, 5 ,90);

    printList(root);

    deleteByData(&root, 20);

    printList(root);

	deleteByIndex(&root, 2);*/

	addInOrder(&root, 10);
	addInOrder(&root, 20);
	addInOrder(&root, 3);
	addInOrder(&root, 7);

    printList(root);

}

