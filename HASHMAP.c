#include "biblioteca.h"
int funct(char *sir)
{
    uint64_t index = 0;
    char c;
    while((c = *(sir++)))
        index = index*2 + c - 'A';
    index %= 71;
    return (int)(index);
}

void Map(statie *hs[], statie *elem)
{
    int index = funct(elem->nume);

    if(hs[index]->nume == NULL)
    {
        *hs[index] = *elem;
        hs[index]->next = NULL;
    }
    else
        addEnd(hs, *elem);
}

int searchHash(statie *hs[], statie *elem)
{
    int index = funct(elem->nume);

    if(!hs[index]->nume)
        return 0;
    for(register statie *p = hs[index]; p; p = p->next)
        if(!strcmp(p->nume, elem->nume))
        return 1;
    return 0;
}

void initHash(statie *hs[])
{
    for(register int i = 0; i < 71; i++)
        hs[i] = createList();
}

void delHash(statie *hs[])
{
    for(register int i = 0; i < 71; i++)
    {
        free(hs[i]->nume);
        free(hs[i]->linie);
        free(hs[i]);
        hs[i] = NULL;
    }
}
