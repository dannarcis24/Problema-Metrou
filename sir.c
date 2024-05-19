#include "biblioteca.h"
void realocare(char **sir, int nr, char *nume)
{
    *sir = (char*)realloc(*sir, sizeof(char) * nr);
    if(!(*sir))
    {
        printf("variabilei %s nu i s-a putut realoca memorie", nume);
        exit(1);
    }
}

char* alocare(int nr, char *nume)
{
    char *sir = (char*)malloc(sizeof(char) * nr);
    if(!sir)
    {
        printf("variabilei %s nu i s-a putut aloca memorie", nume);
        exit(1);
    }
    sir[0] = '\0';

    return sir;
}

char* citireSir(FILE *f, int ok)
{
    char *sir = (char*)malloc(sizeof(char));
    if(!sir)
    {
        printf("variabilei sir nu i s-a putut aloca memorie");
        exit(1);
    }

    char car;
    int k = 0;

    fscanf(f, "%c", &car);
    while((ok && car != ',') || (!ok && car != '\n'))
    {
        sir[k++] = car;
        fscanf(f, "%c", &car);

        sir = (char*)realloc(sir, sizeof(char) * (k+1));
        if(!sir)
        {
            printf("variabilei sir nu i s-a putut realoca memorie");
            exit(1);
        }

        if(feof(f))
            break;
    }
    sir[k] = '\0';

    return sir;
}
\
