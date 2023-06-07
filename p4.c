/*
    Pentru nr de inmatriculare formatul este B01RAR
    Pentru capacitatea motorului formatul este 19 - reprezentand 1.9TDI in acest caz
    Am incercat sa schimb variabila intr-un string & am incercat si scanf si gets
    pentru a putea citi formatul cum ar trebui insa nu am reusit.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REG_LEN 20

typedef struct {
  char nr_inmatriculare[MAX_REG_LEN];
  char producator[MAX_REG_LEN];
  char culoare[MAX_REG_LEN];
  int nr_locuri;
  char carburant[MAX_REG_LEN];
  int capacitate_motor;
  char vin[MAX_REG_LEN];
  int vechime;
  int nr_kilometri;
} Car;


// Registru functii
void creaza_fisier();
void listeaza_date_fisier();
void creaza_masina();
void modifica_vechime_kilometrii();

int main() {
  int optiune;

  printf("Meniu:\n");
  printf("1. Creaza un fisier si introdu date\n");
  printf("2. Listeaza continutul fisierului\n");
  printf("3. Adauga o noua masina\n");
  printf("4. Modifica vechimea si numarul de kilometrii ai unui vehicul\n");
  printf("Introdu o optiune: ");
  scanf("%d", &optiune);

  switch (optiune) {
    case 1:
      creaza_fisier();
      break;
    case 2:
      listeaza_date_fisier();
      break;
    case 3:
      creaza_masina();
      break;
    case 4:
      modifica_vechime_kilometrii();
      break;
    default:
      printf("Optiune invalida, introdu o optiune valida.\n");
      break;
  }
  main();
  return 0;
}

// Functie pentru crearea masinilor
void creaza_fisier() {
  Car car;
  FILE *fp;

  fp = fopen("masini.bin", "wb");
  if (fp == NULL) {
    printf("S-a produs o eroare la deschiderea fisierului, incercati sa resetati programul.\n");
    return;
  }

  printf("Introdu datele pentru fiecare masina sau -1 pentru a termina inregistrarea:\n");
  printf("Introdu numarul de inmatriculare legat sau -1: ");
  scanf("%s", car.nr_inmatriculare);
  while (strcmp(car.nr_inmatriculare, "-1") != 0) {
    printf("Introdu producator: ");
    scanf("%s", car.producator);
    printf("Introdu culoare: ");
    scanf("%s", car.culoare);
    printf("Introdu numarul de locuri: ");
    scanf("%d", &car.nr_locuri);
    printf("Introdu tipul de carburant: ");
    scanf("%s", car.carburant);
    printf("Introdu capacitatea motorului legat: ");
    scanf("%d", &car.capacitate_motor);
    printf("Introdu numarul VIN: ");
    scanf("%s", car.vin);
    printf("Introdu vechimea masinii in ani: ");
    scanf("%d", &car.vechime);
    printf("Introdu numarul de kilometri: ");
    scanf("%d", &car.nr_kilometri);

    fwrite(&car, sizeof(Car), 1, fp);

    printf("Introdu numarul de inmatriculare legat sau -1: ");
    scanf("%s", car.nr_inmatriculare);
    }

    fclose(fp);
}

void listeaza_date_fisier() {
    Car car;
    FILE *fp;

    fp = fopen("masini.bin", "rb");
    if (fp == NULL) {
        printf("S-a produs o eroare la deschiderea fisierului, incercati sa resetati programul.\n");
    return;
}


    printf("\nDatele masinilor introduse in fisier:\n");
    while (fread(&car, sizeof(Car), 1, fp) == 1) {
    printf("---------------------------\n");
    printf("Numar de inmatriculare: %s\n", car.nr_inmatriculare);
    printf("producator: %s\n", car.producator);
    printf("culoare: %s\n", car.culoare);
    printf("Numar de locuri: %d\n", car.nr_locuri);
    printf("Tip carburant: %s\n", car.carburant);
    printf("capacitatea motorului: %d\n", car.capacitate_motor);
    printf("VIN: %s\n", car.vin);
    printf("vechime in ani: %d\n", car.vechime);
    printf("Numarul de kilometrii: %d\n", car.nr_kilometri);
    printf("---------------------------\n\n");
    }

    fclose(fp);
}


void creaza_masina() {
    Car car;
    FILE *fp;
    /*char nr_inmatriculare[MAX_REG_LEN];
    int masina_gasita = 0; */

    fp = fopen("masini.bin", "ab");
    if (fp == NULL) {
    printf("S-a produs o eroare la deschiderea fisierului, incercati sa resetati programul.\n");
    return;
    }


    printf("Introdu datele pentru fiecare masina sau -1 pentru a termina inregistrarea:\n");
    printf("Introdu numarul de inmatriculare legat sau -1: ");
    scanf("%s", car.nr_inmatriculare);
    /*while (fread(&car, sizeof(Car), 1, fp) == 1) {
        if (strcmp(car.nr_inmatriculare, nr_inmatriculare) == 0) {
            masina_gasita = 1;
            printf("\nNumarul de inmatriculare exista in baza de date\n");
        }
    }
    printf("Introdu datele pentru fiecare masina sau -1 pentru a termina inregistrarea:\n");
    printf("Introdu numarul de inmatriculare legat sau -1: ");
    scanf("%s", car.nr_inmatriculare);*/
    while (strcmp(car.nr_inmatriculare, "-1") != 0) {
        printf("Introdu producator: ");
        scanf("%s", car.producator);
        printf("Introdu culoare: ");
        scanf("%s", car.culoare);
        printf("Introdu numarul de locuri: ");
        scanf("%d", &car.nr_locuri);
        printf("Introdu tipul de carburant: ");
        scanf("%s", car.carburant);
        printf("Introdu capacitatea motorului legat: ");
        scanf("%d", &car.capacitate_motor);
        printf("Introdu numarul VIN: ");
        scanf("%s", car.vin);
        printf("Introdu anul de fabricatie: ");
        scanf("%d", &car.vechime);
        printf("Introdu numarul de kilometri: ");
        scanf("%d", &car.nr_kilometri);
    }

    fwrite(&car, sizeof(Car), 1, fp);

    fclose(fp);
}

void modifica_vechime_kilometrii() {
    Car car;
    char nr_inmatriculare[MAX_REG_LEN];
    FILE *fp;
    int masina_gasita = 0;

    fp = fopen("masini.bin", "rb+");
    if (fp == NULL) {
    printf("S-a produs o eroare la deschiderea fisierului, incercati sa resetati programul.\n");
    return;
}

    printf("Introdu numarul de inmatriculare al vehicului pe care vrei sa il modific: ");
    scanf("%s", nr_inmatriculare);

    while (fread(&car, sizeof(Car), 1, fp) == 1) {
        if (strcmp(car.nr_inmatriculare, nr_inmatriculare) == 0) {
            masina_gasita = 1;
            break;
        }
    }

    if (masina_gasita) {
        printf("Introdu noua vechime: ");
        scanf("%d", &car.vechime);
        printf("Introdu noul numar de kilometrii: ");
        scanf("%d", &car.nr_kilometri);

        fseek(fp, -sizeof(Car), SEEK_CUR);

        fwrite(&car, sizeof(Car), 1, fp);
    } else {
        printf("Masina cu numarul de inmatriculare %s nu a fost gasita\n", nr_inmatriculare);
    }

    fclose(fp);
}
