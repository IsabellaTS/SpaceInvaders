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
int  k;
int  q;

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
void fnalien           (int x, int y);
void fnborraalien       ();
void fnscore            ();
void fnmovimientoaliens ();
void fnconteoarray      ();


void main(){
  fnjugador(Jix, Jfx, Jiy, Jfy, n, c=3);
  fnmovimientoaliens();
  return;
}

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
		case 32: fnTop5; break;
		case 13:
		{
			fnnombre();
      fnjugar();
			break;
		}
    case 27: exit(1); break;
	}
	return;
}

void fnjuega(){

  return;
}

void fnjugar(){
	system("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	fngotoxy(Ci, (Fi-1));
	for (i; i<10; i++){
		printf("%c", nombre[i]);
	}
	fnscore();
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

void fnarraygeneral(){
	for (y=0; y<(TOPEY-1); y++){
		for (x=0; x<(TOPEX-3); x++){
			A[y][x]=0;
		}
	}
	return;
}

void fnalien(int x, int y){
  if (A[(y-1)][x] == 20){
      A[(y)][x] = 20;
    }
  else if (A[y][x] == 20){
    if ((y==Jiy)&&(x==(Jix+4+n))){
      FnSetColor(0,5);
      A[y][x]=219;
      fngotoxy(x, y);
      printf ("%c", A[y][x]);
    }
    else if ((y>Jiy)&&((Jix+n)<=(x))&&((Jfx+n)>(x))&&(y<=Jfy)){
      FnSetColor(0,5);
      A[y][x]=219;
      A[y+1][x] = 219;
      fngotoxy(x, y);
      printf ("%c", A[y][x]);
      fngotoxy(x, (y+1));
      printf("%c", A[y+1][x]);
    }
    else{
      A[y-1][x] = 0;
      q = 0;
      FnSetColor(0, q);
      fngotoxy(x, y);
      printf ("%c", A[y][x]);
    }
  }
  else{
    c = 2;
    FnSetColor(0, c);
    A[y][x]=a;
    fngotoxy(x, y);
    printf("%c", A[y][x]);
      }

  return;
}

void fnaliens(){
  int e;
  int m;
  for (m = 0; m<5; m++){
    y = fi + m;
    for (e=0; e<100; e++){
      x = ci + e;
      if ((y)>=TOPEY){
				a = 0;
        FnSetColor(0,3);
				fnalien(x, y);
				e += 3;
      }
     	else if (((y+1)==Jiy)&&((Jix+n)<(ci+e))&&(A[y][x]==232)&&((Jfx+n)>(ci+e))){
				fngotoxy(0, 27);
        exit(1);
    	}
      else{
          fnalien(x, y);
          e += 3;
      }
    }
    m += 1;
    e = 0;
  }
  return;
}

void fnmovimientoaliens(){
  while (1){
    if (!kbhit()){
      a = 0; c = 0;
      fnaliens();
      fi++;
      a = 232; c = 2;
      fnaliens();
      fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
			fnconteoarray();
      Sleep(1000);
    }
    else{
      fninteracciones();
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
									if (A[Jiy-t][Jix+4+n] == 232){
									fnborraalien();
                  fnscore();
									fngotoxy(0,27);
									printf("%d", v);
									}
									else{
                    if (A[Jiy-t][Jix+4+n] == 20){
                      FnSetColor(0,W);
                      A[Jiy-t][Jix+4+n] = 124;
  										fngotoxy((Jix+4+n),(Jiy-t));
  										printf("%c", A[Jiy-t][Jix+4+n]);
  										Sleep(1);
  										FnSetColor(0,0);
  										fngotoxy((Jix+4+n),(Jiy-t));
  										printf("%c", A[Jiy-t][Jix+4+n]);
  										A[Jiy-t][Jix+4+n] = 20;
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
								}
								break;
							}
							case 27: {
								fngotoxy(0,27);
								exit(1);
								break;
							}
			}
	return;
}
void fnconteoarray(){
	v = 0;
	for (y=0; y<(TOPEY); y++){
		for (x=0; x<(TOPEX); x++){
			if (A[y][x]==232){
					v = A[y][x];
			}
		}
	}
	if (v==0){
		exit(1);
	}
	return;
}


void fnborraalien(){
  x = (Jix+4+n); y = (Jiy-t);
  A[y][x] = 20;
  fnalien(x, y);
  Score += 100;
  t = 22;
  //sleep(1);
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
