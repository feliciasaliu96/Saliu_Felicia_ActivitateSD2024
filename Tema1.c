#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char* firma;
    float diagonala;
    float* preturi;
    int nrMagazine;
} Smartphone;

Smartphone citireSmartphone() {
    Smartphone s;
    char buffer[100];

    printf("ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Firma: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
    s.firma = (char*)malloc(strlen(buffer) + 1);
    strcpy(s.firma, buffer);

    printf("Diagonala (inch): ");
    scanf("%f", &s.diagonala);

    printf("Numar magazine: ");
    scanf("%d", &s.nrMagazine);

    s.preturi = (float*)malloc(s.nrMagazine * sizeof(float));
    for (int i = 0; i < s.nrMagazine; i++) {
        printf("Pret in magazinul %d: ", i + 1);
        scanf("%f", &s.preturi[i]);
    }

    return s;
}

float calculeazaMediePreturi(Smartphone s) {
    float suma = 0;
    for (int i = 0; i < s.nrMagazine; i++) {
        suma += s.preturi[i];
    }
    return (s.nrMagazine > 0) ? suma / s.nrMagazine : 0;
}

void modificaDiagonala(Smartphone* s, float nouaDiagonala) {
    s->diagonala = nouaDiagonala;
}

void afisareSmartphone(Smartphone s) {
    printf("\n--- Detalii Smartphone ---\n");
    printf("ID: %d\n", s.id);
    printf("Firma: %s\n", s.firma);
    printf("Diagonala: %.2f inch\n", s.diagonala);
    printf("Preturi in %d magazine:\n", s.nrMagazine);
    for (int i = 0; i < s.nrMagazine; i++) {
        printf("  Magazin %d: %.2f lei\n", i + 1, s.preturi[i]);
    }
    printf("Media preturilor: %.2f lei\n", calculeazaMediePreturi(s));
}

void elibereazaMemorie(Smartphone* s) {
    free(s->firma);
    free(s->preturi);
}

int main() {
    Smartphone s = citireSmartphone();
    afisareSmartphone(s);

    float nouaDiagonala;
    printf("\nNoua diagonala: ");
    scanf("%f", &nouaDiagonala);
    modificaDiagonala(&s, nouaDiagonala);

    printf("\nDupa modificare:\n");
    afisareSmartphone(s);

    elibereazaMemorie(&s);
    return 0;
}
