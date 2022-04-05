#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define  TOPEY     26
#define  TOPEX     112
#define  Ci        3
#define  Fi        1

int  BG   = 0;
int  W    = 15;
int  New_Color;
int  A[TOPEY][TOPEX];
int  x;
int  y;
int  p = 2;

void fnarraygeneral  ();
void fngotoxy        (int x, int y);
void fnimprimemarco  (int fi, int ci, int ff, int cf);
void FnSetColor      (int, int);

void main(){
	fnarraygeneral();
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	return;
}

void fnarraygeneral(){
	system("cls");
	for (y=0; y<(TOPEY-1); y++){
		fngotoxy(4,p);
		p++;
		for (x=0; x<(TOPEX-3); x++){
			A[y][x]= 0;
			printf("%c",A[y][x]);
		}
		printf("\n");
	}
	return;
}

void fnimprimemarco(int fi, int ci, int ff, int cf){
	FnSetColor (0, 9);
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
