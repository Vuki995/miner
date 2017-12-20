#ifndef _POLINOM_H_
#define _POLINOM_H_
#define TIMEF 10 /*vreme za svaki frejm*/
#define MAXK 10  /*koliko brzo se krece igrac*/
/*struktura igraca*/
typedef struct ig{
int stanje;
float x,y,z;
float x1,y1,z1;
int i,j,k;
int i1,j1,k1;
int smer;
int korak;
}igrac;


/*funkcije.c*/
igrac spawn(void);
igrac pokret(igrac a, char c);
#endif

