/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on	08.12.2013 12:05:59
*/
#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif /* __PROGTEST__ */

void rozsir (char ** res, int *resLen, int *resMax,const char * appendStr, int appendLen){

 if ( *resLen + appendLen >= *resMax )
    {
      *resMax = *resLen + appendLen;
      *res = ( char *) realloc ( *res, *resMax );
    }
   memcpy ( *res + *resLen, appendStr, appendLen );
   *resLen += appendLen;
}

int Obsahuje (char vyjimka [2][200][500], int pocetvyjimek,const char *replace){
    int i=0;
    for(i=0;i<=pocetvyjimek;i++)  {
        if( strcmp ( replace,vyjimka[0][i])==0) {    return i;   }
    }
  return -1;
}

char * strReplace ( char * text,const char *replace,const char *with, char vyjimka [2][200][500], int pocetvyjimek )
 {
   char * res = 0, * occ, *nespravny;
   int    resLen = 0, resMax = 0;
   int    replaceLen = strlen ( replace ), withLen = strlen ( with );

   if ( ! replaceLen ) return 0;
   while ( 1 ) {
       int radek=Obsahuje(vyjimka, pocetvyjimek, replace);
     occ = strstr ( text, replace );
      nespravny = strstr ( text, vyjimka[1][radek]);
      if ( occ ) {
          /*if(radek!=-1)
          { printf("obsahuje \n");
        }
           printf("ab %d  strlen %d  %s \n",abs(occ-nespravny),strlen(vyjimka[1][radek]),vyjimka[1][radek] );
          */
           int rozdil=abs(nespravny-occ);
           int delka_spatneho =strlen(vyjimka[1][radek]);
            if(rozdil<delka_spatneho){
          // printf("spatne se nahrazuje %s za %s \n",replace,with);
             rozsir ( &res, &resLen, &resMax, text, occ - text );
      rozsir ( &res, &resLen, &resMax, replace, replaceLen );
            text = occ + replaceLen;
         }
            else{
         rozsir ( &res, &resLen, &resMax, text, occ - text );
          rozsir ( &res, &resLen, &resMax, with, withLen );
          text = occ + replaceLen;
           }
       }
      else {
         rozsir ( &res, &resLen, &resMax, text, strlen ( text ) + 1 );
         return ( res );
       }
    }
   return 0;
 }

char * newSpeak ( const char * text, const char * (*replace)[2] )
 {
    int n=0,i=0,k=0;

   char vyjimka [2][200][500];
 /*
 char *(*vyjimka) [2];
  (*vyjimka)[0] =malloc(20*sizeof(char*));
   (*vyjimka)[1] =malloc(20*sizeof(char*));

for ( i = 0; i < 10; i++ )
{
     vyjimka[i][0] =malloc(20*sizeof(char));
}

 for ( g = 0; g < 10; g++ )
{
     vyjimka[g][1] =malloc(20*sizeof(char));
}

 */
     while(replace[n][0]!=NULL && replace[n][1]!=NULL)   {
      int i=1+n;
      int u=0;

      while(replace[i][0]!=NULL && replace[i][1]!=NULL) {
         if(NULL!=strstr(replace[n][0], replace[i][0]) || NULL!=strstr(replace[i][0], replace[n][0]))
          {
          return 0;
          }
         i++;  }
       while(replace[n][0]!=NULL && replace[u][1]!=NULL){
     if(NULL!=strstr(replace[n][0], replace[u][1]) || NULL!=strstr(replace[u][1], replace[n][0]))  {
         /*
           *vyjimka_a = ( char* ) realloc ( *vyjimka_a, sizeof(char*)*(k+1) );

            *vyjimka_a[k] = ( char **) realloc ( *vyjimka_a[k], sizeof(char**)*(strlen(replace[u][1])+1) );

              *vyjimka_b = ( char* ) realloc ( *vyjimka_b, sizeof(char*)*(k+1) );

            *vyjimka_b[k] = ( char **) realloc ( *vyjimka_b[k], sizeof(char**)*(strlen(replace[n][0])+1) );
            */
           strcpy (vyjimka[1][k],replace[u][1]);
          strcpy (vyjimka[0][k],replace[n][0]);
          //  printf ( "%s ---------- %s\n", vyjimka[1][k],vyjimka[0][k]);
            k++;
          }
      u++; }
      n++; }

  char *ttt =(char*) malloc (sizeof(char)*(strlen(text)+1));

     strcpy(ttt,text);

  while(i<n)
  {
 ttt=strReplace (ttt, replace[i][0], replace[i][1], vyjimka, k);
    i++;
  }
    return ttt;
 }

#ifndef __PROGTEST__
int main ( int argc, char * argv [] ) {
   char * res;
   const char * d1 [][2] = {
     { "murderer", "termination specialist" },
     { "failure", "non-traditional success" },
     { "specialist", "person with certified level of knowledge" },
     { "dumb", "cerebrally challenged" },
     { "teacher", "voluntary knowledge conveyor" },
     { "evil", "nicenest deprived" },
     { "incorrect answer", "alternative answer" },
     { "student", "client" },
     { NULL, NULL }
    };

   const char * d2 [][2] = {
     { "fail", "suboptimal result" },
     { "failure", "non-traditional success" },
     { NULL, NULL }
    };

   res = newSpeak ( "Everybody is happy.", d1 );
   /* res = "Everybody is happy."*/
   free ( res );

   res = newSpeak ( "The student answered an incorrect answer.", d1 );
   /* res = "The client answered an alternative answer."*/

   res = newSpeak ( "He was dumb, his failure was expected.", d1 );
   /* res = "He was cerebrally challenged, his non-traditional success was expected."*/
   free ( res );

   res = newSpeak ( "The evil teacher became a murderer.", d1 );
   /* res = "The nicenest deprived voluntary knowledge conveyor became a termination specialist."*/
   free ( res );

   res = newSpeak ( "Devil's advocate.", d1 );
   /* res = "Dnicenest deprived's advocate."*/
   free ( res );

   res = newSpeak ( "Hello.", d2 );
   /* res = NULL */
   return 0;
 }
#endif /* __PROGTEST__ */
