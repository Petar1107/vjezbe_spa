#define _CRT_SECURE_NO_WARNINGS
#include "vjezba02.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE* f = NULL;
    FILE* f1 = NULL;
    FILE* f2 = NULL;
    FILE* f3 = NULL;
    FILE* f4 = NULL;
    FILE* f5 = NULL;
    objekt3D* objekt;
    objekt3D* objekt1;
    int brojac;
    objekt = read_binary(f);
    pise_u_binarnu(f1, objekt);
    pise_u_tekstualnu(f2, objekt);
    delete_objekt(objekt);
    objekt1=cita_tekstualnu(f3, f4, &brojac);
    pise_tekst_u_tekstualnu(f5, objekt1, brojac);
    delete_objekt(objekt1);
    return 0;

}
