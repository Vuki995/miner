#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>

void napravi(kocka a[10][10][10]){
int i,j,k,l;
 for(i=0;i<brred;i++){
      for(j=0;j<brred;j++){
	for(k=0;k<brred;k++){
		a[i][j][k].x=(4.5-k);
		a[i][j][k].y=(4.5-j);
		a[i][j][k].z=(4.5-i);
    		a[i][j][k].tip=1;
		a[i][j][k].vidjeno=0;
		a[i][j][k].prokopano=0;
		a[i][j][k].health=3;
	}
      }
    }
a[4][0][4].prokopano=1;
a[4][0][3].vidjeno=1;
a[4][0][5].vidjeno=1;
a[3][0][4].vidjeno=1;
a[5][0][4].vidjeno=1;
a[4][1][4].vidjeno=1;
for(i=0;i<20;i++){
	j=rand()%10;
	k=rand()%10;
	l=rand()%10;
	if(j!=4&&k!=0&&l!=4){
		a[j][k][l].tip=2;
	}
	else
		i--;
	}

}

