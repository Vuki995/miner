#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <GL/freeglut.h>

void shot(metak sanzer[brred], bot b[Bnum], igrac *a, int *count){
    int i;
    float q=0.25;
    for(i=0;i<brred;i++){
			if(sanzer[i].ispaljen==1){
				hit(b,&sanzer[i], count, &a->score);
				glPushMatrix();
					glScalef(q,q, q);
					glRotatef(((float)a->smer)*90/100,0,1,0);
					glTranslatef(sanzer[i].x,sanzer[i].y, sanzer[i].z);
					set_mat(4,80);
					glutSolidSphere(0.4,8,8);
				glPopMatrix();}
				
    }
}
void mapa(kocka kocke[brred][brred][brred], int val, igrac * a){
int i,j,k;
float q=0.25;
for(i=0;i<brred;i++){
      for(j=0;j<brred;j++){
	for(k=0;k<brred;k++){
		if(val&&kocke[i][j][k].prokopano==1)		/*deo koji pravi mapu tokom rotacije*/
				{
		    glPushMatrix();
			set_mat(4,100);
		        glScalef(q,q, q);
		        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
		        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
		        glutWireCube(1);
		    glPopMatrix();
			}
		if(!val){/*deo koji pravi stacionarnu mapu*/
			if(a->smer%200==0){ /*u zavisnosti na koju stranu je rotirana mapa, parno*/
				if(kocke[i][j][k].z==a->z){
			        	drawFront(kocke, a, i, j, k,q);
				}
				if(a->smer==0&&kocke[i-1][j][k].vidjeno==1&&kocke[i-1][j][k].prokopano==1&&kocke[i][j][k].z==a->z-1){
					if(kocke[i][j][k].prokopano==0)
			        	drawBack(kocke, a, i, j, k,q);
				}
				if(a->smer==200&&kocke[i+1][j][k].vidjeno==1&&kocke[i+1][j][k].prokopano==1&&kocke[i][j][k].z==a->z+1){
					if(kocke[i][j][k].prokopano==0)
			        	drawBack(kocke, a, i, j, k,q);
				}
			}
			if(a->smer%200==100){ /*neparno*/
				if(kocke[i][j][k].x==a->x){	
					drawFront(kocke, a, i, j, k,q);
				}
				if(a->smer==100&&kocke[i][j][k+1].vidjeno==1&&kocke[i][j][k+1].prokopano==1&&kocke[i][j][k].x==a->x+1){
					if(kocke[i][j][k].prokopano==0)
			        	drawBack(kocke, a, i, j, k,q);
				}
				if(a->smer==300&&kocke[i][j][k-1].vidjeno==1&&kocke[i][j][k-1].prokopano==1&&kocke[i][j][k].x==a->x-1){
					if(kocke[i][j][k].prokopano==0)
			        	drawBack(kocke, a, i, j, k,q);
				}
			}
		}
			
	}
      }
    } 

}
void drawFront(kocka kocke [brred][brred][brred], igrac *a, int i, int j, int k, float q){ /*iscrtava prednji red*/
glPushMatrix();
	if(kocke[i][j][k].vidjeno==1){
		if(kocke[i][j][k].tip==1)
			set_mat(1,kocke[i][j][k].health);
		else if(kocke[i][j][k].tip==2)
			set_mat(2,kocke[i][j][k].health);
		else if(kocke[i][j][k].tip==3)
			set_mat(3,3);
	}/*
	else if(kocke[i][j][k].vidjeno==0)
		set_mat(0,1);*/
        glScalef(q,q, q);
        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
	if(/*kocke[i][j][k].vidjeno==0||*/(kocke[i][j][k].vidjeno==1&&kocke[i][j][k].prokopano==0))
       		glutSolidCube(1);
        if(kocke[i][j][k].vidjeno==1&&kocke[i][j][k].prokopano==0){
			set_mat(4,100);
	glutWireCube(1);
	}
glPopMatrix();
}

void drawBack(kocka kocke [brred][brred][brred], igrac *a, int i, int j, int k, float q){ /*iscrtava red iza igraca*/
glPushMatrix();
	if(kocke[i][j][k].tip==1)
		set_mat(1,2);
	if(kocke[i][j][k].tip==2)
		set_mat(2,2);
	else if(kocke[i][j][k].tip==3)
		set_mat(3,3);
	glScalef(q,q, q);
	glRotatef(((float)a->smer)*90/100, 0, 1, 0);
	glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
	glutSolidCube(1);
glPopMatrix();
}



void botovi(bot b[Bnum], int br,int a){
int i;
float q=0.25;
    for(i=0;i<br;i++){
	if(b[i].ziv==1){
		glPushMatrix();
		set_mat(3,1);
	        glScalef(q,q, q);
	        glRotatef(((float)a)*90/100, 0, 1, 0);
	        glTranslatef(b[i].x,b[i].y, b[i].z);
	        glutSolidCube(1);
	        glPopMatrix();
	}
    }
}
void startstop(int animation_active, int clock, igrac a){
    if(animation_active==0&&(clock==0||clock==timeT)){
    glPushMatrix();
	 set_mat(4,100); 
	if(clock==0)
		ispisi("Press 'g' to start",-1,0,0);
	if(clock==timeT){
		ispisi("Game Over",-1,0,0.2);
		ispisi("Score:",a.score,0,0);
		ispisi("Press 'esc' to exit",-1,0,-0.2);
		ispisi("Press 'r' to restart",-1,0,-0.4);}
    glPopMatrix();}
	if(animation_active==0&&clock>0&&clock<timeT){
	 	set_mat(4,100); 
		ispisi("Game Paused",-1,0,0);}
return;}

void robot(float f, int a, int b, char c){

int i=0;
int j=0;
int k=0;
switch (c){
	case 'a':i=-1;break;
	case 'd':i=1;break;
	case 'w':j=-1;break;
	case 's':j=1;break;
	case 'k':k=1;break;

}
glRotatef(i*90,0,1,0);
glScalef(f*1.5,f,f*1.5);
glRotatef(((float)a)*90/100,0,-1,0);
/*glava*/
 glPushMatrix();
	glRotatef(k*(-30),1,0,0);
	glRotatef(j*30,1,0,0);
	glTranslatef(0,1.5,0);
	glPushMatrix();
	glTranslatef(0,-0.75,1.51);
	set_mat(4,0);
	glBegin(GL_TRIANGLES);
	   glVertex3f(0,0.25,0);
	   glVertex3f(-0.25,-0.1,0);
	   glVertex3f(0.25,-0.1,0);
	glEnd();
	glTranslatef(1,0.75,0);
	glScalef(1,1,0.01);
	glutSolidSphere(0.25,8,8);
	glTranslatef(-2,0,0);
	glScalef(1,1,0.01);
	glutSolidSphere(0.25,8,8);

	glPopMatrix();
	set_mat(4,100);
	glScalef(4,3,3);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();
/*desna ruka*/
    glPushMatrix();
	glTranslatef(-1.5,0,0);
	glRotatef(k*-105,0,0,1);
	glRotatef(sin((float)b/(MAXK/2)*3.14)*45 ,1,0,0);
	glTranslatef(0,-1,0);
	glScalef(1,2,1);
	set_mat(4,100);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();
/*leva ruka*/
    glPushMatrix();
	glTranslatef(1.5,0,0);
	glRotatef(k*105,0,0,1);
	glRotatef(-sin((float)b/(MAXK/2)*3.14)*45,1,0,0);
	glTranslatef(0,-1,0);
	glScalef(1,2,1);
	set_mat(4,100);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();
/*telo*/
    glTranslatef(0,-1,0);
    glPushMatrix();
	glScalef(2,2,1.5);
	set_mat(4,100);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();
    glTranslatef(0,-1,0);
/*desna noga*/
    glPushMatrix();
	glTranslatef(-0.5,0,0);
	glRotatef(-sin((float)b/(MAXK/2)*3.14)*45,1,0,0);
	glTranslatef(0,-1,0);
	glScalef(1,2,1);
	set_mat(4,100);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();
/*leva noga*/
    glPushMatrix();
	glTranslatef(0.5,0,0);
	glRotatef(sin((float)b/(MAXK/2)*3.14)*45,1,0,0);
	glTranslatef(0,-1,0);
	glScalef(1,2,1);
	set_mat(4,100);
	glutSolidCube(1);
	set_mat(4,0);
	glutWireCube(1.001);
    glPopMatrix();


}
