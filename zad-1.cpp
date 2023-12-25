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
    // printf("Adres tablicy dynamicznej: %p\n", wsk);

    int wybranaOpcja;
    do {
        printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("||                  Wybierz funkcje do uruchomienia                      ||\n");
        printf("|| *1* Dodanie imienia do slownika                                       ||\n");
        printf("|| *2* Usuniecie ze slownika imienia o danym numerze                     ||\n");
        printf("|| *3* Usuniecie ze slownika konkretnego imienia                         ||\n");
        printf("|| *4* Wypisanie wszystkich imion znajdujacych sie w slowniku            ||\n");
        printf("|| *5* Wypisanie wszystkich imion zaczynajacych sie dana litera          ||\n");
        printf("|| *6* Sortowanie imion alfabetycznie                                    ||\n");
        printf("|| *7* Sortowanie imion wedlug dlugosci                                  ||\n");
        printf("|| *8* Zakoncz dzialanie programu                                        ||\n");
        printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
        printf("Wprowadz numer wybranej opcji: ");
        scanf("%i", &wybranaOpcja);
        system("cls");
        switch (wybranaOpcja) {
            case 1:
                fflush(stdin);
                printf("Wprowadz imie: ");
                fgets(buf, 81, stdin);
                AddName(buf, wsk);
                break;
           case 2:
               int numer;
               printf("Wprowadz numer elementu do usuniecia: ");
               scanf("%d", &numer);
               RemoveName(numer-1, wsk);
               break;
           case 3:
               fflush(stdin);
               printf ("Wprowadz imię do usuniecia: ");
               fgets (buf, 81, stdin);
               RemoveName(buf, wsk);
               break;
            case 4:
                PrintAllNames(wsk);
                break;
            default:
                printf("Niepoprawna liczba.");
                break;
        }
    } while (wybranaOpcja != 8);

    //PrintAllNames(wsk);
    //for (int i =0; i < 10; i++) {
    //    printf("\nWprowadz imie: ");
    //    fgets(buf, 81, stdin);
    //    AddName(buf, wsk);
    //    PrintAllNames(wsk);
    //}

    return 0;
}

void InitTab(char**& wsk) {
    wsk = (char**) malloc(sizeof(char*));
    *wsk = NULL;
}

void AddName(char* buf, char**& wsk) {
    int poz = 0; // pozycja zawierająca NULL
    while(wsk[poz] != NULL) poz++;
    wsk = (char**) realloc(wsk,(poz+2)*sizeof(char *)); // powiększenie tablicy wskaźników
    wsk[poz+1] = NULL;
    wsk[poz] = strdup(buf); // skopiowanie tekstu z bufora
}

void RemoveName(int nr, char **&wsk) {
    // sprawdzanie czy element o podanym numerze istnieje
    int rozmiar = 0;
    while (wsk[rozmiar] != NULL) rozmiar++;
    if (rozmiar <= nr) {
        printf("Element o podanym numerze nie istnieje w slowniku.");
    }
    else {
        while (wsk[nr] != NULL) {
            nr++;
            wsk[nr-1] = wsk[nr];
        }
        wsk = (char**)realloc(wsk,(rozmiar-1)*sizeof(char *));
    }
}

void RemoveName(char *buf, char **&wsk) {
    // TODO Sprawdzac czy podane imie istnieje w tablicy
    int poz = 0, rozmiar = 0;
    while (wsk[rozmiar] != NULL) rozmiar++;
    while (strcmp(buf, wsk[poz]) != 0 && rozmiar > poz) poz++;
    if (rozmiar == poz) {
        printf("Podanego imienia nie ma w slowniku.");
    } else {
        while (wsk[poz] != NULL) {
            poz++;
            wsk[poz-1] = wsk[poz];
        }
        wsk = (char**)realloc(wsk,(poz-1)*sizeof(char *));
    }
}

void PrintAllNames(char **wsk) {
    int poz = 0;
    while (wsk[poz] != NULL) {
        printf("Imie %d: %s", poz, wsk[poz++]);
    }
}

void PrintNames(char first_letter, char **wsk) {
    //TODO napisac funkcje printowania na litere
}

void SortAlphabet(char **wsk) {
    //TODO napisac funkcje sortowania alfabetycznego
}

void SortLength(char **wsk) {
    //TODO napisac funkcje sortowania dlugoscia
}

