/*
Autor: Dominik Kaczmarek
Grupa: Pn/P 13:15
Temat: Laboratorium 5, zadanie 1
Data: 12.12.2023 r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicjalizacja dynamicznej tablicy dwuwymiarowej.
void InitTab(char **&wsk);

// Dodawanie nowego imienia do tablicy dynamicznej
void AddName(char *buf, char **&wsk);

// Usuwanie imienia znajdującego się w tablicy na danej pozycji
void RemoveName(int nr, char **&wsk);

// Usuwanie z tablicy imienia, wprowadzonego z klawiatury
void RemoveName(char *buf, char **&wsk);

// Drukowanie na ekranie wszystkich imion
void PrintAllNames(char **wsk);

// Drukowanie na ekranie imion rozpoczynających się wskazaną literą
void PrintNames(char first_letter, char **wsk);

// Sortowanie imion zawartych w tablicy według alfabetu
void SortAlphabet(char **wsk);

// Sortowanie imion zawartych w tablicy według długości
void SortLength(char **wsk);

int main() {
    printf("Autor: Dominik Kaczmarek PnP 13:15\n");

    char **wsk; // wskaźnik na dwuwymiarową tablice dynamiczną w której będą pamiętane wszystkie imiona
    char buf[81]; // bufor na dane wczytywane z klawiatury
    InitTab(wsk); // Inicjalizacja tablicy dynamicznej

    AddName(buf,wsk);


    return 0;
}

void InitTab(char**& wsk) {
    wsk = (char**) malloc(sizeof(char*));
    wsk[0] = NULL;
}

void AddName(char* buf, char**& wsk) {
    int poz = 0; // pozycja zawierająca NULL
    while(wsk[poz] != NULL) poz++;
    wsk = (char**)realloc(wsk,(poz+2)*sizeof(char *)); // powiększenie tablicy wskaźników
    wsk[poz+1] = NULL;
    wsk[poz] = strdup(buf); // skopiowanie tekstu z bufora
}
