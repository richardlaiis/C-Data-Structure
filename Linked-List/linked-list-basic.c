#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
void print(node *x) {
	for(; x != NULL; x = x->next) {
		printf("data = %d\n", x->data);
	}
}
void freeLinkedList(node *x) {
	while(x != NULL) {
		node *next = x->next;
		free(x);
		x = next;
	}
}
#define maxn 7
int main() {
	int arr[maxn];
	for(int i = 0; i < maxn; i++) {
		scanf("%d", &(arr[i]));
	}
	node *head;
	node *prev = NULL;
	for(int i = 0; i < maxn; i++) {
		head = genNode(prev, arr[i]);
		prev = head;
	}
	print(head);
	freeLinkedList(head);
	return 0;
}
