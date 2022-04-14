#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


typedef struct top{
    int puntos;
}top;

int pts[5];
int tempPts;

void display	();
void nuevo ();
void sorting ();
void save ();
void comparar();
void primeraVez();
void printArray();
void resto ();

void main() {
  int ch;
  do {
    printf("\n\n1. DISPLAY TOP 5 SCORES");
    printf("\n2. NEW SCORE\n");
    printf("\n0. EXIT\n");

    printf("\n Enter your choice: "); scanf("%d",&ch);

    switch (ch) {
      case 1:
        display();
      break;
      case 2:
        nuevo();
      break;
    }
  } while(ch!=0);
return;
}


void nuevo(){
  top *s ;
  top sl;
  FILE *fp;
  int i=0;
  int n = 1;

  fp = fopen("fileStruct.txt", "r");
    if (fp==NULL){
      primeraVez();
    }

    else{
      resto();
    }

  fclose(fp);
  return;
}

void primeraVez(){
  top *s ;
  top sl;
  FILE *fp;
  int i=0;
  int n = 1;
  s = (top*) calloc(n,sizeof(top));
  fp = fopen("fileStruct.txt", "w");

      fflush(stdin);
      printf("Inserte los puntos: ");
      scanf("%d", &tempPts);
      s[i].puntos = tempPts;
      fwrite(&s[i], sizeof(top),1,fp);

  fclose(fp); // cerrar doc en formato de escritura

    fp = fopen("fileStruct.txt", "r");
    while(fread(&sl,sizeof(top),1,fp)){
        pts[4]=sl.puntos;
        }

  fclose(fp); //cerrar doc en formato de lectura

  printArray();
  return;
}

void resto(){
  top *s ;
  top sl;
  FILE *fp;
  int i = 0;
  int n = 1;

//Recibir nuevo score
    printf("\nInserte los puntos: ");
    scanf("%d", &tempPts);

//Leer documento y guardar en un array temporal
  fp = fopen("fileStruct.txt", "r");
  while(fread(&sl,sizeof(top),1,fp)){
      pts[i]=sl.puntos;
        i++;
      }

  fclose(fp);

// organizar array temporal, compara con el nuevo valor, imprimir top y guardarlo
      sorting(); // comprobado que funciona bien y no retorna error
      comparar();
      printArray();
      save();
      return;
}


// funcion display
void display(){
  top sl;
  FILE *fp;
  int i = 0;

    fp = fopen("fileStruct.txt", "r");
    if(fp == NULL){
      printf("\nNo hay ninguna puntuacion aun, juegue al menos una partida para activar esta seccion\n");
    }
    else{
      while(fread(&sl,sizeof(top),1,fp)){

        pts[i] = sl.puntos;
        i++;

      }
              sorting();
              printArray();

    }

fclose(fp);
return;
}

// funcion sorting
void sorting(){

int step;
int i;
        for (step = 0; step < 5; step++) {
          for (i = 0; i < 5 - step; ++i) {
            if (pts[i] > pts[i + 1]) {
              int temp = pts[i];
              pts[i] = pts[i + 1];
              pts[i + 1] = temp;

            }
          }
        }
        //prueba de que el sorting está bien
     /*   int j;
        for (j = 0 ; j < 5 ; j++){
        	printf("%d", pts[j]);
		}*/ 
}

//funcion comparar
void comparar(){
//tempPts
  if(tempPts <= pts[0]){
    printf("No entra al top");
  }

    else{
      pts[0]  = tempPts;
	int i;

        for( i=0 ; i<5; i++){

            if(pts[i] > pts[i+1]){
              int temp3 = pts[i+1];
              pts[i+1] = pts[i];
              pts[i] = temp3;

            }

        }
    }
    
       int j;
        for (j = 0 ; j < 5 ; j++){
        	printf("%d   ", pts[j]);
		}
}

//funcion save
void save(){
  top *s ;
  FILE *fp;
  int i;
  int n = 1;
  s = (top*) calloc(n,sizeof(top));
  fp = fopen("fileStruct.txt", "w");

   for (i = 0; i < 5; i++) {
      fflush(stdin);
      s[i].puntos = pts[i];
      fwrite(&s[i], sizeof(top),1,fp);
      }
  fclose(fp);
return;
}

void printArray(){
  int i = 4;
  int j;
      for (j = 1; j < 6; j++) {
        printf("\n%d.     %d\n", j, pts[i]);
        i--;
      }
  return;
}
