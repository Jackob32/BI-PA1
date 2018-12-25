/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on	17.10.2015 16:09:50
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#include <stdio.h>
using namespace std;
int main(int argc, char** argv) {
    int Cislo;    printf("ml' nob:\n");
    if (scanf("%d", &Cislo) == 1 && Cislo > 0 && Cislo <= 5) {
        printf("Qapla'\n");
        switch (Cislo){
            case 1:printf("noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");return 0;
            case 2:printf("Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");return 0;
            case 3:printf("qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");return 0;
            case 4:printf("Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");return 0;
            case 5:printf("leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");return 0;
        } } else {printf("luj\n");return 0;}}