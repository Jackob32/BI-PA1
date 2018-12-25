/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 19.11.2015 18:39:35
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/
#include <stdio.h>
#include <math.h>
using namespace std;

void extgcd(long long int length1, long long int length2, long long int & prevr, long long int & prevs, long long int & prevt) {
    long long int s = 1, t = 0, r = length2, tmp = 0;
    long long int q = 0;
    prevs = 0;
    prevt = 1;
    prevr = length1;
    while (r != 0) {
        q = ((long long int) prevr / (long long int) r);
        tmp = r;
        r = prevr - q*tmp;
        prevr = tmp;
        tmp = s;
        s = prevs - q*tmp;
        prevs = tmp;
        tmp = t;
        t = prevt - q*tmp;
        prevt = tmp;
    }
}

int main(int argc, char** argv) {
    long long int length1, length2, reslength, gcd = 0, s = 0, t = 0;
    char sign;
    printf("Delky koleji:\n");
    if (scanf("%lld %lld", &length1, &length2) != 2 || length1 <= 0 || length2 <= 0 || length1 == length2) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("Vzdalenost:\n");
    if (scanf(" %c %lld", &sign, &reslength) != 2 || (sign != '+' && sign != '-') || reslength < 0) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    extgcd(length1, length2, gcd, s, t);

    if (reslength % gcd != 0) {
        printf("Reseni neexistuje.\n");
        return 0;
    }

    /** Nasledujici 4 radky jsou muj vlastni ceil a potom muj vlastni floor**/
    long long int tVetsiNezx = (-1 * ((long double) ((((long double) (reslength)) / (length2)))*((long double) t)));
    long long int tMensiNezy = ((long double) ((((long double) (reslength)) / (length1))*((long double) s)));
    if (-1 * ((long double) ((((long double) reslength) / (length2)))*((long double) t)) > 0) {
        tVetsiNezx = (-1 * ((long double) ((((long double) (reslength)) / (length2)))*((long double) t)) - 0.000000001) + 1;
    }
    if (((long double) ((((long double) (reslength)) / (length1))*((long double) s))) <= 0) {
        tMensiNezy = ((long double) ((((long double) (reslength)) / (length1))*((long double) s) + 0.000000001)) - 1;
    }

    t *= (reslength / gcd);
    s *= (reslength / gcd);

    if (tMensiNezy < tVetsiNezx) {
        printf("Reseni neexistuje.\n");
        return 0;
    }

    if (sign == '-') {
        printf("Celkem variant: %lld\n", tMensiNezy - tVetsiNezx + 1);
        return 0;
    }

    long long int reseni = 0;
    while (tMensiNezy >= tVetsiNezx) {
        if (sign == '+') {
            long long int x = t + (length2 / gcd) * tVetsiNezx;
            long long int y = s - (length1 / gcd) * tVetsiNezx;
            printf("= %lld * %lld + %lld * %lld\n", length1, x, length2, y);
        }
        tVetsiNezx++;
        reseni++;
    }
    if (reseni == 0) {
        printf("Reseni neexistuje.\n");
    } else {
        printf("Celkem variant: %lld\n", reseni);
    }
    return 0;
}

