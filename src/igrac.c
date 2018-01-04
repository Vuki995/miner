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
igrac pokret(igrac a, char c,kocka k[brred][brred][brred]){ 
    a.x1=a.x;
    a.y1=a.y;
    a.z1=a.z;
if(c=='w'){
    if(a.j>0){
        if(k[a.i][a.j-1][a.k].prokopano==1)
	    a.j1=-1;
	else if(k[a.i][a.j-1][a.k].prokopano==0){
		k[a.i][a.j-1][a.k].health--;
		if(k[a.i][a.j-1][a.k].health==0){
			if(k[a.i][a.j-1][a.k].tip==2){
				a.score=a.score+1;}
			k[a.i][a.j-1][a.k].prokopano=1;
			osvetli(k,a.i,a.j-1,a.k);
		}
	}
    }

return a;
}
if(c=='s'){
    if(a.j<9){
        if(k[a.i][a.j+1][a.k].prokopano==1)
	    a.j1=1;
	else if(k[a.i][a.j+1][a.k].prokopano==0){
		k[a.i][a.j+1][a.k].health--;
		if(k[a.i][a.j+1][a.k].health==0){
			if(k[a.i][a.j+1][a.k].tip==2){
				a.score=a.score+1;}
			k[a.i][a.j+1][a.k].prokopano=1;
			osvetli(k,a.i,a.j+1,a.k);
		}
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
			k[a.i][a.j][a.k+1].health--;
			    if(k[a.i][a.j][a.k+1].health==0){
				if(k[a.i][a.j][a.k+1].tip==2){
				     a.score=a.score+1;}
				k[a.i][a.j][a.k+1].prokopano=1;
				osvetli(k,a.i,a.j,a.k+1);
		     	     }
		      }
  		  }
		return a;
	    }
	   if(c=='d'){
		if(a.k>0){
   		     if(k[a.i][a.j][a.k-1].prokopano==1)
			    a.k1=-1;
		     else if(k[a.i][a.j][a.k-1].prokopano==0){
			k[a.i][a.j][a.k-1].health--;
			    if(k[a.i][a.j][a.k-1].health==0){
				if(k[a.i][a.j][a.k-1].tip==2){
				     a.score=a.score+1;}
				k[a.i][a.j][a.k-1].prokopano=1;
				osvetli(k,a.i,a.j,a.k-1);
		     	     }
		      }
		  }
		return a;
	    }break;
    case 100:if(c=='a'){
		if(a.i<9){
   		     if(k[a.i+1][a.j][a.k].prokopano==1)
			    a.i1=1;
		     else if(k[a.i+1][a.j][a.k].prokopano==0){
			k[a.i+1][a.j][a.k].health--;
			    if(k[a.i+1][a.j][a.k].health==0){
				if(k[a.i+1][a.j][a.k].tip==2){
				     a.score=a.score+1;}
				k[a.i+1][a.j][a.k].prokopano=1;
				osvetli(k,a.i+1,a.j,a.k);
		     	     }
		      }
  		  }
		return a;
	    }
	   if(c=='d'){
		if(a.i>0){
   		     if(k[a.i-1][a.j][a.k].prokopano==1)
			    a.i1=-1;
		     else if(k[a.i-1][a.j][a.k].prokopano==0){
			k[a.i-1][a.j][a.k].health--;
			    if(k[a.i-1][a.j][a.k].health==0){
				if(k[a.i-1][a.j][a.k].tip==2){
				     a.score=a.score+1;}
				k[a.i-1][a.j][a.k].prokopano=1;
				osvetli(k,a.i-1,a.j,a.k);
		     	     }
		      }
  		  }
		return a;
	    }break;
    case 200:if(c=='d'){
		if(a.k<9){
   		     if(k[a.i][a.j][a.k+1].prokopano==1)
			    a.k1=1;
		     else if(k[a.i][a.j][a.k+1].prokopano==0){
			k[a.i][a.j][a.k+1].health--;
			    if(k[a.i][a.j][a.k+1].health==0){
				if(k[a.i][a.j][a.k+1].tip==2){
				     a.score=a.score+1;}
				k[a.i][a.j][a.k+1].prokopano=1;
				osvetli(k,a.i,a.j,a.k+1);
		     	     }
		      }
  		  }
		return a;
	    }
	   if(c=='a'){
		if(a.k>0){
   		     if(k[a.i][a.j][a.k-1].prokopano==1)
			    a.k1=-1;
		     else if(k[a.i][a.j][a.k-1].prokopano==0){
			k[a.i][a.j][a.k-1].health--;
			    if(k[a.i][a.j][a.k-1].health==0){
				if(k[a.i][a.j][a.k-1].tip==2){
				     a.score=a.score+1;}
				k[a.i][a.j][a.k-1].prokopano=1;
				osvetli(k,a.i,a.j,a.k-1);
		     	     }
		      }
  		  }
		return a;
	    }break;
    case 300:if(c=='d'){
		if(a.i<9){
   		     if(k[a.i+1][a.j][a.k].prokopano==1)
			    a.i1=1;
		     else if(k[a.i+1][a.j][a.k].prokopano==0){
			k[a.i+1][a.j][a.k].health--;
			    if(k[a.i+1][a.j][a.k].health==0){
				if(k[a.i+1][a.j][a.k].tip==2){
				     a.score=a.score+1;}
				k[a.i+1][a.j][a.k].prokopano=1;
				osvetli(k,a.i+1,a.j,a.k);
		     	     }
		      }
  		  }
		return a;
	    }
	   if(c=='a'){
		if(a.i>0){
   		     if(k[a.i-1][a.j][a.k].prokopano==1)
			    a.i1=-1;
		     else if(k[a.i-1][a.j][a.k].prokopano==0){
			k[a.i-1][a.j][a.k].health--;
			    if(k[a.i-1][a.j][a.k].health==0){
				if(k[a.i-1][a.j][a.k].tip==2){
				     a.score=a.score+1;}
				k[a.i-1][a.j][a.k].prokopano=1;
				osvetli(k,a.i-1,a.j,a.k);
		     	     }
		      }
  		  }
		return a;
	    }break;

}
}
void osvetli(kocka k[brred][brred][brred],int a, int b, int c){/*osvetli polja oko prosledjene lokacije*/
 
if(a<9)
	k[a+1][b][c].vidjeno=1;
if(a>0)
	k[a-1][b][c].vidjeno=1;
if(b<9)
	k[a][b+1][c].vidjeno=1;
if(b>0)
	k[a][b-1][c].vidjeno=1;
if(c<9)
	k[a][b][c+1].vidjeno=1;
if(c>0)
	k[a][b][c-1].vidjeno=1;
return;
}
