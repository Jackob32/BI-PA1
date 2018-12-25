/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 	05.12.2015 14:50:41
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

int CreateArray(char ***Array, int rows, int columns) {
    if (((*Array) = static_cast<char**> (malloc(rows * sizeof ( char*)))) == NULL) {
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        if (((*Array)[i] = static_cast<char*> (malloc(columns * sizeof ( char)))) == NULL) {
            return 2;
        }
    }
    return 0;}
int Uvolni(char ***Array, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*Array)[i]);
    }
    free(*Array);
    return 0;}
int LoadInput(char ***Array, int rows, int columns){
    char c;
    int radek = 0, sloupec = 0;
    while ((c = fgetc(stdin)) != EOF) {
        if (c == '!' || c == 'o' || c == '.'){
            (*Array)[radek][sloupec] = c;
            sloupec++;
        } else if (c == '\n') {
            if (sloupec != columns) {
                printf("Nespravny vstup.\n");
                return 1;
            } else {
                radek++;
                sloupec = 0;            }
        } else if (c == EOF) {
            break;
        } else {
            printf("Nespravny vstup.\n");
            return 2;        }    }
    if (radek != rows) {
        printf("Nespravny vstup.\n");
        return 3;    }
    return 0;}

int main(void) {
    int rows, columns,nakazenych = 0, dni = -1;
    char **kancl, **druhy, **temp;
    printf("Velikost kancelare:\n");
    if (scanf("%d %d ", &rows, &columns) != 2 || rows > 500 || rows < 1 || columns > 500 || columns < 1) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    if (CreateArray(&kancl, rows, columns)) return 0;
    if (CreateArray(&druhy, rows, columns)) return 0;
    if (LoadInput(&kancl, rows, columns)) return 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            druhy[i][j] = kancl[i][j];        }    }
    bool nakazil = true;
    while (nakazil) {
        nakazil = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (kancl[i][j] == '!'){
                    if (j + 1 < columns && kancl[i][j + 1] == 'o') {
                        druhy[i][j + 1] = '!';
                        nakazil = true;                    }
                    if (j - 1 >= 0 && kancl[i][j - 1] == 'o') {
                        druhy[i][j - 1] = '!';
                        nakazil = true;                    }
                    if (i - 1 >= 0 && kancl[i - 1][j] == 'o') {
                        druhy[i - 1][j] = '!';
                        nakazil = true;                    }
                    if (i + 1 < rows && kancl[i + 1][j] == 'o') {
                        druhy[i + 1][j] = '!';
                        nakazil = true;                    }
                    druhy[i][j] = kancl[i][j];
                }            }        }
        temp = kancl;
        kancl = druhy;
        druhy = temp;
        dni++;    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            kancl[i][j] = druhy[i][j];
            if (druhy[i][j] == '!') {
                nakazenych++;            }        }    }
    if (nakazenych == 0) {
        printf("Nikdo neonemocnel.\n");
    } else {
        printf("Nakazenych: %d, doba sireni nakazy: %d\n", nakazenych, dni);
    }
    temp = NULL;
    Uvolni(&kancl,  rows);
    Uvolni(&druhy,  rows);
    return 0;}
