#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Masina {
    int id;
    char* marca;
    float pret;
    int anFabricatie;
};
 
struct Masina initializare(int id, const char* marca, float pret, int anFabricatie) {
    struct Masina m;
    m.id = id;
    m.marca = (char*)malloc(sizeof(char)*strlen(marca) + 1);
    strcpy(m.marca, marca);
    m.pret = pret;
    m.anFabricatie = anFabricatie;
    return m;
}
void afisare(struct Masina m) {
    if (m.marca != NULL)
        printf("Masina %d: %s, Pret: %.2f, An: %d\n", m.id, m.marca, m.pret, m.anFabricatie);
    else
        printf("Masina %d: [marca dezalocata], Pret: %.2f, An: %d\n", m.id, m.pret, m.anFabricatie);
}

void dezalocare(struct Masina* m) {
    if (m->marca != NULL) {
        free(m->marca);
        m->marca = NULL;
    }
}
int main() {

    struct Masina m = initializare(1, "Ford", 30000, 2020);
    afisare(m);
   const int nrMasini = 5;
   struct Masina* masini;
   masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);
   masini[0] = initializare(1, "Dacia", 15000, 2018);
   masini[1] = initializare(2, "BMW", 30000, 2020);
   masini[2] = initializare(3, "Ford", 18000, 2017);
   masini[3] = initializare(4, "Toyota", 19000, 2014);
   masini[4] = initializare(5, "VW", 17000, 2019);
   printf("Toate Masinile \n");
   for (int i = 0; i < nrMasini; i++) {
       afisare(masini[i]);
   }
  
    return 0;
}
