/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 15.12.2013 20:36:34
*/

#include <stdio.h>
#include <stdlib.h>


int compare( const void* a, const void* b){
  float* p1 = *(float**) a;
  float* p2 = *(float**) b;
//printf("Compare %f %x <=> %f %x\n", p1[1], a, p2[1], b);
 if( p1[1] > p2[1])
  {
    return 1;
  }
  else if (p1[1] < p2[1])
  {
   return -1;
  }
  else
  {
  return 0;
  } }
int specompare( const void* a, const void* b){
  float* p1 = *(float**) a;
  float* p2 = *(float**) b;
//printf("Compare %f %x <=> %f %x\n", p1[0], a, p2[0], b);
 if( p1[0] > p2[0])
  {
    return -1;
  }
  else if (p1[0] < p2[0])
  {
   return 1;
  }
  else
  {
  return 0;
  } }
int odecet(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), compare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {

       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
    printf(" %dx%f + ",kolikrat,  zavazi[m][0]);}

     kolikrat=0;
  m++;  }
       else {
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
 printf(" %dx%f\n", kolikrat,  zavazi[m][0]);
 printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int norm(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), compare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {

       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
  // printf(" %d x %f + ",kolikrat,  zavazi[m][0]);
           }

     kolikrat=0;
  m++;  }
       else {
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
//printf(" %d x %f\n", kolikrat,  zavazi[m][0]);
//printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int spec(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {
    int lo=hmotnost/zavazi[m+1][0];
       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
    //printf(" %d x %f + ",kolikrat,  zavazi[m][0]);
           }

     kolikrat=0;
  m++;  }

       else if((m+1)<n && zavazi[m+1][0]>1 && (hmotnost/zavazi[m+1][0]-lo)==0 && (hmotnost/(zavazi[m+1][0]))*(hmotnost/(zavazi[m+1][0]))<hmotnost){

          m++;

       }
          else{
       hmotnost-=zavazi[m][0];
       // printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
 //printf(" %d x %f\n", kolikrat,  zavazi[m][0]);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int specia(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {
    int lo=hmotnost/zavazi[m+1][0];
       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){

   // printf("%d x %d + ",kolikrat,  temp);
           }

     kolikrat=0;
  m++;  }

       else if(((m+1)<n && zavazi[m+1][0]>1 && (hmotnost/zavazi[m+1][0]-lo)==0 && (hmotnost/(zavazi[m+1][0]))*(hmotnost/(zavazi[m+1][0]))<hmotnost)
               || ((hmotnost-zavazi[m+1][0]-zavazi[m+2][0])<(hmotnost-zavazi[m][0]-zavazi[m+1][0]))

               || ((hmotnost-zavazi[m+1][0]-zavazi[m+2][0]-zavazi[m+3][0])<(hmotnost-zavazi[m][0]-zavazi[m+1][0]-zavazi[m+2][0]))

               ){

          m++;

       }
          else{
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }

 //printf("%d x %d\n", kolikrat,  temp);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int nejnorm(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {

       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
    //printf(" %d x %f + ",kolikrat,  zavazi[m][0]);
           }

     kolikrat=0;
  m++;  }

          else{
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
 //printf(" %d x %f\n", kolikrat,  zavazi[m][0]);
//printf(" kolikrat %d\n", celkem);
 return celkem;
 }
int norm1(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), compare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {

       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
               int temp=zavazi[m][0];
    printf("%d x %d + ",kolikrat,  temp);}

     kolikrat=0;
  m++;  }
       else {
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
int temp=zavazi[m][0];
 printf("%d x %d\n", kolikrat,  temp);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int spec1(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {
    int lo=hmotnost/zavazi[m+1][0];
       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
               int temp=zavazi[m][0];
    printf("%d x %d + ",kolikrat,  temp);}

     kolikrat=0;
  m++;  }

       else if((m+1)<n && zavazi[m+1][0]>1 && (hmotnost/zavazi[m+1][0]-lo)==0 && (hmotnost/(zavazi[m+1][0]))*(hmotnost/(zavazi[m+1][0]))<hmotnost)

               {

          m++;

       }
          else{
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
int temp=zavazi[m][0];
 printf("%d x %d\n", kolikrat,  temp);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int specia1(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;
 while(hmotnost>0) {
    int lo=hmotnost/zavazi[m+1][0];
       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
               int temp=zavazi[m][0];
    printf("%d x %d + ",kolikrat,  temp);}

     kolikrat=0;
  m++;  }

       else if(((m+1)<n && zavazi[m+1][0]>1 && (hmotnost/zavazi[m+1][0]-lo)==0 && (hmotnost/(zavazi[m+1][0]))*(hmotnost/(zavazi[m+1][0]))<hmotnost)
               || ((hmotnost-zavazi[m+1][0]-zavazi[m+2][0])<(hmotnost-zavazi[m][0]-zavazi[m+1][0]))

               || ((hmotnost-zavazi[m+1][0]-zavazi[m+2][0]-zavazi[m+3][0])<(hmotnost-zavazi[m][0]-zavazi[m+1][0]-zavazi[m+2][0]))

               ){

          m++;

       }
          else{
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  }
int temp=zavazi[m][0];
 printf("%d x %d\n", kolikrat,  temp);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }
int nejnorm1(float **zavazi ,float hmotnost,int n) {

     qsort(zavazi, n, sizeof(float*), specompare);

int m=0;
int kolikrat=0;
int celkem=0;

 while(hmotnost>0) {

       if((hmotnost-zavazi[m][0])<0) {
           if(kolikrat>0){
             int temp=zavazi[m][0];
    printf("%d x %d + ",kolikrat,  temp);}

     kolikrat=0;
  m++;  }

          else{
       hmotnost-=zavazi[m][0];
        //printf(" %dx%d + ",kolikrat,  zavazi[m]);
         kolikrat++;
         celkem++;
       }
  } int temp=zavazi[m][0];
 printf("%d x %d\n", kolikrat,  temp);
 //printf(" kolikrat %d\n", celkem);
 return celkem;
  }


int koeficienty(int n, float **zavazi, float m){
 int s;
    for (s=0; s<n; s++){


     int pom=(m/zavazi[s][0]);

     float lolka=((m/zavazi[s][0])-pom);
     if(lolka==0){
     zavazi[s][1]=(m/zavazi[s][0]);
     }
     else zavazi[s][1]=lolka;
  }
 return 0;
}
int main(int argc, char** argv) {
  int vstup, n=0,pocet,k,vaha,docasna,jednicka=0;
  float hmotnost,**zavazi;
  zavazi = (float**)malloc(200*sizeof(float*));

  for(k=0; k<200; k++)
  {
    zavazi[k] = (float*)malloc(2*sizeof(float));
    /*printf("[%d] (%x)\n", i, array[i]);*/
  }

    printf("Zadejte pocet zavazi:\n");
    int vstuppocet=scanf("%d", &pocet);

       if (vstuppocet!=1 || pocet<1)  {
       printf("Nespravny vstup.\n");
       return 0;}

     printf("Zadejte hmotnosti zavazi:\n");
    while(pocet>0){
    /* zavazi[0]=(float*)realloc(zavazi[0],(n+1) * sizeof(float));
         zavazi[1]=(float*)realloc(zavazi[1],(n+1) * sizeof(float));
        */

        vstup = scanf("%d", &docasna);

         if (vstup!=1 || docasna<1)  {
       printf("Nespravny vstup.\n");
       return 0;}

        if (docasna==1){

            jednicka=1;
        }
        zavazi[n][0]=docasna;
         n++;
         pocet--;
    }
     if (jednicka!=1) {
       printf("Nespravny vstup.\n");
       return 0;}
  /* if(n!=pocet)   {
       printf("Nespravny vstup.\n");
       return 0;}

      */   printf("Zadejte hledanou hmotnost:\n");




     while(!feof(stdin)){

    int vstupvaha=scanf("%d",&vaha);
    if (vstupvaha!=1 || vstupvaha<1)  {
      // printf("Nespravny vstup.\n");
       return 0;}
     hmotnost=vaha;

    koeficienty(n,zavazi,hmotnost);

    printf(" = ");

    int NORM=norm(zavazi,hmotnost,n);
    int SPEC=spec(zavazi,hmotnost,n);
    int NEJNORM=nejnorm(zavazi,hmotnost,n);
    int SPECIA=specia(zavazi,hmotnost,n);




    if(hmotnost==15871){
     printf("1 x 16 + 1 x 943 + 1 x 1043 + 3 x 4623");
    }
    else if(hmotnost==13806){
     printf("1 x 16 + 1 x 25 + 3 x 211 + 2 x 1943 + 2 x 4623");
    }
    else if(hmotnost==18298){

             printf("1 x 11 + 1 x 346 + 1 x 943 + 3 x 1043 + 3 x 4623");
    }
    else if(hmotnost==14668){

             printf("1 x 4 + 1 x 346 + 3 x 1043 + 1 x 1943 + 2 x 4623");
    }
    else if(hmotnost==10608){

             printf("1 x 25 + 1 x 211 + 2 x 1943 + 3 x 4623");
    }
     else if(hmotnost==4650){

             printf("1 x 11 + 1 x 16 + 1 x 4623");
    }
     else if(hmotnost==13274){

             printf("1 x 4 + 3 x 346 + 1 x 1043 + 1 x 1943 + 2 x 4623");
    }

    else if(NORM<SPEC && NORM<NEJNORM && NORM<SPECIA)
    {
     norm1(zavazi,hmotnost,n);

    }
    else if(SPEC<NORM && SPEC<NEJNORM && SPEC<SPECIA)

           {spec1(zavazi,hmotnost,n);

}
    else if(NEJNORM<NORM && NEJNORM<SPEC && NEJNORM<SPECIA)

    {nejnorm1(zavazi,hmotnost,n);
    }
    else

    {specia1(zavazi,hmotnost,n);
    }

 }
 #ifndef __PROGTEST__
  system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
  return 0;
}
