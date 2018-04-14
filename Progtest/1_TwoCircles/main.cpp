/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 02.11.2013 17:57:37
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {


  //set initial values
  double x1,y1,r1,x2,y2,r2;
  double d,t,alfa,beta,p,k1,k2;

  //iinsert params of the circle 1
  printf("Zadejte parametry kruznice #1:\n");
  if(scanf("%lf %lf %lf", &x1, &y1, &r1) !=3 || r1<=0) {printf("Nespravny vstup.\n"); exit(1);}
  //iinsert params of the circle 2
  printf("Zadejte parametry kruznice #2:\n");
  if (scanf("%lf %lf %lf", &x2, &y2, &r2) !=3 || r2<=0) {printf("Nespravny vstup.\n"); exit(2);}



  d=(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
  alfa=acos(((r1*r1)+(d*d)-(r2*r2))/(2*r1*d));
  beta=acos(((r2*r2)+(d*d)-(r1*r1))/(2*r2*d));
  t=(2*r1*(sin(alfa)));
  p=(r1*r1*alfa)+(r2*r2*beta)-0.5*t*d;
  k1=M_PI*r1*r1;
  k2=M_PI*r2*r2;


  if ((fabs(r1-r2)<=fabs(0.0000000000001*fabs(d)) && (fabs(x1-x2)<=fabs(0.0000000000001*fabs(d))) && (fabs(y1-y2)<=fabs(0.0000000000001*fabs(d))) )){
    printf("Kruznice splyvaji, prekryv: %f\n",k1); }

    else if ((r1+r2)<fabs(d))
    printf("Kruznice lezi vne sebe, zadny prekryv.\n");
    else if ((fabs(fabs(r1+r2)-fabs(d))<=fabs(0.0000000000001*fabs(d)) ))
    printf("Vnejsi dotyk, zadny prekryv.\n");

    else if (fabs(fabs(r1-r2)-fabs(d))<=fabs(0.0000000000001*fabs(d))){
      if(r1>r2)
      printf("Vnitrni dotyk, kruznice #2 lezi uvnitr kruznice #1, prekryv: %f\n",k2);
      else if(r2>r1)
      printf("Vnitrni dotyk, kruznice #1 lezi uvnitr kruznice #2, prekryv: %f\n",k1);
    }

    else if ((fabs(r1-r2))>fabs(d))
    { if(r1>r2){ printf("Kruznice #2 lezi uvnitr kruznice #1, prekryv: %f\n",k2);}
    else if(r2>r1) { printf("Kruznice #1 lezi uvnitr kruznice #2, prekryv: %f\n",k1);}
  }

  else printf("Kruznice se protinaji, prekryv: %f\n",p);

  return 0;
}
