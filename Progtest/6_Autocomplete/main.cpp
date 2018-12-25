/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 19.12.2015 22:59:13
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

typedef struct {
    char * m_Fraze;
    double m_Count;
} Fraze;

void deleteNew(char * str) {
    int l = strlen(str);
    if (str[l - 1] == '\n') str[l - 1] = 0;
}

int FrazesCompare(Fraze *a, Fraze *b) {
    double rozdil = (*a).m_Count - (*b).m_Count;
    if (rozdil < 0) return 1;
    if (rozdil == 0) return 0;
    return -1;
}

int main(int argc, char** argv) {
    Fraze * Frazes;
    int Frazi = 0;
    int FraziMax = 2;
    Frazes = (Fraze *) (malloc((FraziMax) * sizeof (Fraze)));

    printf("Casto hledane fraze:\n");
    while (1) {
        size_t size;
        char *line = NULL;
        double count;
        char dvojtecka;
        char n = getc(stdin);
        //neni nahodou prazdna radka?
        if (n == '\n') {
            break;
        } else {
            ungetc(n, stdin);
        }
        //nacti vstup
        if (scanf(" %lf", &count) != 1 || scanf(" %c", &dvojtecka) != 1 || dvojtecka != ':' || getline(&line, &size, stdin) == -1) {
            printf("Nespravny vstup.\n");
    for (int i = 0; i < Frazi; i++) {
        free(Frazes[i].m_Fraze);
    }
free(Frazes);
            return 0;
        }
        Frazi++;
        if (Frazi > FraziMax) {
            FraziMax *= 2;
            Frazes = (Fraze *) realloc(Frazes, (FraziMax) * sizeof (Fraze));
        }
        Frazes[Frazi - 1].m_Count = count;
        deleteNew(line);
        Frazes[Frazi - 1].m_Fraze = strdup(line);
free(line);
    }

    if (Frazi == 0) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    //seradi
    qsort((void*) Frazes, Frazi, sizeof (Frazes[0]), (int(*) (const void *, const void *))FrazesCompare);

    printf("Hledani:\n");
    char * Top50 [49];
   int Saved=0; 
    while (!feof(stdin)) {
        char * search = NULL;
       Saved=0; 
        size_t size;
        if(getline(&search, &size, stdin) == -1) {
free(search);
            break;
        }
        deleteNew(search);
        for (int i = 0; i < Frazi; i++){
            if (strcasestr(Frazes[i].m_Fraze, search) != NULL){
                Top50[Saved]=strdup(Frazes[i].m_Fraze);
                Saved++;
            }
            if(Saved>=50){
                break;
            }
        }
        
          printf("Nalezeno: %d\n", Saved);
        for (int i = 0; i < Saved; i++) {
        printf("> %s\n", Top50[i]);
    }
            for (int i = 0; i < Saved; i++) {
                free(Top50[i]);
    }
       free(search);
          
    }
  
for (int i = 0; i < Saved; i++) {
                free(Top50[i]);
    }

    for (int i = 0; i < Frazi; i++) {
        free(Frazes[i].m_Fraze);
    }
free(Frazes);
    //free
    return 0;
}
