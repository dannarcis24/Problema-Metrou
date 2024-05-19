#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

// SIRURI
void realocare(char**, int, char*);
char* alocare(int, char*);
char* citireSir(FILE*, int);

typedef struct a{
    char *nume;
    char *linie;
    struct a *next;
} statie;

// LISTE
statie* createList();
void addEnd(statie**, statie);
int searchList(statie*, statie);
void afis(statie*);
void delList(statie**);

// HASHMAP
int funct(char*);
void Map(statie*[71], statie*);
int searchHash(statie*[71], statie*);
void initHash(statie*[71]);
void delHash(statie*[71]);

typedef struct b{
    statie *first, *last;
} coada;

// COZI
coada* createQueue();
void enQueue(coada*, statie*);
statie* deQueue(coada*);
void delQueue(coada**);

typedef struct c{
    int nr_muchii, nr_noduri;
    statie **magistrala;
} Graph;

Graph* createGraph();
void duplicat(statie*, int, int*);
statie* sortStatii(FILE*, int, Graph*);
statie* Search(Graph*, char*);
int sameStation(char*, char*);
void ListaAdiacenta(Graph*, statie*, int);
int muchii(statie**, int);
Graph* input();
void delGraph(Graph**);
