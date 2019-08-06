#ifndef _POLINOM_H_
#define _POLINOM_H_
#define brred 10 /*broj redova kolona zlata i botova*/
#define TIMEF 10 /*vreme za svaki frejm*/
#define MAXK 25  /*koliko brzo se krece igrac*/
#define MAXB 5   /*brzina metka*/
#define MAXS 50  /*brzina botova*/
#define Bnum 20  /*broj botova*/
#define timeT 150 /*vreme trajanja*/
#define rechargeR 25 /*brzina pucanja*/
/*struktura igraca*/
typedef struct ig{
int stanje;
float x,y,z;
float x1,y1,z1;
int i,j,k;
int i1,j1,k1;
int smer;
int korak;
int score;
}igrac;

/*struktura terena*/
typedef struct te {
  float x,y,z ;
  int tip;
  int vidjeno;
  int prokopano;
  int health;
}kocka;


/*struktura metka*/
typedef struct as{
int i,j,k;
float x,y,z;
int i1,j1,k1;
int ispaljen;
int boom;
int put;
}metak;

/*struktura bota*/
typedef struct ad{
int i,j,k;
float x,y,z;
int budan;
int ziv;
int korak;
}bot;

/*heuristika*/
typedef struct aw{
int i,j,k;
float x,y,z;
int h;
}heur;

/*igrac.c*/
igrac spawn(void);
igrac pokret(igrac a, char c, kocka k[brred][brred][brred], int *m, bot b[Bnum], int *count);
void pMove(kocka k[brred][brred][brred], int i, int j, int l, int *m,int * count, bot b[Bnum], igrac * a);
void osvetli(kocka k[brred][brred][brred],int a, int b, int c, int vidi);
void korak(igrac * a,kocka kocke[brred][brred][brred]);
/*funkcije.c*/
void napravi(kocka a[10][10][10]);
void RenderString(float x, float y, void *font, const char* string, float r, float g, float b);
void ispisi(char* d,int j, float a, float b);
/*metak.c*/
void napuni(metak m[brred]);
void opali(igrac a,metak b[brred],char c);
void putanja(metak sanzer[brred],kocka kocke[brred][brred][brred]);
/*bot.c*/
bot probudi(kocka k, int i, int j, int m);
bot vrati(bot b, igrac a,kocka k[brred][brred][brred]);
int distanca(heur h, igrac a);
void hit(bot b[Bnum], metak * m,int *count, int *s);
void kretanje(bot b[Bnum],igrac a, kocka kocke[brred][brred][brred], int * clock );
/*draw.c*/
void shot(metak sanzer[brred], bot b[Bnum], igrac *a, int *count);
void mapa(kocka kocke[brred][brred][brred], int val, igrac * a);
void drawFront(kocka kocke [brred][brred][brred], igrac *a, int i, int j, int k, float q);
void drawBack(kocka kocke [brred][brred][brred], igrac *a, int i, int j, int k, float q);
void botovi(bot b[Bnum], int br, int a);
void startstop(int animation_active, int clock, igrac a);
void robot(float f, int a, int b, char c);
#endif

