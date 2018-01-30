#include <stdlib.h>
#include <GL/glut.h>
#include"header.h"
#include<stdio.h> 

static int window_width, window_height;
static int animation_active;
static kocka kocke[brred][brred][brred];
static metak sanzer[brred];/*skladisti metke*/
static int val=0;/*vrednost za signaliziranje rotacije mape*/
static igrac a;
static char putokaz='l';
static bot b[Bnum];
static int w=0;
static int count=0;
static int countdown=0;
static int clock=0;
static int recharge=0;
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_timer(int value);
static void on_display(void);
int main(int argc, char **argv)
{
    napravi(kocke);
    a=spawn();
    napuni(sanzer); 
    animation_active = 0;
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
 
    /* Kreira se prozor. */
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("rudar");
    /* Registruju se callback funkcije. */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
	if(key==27){exit(0);}
	if(key=='g'&&animation_active==0&&clock<timeT){
		animation_active=1;
   	         glutTimerFunc(10, on_timer, 0);}
	if(key=='h'&&clock<timeT){
		animation_active=0;
	}
	if(key=='r'&&animation_active==0&&clock>=timeT){
		napravi(kocke);
    		a=spawn(); 
    		animation_active = 1;
		w=0;
		count=0;
		countdown=0;
		clock=0;
		putokaz='l';
		glutTimerFunc(10, on_timer, 0);
	} 
	if(animation_active==1){
	    switch(key){ 
		case 'q':if(a.smer%100==0&&!count)
			val=2;break; 
		case 'e':if(a.smer%100==0&&!count)
			val=1; break;
		case 'w':
		case 's':
		case 'a': 
		case 'd':if(!a.korak&&!val&&!a.stanje){
			     putokaz=key;
			     a=pokret(a,key, kocke,&w,b, &count);}
			 if(a.stanje==1&&!recharge){ 
			     opali(a,sanzer, key);
			     recharge=rechargeR;}
			 break;
		case 'k':if(!a.korak&&!val){
			     a.stanje=a.stanje==0?1:0;
			     putokaz=a.stanje*'k';}break;
	    }
	} 
}
static void on_timer(int value)
{
    if (value != 0)
            return; 
    countdown++;
    putanja(sanzer, kocke); /*preracun za svaki ispaljeni metak*/
    if(recharge)
	recharge--; 
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
    korak(&a,kocke); /*animacija kretanja igraca*/
    kretanje(b,a, kocke,&clock ); /*kretanje botova*/
    if(countdown%100==0){
	clock++;
	}
     if(clock>=timeT)
	animation_active=0;
    glutPostRedisplay();
    if(value==0&&animation_active==1)
        glutTimerFunc(TIMEF, on_timer, value);
}
static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
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
    /*start-end*/
    startstop(animation_active, clock, a);
    if(animation_active==1&&(clock>=0||clock<=timeT)){
        /*informacije na ekranu*/ 
        glPushMatrix();
	    glColor3f(1,1,1); 
    	    ispisi("Time:",timeT-clock,0,1.5);
	    ispisi("Points:",a.score,1.2,1.5);
    	    glPopMatrix();
        /*crtanje igraca*/
        glPushMatrix(); 
	        if(animation_active==1)
	    	    glColor3f(0,1,1); 
	        if(a.stanje==1) 
		    glColor3f(0,1,0); 
    	    glScalef(q,q,q);
    	    glRotatef(((float)a.smer)*90/100,0,1,0); 
    	    glTranslatef(a.x,a.y, a.z);
    	    robot(0.1, a.smer, a.korak, putokaz); 
        glPopMatrix();
	    osvetli(kocke,a.i, a.j, a.k, 1);
       /*crtanje mape*/  
       glPushMatrix(); 
           mapa(kocke, val, &a);
       glPopMatrix();
        /*crtanje metaka*/
       glPushMatrix();
           shot(sanzer, b, &a, &count);
       glPopMatrix();  
        /*crtanje botova*/
       glPushMatrix(); 
           botovi(b, w, a.smer);
       glPopMatrix();
    }
    glutSwapBuffers();
}


