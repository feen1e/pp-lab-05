/*
Autor: Dominik Kaczmarek
Grupa: Pn/P 13:15
Temat: Laboratorium 5, zadanie 1
Data: 27.12.2023 r.
*/

#include <istream>
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
        printf("\n\n\n\n");
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
        fflush(stdin); // wyczyszczenie bufora klawiatury
        switch (wybranaOpcja) {
            case 1:
                printf("Wprowadz imie: ");
                fgets(buf, 81, stdin);
                if (buf[0] >= 97 && buf[0] <= 122) buf[0] -= 32;
                AddName(buf, wsk);
                break;
           case 2:
               int numer;
               printf("Wprowadz numer elementu do usuniecia: ");
               scanf("%d", &numer);
               RemoveName(numer-1, wsk);
               break;
           case 3:
               printf ("Wprowadz imie do usuniecia: ");
               fgets (buf, 81, stdin);
               if (buf[0] >= 97 && buf[0] <= 122) buf[0] -= 32;
                RemoveName(buf, wsk);
               break;
            case 4:
                PrintAllNames(wsk);
                break;
            case 5:
                char litera;
                printf("Podaj litere, ktora maja zaczynac sie imiona: ");
                scanf("%c", &litera);
                if (litera >= 97 && litera <= 122) litera -= 32;
                PrintNames(litera, wsk);
                break;
            case 6:
                SortAlphabet(wsk);
                break;
            case 7:
                SortLength(wsk);
                break;
            default:
                printf("Niepoprawna liczba.");
                break;
        }
    } while (wybranaOpcja != 8);

    /*PrintAllNames(wsk);
    for (int i =0; i < 10; i++) {
        printf("\nWprowadz imie: ");
        fgets(buf, 81, stdin);
        AddName(buf, wsk);
        PrintAllNames(wsk);
    }*/
    for(int i = 0; wsk[i] != NULL; i++)
        free(wsk[i]); // zwolnienie pamięci zajmowanej przez poszczegolne imiona
    free(wsk); // zwolnienie pamięci zajmowanej przez tablicę wskaźników
    return 0;
}

void InitTab(char**& wsk) {
    wsk = (char**) malloc(sizeof(char*)); // zaalokowanie pamięci na tablicę wskaźników
    *wsk = NULL;
}

void AddName(char* buf, char**& wsk) {
    int poz = 0; // pozycja zawierająca NULL
    while(wsk[poz] != NULL) poz++;
    wsk = (char**) realloc(wsk,(poz+2)*sizeof(char *)); // powiększenie tablicy wskaźników
    wsk[poz+1] = NULL;
    wsk[poz] = strdup(buf); // skopiowanie tekstu z bufora
    printf("\nImie zostalo dodane.\n");
}

void RemoveName(int nr, char **&wsk) {
    // sprawdzanie czy element o podanym numerze istnieje
    int rozmiar = 0; // rozmiar tablicy
    while (wsk[rozmiar] != NULL) rozmiar++;
    if (rozmiar <= nr) {
        printf("Podany element nie istnieje w slowniku.");
    }
    else {
        printf("\nUsunieto imie nr %d.\n", nr+1);
        free(wsk[nr]); // zwolnienie pamieci zajmowanej przez usuwane imie
        while (wsk[nr] != NULL) {
            nr++;
            wsk[nr-1] = wsk[nr];
        }
        wsk = (char**)realloc(wsk,(rozmiar)*sizeof(char *)); // zmniejszenie tablicy wskaźników
        //printf("Adres tablicy dynamicznej: %p\n", wsk);
    }
}

void RemoveName(char *buf, char **&wsk) {
    int poz = 0; // pozycja w tablicy
    while (wsk[poz] != NULL && strcmp(buf, wsk[poz]) != 0) poz++; // szukanie pozycji imienia w slowniku
    RemoveName(poz, wsk);

    /*int rozmiar = 0;
    while (wsk[rozmiar] != NULL) rozmiar++;
    if (rozmiar == poz) {
        printf("Podanego imienia nie ma w slowniku.");
    } else {
        while (wsk[poz] != NULL) {
            poz++;
            //printf("przed %s       po %s", wsk[poz-1], wsk[poz]);
            wsk[poz-1] = wsk[poz];
        }
        wsk = (char**)realloc(wsk,(rozmiar)*sizeof(char *));
        //wsk[poz] = NULL;
    }
    //printf("Adres tablicy dynamicznej: %p\n", wsk);*/
}

void PrintAllNames(char **wsk) {
    if (wsk[0] == NULL) printf("W slowniku nie ma jeszcze zadnych imion.");
    else {
        int poz = 0; // pozycja w tablicy
        while (wsk[poz] != NULL) {
            printf("Imie %d: %s", poz, wsk[poz++]);
        }
    }
}

void PrintNames(char first_letter, char **wsk) {
    if (wsk[0] == NULL) printf("W slowniku nie ma jeszcze zadnych imion.");
    else {
        int poz = 0; // pozycja w tablicy
        bool czy_wypisano = false; // zmienna przechowująca informację czy wypisano jakiekolwiek imię
        while (wsk[poz] != NULL) {
            if (wsk[poz][0] == first_letter) {
                printf("Imie %d: %s", poz+1, wsk[poz]);
                czy_wypisano = true;
            }
            poz++;
        }
        if (!czy_wypisano) printf("W slowniku nie ma imion zaczynajacych sie podana litera.");
    }
}

void SortAlphabet(char **wsk) {
    for (int i = 0; wsk[i] != NULL; i++) {
        char *pomocnicza = wsk[i]; // pomocnicza zmienna przechowująca aktualnie sortowany element
        for (int j = i - 1; j >= 0 && strcmp(wsk[j], pomocnicza) > 0; j--) {
            wsk[j + 1] = wsk[j];
            wsk[j] = pomocnicza;
        }
    }
    printf("Imiona zostaly posortowane.");
}

void SortLength(char **wsk) {
    int rozmiar = 0; // rozmiar tablicy
    while (wsk[rozmiar] != NULL) rozmiar++;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (strlen(wsk[j]) > strlen(wsk[j+1])) {
                char *pomocnicza = wsk[j]; // pomocnicza zmienna przechowująca aktualnie sortowany element
                wsk[j] = wsk[j+1];
                wsk[j+1] = pomocnicza;
            }
        }
    }
    printf("Imiona zostaly posortowane.");
}

