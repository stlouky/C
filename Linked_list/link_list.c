#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "list.h"

#define INT_MIN (-2147483648)
#define INT_MAX 2147483647
#define MIN_MENU 1      //První položka menu
#define MAX_MENU 6      //Poslední položka menu

/**
 * Vytvoř program, který:

Implementuje jednosměrný spojový seznam pro ukládání celých čísel (int).
Poskytne uživateli následující možnosti prostřednictvím interaktivního menu:

Přidat prvek na začátek seznamu.
Přidat prvek na konec seznamu.
Vypsat všechny prvky v seznamu.
Vyhledat prvek v seznamu.
Odstranit prvek ze seznamu.
Uvolnit celý seznam a ukončit program.
Interaktivní Menu:

Program by měl zobrazit menu s výše uvedenými možnostmi a umožnit uživateli vybrat si akci.
 */

/*
Tipy:
Použití dvojitého ukazatele (struct Node **hlava) pro funkce, které mohou měnit hlavu seznamu (např. při přidávání nebo odstraňování prvku).

Práce s ukazateli:
Při přidávání nebo odstraňování prvků správně manipuluj s ukazateli, aby seznam zůstal konzistentní.
Výpis seznamu:
Projdi seznam pomocí smyčky while nebo for a vypiš hodnoty všech uzlů.
Vyhledávání prvku:
Projdi seznam a porovnávej hodnoty data v každém uzlu s hledanou hodnotou.
Odstranění prvku:
Dávej pozor na speciální případy, jako je odstraňování hlavy seznamu nebo prvku uprostřed či na konci.
*/
/*
Menu:
1. Přidat prvek na začátek
2. Přidat prvek na konec
3. Vypsat seznam
4. Vyhledat prvek
5. Odstranit prvek
6. Ukončit program
Vyberte možnost: 1
Zadejte hodnotu: 10
Prvek přidán na začátek.

Menu:
1. Přidat prvek na začátek
2. Přidat prvek na konec
3. Vypsat seznam
4. Vyhledat prvek
5. Odstranit prvek
6. Ukončit program
Vyberte možnost: 2
Zadejte hodnotu: 20
Prvek přidán na konec.

Menu:
1. Přidat prvek na začátek
2. Přidat prvek na konec
3. Vypsat seznam
4. Vyhledat prvek
5. Odstranit prvek
6. Ukončit program
Vyberte možnost: 3
Seznam: 10 -> 20

Menu:
...
*/

/**
 * Vytiskne menu (seznam).
 * @return vrátí číslo (1-6) zvolené položky v menu.
*/
int tiskni_menu();

/**
 * Přijme vstup od uživatele a ověří zda se jedná o platný vstup
 * v rozsahu danných hodnot
 * @param zprava text který se vypíše na konzoli.
 * @param rozsah_cisel má číslo rozsah (menu MIN_MENU 1 - MAX_MENU 6) 
 * @return platná hodnota zadaná uživatelem
 */
int platny_vstup(char *zprava, bool rozsah_cisel);

int main(){

    //Node next = create_node(0);
    
    switch (tiskni_menu()){
    case 1:
        printf("Zadaná hodnota [%d]\n", platny_vstup("Zadejte hodnotu:", false));
        // code 
        printf("Prvek přidán na začátek.\n\n");
        break;
    case 2:
        printf("Zadaná hodnota [%d]\n", platny_vstup("Zadejte hodnotu:", false));
        // code 
        printf("Prvek přidán na Konec.\n");
        break;
     case 3:
        printf("Seznam ");
        // code
        break;
    case 4:
        printf("Zadejte hodnotu: ");
        // code
        printf("Prvek je na...\n");
        break;
    case 5:
        printf("Zadejte hodnotu: ");
        // code
        printf("Prvek byl odstraněn\n");
        break;
    case 6:
        // code
        printf("Program byl ukončen\n");
        break;

    default:
        break;
    }
            

    return 0;
}

int platny_vstup(char *zprava, bool rozsah_cisel){
    bool platny_vstup = false;
    int vstup;
    char buffer[100]; // Dostatečně velký buffer pro vstup
    char *endptr;

    while (!platny_vstup){
        printf("%s", zprava);       
            
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Odstranění znaku nového řádku na konci řetězce
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            } else {
                // Pokud nebyl načten znak nového řádku, vyčistíme zbytek vstupu
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }

            errno = 0; // Resetujeme errno před převodem
            long temp = strtol(buffer, &endptr, 10);

            // Kontrola, zda došlo k chybě při převodu
            if (errno != 0 || endptr == buffer || *endptr != '\0') {
                printf("Neplatný vstup. Vlož číslo %d - %d\n", MIN_MENU, MAX_MENU);
                platny_vstup = false;
            } else {
                vstup = (int)temp;

                // Kontrola rozsahu hodnoty typu int
                if (temp < INT_MIN || temp > INT_MAX) {
                    printf("Zadané číslo je mimo rozsah typu int.\n");
                    platny_vstup = false;
                } else if (rozsah_cisel) {
                    if (vstup < MIN_MENU || vstup > MAX_MENU) {
                        printf("Neplatný vstup. Vlož číslo %d - %d\n", MIN_MENU, MAX_MENU);
                        platny_vstup = false;
                    } else {
                        platny_vstup = true;
                    }
                } else {
                    platny_vstup = true;
                }
            }
        } else {
            // Chyba při čtení vstupu
            printf("Chyba při čtení vstupu.\n");
            platny_vstup = false;
            // Vyčistíme vstupní buffer pro další pokus
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }     
    return vstup;
}

int tiskni_menu(){
    printf("Menu:\n"
    "1. Přidat prvek na začátek\n"
    "2. Přidat prvek na konec\n"
    "3. Vypsat seznam\n"
    "4. Vyhledat prvek\n"
    "5. Odstranit prvek\n"
    "6. Ukončit program\n"
    );

    // přijme vstup od uživatele a vrátí jako číslo
    return platny_vstup("Vyberte možnost: ", true);
}