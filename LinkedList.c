#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <stdio.h>


// worked with Tyler Swanson

struct Node* createNode (char* data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  //  Make sure memory was successfully allocated for the new node
  if (node == NULL) {
	  return NULL;
  }
  node->next = NULL;
  node->data = data;
  return node;
}

struct LinkedList* create (char* data) {
  struct LinkedList* newList = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  if (newList != NULL) {
    newList->head = createNode(data);
  }
  return newList;
}

struct LinkedList* insertAfter (struct LinkedList* list, char* insertNodeValue, char* newValue) {
  struct Node* currentNode = list->head;
  while (currentNode != NULL && strcmp(currentNode->data, insertNodeValue) != 0) {
    currentNode = currentNode->next; 
  }
  
  //  If we didn't find the value, return NULL to indicate that fact
  if (currentNode == NULL) {
    return NULL;
  }
  
  //  Otherwise, create a new node, and set up the pointers appropriately
  struct Node* newNode = createNode(newValue);
  if (newNode != NULL) {
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
  return list;
}

void print(struct LinkedList* list){
	struct Node* tmp = list->head;
	while (tmp != NULL) {
		printf ("%s", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/*
Returns 1 if the list named "list" contains a node whose
value is sValue, 0 if not
*/
int contains (struct LinkedList* list, char* sValue){
	struct Node* tmp = list->head;
	while(tmp != NULL){
		if(strcmp(sValue,tmp->data) == 0){
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

struct LinkedList* copy (struct LinkedList* src){
	struct Node* tmp = src->head;
	struct LinkedList* newLinkedList = create(src->head->data);
	while(tmp != NULL){
		char* toAdd = strdup(tmp->data);
		tmp = tmp->next;
		if(tmp != NULL){
			insertAfter(newLinkedList, toAdd, tmp->data);
		}
	}
	return newLinkedList;
}

/**
 Inserts a new node with value "value" into the list
referenced by "list" so that the new node comes before
 the node with value "sValue"
 Returns 0 if no node with value "sValue" can be found
 in the list. Returns -1 if no memory can be allocated
 for a new node, and 1 if the new node is created
**/
int insertBefore (struct LinkedList* list, char* sValue, char* value){
  struct Node* currentNode = list->head;
  struct Node* previousNode;
  if(strcmp(list->head->data, sValue) == 0){
	  struct Node* newNode = createNode(value);
  if (newNode != NULL) {
		list->head = newNode;
		newNode->next = currentNode;
  } else {
	  return -1;
  }
	return 1;
  }
  while (currentNode != NULL && strcmp(currentNode->data, sValue) != 0) {
	previousNode = currentNode;
    currentNode = currentNode->next; 
  }
  
 
  
  //  If we didn't find the value, return NULL to indicate that fact
  if (currentNode == NULL) {
    return 0;
  }
  
  //  Otherwise, create a new node, and set up the pointers appropriately
  struct Node* newNode = createNode(value);
  if (newNode != NULL) {
		previousNode->next = newNode;
		newNode->next = currentNode;
  }else{
	  return -1;
  }
  return 1;
}

/**
 Deletes the node in the list with value "value"
 Returns 0 if such a node cannot be found; otherwise
 returns 1
**/
int delete(struct LinkedList* list, char* value){
	struct Node* currentNode = list->head;
	struct Node* previousNode;
	
	while (currentNode != NULL) {
	previousNode = currentNode;
    currentNode = currentNode->next;
	if(strcmp(currentNode->data, value) == 0){
		previousNode->next = currentNode->next;
		free(currentNode);
		return 1;
	}
  }
  return 0;
}