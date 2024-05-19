#include "biblioteca.h"
statie* createList()
{
    statie *list = (statie*)malloc(sizeof(statie));
    if(!list)
    {
        printf("variabilei statie nu i s-a putut aloca memorie");
        exit(1);
    }

    list->linie = list->nume = NULL;
    list->next = NULL;
    return list;
}

void addEnd(statie **list, statie elem)
{
    if(!(*list))
    {
        *list = createList();
        **list = elem;
        (*list)->next = NULL;

        return;
    }

    statie *p;
    for(p = *list; p->next; p = p->next)
        ;

    p->next = createList();
    p->next->nume = strdup(elem.nume);
    p->next->linie = strdup(elem.linie);
    p->next->next = NULL;
}

int searchList(statie *list, statie elem)
{
    if(!list)
        return 0;
    if(!strcmp(list->nume, elem.nume))
        return 1;
    return searchList(list->next, elem);
}

void afis(statie *list)
{
    if(list)
    {
        printf("%s ", list->nume);
        afis(list->next);
    }
}

void delList(statie **list)
{
    if(!(*list))
        return;

    statie *p = *list;
    while(*list)
    {
        p = (*list)->next;
        free((*list)->nume);
        free((*list)->linie);
        free(*list);
        *list = p;
    }
    *list = NULL;
}
