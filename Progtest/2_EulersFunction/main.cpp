#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
 int n;
    int d=2;
    printf("Zadejte n:\n");   
if (scanf ("%d", &n)!=1 || n < 1) {
    printf("Nespravny vstup.\n");
    return 0;
}
    int blb=n; 
     int vstup=n;
    while(1<sqrt(n)){
      
       int temp;
      if(n % d == 0) {
       if(temp!=d){
          blb-=blb/d;
      temp=d; 
 
       }
      n /= d;
  } 
 else {
   d ++;
  }
} printf("phi(%d) = %d\n",vstup,blb);

 return 0;
}
