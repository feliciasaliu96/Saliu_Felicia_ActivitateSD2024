#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    struct Masina {

    int id;
    char* marca;
    float pret;
    int anFabricatie;
};

struct Masina initializare(int id, const char* marca, float pret, int anFabricatie) {

    struct Masina m;
    m.id = id;
    m.marca = (char*)malloc(sizeof(char) * (strlen(marca) + 1));
    strcpy(m.marca, marca);
    m.pret = pret;
    m.anFabricatie = anFabricatie;
    return m;
}

void afisare(struct Masina m) {

    if (m.marca != NULL)
        printf("Id: %d Masina marca: %s cu pretul %5.2f si an fabricatie %d\n", m.id, m.marca, m.pret, m.anFabricatie);
    else
        printf("Memorie dezalocata\n");
}

void modificarePret(struct Masina* m, float pretNou) {

    if (pretNou > 0)
        m->pret = pretNou;
}

//afisare vector
void afisareVector(struct Masina* vector, int nrElemente) {

    for (int i = 0; i < nrElemente; i++) {
        afisare(vector[i]);
    }
}
//vector care copiaza in alt vector n elemente
struct Masina* copiazaVector(struct Masina* vector, int nrElemente, int nrCopiate) {
    struct Masina* vectorNou = NULL;
    vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * nrCopiate);
    for (int i = 0; i < nrCopiate; i++) {
        vectorNou[i] = vector[i];
        vectorNou[i].marca = (char*)malloc(strlen(vector[i].marca) + 1);
        strcpy(vectorNou[i].marca, vector[i].marca);
    }

    return vectorNou;
}

void dezalocare(struct Masina* m) {

    if (m->marca != NULL)
        free(m->marca);
    m->marca = NULL;
}

void copiazaAnumiteMasini(struct Masina* vector, int nrElemente, float pretMinim, struct Masina** vectorNou, int* dimensiune) {

    *dimensiune = 0;
    for (int i = 0; i < nrElemente; i++) {

        if (vector[i].pret >= pretMinim) {
            (*dimensiune)++;
        }
    }
    if ((*vectorNou) != NULL) {
        free((*vectorNou));
    }
    *vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * (*dimensiune));
    int k = 0;
    for (int i = 0; i < nrElemente; i++) {
        if (vector[i].pret >= pretMinim) {
            (*vectorNou)[k] = vector[i];
            (*vectorNou)[k].marca = (char*)malloc(strlen(vector[i].marca) + 1);
            strcpy((*vectorNou)[k].marca, vector[i].marca);
            k++;
        }
    }
}

struct Masina getPrimaMasinabyMarca(struct Masina* vector, int nrElemente, const char* marca) {
    struct Masina m;
    m.marca = NULL;
    for (int i = 0; i < nrElemente; i++) {

        if (strcmp(vector[i].marca, marca) == 0) {
            m = vector[i];
            m.marca = (char*)malloc(strlen(vector[i].marca) + 1);
            strcpy(m.marca, vector[i].marca);
            return m;
        }
    }
    return m;
}
//dezalocare vector

void dezalocareVector(struct Masina** vector, int* nrElemente) {
    for (int i = 0; i < (*nrElemente); i++) {
        if ((*vector) != NULL) {
            free((*vector)[i].marca);
        }
    }
    free(*vector);
    *vector = NULL;
    *nrElemente = 0;
}

int main() {

    struct Masina m;
    m = initializare(1, "Ford", 30000.54, 2020);
    afisare(m);
    modificarePret(&m, 2000.50);
    afisare(m);
    dezalocare(&m);
    afisare(m);

    //declar vector
    struct Masina* masini = NULL;
    int nrMasini = 3;
    //aloc memorie pentru vector
    masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);
    masini[0] = initializare(2, "Volvo", 20000, 2015);
    masini[1] = initializare(3, "BMW", 40000, 2024);
    masini[2] = initializare(4, "Dacia", 25000, 2018);
    afisareVector(masini, nrMasini);

    //copiazaVector
    struct Masina* masiniPrimele = NULL;
    int nrMasiniPrimele = 2;
    masiniPrimele = copiazaVector(masini, nrMasini, nrMasiniPrimele);
    printf("Primele masini sunt: \n");
    afisareVector(masiniPrimele, nrMasiniPrimele);


    //dezalocareVector
    dezalocareVector(&masiniPrimele, &nrMasiniPrimele);
    afisareVector(masiniPrimele, nrMasiniPrimele);

    struct Masina* masiniScumpe = NULL;
    int nrMasiniScumpe = 0;
    copiazaAnumiteMasini(masini, nrMasini, 25000, &masiniScumpe, &nrMasiniScumpe);
    printf("Masini scumpe:\n");
    afisareVector(masiniScumpe, nrMasiniScumpe);
    dezalocareVector(&masiniScumpe, &nrMasiniScumpe);


    struct Masina masina = getPrimaMasinabyMarca(masini, nrMasini, "BMW");
    printf("Masina gasita:\n");
    afisare(masina);
    if (masina.marca != NULL) {

        free(masina.marca);
        masina.marca = NULL;
    }

    dezalocareVector(&masini, &nrMasini);
    return 0;
}