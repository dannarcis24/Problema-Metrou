#include "biblioteca.h"
Graph* createGraph()
{
    Graph *g = (Graph*)malloc(sizeof(Graph));
    if(!g)
    {
        printf("variabilei g nu i s-a putut aloca memorie");
        exit(1);
    }

    g->nr_muchii = g->nr_noduri = 0;
    g->magistrala = NULL;
    return g;
}

void duplicat(statie *list, int nr, int *nod)
{
    char *sir = alocare(strlen(list[nr].linie)+1, "sir");
    strcpy(sir, list[nr].linie);

    for(register int i = 0; i < nr; i++)
        if(strcmp(list[i].nume, list[nr].nume) == 0)
        {
            realocare(&sir, strlen(sir) + strlen(list[i].linie)+1, "sir");
            strcat(sir, list[i].linie);
            (*nod)--;
            break;
        }
    for(register int i = 0; i <= nr; i++)
        if(strcmp(list[i].nume, list[nr].nume) == 0)
        {
            realocare(&list[i].linie, strlen(sir)+1, "list[i].linie");
            strcpy(list[i].linie, sir);
        }

    free(sir);
}

statie* sortStatii(FILE *f, int nr, Graph *g)
{
    statie *list = (statie*)malloc(sizeof(statie) * nr);
    if(!list)
    {
        printf("variabilei list nu i s-a putut aloca memorie");
        exit(1);
    }

    g->nr_muchii = 0;
    for(register int i = 0; i < nr; i++)
    {
        list[i].nume = citireSir(f, 1);
        fseek(f, 1L, SEEK_CUR);
        list[i].linie = citireSir(f, 0);
        duplicat(list, i, &g->nr_noduri);

        list[i].next = NULL;
    }

    return list;
}

statie* Search(Graph *g, char *sir)
{
    for(register int i = 0; i < g->nr_noduri; i++)
        if(g->magistrala[i]->nume)
        {
            if(!strcmp(g->magistrala[i]->nume, sir))
                return g->magistrala[i];
        }
        else
            break;
    return NULL;
}

int sameStation(char *sir1, char *sir2)
{
    if(strstr(sir1, "M1") && strstr(sir2, "M1"))
        return 1;
    if(strstr(sir1, "M2") && strstr(sir2, "M2"))
        return 1;
    if(strstr(sir1, "M3") && strstr(sir2, "M3"))
        return 1;
    if(strstr(sir1, "M4") && strstr(sir2, "M4"))
        return 1;
    if(strstr(sir1, "M5") && strstr(sir2, "M5"))
        return 1;

    return 0;
}

void ListaAdiacenta(Graph *g, statie *list, int nr)
{
    g->magistrala = (statie**)malloc(sizeof(statie*) * g->nr_noduri);
    if(!g->magistrala)
    {
        printf("variabilei g->magistrala nu i s-a putut aloca memorie");
        exit(1);
    }
    for(register int i = 0; i < g->nr_noduri; i++)
        g->magistrala[i] = createList();

    int k = 0;
    for(register int i = 0; i < nr; i++)
        if(!Search(g, list[i].nume))
        {
            *(g->magistrala[k]) = list[i];
            g->magistrala[k]->next = NULL;

            if(i)
                if(sameStation(list[i].linie, list[i-1].linie) && !searchList(g->magistrala[k], list[i-1]))
                    addEnd(&g->magistrala[k], list[i-1]);
            if(i < nr-1)
                if(sameStation(list[i].linie, list[i+1].linie) && !searchList(g->magistrala[k], list[i+1]))
                    addEnd(&g->magistrala[k], list[i+1]);

            k++;
        }
        else
        {
            statie *p = Search(g, list[i].nume);

            if(i)
                if(sameStation(list[i].linie, list[i-1].linie) && !searchList(p, list[i-1]))
                addEnd(&p, list[i-1]);
            if(i < nr - 1)
                if(sameStation(list[i].linie, list[i+1].linie) && !searchList(p, list[i+1]))
                addEnd(&p, list[i+1]);
        }

//adaugarea de muchii separate se va face cu citirea nodurilot dintr-un fisier dinstinctiv, asta doar pentru magistrale circulare
//functie de search dupa un element si se adauga la final, in cazul de fata nu am nevoie
    statie *p = Search(g, "Dristor 1");
    statie *q = Search(g, "Dristor 2");
    if(p && q)
    {
        addEnd(&p, *q);
        addEnd(&q, *p);
    }
}

int muchii(statie **listA, int nr)
{
    int m = 0;
    for(register int i = 0; i < nr; i++)
        for(register statie *p = listA[i]; p->next; p = p->next)
        m++;
    return m;
}

Graph* input()
{
    FILE *f = fopen("ListaStatii.in", "rt");
    if(!f)
    {
        printf("fisierul ListaStatii.in nu s-a putut deschide");
        exit(1);
    }

    Graph *metrou = createGraph();

    // M1 - 22STATII
    // M2 - 15STATII
    // M3 - 15STATII
    // M4 - 8STATII
    // M5 - 10STATII
    fscanf(f, "%d", &metrou->nr_noduri);
    fseek(f, 2L, SEEK_CUR);

    int nr = metrou->nr_noduri;
    statie *list = sortStatii(f, metrou->nr_noduri, metrou);
    fclose(f);
    ListaAdiacenta(metrou, list, nr);
    free(list);
    metrou->nr_muchii = muchii(metrou->magistrala, metrou->nr_noduri);

    return metrou;
}

void delGraph(Graph **g)
{
    if(!(*g))
    {
        printf("graful este gol");
        return;
    }

    if((*g)->magistrala)
    {
        for(register int i = 0; i < (*g)->nr_noduri; i++)
            delList(&(*g)->magistrala[i]);
        free((*g)->magistrala);
    }

    free(*g);
    *g = NULL;
}
