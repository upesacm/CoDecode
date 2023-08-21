
#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* prev;
struct Node* next;
};

void insertEnd(struct Node** head, int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;

if (*head == NULL) {
*head = newNode;
newNode->prev = NULL;
} else {
struct Node* current = *head;
while (current->next != NULL)
current = current->next;

current->next = newNode;
newNode->prev = current;
}
}

void printReverse(struct Node* head) {
struct Node* current = head;
while (current->next != NULL)
current = current->next;

while (current != NULL) {
printf("%d ", current->data);
current = current->prev;
}
printf("\n");
}
int main() {
int n;
scanf("%d", &n);

struct Node* head = NULL;
for (int i = 0; i < n; i++) {
int data;
scanf("%d", data);
insertEnd(&head, data);
}
printReverse(head);

return 0;
}

