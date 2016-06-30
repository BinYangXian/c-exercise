
#include  <stdio.h>  //°üº¬I/Oº¯Êý¿â 
main()

{

unsigned char  x,y,z;

unsigned char  *p,*p1,*p2,*p3;


printf("input  x,y and z:\n");

scanf("%c,%c,%c",&x,&y,&z);

printf("\n");

p1=&x;p2=&y; p3=&z;

if (*p1<*p2) {p=p1;p1=p2;p2=p;}

if (*p2<*p3) {p=p2;p2=p3;p3=p;}

if (*p1<*p2) {p=p1;p1=p2;p2=p;} printf("max to min is:%c,%c,%c\n",*p1,*p2,*p3);

}