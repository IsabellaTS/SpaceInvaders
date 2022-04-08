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
int b;
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
int  ci = 17;
int m;

void fnarraygeneral    	();
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
int  fnalien           	(int C, int a, int b);
void fnmovimientoaliens ();

void main (){
  fnarraygeneral();
  fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
  fnmovimientoaliens(c);
  fngotoxy(0,27);
  printf("%d", x);
  return;
}


int fnalien(int C, int a, int b){
  FnSetColor(0,c);
  for (p; p>(t-3); p--){
    x = ci + p;
    A[y][x] = a;
    fngotoxy(x,y);
    printf("%c", A[y][x]);
    A[y+1][x] = b;
    fngotoxy (x, (y+1));
    printf("%c", A[y+1][x]);
  }
  return x;
}

void fnaliens(){
    y = Fi + m;
    do{
      x = ci + t;
      p = t;
      fnalien(c=5, a, b);
      n++;
      t += 5;
    }
    while (n<18);
    n = 0;
  return;
}

void fnmovimientoaliens(){
  do {
      a = 219;
      b = 31;
      for (m=1; m<9; m+=3){
        t=i;
        fnaliens();
      }
      Sleep(500);
      t = i;
      a = 0;
      b = 0;
      for (m=1; m<9; m+=3){
        t=i;
        fnaliens();
      }
      i++;
      t = i;
    }
    while (x < (TOPEX-4) );

    do {
        a = 219;
        b = 31;
        for (m=1; m<9; m+=3){
          t=i;
          fnaliens();
        }
        Sleep(500);
        t = i;
        a = 0;
        b = 0;
        for (m=1; m<9; m+=3){
          t=i;
          fnaliens();
        }
        i--;
        t = i;
    }
    while((ci+t)>(Ci+3));
}

void fnarraygeneral(){
	for (y=0; y<(TOPEY-1); y++){
	  fngotoxy(4,p);
		p++;
		for (x=0; x<(TOPEX-3); x++){
			A[y][x]= 0;
			printf("%c",A[y][x]);
		}
	}
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
