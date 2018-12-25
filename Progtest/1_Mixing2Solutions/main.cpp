/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 31.10.2015 22:18:30
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;

int check(double m1, double k1) {
    if (m1 < 0 || k1 < 0 || k1 > 1)
        return 1;
    return 0;
}

int loadSolution(double &m, double &k) {
    if (scanf("%lf %lf", &m, &k) != 2 || check(m, k)) {
        printf("Nespravny vstup.\n");
        return 0;
    }
    return 1;
}

double frag(double kx, double ky) {
    if (fabs(kx - ky) < 1e-12)
        return 0;
    return fabs(kx - ky);
}

int main(int argc, char * argv []) {
    double m1, k1, m2, k2, mx, kx, res1 = 0, res2 = 0;
    printf("Hmotnost a koncentrace #1:\n");
    if (!loadSolution(m1, k1))return 0;
    printf("Hmotnost a koncentrace #2:\n");
    if (!loadSolution(m2, k2))return 0;
    printf("Hmotnost a koncentrace vysledku:\n");
    if (!loadSolution(mx, kx))return 0;
    if (mx == 0) {
        printf("%f x #1 + %f x #2\n", res1, res2);
        return 0;
    }
    if ((kx == 0 && (k1 != 0 && k2 != 0)) || (k1 > kx && k2 > kx) || (k1 < kx && k2 < kx) || (m1 + m2 - mx < -1e-12) || (m1 * k1 + m2 * k2 - mx * kx < -1e-12)) {
        printf("Nelze dosahnout.\n");
        return 0;
    }
    if (k1 == kx && k2 == kx) {
        if (m1 >= mx) {
            res1 = mx;
            res2 = 0;
        } else {
            res1 = m1;
            res2 = mx - m1;
        }
        printf("%f x #1 + %f x #2\n", res1, res2);
        return 0;
    }
    double frag1 = frag(kx, k2);
    double frag2 = frag(kx, k1);
    res1 = (frag1 / (frag2 + frag1)) * mx;
    res2 = (frag2 / (frag1 + frag2)) * mx;
    if (res1 - m1 > 1e-12 || res2 - m2 > 1e-12) {
        printf("Nelze dosahnout.\n");
        return 0;
    }
    printf("%f x #1 + %f x #2\n", res1, res2);
    return 0;
}

