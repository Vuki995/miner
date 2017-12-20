#include <stdlib.h>
#include <GL/glut.h>
#include"header.h"
#include<stdio.h>

static int window_width, window_height;
static int animation_active;
static int val=0;/*vrednost za signaliziranje rotacije mape*/
static igrac a;
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);

int main(int argc, char **argv)
{
    a=spawn();
    animation_active = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("rudar");
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
	if(key==27){exit(0);}
	if(key=='g'&&animation_active==0){			/*start dugme*/
		animation_active=1;
   	         glutTimerFunc(10, on_timer, 0);}
	if(key=='h'){ 						/*pauza*/
		animation_active=0;
	}
	if(animation_active==1){
	    switch(key){
		case 'q':if(a.smer%100==0)
			val=2;break;
		case 'e':if(a.smer%100==0)
			val=1; break;
		case 'w':if(a.korak==0&&!val){
			     a=pokret(a,'w');
			 }break;
		case 's':if(a.korak==0&&!val){
			     a=pokret(a,'s');
			 }break;
		case 'a':if(a.korak==0&&!val){
			     a=pokret(a,'a');
			 }break;
		case 'd':if(a.korak==0&&!val){
			     a=pokret(a,'d');
			 }break;
	    }
	}
}
static void on_timer(int value)
{
    if (value != 0)
            return; 
    if (val==1){
	if(a.smer==0)
		a.smer=400;
	a.smer=a.smer-1;
   	if(a.smer%100==0)
		val=0;
    } 
    if (val==2){
	if(a.smer==300)
		a.smer=-100;
	a.smer=a.smer+1;
	if(a.smer%100==0)
		val=0;
    }
    if(a.i1!=0||a.j1!=0||a.k1!=0){
	if(a.korak<MAXK){ 
	    a.x=(a.x*100-(a.k1*100/MAXK))/100;   
	    a.y=(a.y*100-(a.j1*100/MAXK))/100;
	    a.z=(a.z*100-(a.i1*100/MAXK))/100;
	    a.korak++;
	}
	if(a.korak==MAXK){
	    a.x=a.x1-a.k1;
	    a.y=a.y1-a.j1;
	    a.z=a.z1-a.i1;
	    a.i=a.i+a.i1;
	    a.j=a.j+a.j1;
	    a.k=a.k+a.k1;
	    a.i1=a.j1=a.k1=a.korak=0;
	}
    }


    glutPostRedisplay();
    if(value==0&&animation_active==1)
        glutTimerFunc(TIMEF, on_timer, value);
}
static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;
}

static void on_display(void)
{ 
    float q=0.25;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window_width, window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, window_width/(float)window_height, 1, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);
    /*crta igraca*/
    glPushMatrix();
	    if(animation_active==1){
		glColor3f(1,0,0);}
	    else
		glColor3f(0,0,1);
    	glScalef(q,q,q);
    	glRotatef(((float)a.smer)*90/100,0,1,0);
    	glTranslatef(a.x,a.y, a.z);
    	glutSolidCube(1);
    glPopMatrix();
    glutSwapBuffers();
}
