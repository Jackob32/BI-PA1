/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 27.12.2015 23:56:53
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int **Result, **Temp, *Data, count = 0, GlobMin = 2147483647, Optim, Size;

int diesel(const int a,const int b,const int c,const int Size, int i) {
    count++, i++;
    if (i < Size) {
        int minA = 2147483647, minB = 2147483647, minC = 2147483647;
        if ((a + Data[i]) < GlobMin) {
            Temp[0][i] = Data[i], Temp[1][i] = 0, Temp[2][i] = 0;
            minA = diesel(a + Data[i], b, c, Size, i);
        }
        if ((b + Data[i]) < GlobMin && (b + Data[i]) < minA && !(a == b && b == c) && minA != Optim) {
            Temp[0][i] = 0, Temp[1][i] = Data[i], Temp[2][i] = 0;
            minB = diesel(a, b + Data[i], c, Size, i);
        }
        if ((c + Data[i]) < GlobMin && (c + Data[i]) < minA && (c + Data[i]) < minB && !(a == b && b == c) && minB != Optim && minA != Optim) {
            Temp[0][i] = 0, Temp[1][i] = 0, Temp[2][i] = Data[i];
            minC = diesel(a, b, c + Data[i], Size, i);
        }
        if (minA <= minB && minA <= minC) {return minA;}
        else if (minB <= minA && minB <= minC) {return minB;}
        else {return minC;}
    } else {
        int min;
        if (a >= b && a >= c) {min = a;}
        else if (b >= a && b >= c) {min = b;}
        else {min = c;}
        if (min < GlobMin) {
            GlobMin = min;
            for (int i = 0; i < 3; i++) {
                for (int p = 0; p < Size; p++) {
                    Result[i][p] = Temp[i][p];
                }
            }
        }
        return min;
    }
}

int BigSmall(const int * a, const int * b) {
    return ( *b - *a);
}

int Greedy(void) {
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < Size; i++) {
        if (a <= b && a <= c) {
            a += Data[i];
        } else if (b <= a && b <= c) {
            b += Data[i];
        } else if (c <= b && c <= a) {
            c += Data[i];
        }
    }
    //Sets the possibly reachable optimum
    if ((a + b + c) % 3 == 0) {
        Optim = (a + b + c) / 3;
    } else {
        Optim = (a + b + c) / 3 + 1;
    }

    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    }
    return c;

}

void PrintOutlet(int Outlet) {
    int prvni = 1;
    for (int i = 0; i < Size; i++) {
        if (Result[Outlet][i] != 0) {
            if (prvni) {
                printf("%d", Result[Outlet][i]);
                prvni = 0;
            } else {
                printf(", %d", Result[Outlet][i]);
            }
        }
    }
    printf("\n");
}

int OptimumDiesel(void) {
//Load data
    printf("Emise ventilu:\n");
    while (!feof(stdin)) {
        int emise;
        //Scans only N
        if (scanf(" %d ", &emise) == 1 && emise > 0) {
            Size++;
            Data = (int*) realloc(Data, (Size) * sizeof (int));
            Data[Size - 1] = emise;
        } else {
            printf("Nespravny vstup.\n");
            return 1;
        }
    }
//Sort Data Bigger-Small
    qsort(Data, Size, sizeof ( *Data), (int(*)(const void *, const void *))BigSmall);
//Calloc the result data
    Result = (int**) calloc(3, sizeof (int *));
    for (int i = 0; i < 3; i++) {
        Result[i] = (int*) calloc(Size, sizeof (int));
    }
//Calloc the temp data
    Temp = (int**) calloc(3, sizeof (int *));
    for (int i = 0; i < 3; i++) {
        Temp[i] = (int*) calloc(Size, sizeof (int));
    }
    // int min = diesel(0, 0, 0, Size, -1);
//Find the suboptimal/optimal reacheble minimum
    GlobMin = Greedy()+1;
//Does the first pick & Finds the Best possibility
    Temp[0][0] = 0, Temp[1][0] = Data[0], Temp[2][0] = 0;
    int min = diesel(0, 0 + Data[0], 0, Size, 0);
//Prints the results
    printf("Nejvyssi emise: %d\n", min);
    //printf("Count> %d\n", count);
    //printf("Greedy> %d\n", hladovy);
    printf("A: ");
    PrintOutlet(0);
    printf("B: ");
    PrintOutlet(1);
    printf("C: ");
    PrintOutlet(2);
    free(Data);
    free(Result);
    return 0;
}

int main(int argc, char** argv) {

    if (OptimumDiesel()) {
        return 0;
    }

    return 0;
}

