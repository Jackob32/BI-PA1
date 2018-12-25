/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 08.11.2015 12:44:38
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


void findSolution3(double &m1, double &k1, double &m2, double &k2, double mx, double kx) {
    double frag1 = frag(kx, k2);
    double frag2 = frag(kx, k1);
    m1 = (frag1 / (frag2 + frag1)) * mx;
    m2 = (frag2 / (frag1 + frag2)) * mx;
}

void findSolution(double &m1, double &k1, double &m2, double &k2, double &m3, double &k3, double &mx, double &kx) {
    double frg1 = frag(kx , k1);
    double frg2 = frag(kx , k2);
    double frg3 = frag(kx , k3);
    if (k2 >= kx) {
        double tmp = frg1 + frg2;
        frg1 = frg3;
        frg2 = frg3;
        frg3 = tmp;
    } else {
        double tmp = frg2 + frg3;

        frg2 = frg1;
        frg3 = frg1;
        frg1 = tmp;
    }
    m1 = (frg1 / (frg1 + frg2 + frg3)) * mx;
    m2 = (frg2 / (frg1 + frg2 + frg3)) * mx;
    m3 = (frg3 / (frg1 + frg2 + frg3)) * mx;
}

void findSolution2(double &m1, double &k1, double &m2, double &k2, double &m3, double &k3, double &mx, double &kx) {
    double arga = k1-k3;
    // printf("arga %f \n", arga);

    double argb = k2-k3;
    //printf("argb %f \n", argb);

    double rovnase = mx*(kx-k3);
    // printf("rovnase %f \n", rovnase);

    double a1=(rovnase-argb*m2)/arga;
    //printf("a1 %f \n", a1);

    double a2=m1;
    // printf("a2 %f \n", a2);

    double a=(a1+a2)/2;
    double b=((rovnase-a*arga)/argb);
    double c=mx-a-b;

    m1=a;
    m2=b;
    m3=c;

}
int main(int argc, char * argv []) {
    double m1, k1, m2, k2, m3, k3, mx, kx, res1 = 0, res2 = 0, res3 = 0;
    printf("Hmotnost a koncentrace #1:\n");
    if (!loadSolution(m1, k1))return 0;
    printf("Hmotnost a koncentrace #2:\n");
    if (!loadSolution(m2, k2))return 0;
    printf("Hmotnost a koncentrace #3:\n");
    if (!loadSolution(m3, k3))return 0;
    printf("Hmotnost a koncentrace vysledku:\n");
    if (!loadSolution(mx, kx))return 0;
    if (mx == 0) {
        printf("%f x #1 + %f x #2 + %f x #3\n", res1, res2, res3);
        return 0;
    }
    if ((kx == 0 && (k1 != 0 && k2 != 0 && k3 != 0)) ||
        (k1 > kx && k2 > kx && k3 > kx) ||
        (k1 < kx && k2 < kx && k3 < kx) ||
        (m1 + m2 + m3 - mx < -1e-8) ||
        (m1 * k1 + m2 * k2 + m3 * k3 - mx * kx < -1e-8)) {
        //printf("a %f, b %f, c %f , xx %f, all : %f \n", m1 * k1, m2 * k2, m3 * k3,mx * kx,m1 * k1 + m2 * k2 + m3 * k3 - mx * kx);
        printf("Nelze dosahnout.\n");
        return 0;
    }
    if (k1 == kx && k2 == kx && k3 == kx) {
        if (m1 >= mx) {
            res1 = mx;
            res2 = 0;
        } else if (m1 + m2 >= mx) {
            res1 = m1;
            res2 = mx - m1;
        } else {
            res1 = m1;
            res2 = m2;
            res3 = mx - m1 - m2;
        }
        printf("%f x #1 + %f x #2 + %f x #3\n", res1, res2, res3);
        return 0;
    }

    res1=m1;
    res2=m2;
    res3=m3;


    if (k1 >= k2 && k1 > k3 && k2 > k3) {
        findSolution(m1, k1, m2, k2, m3, k3, mx, kx);
    } else if (k1 >= k2 && k1 > k3 && k2 <= k3) {
        findSolution(m1, k1, m3, k3, m2, k2, mx, kx);
    } else if (k2 >= k1 && k2 > k3 && k3 > k1) {
        findSolution(m2, k2, m3, k3, m1, k1, mx, kx);
    } else if (k2 >= k1 && k2 > k3 && k3 <= k1) {
        findSolution(m2, k2, m1, k1, m3, k3, mx, kx);
    } else if (k3 >= k1 && k3 > k2 && k1>k2) {
        findSolution(m3, k3, m1, k1, m2, k2, mx, kx);
    }else if (k3 >= k1 && k3 > k2 && k1<=k2) {
        findSolution(m3, k3, m2, k2, m1, k1, mx, kx);
    }

    //  printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
    // printf("findSolution1 %f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);

    if (m1-res1 > 1e-8 || m2-res2 > 1e-8 || m3-res3 > 1e-8 || m1<0 || m2<0 || m3<0){
        m1=res1;
        m2=res2;
        m3=res3;
        findSolution2(m1, k1, m2, k2, m3, k3, mx, kx);
        //  printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
        //  printf("findSolution2 %f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);
    }

    if (m1-res1 > 1e-8 || m2-res2 > 1e-8 || m3-res3 > 1e-8 || m1<0 || m2<0 || m3<0){
        m1=res1;
        m2=res2;
        m3=res3;
        findSolution3(m1, k1, m2, k2, mx-m3, (mx*kx-m3*k3)/(mx-m3));
        //  printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
        //  printf("findSolution3-1 %f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);
    }
    if (m1-res1 > 1e-8 || m2-res2 > 1e-8 || m3-res3 > 1e-8 || m1<0 || m2<0 || m3<0){
        m1=res1;
        m2=res2;
        m3=res3;
        findSolution3(m2, k2, m3, k3, mx-m1, (mx*kx-m1*k1)/(mx-m1));
        //  printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
        //  printf("findSolution3-2 %f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);
    }
    if (m1-res1 > 1e-8 || m2-res2 > 1e-8 || m3-res3 > 1e-8 || m1<0 || m2<0 || m3<0){
        m1=res1;
        m2=res2;
        m3=res3;
        findSolution3(m1, k1, m3, k3, mx-m2, (mx*kx-m2*k2)/(mx-m2));
        //  printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
        //  printf("findSolution3-3 %f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);
    }
    if (m1-res1 > 1e-8 || m2-res2 > 1e-8 || m3-res3 > 1e-8 || fabs(m1*k1+ m2*k2+ m3*k3-mx*kx)>1e-8) {
        //printf("%f m1-res1 #1 %f m2-res2 #3 %f m3-res #3\n",m1-res1, m2-res2,m3-res3);
        printf("Nelze dosahnout.\n");
        return 0;
    }
    //printf("%f #1 + %f #2 + %f #3 =>  %f == %f\n", m1*k1, m2*k2, m3*k3,m1*k1+ m2*k2+ m3*k3, mx*kx);

    printf("%f x #1 + %f x #2 + %f x #3\n", m1, m2, m3);
    return 0;
    //???

}

