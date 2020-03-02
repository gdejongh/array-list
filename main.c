#include "LinkedList.h"
#include <stdio.h>

int main (int argc, char** argv) {
 struct LinkedList* list = create("Hello");
 insertAfter(list, "Hello", " ");
 insertAfter(list, " ", "World");
 insertAfter(list, "World", "\n");	
 print(list);
 printf("%d\n",contains(list, "Hello"));
 printf("%d\n",contains(list, " "));
 printf("%d\n",contains(list, "World"));
 printf("%d\n",contains(list, "goodbye"));
 struct LinkedList* newList = copy(list);
 insertAfter(list, " ", "new");
 print(newList);
 print(list);
 insertBefore(list, "World", " Cruel ");
 print(list);
 delete(list, " Cruel ");
 print(list);
}