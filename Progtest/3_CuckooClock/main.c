/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on	17.11.2013 23:59:59
*/
#ifndef __PROGTEST__

#include <stdio.h>

#endif /* __PROGTEST__ */
/* Not Working */
/* vase pomocne funkce */

int overlapYear(int y) {
    if (y % 4 == 0 && ((y % 100 != 0 || y % 400 == 0) && (y % 4000 != 0)))
        return 29;
    return 28;
}

int daysInMonth(int m, int y) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return (overlapYear(y));
        default:
            return 30;
    }
}

int overlaps(int y, int m, int d, int h, int i) {
    int n = 0;
    int startyear = 1600;

    if(m<2 || (m==2 && d<29)) y--;
   for (startyear; startyear <= y; startyear++) {
        if (overlapYear(startyear) == 29)
            n++;
    }



    return n;
}

long long int calc(int y, int m, int d, int h, int min) {
    //computes minutes from last
    long long int fullminutes = (y - 1600) * 365 * 24 * 60;
int tempm=m-1;
    for (tempm; tempm >= 1; tempm--) {
        fullminutes += (daysInMonth(tempm, y)) * 24 * 60;
    }
    fullminutes += ((daysInMonth(m, y)) * 24 * 60);
    fullminutes += (((d - 1) + (overlaps(y,m,d,h,min))) * 24 * 60);
   // fullminutes += (h * 60);
    //fullminutes += (min);
    return fullminutes;
}

int inputTest(int rok, int mesic, int den, int hodina, int minuta) {

    if (rok < 1600 || mesic < 1 || mesic > 12 || den > 31 || den < 1 || hodina > 23 || minuta > 59 || minuta < 0 ||
        hodina < 0 || hodina < 0 || (den > (daysInMonth(mesic, rok))))
        return 0;
    else
        return 1;
}

int cuckooClock(int y1, int m1, int d1, int h1, int i1, int y2, int m2, int d2, int h2, int i2, long long int *cuckoo) {
    long long int time1 = calc(y1, m1, d1, h1, i1);
    long long int time2 = calc(y2, m2, d2, h2, i2);
    *cuckoo = 0;
    printf(" %lld - %lld ", time1, time2);

    if ((inputTest(y1, m1, d1, h1, i1) && inputTest(y2, m2, d2, h2, i2) && time1 <= time2) != 1) {
        return 0;
    }

    time1 = calc(y1, m1, d1, h1, i1);
    time2 = calc(y2, m2, d2, h2, i2);


    long long int diff = (time2 - time1);

    //prestupne roky vyreseni, vcetne nebo bez?
/*
    if (overlapYear(y1) == 29 && m1>2) diff-=24 * 60;

    if (overlapYear(y2) == 29 && (m2<2  || (m2==2 && d2<29))) diff-=24 * 60;

    if(overlapYear(y1) == 29 && y2==y1) diff+=24 * 60;

    */

    for (diff; diff >= 1440; diff -= 1440) {
        (*cuckoo) += 180;
    }
    printf("rozdil %lld ", diff);


    if (h1==0 && i1==0 && daysInMonth(m1,y1)==d1) { (*cuckoo) -= 180; }

    if (i1 <= 30) { (*cuckoo)++; }
    if (i2 < 30) { (*cuckoo)--; }
   // if (h1 == h2 && i2 >= 30) { (*cuckoo)++; }

    int tmp1 = h1 + 1;
    for (tmp1; tmp1 <= h2; tmp1++) {
        if (tmp1 > 12)
            *cuckoo += tmp1 - 12 + 1;
        else
            *cuckoo += tmp1 + 1;
    }
    if (h1 == 0 && i1 == 0) { (*cuckoo) += 12; }
    else if (i1 == 0) {
        if (h1 > 12)
            (*cuckoo) += h1 - 12;
        else
            (*cuckoo) += h1;
    }


    int partday = 0;
    if (h1 > h2) {
        int tmp1 = h2 + 1;
        for (tmp1; tmp1 <= h1; tmp1++) {
            if (tmp1 > 12)
                partday += tmp1 - 12 + 1;
            else
                partday += tmp1 + 1;
        }
    }

    (*cuckoo) -= partday;

    if (diff != 0) {
        printf("chyba %lld ", diff);
    }


    return 1;
}


#ifndef __PROGTEST__

int main(int argc, char *argv[]) {
    long long int cuckoo;
    int res;


    res = cuckooClock(2013, 11, 1, 12, 0, 2013, 10, 1, 12, 0, &cuckoo);
    printf("%d == 0 && %lld == N/A\n", res, cuckoo);


    res = cuckooClock(2013, 10, 32, 12, 0, 2013, 11, 10, 12, 0, &cuckoo);
    printf("%d == 0 && %lld == N/A\n", res, cuckoo);

    res = cuckooClock(2100, 2, 29, 12, 0, 2100, 2, 29, 12, 0, &cuckoo);
    printf("%d == 0 && %lld == N/A\n", res, cuckoo);

    res = cuckooClock(1900, 1, 1, 13, 15, 1900, 10, 5, 11, 20, &cuckoo);
    printf("%d == 1 && %lld == 49845\n", res, cuckoo);

    res = cuckooClock(2083, 2, 17, 2, 56, 2182, 2, 15, 10, 52, &cuckoo);
    printf("%d == 1 && %lld == 6508320\n", res, cuckoo);

    res = cuckooClock(1922, 4, 3, 17, 53, 1945, 9, 7, 7, 41, &cuckoo);
    printf("%d == 1 && %lld == 1540365\n", res, cuckoo);

    res = cuckooClock(2136, 4, 2, 9, 3, 2193, 6, 11, 17, 34, &cuckoo);
    printf("%d == 1 && %lld == 3760077\n", res, cuckoo);

    res = cuckooClock(2035, 3, 10, 16, 44, 2153, 10, 29, 19, 43, &cuckoo);
    printf("%d == 1 && %lld == 7799781\n", res, cuckoo);

    res = cuckooClock(1905, 10, 9, 14, 57, 2088, 3, 10, 11, 28, &cuckoo);
    printf("%d == 1 && %lld == 11993021\n", res, cuckoo);

    res = cuckooClock(2000, 11, 30, 0, 0, 2000, 12, 29, 0, 0, &cuckoo);
    printf("%d == 1 && %lld == 5232\n", res, cuckoo);

    res = cuckooClock(2017, 11, 22, 0, 0, 2017, 11, 22, 3, 45, &cuckoo);
    printf("%d == 1 && %lld == 22\n", res, cuckoo);

    res = cuckooClock(2050, 7, 7, 0, 30, 2050, 7, 7, 2, 0, &cuckoo);
    printf("%d == 1 && %lld == 5\n", res, cuckoo);

    res = cuckooClock(2090, 4, 15, 1, 0, 2090, 4, 15, 12, 15, &cuckoo);
    printf("%d == 1 && %lld == 89\n", res, cuckoo);

    res = cuckooClock(2082, 7, 10, 23, 0, 2082, 7, 10, 23, 45, &cuckoo);
    printf("%d == 1 && %lld == 12\n", res, cuckoo);

    res = cuckooClock(2091, 9, 5, 0, 45, 2091, 9, 5, 0, 45, &cuckoo);
    printf("%d == 1 && %lld == 0\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 13, 15, 2013, 10, 1, 18, 45, &cuckoo);
    printf("%d == 1 && %lld == 26\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 13, 15, 2013, 10, 2, 11, 20, &cuckoo);
    printf("%d == 1 && %lld == 165\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 0, 0, 2013, 10, 1, 12, 0, &cuckoo);
    printf("%d == 1 && %lld == 102\n", res, cuckoo);

    res = cuckooClock(2400, 2, 29, 12, 0, 2400, 2, 29, 12, 0, &cuckoo);
    printf("%d == 1 && %lld == 12\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 12, 0, 2013, 10, 1, 12, 0, &cuckoo);
    printf("%d == 1 && %lld == 12\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 0, 15, 2013, 10, 1, 0, 25, &cuckoo);
    printf("%d == 1 && %lld == 0\n", res, cuckoo);

    res = cuckooClock(2013, 10, 1, 12, 0, 2013, 10, 1, 12, 0, &cuckoo);
    printf("%d == 1 && %lld == 12\n", res, cuckoo);

    res = cuckooClock(2000, 1, 1, 0, 10, 2000, 1, 1, 3, 45, &cuckoo);
    printf("%d == 1 && %lld == 10\n", res, cuckoo);

    res = cuckooClock(2000, 12, 24, 0, 0, 2000, 12, 29, 0, 0, &cuckoo);
    printf("%d == 1 && %lld == 912\n", res, cuckoo);

    res = cuckooClock(2100, 12, 26, 0, 0, 2100, 12, 31, 0, 0, &cuckoo);
    printf("%d == 1 && %lld == 912\n", res, cuckoo);

    res = cuckooClock(2012, 2, 26, 10, 10, 2012, 2, 29, 8, 30, &cuckoo);
    printf("%d == 1 && %lld == 520\n", res, cuckoo);

    res = cuckooClock(2000, 1, 1, 0, 10, 2000, 1, 1, 3, 45, &cuckoo);
    printf("%d == 1 && %lld == 10\n", res, cuckoo);

    res = cuckooClock(2046, 10, 12, 0, 0, 2046, 10, 12, 0, 0, &cuckoo);
    printf("%d == 1 && %lld == 12\n", res, cuckoo);

    res = cuckooClock(2023, 10, 20, 0, 0, 2023, 10, 20, 0, 30, &cuckoo);
    printf("%d == 1 && %lld == 13\n", res, cuckoo);

    res = cuckooClock(2012, 1, 1, 13, 15, 2012, 10, 5, 11, 20, &cuckoo);
    printf("%d == 1 && %lld == 50025\n", res, cuckoo);

    res = cuckooClock(2072, 7, 2, 20, 16, 2062961132, 11, 8, 4, 7, &cuckoo);
    printf("%d == 1 && %lld == 135626365594680\n", res, cuckoo);

    res = cuckooClock(1969, 6, 19, 15, 30, 2028, 11, 11, 17, 31, &cuckoo);
    printf("%d == 1 && %lld == 3905112\n", res, cuckoo);

    res = cuckooClock(2016, 1, 7, 8, 10, 2016, 4, 4, 0, 0, &cuckoo);
    printf("%d == 1 && %lld == 15796\n", res, cuckoo);

    res = cuckooClock(1908, 4, 13, 3, 32, 2036998342, 10, 17, 8, 57, &cuckoo);
    printf("%d == 1 && %lld == 133919488976975\n", res, cuckoo);

    //res = cuckooClock(1804289383, 10, 30, 8, 16, 1920672709, 11, 6, 19, 33, &cuckoo);
    //printf("%d == 1 && %lld == 7651459414342\n", res, cuckoo);

    //res = cuckooClock(572660336, 10, 22, 0, 56, 1879492669, 7, 17, 10, 56, &cuckoo);
    //printf("%d == 1 && %lld == 85915868684645\n", res, cuckoo);

    res = cuckooClock(2087, 3, 25, 0, 30, 2087, 3, 25, 0, 30, &cuckoo);
    printf("%d == 1 && %lld == 1\n", res, cuckoo);

    res = cuckooClock(1969, 6, 19, 15, 30, 2028, 11, 11, 17, 31, &cuckoo);
    printf("%d == 1 && %lld == 3905112\n", res, cuckoo);


    res = cuckooClock(2013, 10, 1, 18, 15,
                      2013, 10, 1, 18, 20, &cuckoo);
    /*res = 1, cuckoo = 0 */
    printf("res: 1 vs %d, cuckoo: 0 vs %lld\n", res, cuckoo);


    res = cuckooClock(2013, 10, 1, 13, 15,
                      2013, 10, 1, 18, 45, &cuckoo);
    /*res = 1, cuckoo = 26 */

    printf("res: 1 vs %d, cuckoo: 26 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 10, 1, 13, 15,
                      2013, 10, 2, 11, 20, &cuckoo);
    /* res = 1, cuckoo = 165 */
    printf("res: 1 vs %d, cuckoo: 165 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 1, 1, 13, 15,
                      2013, 10, 5, 11, 20, &cuckoo);
    /* res = 1, cuckoo = 49845 */
    printf("res: 1 vs %d, cuckoo: 49845 vs %lld\n", res, cuckoo);
    res = cuckooClock(2012, 1, 1, 13, 15,
                      2012, 10, 5, 11, 20, &cuckoo);
    /* res = 1, cuckoo = 50025 */
    printf("res: 1 vs %d, cuckoo: 50025 vs %lld\n", res, cuckoo);
    res = cuckooClock(1900, 1, 1, 13, 15,
                      1900, 10, 5, 11, 20, &cuckoo);
    /* res = 1, cuckoo = 49845 */
    printf("res: 1 vs %d, cuckoo: 49845 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 10, 1, 0, 0,
                      2013, 10, 1, 12, 0, &cuckoo);
    /* res = 1, cuckoo = 102 */
    printf("res: 1 vs %d, cuckoo: 102 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 10, 1, 0, 15,
                      2013, 10, 1, 0, 25, &cuckoo);
    /* res = 1, cuckoo = 0 */
    printf("res: 1 vs %d, cuckoo: 0 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 10, 1, 12, 0,
                      2013, 10, 1, 12, 0, &cuckoo);
    /* res = 1, cuckoo = 12 */
    printf("res: 1 vs %d, cuckoo: 12 vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 11, 1, 12, 0,
                      2013, 10, 1, 12, 0, &cuckoo);
    /* res = 0, cuckoo = N/A */
    printf("res: 0 vs %d, cuckoo: N/A vs %lld\n", res, cuckoo);
    res = cuckooClock(2013, 10, 32, 12, 0,
                      2013, 11, 10, 12, 0, &cuckoo);
    /* res = 0, cuckoo = N/A */
    printf("res: 0 vs %d, cuckoo: N/A vs %lld\n", res, cuckoo);
    res = cuckooClock(2100, 2, 29, 12, 0,
                      2100, 2, 29, 12, 0, &cuckoo);
    /* res = 0, cuckoo = N/A */
    printf("res: 0 vs %d, cuckoo: N/A vs %lld\n", res, cuckoo);
    res = cuckooClock(2400, 2, 29, 12, 0,
                      2400, 2, 29, 12, 0, &cuckoo);
    /* res = 1, cuckoo = 12 */
    printf("res: 1 vs %d, cuckoo: 12 vs %lld\n", res, cuckoo);
    return 0;
}

#endif /* __PROGTEST__ */
