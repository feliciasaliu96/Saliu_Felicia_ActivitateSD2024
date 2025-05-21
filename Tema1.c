#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Fisier {
    int id;
    char* nume;
    int dimensiune;
    bool esteDeschis;
};

struct Fisier initializare(int id, const char* nume, int dimensiune, bool esteDeschis) {
    struct Fisier f;
    f.id = id;
    f.nume = (char*)malloc(strlen(nume) + 1);
    strcpy(f.nume, nume);
    f.dimensiune = dimensiune;
    f.esteDeschis = esteDeschis;
    return f;
}
void afisare(struct Fisier f) {

    if(f.nume!=NULL)
    printf("%d Fisierul %s cu dimensiunea %d esteDeschis %d\n", f.id, f.nume, f.dimensiune, f.esteDeschis);
    else
        printf("%d Fisierul [DEZALOCAT] cu dimensiunea %d esteDeschis %d\n", f.id, f.dimensiune, f.esteDeschis);
}
void modificaDimensiune(struct Fisier* f, int dimensiuneNoua) {

    if (dimensiuneNoua > 0)
        f->dimensiune = dimensiuneNoua;
}
void dezalocare(struct Fisier* f) {
    if (f->nume != NULL)
        free(f->nume);
    f->nume = NULL;
}
int main() {
    struct Fisier f = initializare(1, "tema", 34, true);
    afisare(f);
    modificaDimensiune(&f, 50);
    afisare(f);
    dezalocare(&f);
    afisare(f);
    return 0;
}
