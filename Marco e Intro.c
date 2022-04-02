#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define  TOPEY     26
#define  TOPEX     115
#define  Ci        3
#define  Fi        2

int  BG   = 0;
int  W    = 15;
int  Line = 9;
int  score[5];
char jugadores[5]={'a','b','c','d','e'};
int  New_Color;
char Tecla;
int  i;
char nombre[10];
long long int Score;


void FnSetColor        (int, int);
void fngotoxy          (int x, int y);
void fnimprimemarco    (int fi, int ci, int ff, int cf);
void fnintro           ();
void fnTop5            ();
void fnnombre          ();
void fnjugar           ();

void main(){
	//fnpantallasize();
	fnintro();
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
	fngotoxy(41,15);
	printf("Presione cualquier tecla para salir");
	fngotoxy(82, 10);
	Tecla = getch();
	fngotoxy(0, 26);
	switch(Tecla){
		case 32: fnTop5();  break;
		case 13: fnnombre(); break;
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
		if (nombre[i]== 13) i = 11;
		else {
			printf("%c", nombre[i]);
			i++;
		}
	}
	i=0;
	fnjugar();
	return;
}

void fnjugar(){
	system("cls");
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	fngotoxy(Ci, (Fi-1));
	for (i; i<10; i++){
		printf("%c", nombre[i]);
	}
	fngotoxy((Ci+15), (Fi-1));
	printf("Score:");
	printf("%d", Score);
	fngotoxy(0,27);
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
