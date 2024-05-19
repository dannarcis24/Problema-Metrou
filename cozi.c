#include "biblioteca.h"
coada* createQueue()
{
    coada *q = (coada*)malloc(sizeof(coada));
    if(!q)
    {
        printf("variabilei q nu i s-a putut aloca memorie");
        exit(1);
    }

    q->first = q->last = NULL;
    return q;
}

void enQueue(coada *q, statie *nod)
{
    if(!q->first)
    {
        q->first = q->last = nod;
        return;
    }

    q->last->next = nod;
    q->last = q->last->next;
    q->last->next = NULL;
}

statie* deQueue(coada *q)
{
    if(!q)
        return NULL;

    statie *nod = createList();
    statie *p = q->first;
    nod = q->first;
    q->first = p->next;
    free(p);

    return nod;
}

void delQueue(coada **q)
{
    if(!(*q))
        return;

    statie *p = (*q)->first;
    while(p)
    {
        statie *a = p->next;
        free(p->nume);
        free(p->linie);
        free(p);
        p = a;
    }
    free(*q);
    *q = NULL;
}
