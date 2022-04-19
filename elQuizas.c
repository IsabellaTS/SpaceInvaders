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
int  pts[5];
char jugadores[5]={'-','-','-','-','-'};
int  New_Color;
char Tecla;              //Movimiento
int  i;                  //Indice del array del nombre
char nombre[10];
int Score;
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
int z; // para el manejo del file
int op; // para el manejo del file

//estructura para el file de los puntos
typedef struct top{
    int puntos;
}top;

void fnarraygeneral    	();
void FnSetColor        	(int, int);
void fngotoxy          	(int x, int y);
void fnimprimemarco    	(int fi, int ci, int ff, int cf);
void fnjugador         	(int JIx, int JFx, int JIy, int JFy, int N, int C);
void fninteracciones   	();
void fnaliens          	();
void fnalien           (int x, int y);
void fnborraalien       ();
void fnscore            ();
void fnmovimientoaliens ();
void fnconteoarray      ();
void gameover           ();
void resto              ();
void printArray         ();
void sorting            ();
void comparar           ();
void save               ();
void topScores          ();

void primeraVez         ();

void main(){
  fnjugador(Jix, Jfx, Jiy, Jfy, n, c=3);
  fnmovimientoaliens();
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

        gameover();
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

void gameover(){
  system("cls");
  fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
  fngotoxy(57,5);
  printf("GAME OVER\n");
  sleep(2);

  fngotoxy(54,7);
  printf("Final Score: %d", Score);

  topScores();
    sleep(3);
 exit(1);

  return;
}

void topScores(){

  top *s ;
  top sl;
  FILE *fp;
  z = 0;
  op = 1;

        fngotoxy(55,10);
      printf("TOP 5 SCORES ");

  fp = fopen("fileStruct.txt", "r");
    if (fp==NULL){
      primeraVez();}

    else{
      resto();}

  fclose(fp);
  return;
}

void primeraVez(){
  top *s ;
  top sl;
  FILE *fp;
  z = 0;
  op = 1;
  s = (top*) calloc(op,sizeof(top));

  //abrir doc en formato de escritura
  fp = fopen("fileStruct.txt", "w");

      fflush(stdin);
      s[z].puntos = Score;
      fwrite(&s[z], sizeof(top),1,fp);
 fclose(fp);
 // cerrar doc en formato de escritura

  //abrir doc en formato de lectura
  fp = fopen("fileStruct.txt", "r");
    while(fread(&sl,sizeof(top),1,fp)){
        pts[4]=sl.puntos;
        }
  fclose(fp);
  //cerrar doc en formato de lectura

  printArray();
  return;
}

void resto(){
  top *s ;
  top sl;
  FILE *fp;
  z = 0;
  op = 1;
//Leer documento y guardar en un array temporal
  fp = fopen("fileStruct.txt", "r");
  while(fread(&sl,sizeof(top),1,fp)){
      pts[z]=sl.puntos;
        z++;
      }

  fclose(fp);

      sorting(); // comprobado que funciona bien y no retorna error
      comparar(); // funcion comparar tiene el error :(
      printArray();
      save();
      return;
}


void sorting(){
  int step;
          for (step = 0; step < 5; step++) {
            for (z = 0; z < 5 - step; ++z) {
              if (pts[z] > pts[z + 1]) {
                int temp = pts[z];
                pts[z] = pts[z + 1];
                pts[z + 1] = temp;
              }
            }
          }
  return;
}

void comparar(){
        if(Score > pts[0]){
          pts[0]  = Score;
          int stopper = 0;

            for( z=0 ; (z < 5) && (stopper == 0); z++){
                  if(pts[z] > pts[z+1]){
                    int temp3 = pts[z+1];
                    pts[z+1] = pts[z];
                    pts[z] = temp3;
                  }

                  else {
                    stopper = 1;
                  }
            }
        }
    return;
}

void save(){
  top *s ;
  FILE *fp;
  op = 1;
  s = (top*) calloc(op,sizeof(top));
  fp = fopen("fileStruct.txt", "w");

   for (z = 0; z < 5; z++) {
      fflush(stdin);
      s[z].puntos = pts[z];
      fwrite(&s[z], sizeof(top),1,fp);
      }
  fclose(fp);
  return;
}

void printArray(){
  z = 4;
  int j;
      for (j = 1; j < 6; j++) {
        fngotoxy(58,(9+(j+3)));
        printf("%d.   %d", j, pts[z]);
        z--;
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
								gameover();
						       	}
                    break;
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
		gameover();
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
