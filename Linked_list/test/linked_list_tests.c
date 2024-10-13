#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "linked_list_tests.h"

// Deklarace testovacích funkcí ze souboru list_tests.c
void test_add_to_start();
void test_add_to_end();
void test_find_element();
void test_remove_element();
void test_free_list();
void test_print_list();

int main() {
    // Lokální testy definované v tomto souboru
    test_create_node();

    // Testovací funkce z list_tests.c
    test_add_to_start();
    test_add_to_end();
    test_find_element();
    test_remove_element();
    test_free_list();
    test_print_list();

    printf("Všechny testy proběhly úspěšně.\n");
    return 0;
}

void test_create_node() {
    Node* node = create_node(10);
    assert(node != NULL);
    assert(node->data == 10);
    assert(node->next == NULL);
    free(node);
    printf("test_create_node úspěšně dokončen.\n");
}
