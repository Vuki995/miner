#include <stdlib.h>
#include <GL/glut.h>
#include"header.h"

void init_lighting()
{
    GLfloat light_direction[] = {155, 0, 75};
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1};
    GLfloat light_diffuse[]  = {0.8, 0.8, 0.8, 1};
    GLfloat light_specular[] = {0.9, 0.9, 0.9, 1};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void set_mat(int a,int b){
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
        GLfloat shininess[1];
	GLfloat emission[4];
	
	switch (a){
	case 0: ambient[0]=0;ambient[1]=0;ambient[2]=0;ambient[3]=1;
		diffuse[0]=0;diffuse[1]=0;diffuse[2]=0;diffuse[3]=1;
		specular[0]=0;specular[1]=0;specular[2]=0;specular[3]=1;
		emission[0]=0;emission[1]=0;emission[2]=0;emission[3]=1;shininess[0]=1;break;
	case 1: ambient[0]=0*b/3;ambient[1]=0*b/3;ambient[2]=0;ambient[3]=1;
		diffuse[0]=1.0f*b/3;diffuse[1]=0.5*b/3;diffuse[2]=0;diffuse[3]=1;
		specular[0]=0;specular[1]=0;specular[2]=0;specular[3]=1;
		emission[0]=0;emission[1]=0;emission[2]=0;emission[3]=1;shininess[0]=10;break;
	case 2: ambient[0]=1.0f*b/3;ambient[1]=1.0f*b/3;ambient[2]=0;ambient[3]=1;
		diffuse[0]=1.0f*b/3;diffuse[1]=1.0f*b/3;diffuse[2]=0;diffuse[3]=1;
		specular[0]=1;specular[1]=1;specular[2]=1;specular[3]=1;
		emission[0]=0;emission[1]=0;emission[2]=0;emission[3]=1;shininess[0]=100.0f*b/3;break;
	case 3: ambient[0]=1.0f*b/3;ambient[1]=0;ambient[2]=0;ambient[3]=1;
		diffuse[0]=1.0f*b/3;diffuse[1]=0;diffuse[2]=0;diffuse[3]=1;
		specular[0]=0.5;specular[1]=0;specular[2]=0;specular[3]=1;
		emission[0]=0;emission[1]=0;emission[2]=0;emission[3]=1;shininess[0]=100;break;
	case 4: ambient[0]=1.0f/100*b;ambient[1]=1.0f/100*b;ambient[2]=1.0f/100*b;ambient[3]=1;
		diffuse[0]=1.0f/100*b;diffuse[1]=1.0f/100*b;diffuse[2]=1.0f/100*b;diffuse[3]=1;
		specular[0]=0;specular[1]=0;specular[2]=0;specular[3]=1;
		emission[0]=b/100;emission[1]=b/100;emission[2]=b/100;emission[3]=1;shininess[0]=1;break;
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
}
