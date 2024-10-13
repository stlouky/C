#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "list.h"

#define INT_MIN (-2147483648)
#define INT_MAX 2147483647
#define MIN_MENU 1      // První položka menu
#define MAX_MENU 7      // Poslední položka menu (aktualizováno na 7 kvůli nápovědě)

/**
 * Program, který implementuje jednosměrný spojový seznam pro ukládání celých čísel (int).
 * Poskytuje uživateli následující možnosti prostřednictvím interaktivního menu:
 * - Přidání prvku na začátek seznamu
 * - Přidání prvku na konec seznamu
 * - Vypsání všech prvků v seznamu
 * - Vyhledání prvku v seznamu
 * - Odstranění prvku ze seznamu
 * - Zobrazení nápovědy pro každou položku menu
 * - Uvolnění celého seznamu a ukončení programu
 */

/**
 * Vytiskne interaktivní menu a vrátí číslo zvolené položky.
 *
 * @return Číslo (1-7) zvolené položky v menu.
 */
int tiskni_menu();

/**
 * Přijme vstup od uživatele a ověří, zda se jedná o platný vstup.
 *
 * @param zprava Text, který se vypíše na konzoli.
 * @param rozsah_cisel Pokud true, ověřuje, zda vstup spadá do rozsahu menu (MIN_MENU - MAX_MENU).
 * @return Platná hodnota zadaná uživatelem.
 */
int platny_vstup(char *zprava, bool rozsah_cisel);

/**
 * Validuje vstupní řetězec a převádí jej na celé číslo.
 *
 * @param buffer Vstupní řetězec od uživatele.
 * @return Platná hodnota zadaná uživatelem nebo -1 při chybě.
 */
int validate_input(char *buffer);

/**
 * Ověřuje, zda je hodnota v platném rozsahu menu.
 *
 * @param value Hodnota pro kontrolu.
 * @param rozsah_cisel True, pokud má být kontrolováno v rozsahu menu.
 * @return True, pokud je hodnota platná, jinak false.
 */
bool is_value_in_range(int value, bool rozsah_cisel);

/**
 * Hledá prvek v seznamu podle hodnoty.
 *
 * @param head Ukazatel na hlavu seznamu.
 * @param value Hodnota, kterou hledáme.
 * @return Ukazatel na nalezený uzel nebo NULL, pokud prvek není v seznamu.
 */
Node* find_element(Node* head, int value);

/**
 * Odstraní prvek ze seznamu podle hodnoty.
 *
 * @param head Ukazatel na ukazatel hlavy seznamu.
 * @param value Hodnota prvku, který má být odstraněn.
 * @return True, pokud byl prvek úspěšně odstraněn, jinak false.
 */
bool remove_element(Node** head, int value);

/**
 * Uvolní všechny uzly v seznamu.
 *
 * @param head Ukazatel na hlavu seznamu.
 */
void free_list(Node* head);

/**
 * Zabalí hlavní menu smyčku do samostatné funkce, která zpracovává volby uživatele.
 *
 * @param head Ukazatel na ukazatel hlavy seznamu.
 */
void run_menu(Node** head);

// Definice enumerátoru pro možnosti menu
typedef enum {
    ADD_TO_START = 1,  /**< Přidání prvku na začátek seznamu */
    ADD_TO_END,        /**< Přidání prvku na konec seznamu */
    PRINT_LIST,        /**< Vypsání všech prvků v seznamu */
    FIND_ELEMENT,      /**< Vyhledání prvku v seznamu */
    REMOVE_ELEMENT,    /**< Odstranění prvku ze seznamu */
    DISPLAY_HELP,      /**< Zobrazení nápovědy pro každou položku menu */
    EXIT_PROGRAM       /**< Ukončení programu a uvolnění paměti */
} MenuOption;

int main() {
    Node* head = NULL;  // Začátek spojového seznamu
    run_menu(&head);    // Spuštění hlavní smyčky menu
    return 0;
}

void run_menu(Node** head) {
    bool running = true;
    while (running) {
        switch ((MenuOption)tiskni_menu()) {
            case ADD_TO_START:
                add_to_start(head, platny_vstup("Zadejte hodnotu: ", false));
                printf("Prvek přidán na začátek.\n");
                break;
            case ADD_TO_END:
                add_to_end(head, platny_vstup("Zadejte hodnotu: ", false));
                printf("Prvek přidán na konec.\n");
                break;
            case PRINT_LIST:
                print_list(*head);
                break;
            case FIND_ELEMENT: {
                int value = platny_vstup("Zadejte hodnotu: ", false);
                Node* found = find_element(*head, value);
                if (found != NULL) {
                    printf("Prvek s hodnotou %d nalezen v seznamu.", value);
                } else {
                    printf("Prvek s hodnotou %d není v seznamu.", value);
                }
                break;
            }
            case REMOVE_ELEMENT: {
                int value = platny_vstup("Zadejte hodnotu: ", false);
                if (remove_element(head, value)) {
                    printf("Prvek s hodnotou %d byl odstraněn.", value);
                } else {
                    printf("Prvek s hodnotou %d nebyl nalezen v seznamu.", value);
                }
                break;
            }
            case DISPLAY_HELP:
                printf("Nápověda:"
                       "1. Přidat prvek na začátek - Přidá nový prvek na začátek seznamu."
                       "2. Přidat prvek na konec - Přidá nový prvek na konec seznamu."
                       "3. Vypsat seznam - Vypíše všechny prvky aktuálně uložené v seznamu."
                       "4. Vyhledat prvek - Umožní zadat hodnotu a vyhledat prvek v seznamu."
                       "5. Odstranit prvek - Umožní zadat hodnotu a odstranit prvek ze seznamu."
                       "6. Zobrazit nápovědu - Zobrazí tento popis všech položek menu."
                       "7. Ukončit program - Uvolní paměť a ukončí program.\n");
                break;
            case EXIT_PROGRAM:
                running = false;
                free_list(*head);
                printf("Program byl ukončen");
                break;
            default:
                break;
        }
    }
}

int platny_vstup(char *zprava, bool rozsah_cisel){
    bool platny_vstup = false;
    int vstup;
    char buffer[100]; // Dostatečně velký buffer pro vstup

    while (!platny_vstup){
        printf("%s", zprava);       
            
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (buffer[strlen(buffer) - 1] != '\n') {
                printf("Vstup je příliš dlouhý. Zkuste to znovu.");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }
            vstup = validate_input(buffer);
            if (vstup == -1) {
                printf("Neplatný vstup. Vlož číslo %d - %d", MIN_MENU, MAX_MENU);
                continue;
            }
            if (is_value_in_range(vstup, rozsah_cisel)) {
                platny_vstup = true;
            } else {
                printf("Neplatný vstup. Vlož číslo %d - %d ", MIN_MENU, MAX_MENU);
            }
        } else {
            printf("Chyba při čtení vstupu.");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }     
    return vstup;
}

int validate_input(char *buffer) {
    char *endptr;
    errno = 0;
    long temp = strtol(buffer, &endptr, 10);

    if (errno != 0 || endptr == buffer || *endptr != '\0' || temp < INT_MIN || temp > INT_MAX) {
        return -1;
    }
    return (int)temp;
}

bool is_value_in_range(int value, bool rozsah_cisel) {
    if (rozsah_cisel) {
        return value >= MIN_MENU && value <= MAX_MENU;
    }
    return true;
}

int tiskni_menu(){
    printf("Menu:\n"
    "1. Přidat prvek na začátek\n"
    "2. Přidat prvek na konec\n"
    "3. Vypsat seznam\n"
    "4. Vyhledat prvek\n"
    "5. Odstranit prvek\n"
    "6. Zobrazit nápovědu\n"
    "7. Ukončit program\n"
    );

    return platny_vstup("Vyberte možnost: ", true);
}
