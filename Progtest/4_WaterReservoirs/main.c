 #include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define X 100
#define Y 200000

int nadrz[Y][4];
 int tabulka[X];
 
int pocet(void){
    int B;
 if(scanf("%d", &B)!=1){printf("Nespravny vstup.\n"); return 0;}
 if(B<1 || B>200000) {printf("Nespravny vstup.\n"); return 0;}
 else return B;
}

static int vetsi(const void* p1, const void* p2) {
  int* nadrz1 = (int*)p1;
  int* nadrz2 = (int*)p2;
  int diff1 = (nadrz1[0]>nadrz2[0]) - (nadrz1[0]<nadrz2[0]);
  if (diff1!=0) return diff1;
 return (nadrz1[1] > nadrz2[1]) - (nadrz1[1] < nadrz2[1]);
}
int seradit(int n){
   qsort(nadrz, n, sizeof(int)*4, vetsi);
   return 0;
}

int ctiMatici(int m, int *max) {
  int r, Alt, H, W, D;
printf("Zadejte parametry nadrzi:\n");
for (r=0; r<m; r++){
  if (scanf("%d%d%d%d", &Alt, &H, &W, &D)!=4 ){
    return 0;}
  else{   
    nadrz[r][0]=Alt;
    nadrz[r][1]=H;
    nadrz[r][2]=W;
    nadrz[r][3]=D;
    if((nadrz[r][0]+nadrz[r][1])>*max){ 
        *max=(nadrz[r][0]+nadrz[r][1]);
    }}}
return 1;
}

 void ctiCisla(int tab[],int max,int N,float Vyska) { 
int i, u;

 for (i=Vyska; i<=(max); i++)
 { 
  for(u=0; u<=N;u++)
   {
    if(((nadrz[u][0])<=i) && (((nadrz[u][0])+(nadrz[u][1]))>i)) {
          tabulka[i]+=((nadrz[u][2])*(nadrz[u][3]));  
    
    }
    
 }
}
return; } 

float Objem(float Vyska, int max,float V){
    int i=Vyska;
  for(i;i<=max;i++)
    {
      
     if((V-tabulka[i])>0)
      {
          V-=tabulka[i];
          Vyska++;
     
      }
      else{
       Vyska+=(V/tabulka[i]);
     return Vyska;
     
      }  
    }
     return -666;
}

 int main ( int argc, char * argv [] ) {
 int N, max;   
 float Vyska,vysledek, V;
 printf("Zadejte pocet nadrzi:\n");
 
 if((N=pocet())==0)
     {printf("Nespravny vstup.\n"); return 0;}
  
 if((ctiMatici(N, &max))==0){printf("Nespravny vstup.\n"); return 0;}
 
 seradit(N);
  

Vyska=(nadrz[0][0]);
ctiCisla(tabulka,max ,N,Vyska);



printf("Zadejte objem vody:\n"); 

while(1){
   
    
   if((scanf("%f", &V))!=1){printf("Nespravny vstup.\n"); return 0;}
   else if(feof(stdin)){ break;}      
   vysledek=(Objem(Vyska,max,V)); 
   
   if(V<0){printf("Nespravny vstup.\n"); return 0;}
else if(V==0)
{printf("Prazdne.\n");
}
else if(vysledek==-666)
{printf("Pretece.\n");
}
else {
printf("h = %f\n", vysledek); 

}

  return 0; 
}


  return 0;
} 