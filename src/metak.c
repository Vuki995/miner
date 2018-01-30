#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>

void napuni(metak m[brred]){
int i;
for(i=0;i<brred;i++){
	m[i].x=0.5;
	m[i].y=0.5;
	m[i].z=0.5;
	m[i].i=0;
	m[i].j=0;
	m[i].k=0;
	m[i].i1=0;
	m[i].j1=0;
	m[i].k1=0;
	m[i].ispaljen=0;
	m[i].boom=0;
	m[i].put=0;
	}
}

void opali(igrac a,metak b[brred],char c){
int i;
for(i=0;i<brred;i++){   
	if(b[i].ispaljen==0){
		 b[i].ispaljen=1;
		 b[i].x=a.x;
		 b[i].y=a.y;
		 b[i].z=a.z;
		 b[i].i=a.i;	
		 b[i].j=a.j;
		 b[i].k=a.k;
		 if(c=='w'){
		     b[i].j1=-1;return;
		 }
		 if(c=='s'){
		     b[i].j1=1;return;
		 }
		switch (a.smer)  {
			case 0:if(c=='a'){
					b[i].k1=1;return;}
				if(c=='d'){	
					b[i].k1=-1;return;}break;
			case 100:if(c=='a'){
					b[i].i1=1;return;}
				if(c=='d'){
					b[i].i1=-1;return;}break;
			case 200:if(c=='a'){
					b[i].k1=-1;return;}
				if(c=='d'){
					b[i].k1=1;return;}break;
			case 300:if(c=='a'){
					b[i].i1=-1;return;}
				if(c=='d'){
					b[i].i1=1;return;}break;
		}
	}
}
}
void putanja(metak sanzer[brred],kocka kocke[brred][brred][brred]){
int i,j,k,l;
    for(i=0;i<brred;i++){
		 if(sanzer[i].ispaljen==1&&sanzer[i].boom==0){
				j=sanzer[i].i+sanzer[i].i1;
				k=sanzer[i].j+sanzer[i].j1;
				l=sanzer[i].k+sanzer[i].k1;
			if(l<=9&&l>=0&&k<=9&&k>=0&&j<=9&&j>=0&&kocke[j][k][l].prokopano==1){
				sanzer[i].x=(sanzer[i].x*100-(sanzer[i].k1*100/MAXB))/100;
				sanzer[i].y=(sanzer[i].y*100-(sanzer[i].j1*100/MAXB))/100;
				sanzer[i].z=(sanzer[i].z*100-(sanzer[i].i1*100/MAXB))/100;
				sanzer[i].put++;
				if(sanzer[i].put==MAXB){
				    sanzer[i].k=l;
				    sanzer[i].j=k;
				    sanzer[i].i=j;
				    sanzer[i].put=0;
				    }
			} 
			else{
				sanzer[i].ispaljen=0;
				sanzer[i].i1=sanzer[i].j1=sanzer[i].put=sanzer[i].k1=0;} 
		}
	}
}
