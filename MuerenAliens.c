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

int  d;
int  a;
int  b;
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
int  m;
int  nivel;
int  v;
int segundos, minutos;

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
int  fnalien           	(int C, int a, int b, int p, int y);
void fnfilasaliens ();
void fnborraalien       ();
void fnscore            ();
void fnniveles          ();


void main(){
	fnintro();
	return;
}
/*
void fnniveles(){
	for (y=0; y<(TOPEY-1); y++){
		fngotoxy(4,p);
		p++;
		for (x=0; x<(TOPEX-3); x++){
			if(A[y][x]==0);
		}
	}
}
*/

void fnintro(){
	system ("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	FnSetColor(0, W);
	fngotoxy(36,10);
	printf("Bienvenido a Space Invaders. Elige una opci%cn:\n", 162);
	fngotoxy(53,12);
	printf("Jugar    ENTER");
	fngotoxy(53,13);
	printf("Top 5    SPACE");
	fngotoxy(46,15);
	printf("Presione otra tecla para salir");
	fngotoxy(82, 10);
	Tecla = getch();
	fngotoxy(0, 26);
	switch(Tecla){
		case 32: fnTop5();  break;
		case 13:
		{
			fnnombre();
			fnjugar();
			break;
		}
	}
	return;
}

void fnnombre(){
	system ("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	fngotoxy(43,12);
	printf("Ingrese su nombre de jugador:");
	fngotoxy(55, 14);
	while(i<10){
		nombre[i] = getch();
		if (nombre[i]== 13) {
			i = 11;
		}
		else {
			printf("%c", nombre[i]);
			i++;
		}
	}
	i=3;
	fngotoxy(52, 16);
	printf("Empieza en: ");
	for (i; i>0; i--){
		fngotoxy(66,16);
		printf("%d", i);
		printf("%c", 7); // Sonido de Campana
		sleep(1);
	}
	i=0;
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

int fnalien(int C, int a, int b, int p, int y){
  FnSetColor(0,c);
  for (p; p>((d)-3); p--){
    x = ci + p;
    A[y][x] = b;
    fngotoxy(x,y);
    printf("%c", A[y][x]);
    A[y-1][x] = a;
    fngotoxy (x, (y-1));
    printf("%c", A[y-1][x]);
  }
  return x;
}

void fnaliens(){
    for(m=2; m<9; m+=3){
    	y = Fi + m;
    do{
      x = ci + d;
      p = d;
      fnalien(c=2, a, b, p, y);
      n++;
      d += 5;
    }
    while (n<18);
    n = 0;
    d=0;
	}
  return;
}

void fnfilasaliens(){
	for (m=2; m<9; m+=3){
		a=219;
		b=31;
		fnaliens();
		d=0;
	}
	return;
}

void fnarraygeneral(){
	v = 0;
	for (y=0; y<(TOPEY-1); y++){
		for (x=0; x<(TOPEX-3); x++){
			if (A[y][x]> v){
					v = A[y][x];
			}
		}
	}
	if (v==0){
		Tecla = 27;
	}
	return;
}

void fninteracciones(){

	while (!kbhit()){
		while(minutos< 60){
			while (segundos < 60 ) {
						fngotoxy(110,1);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
				printf("%d : %d", minutos, segundos);
				Sleep(500);
				segundos++;
				getch();
			}
			 minutos++;
		}
	}

while ( kbhit() ) {
	while(Tecla != 27){
		Tecla = getch();
		if(Tecla == 0) Tecla = getch();
		else{
			switch(Tecla) {
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
									if (A[Jiy-t][Jix+4+n]!= 0 ){
										c=1;
										fnborraalien();
										fnarraygeneral();
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
			}
		}
}

	return;
}


void fnscore(){
	FnSetColor(0, W);
	fngotoxy((Ci+15), (Fi-1));
	printf("Score: ");
	printf("%d", Score);
	return;
}

void fnborraalien(){
	if (A[Jiy-t][(Jix+4+n)-1] == 0){
		c = 1; d = (Jix+4+n); p = d; ci = 2;
		fnalien((c = c-1), a=219, b=31, p, (Jiy-t));
		if (c==0){
			fnalien((c = c-1), a=0, b=0, p, (Jiy-t));
		}
		t=22;
		Tecla = 0;
		Score +=100;
		fnscore();
	}
	else if (A[Jiy-t][(Jix+4+n)+1] == 0){
		c = 1; d = (Jix+2+n); p = d; ci = 2;
		fnalien((c = c-1), a=219, b=31, p, (Jiy-t));
		if (c==0){
			fnalien((c = c-1), a=0, b=0, p, (Jiy-t));
		}
		t=22;
		Tecla = 0;
		Score += 100;
		fnscore();
    }
    else if ((A[Jiy-t][(Jix+4+n)+1] != 0) && (A[Jiy-t][(Jix+4+n)-1] != 0)){
    	c = 1; d = (Jix+3+n); p = d; ci = 2;
		fnalien((c = c-1), a=219, b=31, p, (Jiy-t));
		if (c==0){
			fnalien((c = c-1), a=0, b=0, p, (Jiy-t));
		}
		t=22;
		Tecla = 0;
		Score += 100;
		fnscore();
	}
	return;
}


void fnjugar(){
	system("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	fngotoxy(Ci, (Fi-1));
	for (i; i<10; i++){
		printf("%c", nombre[i]);
	}
	fngotoxy(0,27);
	fnscore();
	fnfilasaliens();
	fnaliens();
	fnjugador(Jix, Jfx, Jiy, Jfy, n, c=5);
	fninteracciones();
	fngotoxy(0, 27);
	FnSetColor(0, W);
	return;
}
void fnTop5(){
	system ("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	fngotoxy(50,9);
	printf("Top 5 Jugadores:");
	for (i; i<5; i++){
		fngotoxy(50, (10+i));
		printf("%5c %5d", jugadores[i], score[i]);
	}
	i=0;
	fngotoxy(39, 18); printf("Presione ESC para regresar al INICIO");
	fngotoxy(66, 9);
	Tecla = getch();
	while (Tecla != 27){
		Tecla = getch();
	}
	fnintro();

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
