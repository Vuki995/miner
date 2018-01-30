#include"header.h"
#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include <GL/freeglut.h>
igrac spawn(void){
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
    a.stanje=0;
    a.smer=0;
    a.i1=0;
    a.j1=0;
    a.k1=0;
    a.score=0;
return a;
}

igrac pokret(igrac a, char c,kocka k[brred][brred][brred], int *m, bot b[Bnum], int *count){ 
    a.x1=a.x;
    a.y1=a.y;
    a.z1=a.z;
if(c=='w'){
    if(a.j>0){
        if(k[a.i][a.j-1][a.k].prokopano==1)
	    a.j1=-1;
	else if(k[a.i][a.j-1][a.k].prokopano==0){
		pMove(k, a.i, a.j-1, a.k, m,count, b, &a);
	}
    }

return a;
}
if(c=='s'){
    if(a.j<9){
        if(k[a.i][a.j+1][a.k].prokopano==1)
	    a.j1=1;
	else if(k[a.i][a.j+1][a.k].prokopano==0){
		pMove(k, a.i, a.j+1, a.k, m,count, b, &a);
	}
    }
return a;
}
switch(a.smer){
    case 0:if(c=='a'){
   		 if(a.k<9){
   		     if(k[a.i][a.j][a.k+1].prokopano==1)
			    a.k1=1;
		     else if(k[a.i][a.j][a.k+1].prokopano==0){
			pMove(k, a.i, a.j, a.k+1, m,count, b, &a);
		      }
  		  }
		return a;
	    }
	   if(c=='d'){
		if(a.k>0){
   		     if(k[a.i][a.j][a.k-1].prokopano==1)
			    a.k1=-1;
		     else if(k[a.i][a.j][a.k-1].prokopano==0){
			pMove(k, a.i, a.j, a.k-1, m,count, b, &a);
		      }
		  }
		return a;
	    }break;
    case 100:if(c=='a'){
		if(a.i<9){
   		     if(k[a.i+1][a.j][a.k].prokopano==1)
			    a.i1=1;
		     else if(k[a.i+1][a.j][a.k].prokopano==0){
			pMove(k, a.i+1, a.j, a.k, m,count, b, &a);
		      }
  		  }
		return a;
	    }
	   if(c=='d'){
		if(a.i>0){
   		     if(k[a.i-1][a.j][a.k].prokopano==1)
			    a.i1=-1;
		     else if(k[a.i-1][a.j][a.k].prokopano==0){
			pMove(k, a.i-1, a.j, a.k, m,count, b, &a);
		      }
  		  }
		return a;
	    }break;
    case 200:if(c=='d'){
		if(a.k<9){
   		     if(k[a.i][a.j][a.k+1].prokopano==1)
			    a.k1=1;
		     else if(k[a.i][a.j][a.k+1].prokopano==0){
			pMove(k, a.i, a.j, a.k+1, m,count, b, &a);
		      }
  		  }
		return a;
	    }
	   if(c=='a'){
		if(a.k>0){
   		     if(k[a.i][a.j][a.k-1].prokopano==1)
			    a.k1=-1;
		     else if(k[a.i][a.j][a.k-1].prokopano==0){
			pMove(k, a.i, a.j, a.k-1, m,count, b, &a);
		      }
  		  }
		return a;
	    }break;
    case 300:if(c=='d'){
		if(a.i<9){
   		     if(k[a.i+1][a.j][a.k].prokopano==1)
			    a.i1=1;
		     else if(k[a.i+1][a.j][a.k].prokopano==0){
			pMove(k, a.i+1, a.j, a.k, m,count, b, &a);
		      }
  		  }
		return a;
	    }
	   if(c=='a'){
		if(a.i>0){
   		     if(k[a.i-1][a.j][a.k].prokopano==1)
			    a.i1=-1;
		     else if(k[a.i-1][a.j][a.k].prokopano==0){
			pMove(k, a.i-1, a.j, a.k, m,count, b, &a);
		      }
  		  }
		return a;
	    }break;

}
}
void pMove(kocka k[brred][brred][brred], int i, int j, int l, int *m,int * count, bot b[Bnum], igrac * a){
	if(k[i][j][l].tip==3){
		b[*m]=probudi(k[i][j][l],i,j,l);
		k[i][j][l].health=0;
		k[i][j][l].prokopano=1;
		*m=*m+1;
		*count=*count+1;
	}
	k[i][j][l].health--;
	if(k[i][j][l].health==0){
		if(k[i][j][l].tip==2){
			a->score=a->score+100;}
		k[i][j][l].prokopano=1;
	}
}

void osvetli(kocka k[brred][brred][brred],int a, int b, int c, int vidi){
int vid=0;
 if(vidi){
vid=1;}
k[a][b][c].vidjeno=vid;
if(a<9){
	k[a+1][b][c].vidjeno=vid;
		if(k[a+1][b][c].prokopano){
			if(a+1<9){
				k[a+2][b][c].vidjeno=vid;
				if(k[a+2][b][c].prokopano){
					if(a+2<9)
						k[a+3][b][c].vidjeno=vid;
					if(b<9)
						k[a+2][b+1][c].vidjeno=vid;
					if(b>0)
						k[a+2][b-1][c].vidjeno=vid;
				}
			}
			if(b<9)
				k[a+1][b+1][c].vidjeno=vid;
			if(b>0)
				k[a+1][b-1][c].vidjeno=vid;
		}
	}
if(a>0){
	k[a-1][b][c].vidjeno=vid;
		if(k[a-1][b][c].prokopano){
			if(a-1>0){
				k[a-2][b][c].vidjeno=vid;
				if(k[a-2][b][c].prokopano){
					if(a-2>0)
						k[a-3][b][c].vidjeno=vid;
					if(b<9)
						k[a-2][b+1][c].vidjeno=vid;
					if(b>0)
						k[a-2][b-1][c].vidjeno=vid;
				}
			}
			if(b<9)
				k[a-1][b+1][c].vidjeno=vid;
			if(b>0)
				k[a-1][b-1][c].vidjeno=vid;
		}
	}
if(b<9){
	k[a][b+1][c].vidjeno=vid;
		if(k[a][b+1][c].prokopano){
			if(b+1<9){
				k[a][b+2][c].vidjeno=vid;
				if(k[a][b+2][c].prokopano){
					if(b+2<9)
						k[a][b+3][c].vidjeno=vid;
					if(a<9)
						k[a+1][b+2][c].vidjeno=vid;
					if(a>0)
						k[a-1][b+2][c].vidjeno=vid;
					if(c<9)
						k[a][b+2][c+1].vidjeno=vid;
					if(c>0)
						k[a][b+2][c-1].vidjeno=vid;
				}
			}
			if(a<9)
				k[a+1][b+1][c].vidjeno=vid;
			if(a>0)
				k[a-1][b+1][c].vidjeno=vid;
			if(c<9)
				k[a][b+1][c+1].vidjeno=vid;
			if(c>0)
				k[a][b+1][c-1].vidjeno=vid;
		}
	}
if(b>0){
	k[a][b-1][c].vidjeno=vid;
		if(k[a][b-1][c].prokopano){
			if(b-1>0){
				k[a][b-2][c].vidjeno=vid;
				if(k[a][b-2][c].prokopano){
					if(b-2>0)
						k[a][b-3][c].vidjeno=vid;
					if(a<9)
						k[a+1][b-2][c].vidjeno=vid;
					if(a>0)
						k[a-1][b-2][c].vidjeno=vid;
					if(c<9)
						k[a][b-2][c+1].vidjeno=vid;
					if(c>0)
						k[a][b-2][c-1].vidjeno=vid;
				}
			}
			if(a<9)
				k[a+1][b-1][c].vidjeno=vid;
			if(a>0)
				k[a-1][b-1][c].vidjeno=vid;
			if(c<9)
				k[a][b-1][c+1].vidjeno=vid;
			if(c>0)
				k[a][b-1][c-1].vidjeno=vid;
		}
	}
if(c<9){
	k[a][b][c+1].vidjeno=vid;
		if(k[a][b][c+1].prokopano){
			if(c+1<9){
				k[a][b][c+2].vidjeno=vid;
				if(k[a][b][c+2].prokopano){
					if(c+2<9)
						k[a][b][c+3].vidjeno=vid;
					if(b<9)
						k[a][b+1][c+2].vidjeno=vid;
					if(b>0)
						k[a][b-1][c+2].vidjeno=vid;
				}
			}
			if(b<9)
				k[a][b+1][c+1].vidjeno=vid;
			if(b>0)
				k[a][b-1][c+1].vidjeno=vid;
		}
	}
if(c>0){
	k[a][b][c-1].vidjeno=vid;
		if(k[a][b][c-1].prokopano){
			if(c-1>0){
				k[a][b][c-2].vidjeno=vid;
				if(k[a][b][c-2].prokopano){
					if(c-2>0)
						k[a][b][c-3].vidjeno=vid;
					if(b<9)
						k[a][b+1][c-2].vidjeno=vid;
					if(b>0)
						k[a][b-1][c-2].vidjeno=vid;
				}
			}
			if(b<9)
				k[a][b+1][c-1].vidjeno=vid;
			if(b>0)
				k[a][b-1][c-1].vidjeno=vid;
		}
	}
return;
}
void korak(igrac * a,kocka kocke[brred][brred][brred]){
if(a->i1!=0||a->j1!=0||a->k1!=0){
	if(a->korak<MAXK){
	    a->x=(a->x*100-(a->k1*100/MAXK))/100;   
	    a->y=(a->y*100-(a->j1*100/MAXK))/100;
	    a->z=(a->z*100-(a->i1*100/MAXK))/100;
	    a->korak++;
	} 
	if(a->korak==MAXK){	
	    osvetli(kocke,a->i, a->j, a->k, 0);
	    a->x=a->x1-a->k1;
	    a->y=a->y1-a->j1;
	    a->z=a->z1-a->i1;
	    a->i=a->i+a->i1;
	    a->j=a->j+a->j1;
	    a->k=a->k+a->k1; 
	    a->i1=a->j1=a->k1=a->korak=0;
	    osvetli(kocke,a->i, a->j, a->k, 1);
	}
    }
}
