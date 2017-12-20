#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>
igrac spawn(void){ /*postavlja pocetne vrednosti igraca*/
    igrac a;
    a.i=4;
    a.j=0;
    a.k=4;
    a.x=0.5;
    a.y=4.5;
    a.z=0.5;
    a.x1=0.5;
    a.y1=4.5;
    a.z1=0.5;
    a.korak=0;
    a.stanje=1;
    a.smer=0;
    a.i1=0;
    a.j1=0;
    a.k1=0;
return a;
}
/*funkcija kretanja, u zavisnosti od pritisnutog dugmeta, orijentacije i pozicije, funkcija odredjuje da li igrac moze da se krece*/
igrac pokret(igrac a, char c){ 
    a.x1=a.x;
    a.y1=a.y;
    a.z1=a.z;
if(c=='w'){
    if(a.y<4.5)
	a.j1=-1;
return a;
}
if(c=='s'){
    if(a.y>-4.5)
	a.j1=1;
return a;
}
switch(a.smer){
    case 0:if(c=='a'){
		if(a.x>-4.5)
		    a.k1=1;
		return a;
	    }
	   if(c=='d'){
		if(a.x<4.5)
		    a.k1=-1;
		return a;
	    }break;
    case 100:if(c=='a'){
		if(a.z>-4.5)
		    a.i1=1;
		return a;
	    }
	   if(c=='d'){
		if(a.z<4.5)
		    a.i1=-1;
		return a;
	    }break;
    case 200:if(c=='d'){
		if(a.x>-4.5)
		    a.k1=1;
		return a;
	    }
	   if(c=='a'){
		if(a.x<4.5)
		    a.k1=-1;
		return a;
	    }break;
    case 300:if(c=='d'){
		if(a.z>-4.5)
		    a.i1=1;
		return a;
	    }
	   if(c=='a'){
		if(a.z<4.5)
		    a.i1=-1;
		return a;
	    }break;


}
}
