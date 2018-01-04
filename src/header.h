#ifndef _POLINOM_H_
#define _POLINOM_H_
#define brred 10 /*dimenzije terena*/
#define TIMEF 10 /*vreme za svaki frejm*/
#define MAXK 10  /*koliko brzo se krece igrac*/
/*struktura igraca*/
typedef struct ig{
int stanje;
float x,y,z;
float x1,y1,z1;
int i,j,k;
int i1,j1,k1;
int score;
int smer;
int korak;
}igrac;
/*struktura terena*/
typedef struct te {
  float x,y,z ;
  int tip;
  int vidjeno;
  int prokopano;
  int health;
}kocka;

/*igrac.c*/
igrac spawn(void);
igrac pokret(igrac a, char c, kocka k[brred][brred][brred]);
void osvetli(kocka k[brred][brred][brred],int a, int b, int c);
/*funkcije.c*/
void napravi(kocka a[10][10][10]);
/*draw.c*/
void mapa(kocka kocke[brred][brred][brred], int val, igrac * a);
void karakter(int animation_active, igrac a);
#endif

