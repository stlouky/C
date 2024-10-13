#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * Vytvoří nový uzel se zadanou hodnotou.
 * 
 * @param value Hodnota, která má být uložena v novém uzlu.
 * @return Ukazatel na nově vytvořený uzel.
 */
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Chyba: Nepodařilo se alokovat paměť pro nový uzel.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

/**
 * Přidá nový uzel se zadanou hodnotou na začátek seznamu.
 * 
 * @param head Ukazatel na ukazatel hlavy seznamu.
 * @param value Hodnota, která má být přidána do seznamu.
 */
void add_to_start(Node** head, int value) {
    Node* new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

/**
 * Přidá nový uzel se zadanou hodnotou na konec seznamu.
 * 
 * @param head Ukazatel na ukazatel hlavy seznamu.
 * @param value Hodnota, která má být přidána do seznamu.
 */
void add_to_end(Node** head, int value) {
    Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/**
 * Hledá uzel se zadanou hodnotou v seznamu.
 * 
 * @param head Ukazatel na hlavu seznamu.
 * @param value Hodnota, kterou hledáme v seznamu.
 * @return Ukazatel na nalezený uzel nebo NULL, pokud není nalezen.
 */
Node* find_element(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * Odstraní uzel se zadanou hodnotou ze seznamu.
 * 
 * @param head Ukazatel na ukazatel hlavy seznamu.
 * @param value Hodnota uzlu, který má být odstraněn.
 * @return True, pokud byl uzel úspěšně odstraněn, jinak false.
 */
bool remove_element(Node** head, int value) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                // Odstraňujeme hlavu seznamu
                *head = current->next;
            } else {
                // Odstraňujeme prvek uprostřed nebo na konci
                previous->next = current->next;
            }
            free(current);
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

/**
 * Uvolní paměť všech uzlů v seznamu.
 * 
 * @param head Ukazatel na hlavu seznamu.
 */
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * Vytiskne všechny hodnoty uzlů v seznamu.
 * 
 * @param head Ukazatel na hlavu seznamu.
 */
void print_list(Node* head) {
    Node* current = head;
    printf("Seznam: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}