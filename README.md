# 🚇 Metro Navigator - Bucharest Subway Router

[![C Language](https://img.shields.io/badge/Language-C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Data Structures](https://img.shields.io/badge/Focus-Data%20Structures-green?style=flat)]()

**Metro Navigator** este o aplicație dezvoltată în limbajul C care modelează harta metroului din București folosind structuri de date avansate (Grafuri, Tabele Hash și Cozi). Scopul principal este găsirea rutei optime între două stații folosind algoritmul de căutare în lățime (BFS).

## 🚀 Funcționalități

* **Modelare Rețea**: Utilizează un graf neorientat pentru a reprezenta stațiile (noduri) și legăturile dintre ele (muchii).
* **Algoritm de Rutare**: Implementează **BFS (Breadth-First Search)** pentru a garanta cel mai scurt drum (ca număr de stații) între plecare și sosire.
* **Tabelă Hash (HashMap)**: Utilizată pentru indexarea rapidă a stațiilor și verificarea vizitării acestora în timpul parcurgerii grafului, asigurând o complexitate temporală optimă.
* **Management Dinamic**: Gestionare riguroasă a memoriei pentru șiruri de caractere și liste adiacente.
* **Suport Multi-Magistrală**: Recunoaște stațiile de transfer (noduri comune între magistralele M1, M2, M3, M4, M5).



---

## 🛠️ Structura Proiectului

* `main.c`: Coordonatorul principal al aplicației; conține logica de BFS și interfața cu utilizatorul.
* `biblioteca.h`: Header-ul principal care definește structurile (`statie`, `Graph`, `coada`) și prototipurile funcțiilor.
* `codes.c`: Logica de construcție a grafului și citirea datelor din fișierul de intrare.
* `list.c`: Gestionarea listelor simplu înlănțuite pentru nodurile grafului.
* `cozi.c`: Implementarea cozii (Queue) necesară pentru algoritmul BFS.
* `HASHMAP.c`: Implementarea tabelei hash pentru căutare rapidă (funcție de hash bazată pe caracterele numelui stației).
* `sir.c`: Utilitare pentru alocarea și realocarea dinamică a memoriei pentru string-uri.
* `ListaStatii.in`: Baza de date a stațiilor (nume stație, magistrală).

---

## 🏗️ Detalii Tehnice

### Algoritmul BFS
Aplicația parcurge graful nivel cu nivel. Pentru fiecare stație curentă, se analizează toate stațiile adiacente care nu au fost încă vizitate (verificare efectuată în $O(1)$ prin HashMap). Distanța este calculată incremental până când stația destinație este găsită.

### Structuri de Date
* **Graf**: Reprezentat prin liste de adiacență.
* **HashMap**: Dimensiune fixă (71), folosind adresare deschisă/liste pentru coliziuni.
* **Coada**: Utilizată pentru a menține ordinea de vizitare a nodurilor în BFS.



---

## ⚙️ Instalare și Rulare

1.  **Cerințe**: Un compilator de C (GCC, Clang).
2.  **Compilare**:
    Utilizați următoarea comandă în terminal:
    ```bash
    gcc -o metro_nav main.c codes.c list.c cozi.c HASHMAP.c sir.c -I.
    ```
3.  **Execuție**:
    ```bash
    ./metro_nav
    ```
4.  **Utilizare**: Introduceți numele stației de plecare și al stației de sosire când vi se solicită (atenție la diacritice și formatul din `ListaStatii.in`).

---

## 📂 Format fișier de intrare (`.in`)
Fișierul trebuie să conțină numărul total de legături pe prima linie, urmat de stațiile în formatul:
`Nume Statie, Magistrala`
