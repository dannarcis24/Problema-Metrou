#include "biblioteca.h"

int verif(Graph *g, char *sir1, char *sir2)
{
    if(!strcmp(sir1, sir2))
    {
        printf("este aceeasi statie");
        return 0;
    }
    if(!Search(g, sir1))
    {
        printf("nu exista statie de plecare");
        return 0;
    }
    if(!Search(g, sir2))
    {
        printf("nu exista statia de sosire");
        return 0;
    }
    return 1;
}

void BFS(Graph *g, statie *finish, coada *q, statie *hs[], int dist[], int *h)
{
    statie *curr = deQueue(q);
    curr = Search(g, curr->nume);
    if(curr == finish)
    {
        *h = dist[funct(finish->nume)];
        printf("Numarul de statii: %d\n", *h);
        printf("%s ", finish->nume);
        return;
    }

    Map(hs, curr);
    *h = dist[funct(curr->nume)];
    if(*h == -1)
    {
        *h = 0;
        dist[funct(curr->nume)] = 1;
    }
    for(register statie *p = curr->next; p; p = p->next)
        if(!searchHash(hs, p))
        {
            dist[funct(p->nume)] = *h +1;
            statie *aux = createList();
            *aux = *p;
            aux->next = NULL;
            enQueue(q, aux);
        }

    BFS(g, finish, q, hs, dist, h);

    if(*h && searchList(curr, *finish))
    {
        printf("%s ", curr->nume);
        finish = Search(g, curr->nume);
    }
}

int height(Graph *g, char *sir1, char *sir2)
{
    if(!verif(g, sir1, sir2))
        return 0;

    int h = 0;
    statie *statie1 = Search(g, sir1),
           *statie2 = Search(g, sir2);
    coada *q = createQueue();

    statie *hs[71];
    initHash(hs);
    int dist[71];
    for(register int i = 0; i < 71; i++)
        dist[i] = -1;

    statie *aux = createList();
    *aux = *statie1;
    aux->next = NULL;
    enQueue(q, aux);

    BFS(g, statie2, q, hs, dist, &h);

    delHash(hs);
    delQueue(&q);
    return h;
}

int main()
{
    Graph* g = input();
    int h = height(g, "Eroilor", "Grozavesti");
    delGraph(&g);
    return 0;
}
