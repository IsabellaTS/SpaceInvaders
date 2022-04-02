#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define  TOPEY     26
#define  TOPEX     115
#define  Ci        3
#define  Fi        1


void fngotoxy(int x, int y);
void fnpantallasize();
void fnimprimemarco(int fi, int ci, int ff, int cf);

void main(){
	//fnpantallasize();
	fnimprimemarco(Fi, Ci, TOPEY, TOPEX);
	return;
}

void fnimprimemarco(int fi, int ci, int ff, int cf){
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

void fnpantallasize(){
    HANDLE wHnd;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 50, 15};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    return ;
}
