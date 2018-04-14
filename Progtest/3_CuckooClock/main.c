#ifndef __PROGTEST__
#include <stdio.h>
#endif /* __PROGTEST__ */

/* vase pomocne funkce */
int PrestupnostRoku(int rok){
if (rok % 4 == 0 && ((rok % 100 != 0 || rok % 400 == 0) && (rok % 4000 != 0))) 
{
      printf(" P ");
    return 29;}
else 
 return 28;
}
int DniMesici(int mesic,int rok){
switch (mesic)
    {  case 1:  return 31;  break;
       case 2: return (PrestupnostRoku(rok));  break;
       case 3: return 31; break;
       case 4: return 30; break;
       case 5: return 31;  break;
       case 6: return 30; break;
       case 7: return 31; break;
       case 8 : return 31; break;
       case 9: return 30; break;
       case 10: return 31; break;
       case 11: return 30; break;
       case 12: return 31; break;
      //hodnota jina ne?? v p??edchoz??ch casech
       default: return 2; break;
    }
  }
int Prestupnych(int rok){
  
      int kolik=0;
    int zmenrok=1600;
   
  for(zmenrok; zmenrok<=rok; zmenrok++) 
  {
     if ((zmenrok % 4 == 0) && ((zmenrok % 100 != 0 || zmenrok % 400 == 0 && zmenrok % 4000 != 0)))  
     {kolik++;
     }
  }
 
     return kolik;     
      }  
long long int Prepocet(int rok, int mesic, int den, int hodina, int minuta){
long long int JenMin=0;  

JenMin+=(rok*365*24*60);

for(mesic--;mesic>=1;mesic--)
{  
 JenMin+=((DniMesici(mesic,rok))*24*60);
}
JenMin+=(((den-1)+(Prestupnych(rok)))*24*60);
JenMin+=(hodina*60);
JenMin+=(minuta);

return JenMin;
}
int podminky (int rok, int mesic, int den, int hodina, int minuta)
{
    
    if(rok<1600 || mesic<1 || mesic>12 || den>31 || den<1 || hodina>23 || minuta>59 || minuta<0 || hodina<0 || hodina <0 || (den>(DniMesici(mesic,rok))) )
    return 0;
    else
        return 1;
}
int cuckooClock ( int y1, int m1, int d1, int h1, int i1,int y2, int m2, int d2, int h2, int i2,long long int * cuckoo ) {
    long long int cas1=Prepocet(y1, m1, d1, h1, i1);
    long long int cas2=Prepocet(y2, m2, d2, h2, i2);
    if ((podminky(y1, m1, d1, h1, i1) && podminky(y2, m2, d2, h2, i2 ) && ((cas2)>=(cas1)))!=1)
    {
        return 0;
    }
  * cuckoo=0;
    
   long long int rozdil=(cas2 - cas1);
    
    for (rozdil;rozdil>=720;rozdil-=720){
   * cuckoo+=90;
    }
   printf ( "rozdil %lld ", rozdil );   
   
   
   
  if(h1<=12){
      * cuckoo+=90   ;
    rozdil-=720;
    }
    
    for(h1;h1<=12;h1++)
    {
     * cuckoo+=h1;
    * cuckoo++;
    rozdil-=60;
    }
    
      if(h2>=12){
      * cuckoo+=90   ;
      h2-=12;
       rozdil-=720;
    }
    
     for(h2;h2>0;h2--)
    {
     * cuckoo+=h1;
    * cuckoo++;
    rozdil-=60;
    }
    
   * cuckoo+=12;
    /* todo */
  
return 1;
}
#ifndef __PROGTEST__
int main ( int argc, char * argv [] ) 
 {
   long long int cuckoo;
   int res;

    res = cuckooClock ( 2013, 11,  1, 12,  0, 2013, 10,  1, 12,  0, &cuckoo );
    printf ( "%d == 0 && %lld == N/A\n", res, cuckoo );
   
    res = cuckooClock ( 2013, 10, 32, 12,  0, 2013, 11, 10, 12,  0, &cuckoo );
    printf ( "%d == 0 && %lld == N/A\n", res, cuckoo );
   
    res = cuckooClock ( 2100, 2, 29, 12,  0, 2100,  2, 29, 12,  0, &cuckoo );
    printf ( "%d == 0 && %lld == N/A\n", res, cuckoo );
   
    res = cuckooClock ( 1900,  1,  1, 13, 15, 1900, 10,  5, 11, 20, &cuckoo );
    printf ( "%d == 1 && %lld == 49845\n", res, cuckoo );
 
    res = cuckooClock ( 2083, 2, 17, 2, 56, 2182, 2, 15, 10, 52, &cuckoo );
    printf ( "%d == 1 && %lld == 6508320\n", res, cuckoo );  
 
    res = cuckooClock ( 1922, 4, 3, 17, 53, 1945, 9, 7, 7, 41, &cuckoo );
    printf ( "%d == 1 && %lld == 1540365\n", res, cuckoo );
 
    res = cuckooClock (  2136, 4, 2, 9, 3, 2193, 6, 11, 17, 34, &cuckoo );
    printf ( "%d == 1 && %lld == 3760077\n", res, cuckoo );
 
    res = cuckooClock (  2035, 3, 10, 16, 44, 2153, 10, 29, 19, 43, &cuckoo );
    printf ( "%d == 1 && %lld == 7799781\n", res, cuckoo );
 
    res = cuckooClock ( 1905, 10, 9, 14, 57, 2088, 3, 10, 11, 28, &cuckoo );
    printf ( "%d == 1 && %lld == 11993021\n", res, cuckoo );
 
    res = cuckooClock ( 2000, 11, 30, 0, 0, 2000, 12, 29, 0, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 5232\n", res, cuckoo );
 
    res = cuckooClock ( 2017, 11, 22, 0, 0, 2017, 11, 22, 3, 45, &cuckoo );
    printf ( "%d == 1 && %lld == 22\n", res, cuckoo );
 
    res = cuckooClock ( 2050, 7, 7, 0, 30, 2050, 7, 7, 2, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 5\n", res, cuckoo );
 
    res = cuckooClock ( 2090, 4, 15, 1, 0, 2090, 4, 15, 12, 15, &cuckoo );
    printf ( "%d == 1 && %lld == 89\n", res, cuckoo );
 
    res = cuckooClock ( 2082, 7, 10, 23, 0, 2082, 7, 10, 23, 45, &cuckoo );
    printf ( "%d == 1 && %lld == 12\n", res, cuckoo );
 
    res = cuckooClock ( 2091, 9, 5, 0, 45, 2091, 9, 5, 0, 45, &cuckoo );
    printf ( "%d == 1 && %lld == 0\n", res, cuckoo );
 
    res = cuckooClock ( 2013, 10,  1, 13, 15, 2013, 10,  1, 18, 45, &cuckoo );
    printf ( "%d == 1 && %lld == 26\n", res, cuckoo );  
 
    res = cuckooClock ( 2013, 10,  1, 13, 15, 2013, 10,  2, 11, 20, &cuckoo );
    printf ( "%d == 1 && %lld == 165\n", res, cuckoo );
 
    res = cuckooClock ( 2013, 10,  1,  0,  0, 2013, 10,  1, 12,  0, &cuckoo );
    printf ( "%d == 1 && %lld == 102\n", res, cuckoo );
 
    res = cuckooClock ( 2400,  2, 29, 12,  0, 2400,  2, 29, 12,  0, &cuckoo );
    printf ( "%d == 1 && %lld == 12\n", res, cuckoo );
 
    res = cuckooClock ( 2013, 10,  1, 12,  0, 2013, 10,  1, 12,  0, &cuckoo );
    printf ( "%d == 1 && %lld == 12\n", res, cuckoo );
 
    res = cuckooClock ( 2013, 10,  1,  0, 15, 2013, 10,  1,  0, 25, &cuckoo );
    printf ( "%d == 1 && %lld == 0\n", res, cuckoo );
 
    res = cuckooClock ( 2013, 10, 1, 12, 0, 2013, 10, 1, 12, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 12\n", res, cuckoo );
 
    res = cuckooClock ( 2000, 1, 1, 0,  10, 2000, 1, 1, 3,  45, &cuckoo );
    printf ( "%d == 1 && %lld == 10\n", res, cuckoo );
 
    res = cuckooClock ( 2000, 12, 24, 0, 0, 2000, 12, 29, 0, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 912\n", res, cuckoo );
 
    res = cuckooClock ( 2100, 12, 26, 0, 0, 2100, 12, 31, 0, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 912\n", res, cuckoo );
 
    res = cuckooClock ( 2012, 2, 26, 10, 10, 2012, 2, 29, 8, 30, &cuckoo );
    printf ( "%d == 1 && %lld == 520\n", res, cuckoo );
 
    res = cuckooClock ( 2000, 1, 1, 0,  10, 2000, 1, 1, 3,  45, &cuckoo );
    printf ( "%d == 1 && %lld == 10\n", res, cuckoo );
 
    res = cuckooClock ( 2046, 10, 12, 0, 0, 2046, 10, 12, 0, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 12\n", res, cuckoo );
 
    res = cuckooClock (  2023, 10, 20, 0, 0, 2023, 10, 20, 0, 30, &cuckoo);
    printf ( "%d == 1 && %lld == 13\n", res, cuckoo );
 
    res = cuckooClock ( 2012,  1,  1, 13, 15, 2012, 10,  5, 11, 20, &cuckoo );
    printf ( "%d == 1 && %lld == 50025\n", res, cuckoo );
   
    res = cuckooClock ( 2072, 7, 2, 20, 16, 2062961132, 11, 8, 4, 7, &cuckoo );
    printf ( "%d == 1 && %lld == 135626365594680\n", res, cuckoo );
   
    res = cuckooClock ( 1969, 6, 19, 15, 30, 2028, 11, 11, 17, 31, &cuckoo );
    printf ( "%d == 1 && %lld == 3905112\n", res, cuckoo );
   
    res = cuckooClock ( 2016,  1,  7, 8, 10, 2016, 4,  4, 0, 0, &cuckoo );
    printf ( "%d == 1 && %lld == 15796\n", res, cuckoo );
   
    res = cuckooClock ( 1908, 4, 13, 3, 32, 2036998342, 10, 17, 8, 57, &cuckoo );
    printf ( "%d == 1 && %lld == 133919488976975\n", res, cuckoo );
 
    res = cuckooClock ( 1804289383, 10, 30, 8, 16, 1920672709, 11, 6, 19, 33, &cuckoo );
    printf ( "%d == 1 && %lld == 7651459414342\n", res, cuckoo );
 
    res = cuckooClock ( 572660336, 10, 22, 0, 56, 1879492669, 7, 17, 10, 56, &cuckoo );
    printf ( "%d == 1 && %lld == 85915868684645\n", res, cuckoo );
   
    res = cuckooClock ( 2087, 3, 25, 0, 30, 2087, 3, 25, 0, 30, &cuckoo );
    printf ( "%d == 1 && %lld == 1\n", res, cuckoo );
   
    res = cuckooClock ( 1969, 6, 19, 15, 30, 2028, 11, 11, 17, 31, &cuckoo );
    printf ( "%d == 1 && %lld == 3905112\n", res, cuckoo );
   
   
   
   res = cuckooClock ( 2013, 10,  1, 13, 15,
                       2013, 10,  1, 18, 45, &cuckoo );
   /* res = 1, cuckoo = 26 */
 printf("%lld\n", cuckoo);
   res = cuckooClock ( 2013, 10,  1, 13, 15,
                       2013, 10,  2, 11, 20, &cuckoo );
   /* res = 1, cuckoo = 165 */

   res = cuckooClock ( 2013,  1,  1, 13, 15,
                       2013, 10,  5, 11, 20, &cuckoo );
   /* res = 1, cuckoo = 49845 */

   res = cuckooClock ( 2012,  1,  1, 13, 15,
                       2012, 10,  5, 11, 20, &cuckoo );
   /* res = 1, cuckoo = 50025 */

   res = cuckooClock ( 1900,  1,  1, 13, 15,
                       1900, 10,  5, 11, 20, &cuckoo );
   /* res = 1, cuckoo = 49845 */

   res = cuckooClock ( 2013, 10,  1,  0,  0,
                       2013, 10,  1, 12,  0, &cuckoo );
   /* res = 1, cuckoo = 102 */

   res = cuckooClock ( 2013, 10,  1,  0, 15,
                       2013, 10,  1,  0, 25, &cuckoo );
   /* res = 1, cuckoo = 0 */

   res = cuckooClock ( 2013, 10,  1, 12,  0,
                       2013, 10,  1, 12,  0, &cuckoo );
   /* res = 1, cuckoo = 12 */

   res = cuckooClock ( 2013, 11,  1, 12,  0,
                       2013, 10,  1, 12,  0, &cuckoo );
   /* res = 0, cuckoo = N/A */

   res = cuckooClock ( 2013, 10, 32, 12,  0,
                       2013, 11, 10, 12,  0, &cuckoo );
   /* res = 0, cuckoo = N/A */

   res = cuckooClock ( 2100,  2, 29, 12,  0,
                       2100,  2, 29, 12,  0, &cuckoo );
   /* res = 0, cuckoo = N/A */

   res = cuckooClock ( 2400,  2, 29, 12,  0,
                       2400,  2, 29, 12,  0, &cuckoo );
   /* res = 1, cuckoo = 12 */

   return 0;
 }
#endif /* __PROGTEST__ */
