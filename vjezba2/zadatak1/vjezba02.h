#define _CRT_SECURE_NO_WARNINGS
#ifndef VJEZBA02_H
#define VJEZBA02_H
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float Vx;
    float Vy;
    float Vz;
}vrh;
typedef struct
{
    float Ni;
    float Nj;
    float Nk;
    vrh niz_vrhova[3];
    int boja_trokuta;

}trokut;
typedef struct
{
    trokut* niz_trokuta;
    unsigned int broj_trokuta;
}objekt3D;

//funkcije

objekt3D* read_binary(FILE* f);
objekt3D* cita_tekstualnu(FILE* f, FILE* f1, int* br1);
void pise_u_binarnu(FILE* f, objekt3D* objekt);
void pise_u_tekstualnu(FILE* f, objekt3D* objekt);
void delete_objekt(objekt3D* objekt);
void pise_tekst_u_tekstualnu(FILE* f, objekt3D* objekt, int brojac);
#endif // !VJEZBA02_H
