#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double vzdalenost2(double x1, double y1, double x2, double y2){
    
    double vzdalenost2=sqrt((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
 
    return vzdalenost2;
}

double porovnani(double * poley, double *polex, int n, double min){
    int i=0;
      while(i<n){   
   if(vzdalenost2(polex[i],poley[i],polex[n],poley[n])<min)
    {  min=vzdalenost2(polex[i],poley[i],polex[n],poley[n]);}
    
   i++;
    }
   
    return min;
}

int hledani(double * poley, double *polex, int n, double min ){
    int i=0,u=0,pocet=0;
    double delka=0;
     while(i<n){
    for(u=(i+1);u<n;u++) {
        delka=0;
        delka=(fabs(vzdalenost2(polex[u],poley[u],polex[i],poley[i])-min));
        
            if((delka)==0 || (((delka)>0.000000000000000000000000001) && ((delka)<0.00000000001)))
          
            {
                pocet++;
                
               
            }
            
        }
        i++;
    }  
    return pocet;
}

int main(void) {
    char Zav, Otv;
   int n=0, vstup, pocet;
 double *polex, *poley, temp_x, temp_y, min=DBL_MAX;
polex=(double*)malloc(1 * sizeof(double));
poley=(double*)malloc(1 * sizeof(double));

printf("Zadejte souradnice:\n");

    while(!feof(stdin)){   
        vstup = scanf(" %c%lf , %lf%c ", &Otv, &temp_x, &temp_y, &Zav);
    
        if((vstup==4) && (Otv=='[' && Zav==']')) {

          poley=(double*)realloc(poley,(n+1) * sizeof(double));
          polex=(double*)realloc(polex,(n+1) * sizeof(double));
          poley[n]=temp_y;
          polex[n]=temp_x;
        
    
     min=porovnani(poley,polex,n,min);    
          n++;
       
         }
       
        else{ printf("Nespravny vstup.\n");
     
        return 0;
        
        }
    
}

if(n==1){printf("Nespravny vstup.\n");  return 0;
}

 pocet=hledani(poley,polex,n,min); 
 
    printf("Vzdalenost nejblizsich letadel: %g\n",min); 
    printf("Nalezenych dvojic: %d\n",pocet); 
 
#ifndef __PROGTEST__
  system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
  return 0;
} 