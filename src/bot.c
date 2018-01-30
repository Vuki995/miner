#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>

bot probudi(kocka k,int i, int j, int m){
bot b;
b.x=k.x;
b.y=k.y;
b.z=k.z;
b.i=i;
b.j=j;
b.k=m;
b.ziv=1;
b.budan=0;
b.korak=0;
return b;
}

bot vrati(bot b, igrac a, kocka k[brred][brred][brred]){

if(b.i==a.i&&b.j==a.j&&b.k==a.k)
return b;
heur m[4];
int i;
for(i=0;i<4;i++){
    m[i].x=b.x;
    m[i].y=b.y;
    m[i].z=b.z;
    m[i].i=b.i;
    m[i].j=b.j;
    m[i].k=b.k;
    m[i].h=1000;
}
if(b.j-1>=0&&k[b.i][b.j-1][b.k].prokopano==1){
    m[0].y=b.y+1;
    m[0].j=b.j-1;
    m[0].h=distanca(m[0],a);
}
if(b.j+1<=9&&k[b.i][b.j+1][b.k].prokopano==1){
    m[2].y=b.y-1;
    m[2].j=b.j+1;
    m[2].h=distanca(m[2],a);
}
if(a.smer%200==0){
    if(b.k-1>=0&&k[b.i][b.j][b.k-1].prokopano==1){
        m[1].x=b.x+1;
        m[1].k=b.k-1;
        m[1].h=distanca(m[1],a);
    }
    if(b.k+1<=9&&k[b.i][b.j][b.k+1].prokopano==1){
        m[3].x=b.x-1;
        m[3].k=b.k+1;
        m[3].h=distanca(m[3],a);
    }

}else{
    if(b.i-1>=0&&k[b.i-1][b.j][b.k].prokopano==1){
        m[1].z=b.z+1;
        m[1].i=b.i-1;
        m[1].h=distanca(m[1],a);
    }
    if(b.i+1<=9&&k[b.i+1][b.j][b.k].prokopano==1){
        m[3].z=b.z-1;
        m[3].i=b.i+1;
        m[3].h=distanca(m[3],a);
    }
}
int min,j;
min=m[0].h;
j=0;
for(i=1;i<4;i++){
	if(m[i].h<min){
		min=m[i].h;
		j=i;
	}
}
b.x=m[j].x;
b.y=m[j].y;
b.z=m[j].z;
b.i=m[j].i;
b.j=m[j].j;
b.k=m[j].k;
return b;
}


int distanca(heur h, igrac a){
    int j,k;
    if(a.smer%200==0){
	j=a.j-h.j;
	j=j<0?j*(-1):j;
	k=a.k-h.k;
	k=k<0?k*(-1):k;
	return k+j;
    }
    else{
	j=a.j-h.j;
	j=j<0?j*(-1):j;
	k=a.i-h.i;
	k=k<0?k*(-1):k;
	return k+j;
    }
}
void hit(bot b[Bnum], metak * m, int *count, int *s){
int i;
	for(i=0;i<Bnum;i++){
		if(b[i].i==m->i&&b[i].j==m->j&&b[i].k==m->k&&b[i].ziv==1){
			b[i].ziv=0;
			m->ispaljen=0;
			m->i1=m->j1=m->put=m->k1=0;
			*count=*count-1;
			*s=*s+50;}
	}
}
void kretanje(bot b[Bnum],igrac a, kocka kocke[brred][brred][brred], int * clock ){
int i;
    for(i=0;i<Bnum;i++){
	    if(b[i].ziv==1){
		b[i].korak++;
		if(b[i].korak==MAXS){
			b[i]=vrati(b[i],a,kocke); b[i].korak=0;
			if(b[i].i==a.i&&b[i].j==a.j&&b[i].k==a.k){
			*clock=timeT;}
		}
    	}
    }
}
