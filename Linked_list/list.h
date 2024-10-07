// knihovna.h
#ifndef LIST_H
#define LIST_H

typedef struct node {
    int data;
    struct node *next;
} Node;


// Deklarace funkcí pracujících se strukturou node
Node* create_node(int data);

// void pridatNaZacatek(struct Node **hlava, int data);
// void pridatNaKonec(struct Node **hlava, int data);
// void vypisSeznam(struct Node *hlava);
// struct Node* vyhledatPrvek(struct Node *hlava, int data);
// void odstranitPrvek(struct Node **hlava, int data);
// void uvolnitSeznam(struct Node **hlava);

#endif // LIST_H