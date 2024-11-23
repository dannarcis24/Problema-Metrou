# CERINTA:
Cautarea celui mai scurt drum intre 2statii de metrou, introduse de la tastatura, in functie de informatiile primite printr-un
fisier text despre harta metroului din Bucuresti (MetroREX).
>In fisier, pe prima linie se afla numarul totatl de statii, urmand ca pe fiecare linie, sa fie scrie numele statiei si magistrala, 
de care apartine
>O statie poate apartine mai multor magistrale, fiind punctul de intersectie al acestora

# PRINCIPALELE STRUCTURI:
typedef struct a{                                   
    char *nume;                          
    char *linie;                            
    struct a *next;                      
} statie;

typedef struct c{                         
    int nr_muchii, nr_noduri;                    
    statie **magistrala;                                
} Graph;

Harta de metrou a Bucurestiului este formata din mai multe magistrale, unde o statie, este formata din mai multe statii, despre
care trebuiesc stiute informatii, precum numele, linia si legatura cu celalalte statii, formand un graf neorientat (dintr-o statie 
eu pot sa ma duc la urmatoarea statie, dar pot sa ma si intorc). Pentru graf trebuiesc retinute urmatoarele informatii: numarul 
de muchii (legaturi intre statii), numarul de noduri (statiile) si legaturile in sine, sub forma unei liste inlantuite, care retine 
lista cu toate legaturile unei statii.   
Un element al listei reprezinta o lista inlantuita, capul listei este statia "principala", iar elementele inlantuite sunt legaturile, 
pe care le are statia, respectiv, unde poate merge mai departe.

# FUNCTIA MAIN:
Se creaza harta metroului, in functie de datele primite din fisierul text si calculeaza cel mai scurt traseu, din punct de vedere 
al numarului de statii, folosind algoritmul BFS.  
Pe ecran se va afisa numarul de statii si traseul parcurs, doar daca ambele statii exista si se poate realiza conexiunea, altfel 
se va afisa un mesaj corespunzator, in care se specifica problema.
>"este aceeasi statie"       
>"nu exista statia de plecare"                
>"nu exista statia de sosire"
          
In final este eliberata toata memoria alocata de catre graf si alte structuri necesare.

# BIBLIOTECI:
> <stdio.h>, <stdlib.h>, <string.h>, <inttypes.h> sunt incluse in biblioteca "biblioteca.h", fiind principala              
In biblioteca "biblioteca.h" sunt declarate functii pentru:
1. Siruri: alocare, realocare, citire sir
2. Liste inlantuite: creare, adaugare la final, cautarea unui nod, afisare, stergerea listei
3. HashMap: creare indice, adaugarea unui nod, cautarea unui nod, initializare, stergerea vectorului
4. Coada: creare, adaugare unui nod, eliminarea unui nod, stergerea integrala a cozii
5. Graf: functii pentru crearea grafului hartii de metrou, conform informatiilor din fisier

# TASK:
Citirea datelor din fisier si initializarea grafului este o problema destul de dificila, asta se datoreaza formatarii 
fisierului. Pentru o gestiune corecta a grafului si fara a incarca memoria mai mult decat este nevoie, in lista o statie 
trebuie sa apara o singura data si sa se cunoasca magistralele, de care apartine, in cazul in care exista conexiuni intre 
magistrale, iar legaturile sa fie corect formate.             
In fisierul text, magistralele sunt ordonate dupa denumire si informatiile sunt urmatoarele: statiile (numele statie si magistrala), 
astfel 2statii consecutive sunt conectate, doar daca apartin aceleiasi magistrale.          
>Datele se vor afla intr-un fisier, care va cuprinde numarul total de statii, urmat de cate o linie cu fiecare statie in parte (ex. Grozavesti, M1); toate datele vor fi salvate intr-un vector, pentru a putea fi sortate
               
Pe masura ce se executa citirea din fisier, statiile vor fi organizate astfel incat sa se stie daca una dintre statii 
se afla in intersectia a 2 sau mai multe magistrale prin concatenarea acestora la linie (ex. Piata Unirii M1M2M3), 
vectorul ramanand cu aceeasi lungime.                          
           
Lista de adiacenta va fi formata astfel:                   
ex. Grozavesti – Petrache Poenaru, Eroilor                           
    Eroilor – Grozavesti, Izvor, Academia Militara; lista de adiacenta va fi un vector de liste, unde fiecare element 
al vectorului este o lista, care are ca prim element statia de referinta, fiind urmat de vecinii sai, repetandu-se o 
singura data si nu se tine importanta de magistrala.                   

>nu vor exista 2liste, care inceo cu aceeasi statie (ex. Eroilor)                                  
>in cazul intersectiilor, statia nu va aparea in inlantuire (ex. Gara de Nord)    

Se va tine cont de faptul ca vectorul este orfonat conform drumului dus de la prima statie a unei magistrale pana la 
final (ex. Preciziei – Anghel Saligny), dar si de faptul ca harta formeaza un graf neorientat astfel vecinii unei statii 
vor fi predecesorul (i-1) si succesorul (i+1) cu conditia sa fie pe aceeasi magistrala.                      

>Pentru a tine cont de rezolvarea magistralelor circulare se va folosi un alt fisier, in care sunt scrise legaturile 
circulare, astfel lista de adiacenta fiind complete (ex. Dristor 1 – Dristor 2) 

!! FUNCTIILE PENTRU PRELUCRAREA SIRURILOR DE CARACTERE -> sir.c                       
!! FUNCTIILE PENTRU GRAF -> codes.c                           
!! FUNCTIILE PENTRU LISTE INLANTUITE -> list.c                  

Calcularea distantei minime intre 2statii consta in numarul de statii, deci se va folosi o parcurgere BFS, pentru a 
cauta pe “nivele” (precum cautarea pe nivele de la arbori binari), pentru evitarea ciclurilor se foloseste o functie de 
hash, astfel maparea in vector are maxim 14coloziuni.    

!! FUNCTIILE PENTRU COZI -> cozi.c                         
!! FUNCTIILE PENTRU HASHMAP -> HASHMAP.c                     
!! FUNCTIILE PENTRU BFS -> main.c               

Inaintea de BFS, se face o verificare, pentru a ne asigura ca statiile exista/ statiile sunt diferite.                      
Algoritmul este unul recursiv, asa ca afisarea statiilor va incepe din momentul, in care s-a gasit statia in intoarcere 
(recursivitate inversa), iar in timpul parcurgerii se calculeaza distanta prin intermediul unui vector de distanta 
(recursivitate directa).
