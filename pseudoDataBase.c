#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>


int main() {

/*  struct top
  {
  char name[10];
};*/
     int punt;

      FILE *fptr;
      int i;
    struct{int punt1[5];}

            fptr = fopen("records3.txt","w");
            for(i = 0; i < 5; ++i)
            {
                printf("Enter score: ");
                scanf("%d", &punt1[i].punt);
                fwrite(punt1,sizeof(punt1),1,fptr);
            }
          //  fwrite(punt1, sizeof(punt1), 1, fptr);
            fclose(fptr);


      fptr = fopen("records3.txt", "r");

        fread(punt1, sizeof(punt1), 1, fptr);
        for(i = 0; i < 5; ++i)
        {
            printf("\nPuntos: %d", punt1[i].punt);
        }
        fclose(fptr);



        return 0;
  }
