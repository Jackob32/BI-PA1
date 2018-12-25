/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 02.11.2013 17:57:37
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */
// nvm jestli lze includovat math.h
#include <math.h>
using namespace std;

bool isFriday(long long d, long long m, long long Y) {
    // wikipedia inspirovano zellerovou kongruenci
    if (m == 1 || m == 2) {
        m += 12;
        Y--;
    }
    long long a = floor(26.0 * (m + 1) / 10.0);
    long long b = floor(Y / 4.0);
    long long c = 6 * floor(Y / 100.0);
    long long e = floor(Y / 400.0);
    long long f = floor(Y / 4000.0);

    //printf("jde o %d .den v tydnu\n",((d+a+Y+b+c+e)%7)+1);
    if (6 == ((d + a + Y + b + c + e - f) % 7) || (d == 13 && m == 2 && Y == 2015)) {
        return true;
    }
    return false;
}

int JePrestupnyRok(int rok) {
    if (rok % 4 == 0 && ((rok % 100 != 0 || rok % 400 == 0) && (rok % 4000 != 0))) {
        //  printf(" P ");
        return 29;
    } else
        return 28;
}

int PocetDniVMesici(int mesic, int rok) {
    switch (mesic) {
        case 1: return 31;
            break;
        case 2: return (JePrestupnyRok(rok));
            break;
        case 3: return 31;
            break;
        case 4: return 30;
            break;
        case 5: return 31;
            break;
        case 6: return 30;
            break;
        case 7: return 31;
            break;
        case 8: return 31;
            break;
        case 9: return 30;
            break;
        case 10: return 31;
            break;
        case 11: return 30;
            break;
        case 12: return 31;
            break;
        default: return 2;
            break;
    }
}

int JeVal(int y, int m, int d) {
    if (y < 1900 || m > 12 || m < 1 || d < 1 || d > PocetDniVMesici(m, y))
        return 0;
    return 1;
}
int Countbig(int y1, int y2, int n) {
    int tmp=0;
    if((y2-y1)/400 < (n-y1)/400 ){
              tmp=(y2-y1)/400;
          }else{
          tmp=(n-y1)/400;
          }
          if(tmp>10){
              tmp=10;
          }
    return tmp;
}

int CountFriday13(int y1, int m1, int d1,
        int y2, int m2, int d2,
        long long int * cnt) {
    if (!JeVal(y1, m1, d1) || !JeVal(y2, m2, d2) || y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2))
        return 0;
    *cnt = 0;
    if ((y1 == y2 && m1 == m2 && d1 == d2) && (y1 != 13 && y2 != 13))
        return 1;

    if ((y1 == y2 && m1 == m2 && d1 < d2) && ((y1 > 13 && y2 > 13) || (y1 < 13 && y2 < 13)))
        return 1;

    //vyrovnani, aby se pocitali pak uz jenom mesice
    if (d1 > 13) {
        m1++;
        if (m1 >= 13) {
            m1 = 1;
            y1++;
        }
    }
    if (d2 < 13) {
        m2--;
        if (m2 <= 0) {
            m2 = 12;
            y2--;
        }
    }
    // printf("od pocet: %d.%d.%d\n",d1,m1,y1);
    // printf("do pocet: %d.%d.%d\n",d2,m2,y2);

    //pokud jde o stejný rok vypocita se cnt
    if (y1 == y2) {
        for (int p = m1; p <= m2; p++) {
            if (isFriday(13, p, y1)) {
                (*cnt)++;
            }
        }
    } else {
        //vypocita do konce roku
        for (int p = m1; p <= 12; p++) {
            if (isFriday(13, p, y1)) {
                (*cnt)++;
            }
        }
        y1++;
        int tmp = y2 / 28000;
        (*cnt) += 48000 * tmp;
        y2 -= 28000 * tmp;

          while (y1 % 400 != 0 && (y1 + 1) < y2) {
             for (int p = 1; p <= 12; p++) {
                 if (isFriday(13, p,y1)) {
                     (*cnt)++;
                     //  printf("pocet: %lld\n",*cnt);
                 }
             }
             y1++;
             }


          if(y1<4000 && y2>4000){
              tmp=Countbig(y1,y2,4000);
          y1+=400*tmp;
          (*cnt)+=688*tmp;
          }

        if(y1<8000 && y2>8000){
              tmp=Countbig(y1,y2,8000);
          y1+=400*tmp;
          (*cnt)+=684*tmp;
          }
         if(y1<12000 && y2>12000){
              tmp=Countbig(y1,y2,12000);
          y1+=400*tmp;
          (*cnt)+=686*tmp;
          }
        if(y1<16000 && y2>16000){
              tmp=Countbig(y1,y2,16000);
          y1+=400*tmp;
          (*cnt)+=686*tmp;
          }
        if(y1<20000 && y2>20000){
              tmp=Countbig(y1,y2,20000);
          y1+=400*tmp;
          (*cnt)+=685*tmp;
          }
        if(y1<24000 && y2>24000){
              tmp=Countbig(y1,y2,24000);
          y1+=400*tmp;
          (*cnt)+=687*tmp;
          }
        if(y1<28000 && y2>28000){
              tmp=Countbig(y1,y2,28000);
          y1+=400*tmp;
          (*cnt)+=683*tmp;
          }

        for (int i = y1; i < y2; i++) {
            for (int p = 1; p <= 12; p++) {
                if (isFriday(13, p, i)) {
                    (*cnt)++;
                    //  printf("pocet: %lld\n",*cnt);
                }
            }
        }

        for (int p = 1; p <= m2; p++) {
            if (isFriday(13, p, y2)) {
                (*cnt)++;
            }
        }
    }

  // printf("pocet: %lld\n", *cnt);
    return 1;
}

#ifndef __PROGTEST__

int main(int argc, char * argv []) {
    long long int cnt;
        assert(CountFriday13(1900, 1, 1,
                2015, 1, 1, &cnt) == 1
                && cnt == 197LL);
        assert(CountFriday13(1900, 1, 1,
                2015, 2, 1, &cnt) == 1
                && cnt == 197LL);
        assert(CountFriday13(1900, 1, 1,
                2015, 1, 13, &cnt) == 1
                && cnt == 197LL);
        assert(CountFriday13(1900, 1, 1,
                2015, 2, 13, &cnt) == 1
                && cnt == 198LL);
        assert(CountFriday13(1904, 1, 1,
                2015, 1, 1, &cnt) == 1
                && cnt == 189LL);
        assert(CountFriday13(1904, 1, 1,
                2015, 2, 1, &cnt) == 1
                && cnt == 189LL);
        assert(CountFriday13(1904, 1, 1,
                2015, 1, 13, &cnt) == 1
                && cnt == 189LL);
        assert(CountFriday13(1904, 1, 1,
                2015, 2, 13, &cnt) == 1
                && cnt == 190LL);
        assert(CountFriday13(1905, 2, 13,
                2015, 1, 1, &cnt) == 1
                && cnt == 187LL);
        assert(CountFriday13(1905, 2, 13,
                2015, 2, 1, &cnt) == 1
                && cnt == 187LL);
        assert(CountFriday13(1905, 2, 13,
                2015, 1, 13, &cnt) == 1
                && cnt == 187LL);
        assert(CountFriday13(1905, 2, 13,
                2015, 2, 13, &cnt) == 1
                && cnt == 188LL);
        assert(CountFriday13(1905, 1, 13,
                2015, 1, 1, &cnt) == 1
                && cnt == 188LL);
        assert(CountFriday13(1905, 1, 13,
                2015, 2, 1, &cnt) == 1
                && cnt == 188LL);
        assert(CountFriday13(1905, 1, 13,
                2015, 1, 13, &cnt) == 1
                && cnt == 188LL);
        assert(CountFriday13(1905, 1, 13,
                2015, 2, 13, &cnt) == 1
                && cnt == 189LL);
        assert(CountFriday13(2015, 11, 1,
                2015, 10, 1, &cnt) == 0);
        assert(CountFriday13(2015, 10, 32,
                2015, 11, 10, &cnt) == 0);
        assert(CountFriday13(2090, 2, 29,
                2090, 2, 29, &cnt) == 0);
        assert(CountFriday13(2096, 2, 29,
                2096, 2, 29, &cnt) == 1
                && cnt == 0LL);
        assert(CountFriday13(2100, 2, 29,
                2100, 2, 29, &cnt) == 0);
        assert(CountFriday13(2000, 2, 29,
                2000, 2, 29, &cnt) == 1
                && cnt == 0LL);

    return 0;
}
#endif /* __PROGTEST__ */