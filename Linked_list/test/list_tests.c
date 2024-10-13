#include <stdio.h>
#include <assert.h>
#include "list.h"

// Testovací funkce definované v tomto souboru
void test_add_to_start() {
    Node* head = NULL;
    add_to_start(&head, 10);
    assert(head != NULL);
    assert(head->data == 10);
    add_to_start(&head, 20);
    assert(head->data == 20);
    assert(head->next->data == 10);
    free_list(head);
    printf("test_add_to_start úspěšně dokončen.\n");
}

void test_add_to_end() {
    Node* head = NULL;
    add_to_end(&head, 10);
    assert(head != NULL);
    assert(head->data == 10);
    add_to_end(&head, 20);
    assert(head->next != NULL);
    assert(head->next->data == 20);
    free_list(head);
    printf("test_add_to_end úspěšně dokončen.\n");
}

void test_find_element() {
    Node* head = NULL;
    add_to_end(&head, 10);
    add_to_end(&head, 20);
    add_to_end(&head, 30);
    Node* found = find_element(head, 20);
    assert(found != NULL);
    assert(found->data == 20);
    found = find_element(head, 40);
    assert(found == NULL);
    free_list(head);
    printf("test_find_element úspěšně dokončen.\n");
}

void test_remove_element() {
    Node* head = NULL;
    add_to_end(&head, 10);
    add_to_end(&head, 20);
    add_to_end(&head, 30);
    bool removed = remove_element(&head, 20);
    assert(removed == true);
    assert(find_element(head, 20) == NULL);
    removed = remove_element(&head, 40);
    assert(removed == false);
    free_list(head);
    printf("test_remove_element úspěšně dokončen.\n");
}

void test_free_list() {
    Node* head = NULL;
    add_to_end(&head, 10);
    add_to_end(&head, 20);
    add_to_end(&head, 30);
    free_list(head);
    head = NULL;
    assert(head == NULL);
    printf("test_free_list úspěšně dokončen.\n");
}

void test_print_list() {
    Node* head = NULL;
    add_to_end(&head, 10);
    add_to_end(&head, 20);
    add_to_end(&head, 30);
    printf("Očekávaný výstup: Seznam: 10 -> 20 -> 30 -> NULL\n");
    printf("Skutečný výstup: ");
    print_list(head);
    free_list(head);
    printf("test_print_list úspěšně dokončen.\n");
}
