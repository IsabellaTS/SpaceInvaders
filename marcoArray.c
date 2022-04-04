#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define  TOPEY     26
#define  TOPEX     115

int i, j;

//crear un array
char A [TOPEY] [TOPEX];
// end of crear array

void main(){

  for(i=0;i<(TOPEY+2);i++) {

      for(j=0;j<(TOPEX+2);j++){

        switch (i) {
          case 0:{
            switch (j) {

              case 0: {
               printf("%c", 218);
              }
              break;

              case (TOPEX + 1): {
               printf("%c\n", 191);
              }
              break;

              default: printf ("%c",196); break;
            }

          }
          break;

          case (TOPEY+1):{
            switch (j) {

              case 0: {
               printf("%c", 192);
              }
              break;

              case (TOPEX + 1): {
              printf("%c", 217);
              }
              break;

              default: {
                printf ("%c",196);
                break;
              }
            }

          }
          break;

            default:{
          switch (j) {

            case 0:{
            printf("%c", 179);
            }
            break;

            case (TOPEX + 1): {
            printf("%c\n", 179);
            }
            break;

            default: {
              printf (" ");
              break;
            }

          }
        }

      }
    }
  }

  return;
}
