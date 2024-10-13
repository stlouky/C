#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// Definice struktury uzlu
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funkční prototypy
Node* create_node(int value);
void add_to_start(Node** head, int value);
void add_to_end(Node** head, int value);
Node* find_element(Node* head, int value);
bool remove_element(Node** head, int value);
void free_list(Node* head);
void print_list(Node* head);

#endif // LIST_H