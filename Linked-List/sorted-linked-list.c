#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define maxn 7
typedef struct Node {
	int data;
	struct Node *next;
} node;
node *genNode(node *next, int data) {
	node *newnode = (node *)malloc(sizeof(node));
	assert(newnode != NULL);
	newnode->next = next;
	newnode->data = data;
	return newnode;
}
node *insertNode(node *head, int data) {
	node *cur = genNode(NULL, data);
	if(head == NULL) return cur;
	node *ptr = head;
	node *last = NULL;
	while(ptr != NULL && ptr->data < data) {
		last = ptr;
		ptr = ptr->next;
	}
	if(last == NULL) {
		cur->next = head;
		return cur;
	}else {
		cur->next = last->next;
		last->next = cur;
		return head;
	}
}
node *deleteNode(node *head, int data) {
	node *temp = head;
	node *last = NULL;
	while(temp != NULL && temp->data != data) {
		last = temp;
		temp = temp->next;
	}
	if(last == NULL) {
		head = temp->next;
		return head;
	}else if(temp == NULL) {
		return head;
	}else {
		last->next = temp->next;
		return head;
	}
	
}
void freeLinkedList(node *x) {
	while(x != NULL) {
		node *next = x->next;
		free(x);
		x = next;
	}
}
void printLinkedList(node *x) {
	for(; x != NULL; x = x->next) {
		printf("data: %d\n", x->data);
	}
}
int main() {
	int arr[maxn] = {5, 1, 3, 4, 7, 9, 2};
	node *head = NULL;
	for(int i = 0; i < maxn; i++) 
		head = insertNode(head, arr[i]);
	head = deleteNode(head, 4);
	printLinkedList(head);
	freeLinkedList(head);
}
