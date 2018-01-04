#include"header.h" 
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>

void mapa(kocka kocke[brred][brred][brred], int val, igrac * a){
int i,j,k;
float q=0.25;
for(i=0;i<brred;i++){
      for(j=0;j<brred;j++){
	for(k=0;k<brred;k++){
		if(val&&kocke[i][j][k].prokopano==1)		/*deo koji pravi mapu tokom rotacije*/
				{
		    glPushMatrix();
			glColor3f( 1, 1, 1 );
		        glScalef(q,q, q);
		        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
		        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
		        glutWireCube(1);
		    glPopMatrix();
			}
		if(!val&&kocke[i][j][k].prokopano==0){/*deo koji pravi stacionarnu mapu*/
			if(a->smer%200==0){ /*u zavisnosti na koju stranu je rotirana mapa, parno*/
				if(kocke[i][j][k].z==a->z){
			        	glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3, 0.2, 0 );
					else if(kocke[i][j][k].tip==2)
						glColor3f(1,1,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1,0,0); 
					if(kocke[i][j][k].vidjeno==0)
						glColor3f(0,0,0);
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
					glutSolidCube(1);
				        if(kocke[i][j][k].vidjeno==1){
						glColor3f(0.99,0.99,0.99);
						glutWireCube(1);
					}
				        glPopMatrix();
				}
				if(a->smer==0&&kocke[i][j][k].z==a->z-1){
			        	glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3-0.04, 0.2-0.04, 0 );
					if(kocke[i][j][k].tip==2)
						glColor3f(1-0.04,1-0.04,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1-0.04,0,0); 
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
				        glutSolidCube(1);
				        glPopMatrix();
					
				}
				if(a->smer==200&&kocke[i][j][k].z==a->z+1){
			        	glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3-0.04, 0.2-0.04, 0 );
					if(kocke[i][j][k].tip==2)
						glColor3f(1-0.04,1-0.04,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1-0.04,0,0); 
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
				        glutSolidCube(1);
				        glPopMatrix();
					
				}
			}
			if(a->smer%200==100){ /*neparno*/
				if(kocke[i][j][k].x==a->x){	
					glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3, 0.2, 0 );
					else if(kocke[i][j][k].tip==2)
						glColor3f(1,1,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1,0,0); 
					if(kocke[i][j][k].vidjeno==0)
						glColor3f(0,0,0);
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
			        	glutSolidCube(1);
				        if(kocke[i][j][k].vidjeno==1){
						glColor3f(0.99,0.99,0.99);
						glutWireCube(1);
					}
					glPopMatrix();
				}
				if(a->smer==100&&kocke[i][j][k].x==a->x+1){
			        	glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3-0.04, 0.2-0.04, 0 );
					else if(kocke[i][j][k].tip==2)
						glColor3f(1-0.04,1-0.04,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1-0.04,0,0); 
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
				        glutSolidCube(1);
				        glPopMatrix();
					
				}
				if(a->smer==300&&kocke[i][j][k].x==a->x-1){
			        	glPushMatrix();
					if(kocke[i][j][k].tip==1)
						glColor3f( 0.4*kocke[i][j][k].health/3-0.04, 0.2-0.04, 0 );
					if(kocke[i][j][k].tip==2)
						glColor3f(1-0.04,1-0.04,0);
					else if(kocke[i][j][k].tip==3)
						glColor3f(1-0.04,0,0); 
				        glScalef(q,q, q);
				        glRotatef(((float)a->smer)*90/100, 0, 1, 0);
				        glTranslatef(kocke[i][j][k].x,kocke[i][j][k].y, kocke[i][j][k].z);
				        glutSolidCube(1);
				        glPopMatrix();
					
				}
			}
		}
			
	}
      }
    } 

}
void karakter(int animation_active, igrac a){
float q=0.25;
	    if(animation_active==1){
		glColor3f(1,0,0);}
	    else
		glColor3f(0,0,1);
    	glScalef(q,q,q);
    	glRotatef(((float)a.smer)*90/100,0,1,0);
    	glTranslatef(a.x,a.y, a.z);
    	glutSolidCube(1);
}
