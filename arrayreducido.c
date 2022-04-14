#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define  TOPEY     26
#define  TOPEX     115
#define  Ci        3
#define  Fi        2
#define  Jiy       23
#define  Jfy       25
#define  Jix       53
#define  Jfx       62

int a;
int  d;
int  t;                  //disparos
int  BG   = 0;           //Fondo negro
int  W    = 15;          //Color blanco
int  Line = 9;           //color del marco
int  Jx;                 //Coordenada en x del jugador
int  Jy;                 //coordenada en y del jugador
int  score[5];
char jugadores[5]={'-','-','-','-','-'};
int  New_Color;
char Tecla;              //Movimiento
int  i;                  //Indice del array del nombre
char nombre[10];
long long int Score;
int  n;                  //Para movimiento del jugador
int  c = 4;                  //Para decidir colores
int  A[TOPEY][TOPEX];    // array general
int  x;                  //Posición en x
int  y;                 //Posición  en y
int  p = 2;
int  over;
int  ci = 10;
int  fi = 3;
int  v;
int  q;
int  k=4;

void fnarrayaliens    	();
void FnSetColor        	(int, int);
void fngotoxy          	(int x, int y);
void fnimprimemarco    	(int fi, int ci, int ff, int cf);
void fnintro           	();
void fnTop5            	();
void fnnombre          	();
void fnjugar           	();
void fnjugador         	(int JIx, int JFx, int JIy, int JFy, int N, int C);
void fninteracciones   	();
void fnaliens          	();
void  fnalien           (int x, int y);
//void fnfilasaliens ();
void fnborraalien       ();
void fnscore            ();
void fnniveles          ();
void fnmovimientoaliens ();
void fnarraygeneral     ();


void main(){
  fnarraygeneral();
  fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
  fnjugador(Jix, Jfx, Jiy, Jfy, n, c=5);
  fnmovimientoaliens();
  fninteracciones();
  return;
}
void fnarraygeneral(){
  for (y=2; y<TOPEY; y++){
    for (x=4; x<TOPEX; x++){
      fngotoxy(x, y);
      A[y][x]= 31;
      printf("%c", A[y][x]);
    }
    printf("\n");
  }
	return;
}

void fnarrayaliens(){
  for (y=0; y<5; y++){
    for (x=0; x<(95); x++){
      FnSetColor(0, c);
      A[y][x]= a;
      fngotoxy(x+12, y+k);
      printf("%c", A[y][x]);
      x += 3;
    }
    y+=1;
  }
	return;
}

void fnalien(int x, int y){
  int k;
  return;
}

void fnaliens(){
  int e;
  int m;
  for (m = 0; m<5; m++){
    y = fi + m;
    for (e=0; e<100; e++){
      x = ci + e;
      fnalien(x, y);
      e += 4;
    }
    m += 1;
    e = 0;
  }
  return;
}

void fnmovimientoaliens(){
  while (1){
    if (kbhit()){
      fninteracciones();
    }
    else{
      if (((y+k)==Jiy)&&((Jix+4+n)<x<(Jfx+4+n))){
        exit(1);
      }
      a = 0; c = 0;
      fnarrayaliens();
      k++;
      a = 232; c = 2;
      fnarrayaliens();
      Sleep(1000);
    }
  }
  return;
}

void fnjugador(int JIx, int JFx, int JIy, int JFy,int N, int C){
	Jx = Jix+n;
	FnSetColor(c, c);
	for (Jx; (Jx<Jfx+n); Jx++){
		fngotoxy(Jx,Jfy);
		printf("%c", 219);
		fngotoxy(Jx,(Jiy + 1));
		printf("%c", 219);
	}
	fngotoxy((Jix+4+n), Jiy);
	printf("%c", 219);
	fngotoxy(0, 27);
	return;
}

void fninteracciones(){
      switch(getch()) {
                case 75:{
                  if ((Jix+n)== (Ci + 1)){
                  break;
                  }
                  else {
                    c = 0;
                    fnjugador(Jix, Jfx, Jiy, Jfy, n, c);
                    n--;
                    c = 5;
                    fnjugador(Jix, Jfx, Jiy, Jfy, n, c);
                  break;
                  }
              }
              case 77:{
                  if ((Jfx+n)== (TOPEX- 1)){
                    break;
                  }
                  else {
                    c = 0;
                    fnjugador(Jix, Jfx, Jiy, Jfy, n, c);
                    c = 5;
                    n++;
                    fnjugador(Jix, Jfx, Jiy, Jfy, n, c);
                  }
                  break;
            }
              case 32: {
                for (t=1; (Jiy-t)>2; t++){
                  if (A[Jiy-t][Jix+4+n] != 0){
                    fnborraalien();
                    break;
                  }
                  else{
                    FnSetColor(0,W);
                    A[Jiy-t][Jix+4+n] = 124;
                    fngotoxy((Jix+4+n),(Jiy-t));
                    printf("%c", A[Jiy-t][Jix+4+n]);
                    Sleep(1);
                    FnSetColor(0,0);
                    fngotoxy((Jix+4+n),(Jiy-t));
                    printf("%c", A[Jiy-t][Jix+4+n]);
                    A[Jiy-t][Jix+4+n] = 0;
                  }
                }

                break;
              }
    }
	return;
}

void fnborraalien(){
  x = (Jix+4+n); y = (Jiy-t);
  A[y][x] = 20;
  fnalien(x, y);
  t = 22;
  return;
}

void fnimprimemarco(int fi, int ci, int ff, int cf){
	FnSetColor(BG,Line);
	fngotoxy(ci, fi); printf("%c", 218);
	fngotoxy(ci, ff); printf("%c", 192);
	fngotoxy(cf, fi); printf("%c", 191);
	fngotoxy(cf, ff); printf("%c", 217);
	int l1 = ci + 1;
	for (l1; l1 < cf; l1++)
	{
		fngotoxy(l1, fi); printf ("%c",196);
		fngotoxy(l1, ff); printf ("%c",196);
	}
	int l2=fi+1;
	for (l2; l2 < ff; l2++)
	{
		fngotoxy(ci, l2); printf ("%c",179);
		fngotoxy(cf, l2); printf ("%c",179);
	}
	printf("\n");
	FnSetColor(BG, W);
	return;
}

void fngotoxy(int x, int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
      return;
}

void FnSetColor (int piFondo, int piColor)
{
	HANDLE Console;
	Console         = GetStdHandle(STD_OUTPUT_HANDLE);
	New_Color       = (piFondo * 16) + piColor;
	SetConsoleTextAttribute(Console, New_Color);
}
