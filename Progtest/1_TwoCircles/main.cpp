/*
* File:   main.cpp
* Author: Jakub Trhlík
*
* Created on 02.11.2013 17:57:37
g++ -std=c++11 -Wall -pedantic -Wno-long-long -O2 -o result *.cpp
*/

#include <stdio.h>
#include <cstdlib>
#include <cmath>

#define PRECISION 0.0000000000001

int main() {

  //set initial values
  double x1,y1,r1,x2,y2,r2;
  double d,t,alpha,beta,p,k1,k2;

  //insert params of the circle 1
  printf("Insert Circle params [x,y,r] #1:\n");
  if(scanf("%lf %lf %lf", &x1, &y1, &r1) !=3 || r1<=0) {printf("Wrong Entry \n"); exit(1);}
  //insert params of the circle 2
  printf("Insert Circle params [x,y,r] #2:\n");
  if (scanf("%lf %lf %lf", &x2, &y2, &r2) !=3 || r2<=0) {printf("Wrong Entry \n"); exit(2);}

  //
  d=(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));

  alpha=acos(((r1*r1)+(d*d)-(r2*r2))/(2*r1*d));
  beta=acos(((r2*r2)+(d*d)-(r1*r1))/(2*r2*d));
  t=(2*r1*(sin(alpha)));
  p=(r1*r1*alpha)+(r2*r2*beta)-0.5*t*d;
  k1=M_PI*r1*r1;
  k2=M_PI*r2*r2;


  if ((fabs(r1-r2)<=fabs(PRECISION*fabs(d)) && (fabs(x1-x2)<=fabs(PRECISION*fabs(d))) && (fabs(y1-y2)<=fabs(PRECISION*fabs(d))) )){
    printf("Circles coincide, overlap: %f\n",k1); }

    else if ((r1+r2)<fabs(d))
    printf("Circles lies outside ourselves, no overlap.\n");
    else if ((fabs(fabs(r1+r2)-fabs(d))<=fabs(PRECISION*fabs(d)) ))
    printf("Circles touch, no overlap.\n");

    else if (fabs(fabs(r1-r2)-fabs(d))<=fabs(PRECISION*fabs(d))){
      if(r1>r2)
      printf("Inside touch, circle #2 lies in circle #1, overlap: %f\n",k2);
      else if(r2>r1)
      printf("Inside touch, circle #1 lies in circle #2, overlap: %f\n",k1);
    }

    else if ((fabs(r1-r2))>fabs(d))
    { if(r1>r2){ printf("Circle #2 lies inside circle #1, overlap: %f\n",k2);}
    else if(r2>r1) { printf("Cirlcle #1 lies inside circle #2, overlap: %f\n",k1);}
  }

  else printf("Circles cross, overlap: %f\n",p);

  return 0;
}
