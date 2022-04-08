#include <stdio.h>

typedef struct student{
  int rno;
  char name [20];
  struct subject{
    int scode;
    char sname[20];
    int mark;
  }sub[3];
  int total;
  float per;
}student;

void create(){
  student *s;
  FILE*fp;
  int n,i,j;
  printf("Enter how many students you want: ");
  scanf("%d",&n);

  s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt","w");

  for (i = 0; i < n; i++) {
    s[i].total=0;
    s[i].per=0;
    printf("Enter RollNo: ");
    scanf("%d",&s[i]);
    fflush(stdin);
    printf("Enter Name : ");
    scanf("%[^\n]s",s[i].name );
    for (j=0 ; j<3 ; j++){
      printf("Enter Marks of subject %d : ", j+1);
      scanf("%d",&s[i].sub[j].mark);
      s[i].total += s[i].sub[j].mark;

    }
    s[i].per = s[i].total / 3.0;
    fwrite(&s[i], sizeof(student),1,fp);
  }
fclose(fp);
}

void display(){
  student sl;
  FILE *fp;
  int i;
  int j;
  fp = fopen("mystudents.txt","r");
  while (fread(&sl, sizeof(student),1,fp)) {

    printf("\n%-5d%-20s", sl.rno,sl.name);
    for (j = 0; j < 3; j++) {
      printf("%4d", sl.sub[j].mark);
    }
    printf("%5d%7.2f",sl.total,sl.per);
  }
fclose(fp);

}

void append(){
  student *s;
  FILE*fp;
  int n,i,j;
  printf("Enter how many students you want: ");
  scanf("%d",&n);

  s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt","a");

  for (i = 0; i < n; i++) {
    s[i].total=0;
    s[i].per=0;
    printf("Enter RollNo: ");
    scanf("%d",&s[i]);
    fflush(stdin);
    printf("Enter Name : ");
    scanf("%[^\n]s",s[i].name );
    for (j=0 ; j<3 ; j++){
      printf("Enter Marks of subject %d : ", j+1);
      scanf("%d",&s[i].sub[j].mark);
      s[i].total += s[i].sub[j].mark;

    }
    s[i].per = s[i].total / 3.0;
    fwrite(&s[i], sizeof(student),1,fp);
  }
fclose(fp);
}

void noofrec(){
  student sl;
  FILE *fp;
  fp = fopen("mystudents.txt","r");
  fseek(fp, 0 , SEEK_END);
  int n = ftell(fp)/sizeof(student);
  printf("\n\n NO OF RECORDS = %d",n);
  fclose(fp);

}
void search(){
  student sl;
  FILE *fp;
  int j, rno, found=0;
  fp = fopen("mystudents.txt","r");
  printf("Enter rollno to Search: ");
  scanf("%d",&rno);

  while (fread(&sl, sizeof(student),1,fp)) {

    if(sl.rno == rno){
      found=1;
      printf("\n%-5d%-20s", sl.rno,sl.name);
      for (j = 0; j < 3; j++) {
        printf("%4d", sl.sub[j].mark);
      }
      printf("%5d%7.2f",sl.total,sl.per);
    }
  }
if(!found) {
  printf("\nRecord not found\n");
}

fclose(fp);
}

void delete(){
  student sl;
  FILE *fp, *fpl;
  int j,rno, found=0;
  fp = fopen("mystudents.txt","r");
  fpl = fopen("temp.txt","w");
  printf("Enter rollno to delete: ");
  scanf("%d",&rno);
  while (fread(&sl, sizeof(student),1,fp)) {

    if(sl.rno == rno){
      found = 1;
    }
    else {
      fwrite(&sl,sizeof(student),1,fpl);
    }
  }
  fclose(fp);
  fclose(fpl);
  if (found){
    fpl = fopen ("temp.txt","r");
    fp = fopen("mystudents.txt","w");

    while(fread(&sl,sizeof(student),1,fpl)){
      fwrite(&sl,sizeof(student),1,fp);
    }
    fclose(fp);
    fclose(fpl);
  }
}
void sortScreen(){}
void sortFile(){}

int main() {
  int ch;

  do {
    printf("\n1. CREATE");
    printf("\n2. DISPLAY");
    printf("\n3. APPEND");
    printf("\n4. NO OF RECORDS");
    printf("\n5. SEARCH");
    printf("\n7. DELETE");
    printf("\n8. SORT BY TOTAL");
    printf("\n9. SORT BY TOTAL FILE");
    printf("\n0. EXIT");

    printf("\n Enter your choice: ");
    scanf("%d",&ch);

    switch (ch) {
      case 1:
        create();
      break;
      case 2:
        display();
      break;
      case 3:
        append();
      break;
      case 4:
        noofrec();
      break;
      case 5:
        search();
      break;
      case 7:
        delete();
      break;
      case 8:
        sortScreen();
      break;
      case 9:
        sortFile();
      break;
    }
  } while(ch!=0);

  return 0;
}
