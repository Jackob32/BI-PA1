/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 12.12.2015 23:34:18
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    int MaxId = 0;
    int **Banka=NULL, *Counter=NULL;
    char c;


    printf("Nejvyssi ID:\n");
    if (scanf("%d", &MaxId) != 1 || MaxId <= 0) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    Counter = (int *) (malloc((MaxId + 1) * sizeof (int)));
    Banka = (int **) (malloc((MaxId + 1) * sizeof (int *)));
    for (int i = 0; i < MaxId + 1; ++i)
        (Banka)[i] = NULL;

    printf("Nabidka a poptavka:\n");

    while (!feof(stdin)){
        //(scanf("%lf,%lf", &number1, &number2) != EOF)
        int idcko = 0, price = 0;
        if (scanf(" %c", &c) != 1 || (c != '-' && c != '+')) {
            printf("Nespravny vstup.\n");
            break;
        }
        if (scanf(" %d %d ", &idcko, &price) != 2 || (idcko > MaxId) || idcko < 0 || price <= 0) {
            printf("Nespravny vstup.\n");
            break;
        }

        if (c == '+') {
            //printf("Pidavam +\n");
            if (Banka[idcko] == NULL) {
                // printf("Novy radek\n");
                Counter[idcko] = 1;
                Banka[idcko] = (int*) (malloc(Counter[idcko] * sizeof (int)));
            } else {
                // printf("Realloc\n");
                Counter[idcko]++;
                Banka[idcko] = (int*) realloc(Banka[idcko], Counter[idcko] * sizeof (int));
            }
            // printf("Prirovnani\n");
            Banka[idcko][Counter[idcko] - 1] = price;
        } else if (c == '-') {
            if (Banka[idcko] == NULL) {
                printf("Neni k dispozici.\n");
            } else {
                int MINprice = 2147483647;
                int MINpriceI = 0;
                for (int i = 0; i < Counter[idcko]; i++) {
                    if (Banka[idcko][i] < MINprice) {
                        MINprice = Banka[idcko][i];
                        MINpriceI = i;
                    }
                }
                if (MINprice <= price) {
                    printf("Prodano za %d\n", MINprice);
                    Banka[idcko][MINpriceI] = Banka[idcko][Counter[idcko] - 1];
                    Counter[idcko]--;
                    Banka[idcko] = (int*) realloc(Banka[idcko], Counter[idcko] * sizeof (int));
                } else {
                    printf("Neni k dispozici.\n");
                }
            }
        }
        /*
        printf("--------------------------\n");
        printf("%c %d %d\n",c,idcko,price);
         
   for (int p = 0; p < MaxId+1; p++) {
       if(Banka[p]!=NULL){
       for (int j = 0; j < Counter[p]; j++) {
           printf("%d ",Banka[p][j]);
       }
       }
       printf("\n");
        
   } printf("-------------------------\n");
         * */
    }



    for (int p = 0; p < MaxId + 1; p++) {
        if (Banka[p] != NULL) {
            free(Banka[p]);
        }
    }
    free(Banka);
    free(Counter);
    return 0;
}

