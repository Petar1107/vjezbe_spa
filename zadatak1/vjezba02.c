#define _CRT_SECURE_NO_WARNINGS
#include "vjezba02.h"
#include <stdio.h>
#include <stdlib.h>
//•Funkciju koja èita binarnu STL datoteku i vraæa ispunjenu Objekt3D  strukturu

objekt3D* read_binary(FILE* f)
{
    objekt3D* objekt;
    objekt = (objekt3D*)malloc(sizeof(objekt3D));
    f = fopen("primjerbin.stl", "rb");
    if (!f)
        return NULL;
    fseek(f, 80, SEEK_SET);
    fread(&(objekt->broj_trokuta), sizeof(int), 1, f);
    objekt->niz_trokuta = (trokut*)malloc(sizeof(trokut) * objekt->broj_trokuta);
    int i = 0;
    while (!feof(f))
    {
        fread(&(objekt->niz_trokuta[i]), 50, 1, f);
        i++;
    }
    fclose(f);
    return objekt;
}
//•	Funkciju koja Objekt3D strukturu zapisuje u binarnu STL datoteku

void pise_u_binarnu(FILE* f, objekt3D* objekt)
{
    int niz_nula_u_zaglavlju[20] = { 0 };
    f = fopen("IspisBinarna.stl", "wb");
    if (!f)
    {
        printf("datoteka se ne moze otvoriti!");
    }
    fwrite(niz_nula_u_zaglavlju, sizeof(niz_nula_u_zaglavlju[0]), 20, f);
    fwrite(&(objekt->broj_trokuta), sizeof(objekt->broj_trokuta), 1, f);
    for (int i = 0; i < objekt->broj_trokuta; i++)
    {
        fwrite(&(objekt->niz_trokuta[i]), 50, 1, f);
    }
    fclose(f);
}
//•	Funkcija koja Objekt3D strukturu zapisuje u tekstualnu STL datoteku

void pise_u_tekstualnu(FILE* f, objekt3D* objekt)
{
    f = fopen("Ispis_binarne_u_tekstualnu.txt", "wt");
    if (!f)
        printf("Neuspjelo otvaranje datoteke!");
    char zaglavlje[] = { "solid OpenSCAD_Model\n" };
    char str1[] ="  facet normal" ;
    char str2[] ="    outer loop";
    char str3[] ="        vertex";
    char str4[] ="    endloop";
    char str5[] ="  endfacet";
    char str6[] = "endsolid OpenSCAD_Model";
    fwrite(zaglavlje, sizeof(zaglavlje), 1, f);
    for (int i = 0; i < objekt->broj_trokuta; ++i)
    {
        fprintf(f, "%s %f %f %f\n", str1, objekt->niz_trokuta[i].Ni, objekt->niz_trokuta[i].Nj, objekt->niz_trokuta[i].Nk);
        fprintf(f, "%s\n", str2);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[0].Vx, objekt->niz_trokuta[i].niz_vrhova[0].Vy, objekt->niz_trokuta[i].niz_vrhova[0].Vz);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[1].Vx, objekt->niz_trokuta[i].niz_vrhova[1].Vy, objekt->niz_trokuta[i].niz_vrhova[1].Vz);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[2].Vx, objekt->niz_trokuta[i].niz_vrhova[2].Vy, objekt->niz_trokuta[i].niz_vrhova[2].Vz);
        fprintf(f, "%s\n", str4);
        fprintf(f, "%s\n", str5);
    }
    fwrite(str6, sizeof(str6), 1, f);
    fclose(f);
}
//brisanje 3d objekta

void delete_objekt(objekt3D* objekt)
{
    free(objekt->niz_trokuta);
    free(objekt);
}
//DODATNA_FUNKCIJA
//Napisati funkciju koja èita tekstualnu STL datoteku.

objekt3D* cita_tekstualnu(FILE* f, FILE* f1, int* br1)
{
    char znak;
    int br = 0;
    objekt3D* objekt;
    objekt = (objekt3D*)malloc(sizeof(objekt3D));
    f = fopen("primjertxt.stl", "rt");
    f1 = fopen("bez_stringova.txt", "wt");
    for (znak = getc(f); znak != EOF; znak = getc(f))
    {
        if ((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z') || (znak == '_'))
        {
            continue;
        }
        else if (znak == '\n')
        {
            br++;
            fputc(znak, f1);
        }
        else
        {
            fputc(znak, f1);
        }
    }
    *br1 = (br + 2) / 7;
    fclose(f);
    fclose(f1);
    f1 = fopen("bez_stringova.txt", "rt");
    objekt->niz_trokuta = (trokut*)malloc(sizeof(trokut) * (*br1));
    for (int i = 0; i < (*br1); i++)
    {
        fscanf(f1, "%f %f %f", &objekt->niz_trokuta[i].Ni, &objekt->niz_trokuta[i].Nj, &objekt->niz_trokuta[i].Nk);
        fscanf(f1, "%f %f %f", &objekt->niz_trokuta[i].niz_vrhova[0].Vx, &objekt->niz_trokuta[i].niz_vrhova[0].Vy, &objekt->niz_trokuta[i].niz_vrhova[0].Vz);
        fscanf(f1, "%f %f %f", &objekt->niz_trokuta[i].niz_vrhova[1].Vx, &objekt->niz_trokuta[i].niz_vrhova[1].Vy, &objekt->niz_trokuta[i].niz_vrhova[1].Vz);
        fscanf(f1, "%f %f %f", &objekt->niz_trokuta[i].niz_vrhova[2].Vx, &objekt->niz_trokuta[i].niz_vrhova[2].Vy, &objekt->niz_trokuta[i].niz_vrhova[2].Vz);
    }
    return objekt;
}
void pise_tekst_u_tekstualnu(FILE* f, objekt3D* objekt, int brojac)
{
    f = fopen("Ispis_teksta_u_tekstualnu.txt", "wt");
    if (!f)
        printf("Neuspjelo otvaranje datoteke!");
    char zaglavlje[] = { "solid OpenSCAD_Model\n" };
    char str1[] = { "  facet normal" };
    char str2[] = { "    outer loop" };
    char str3[] = { "        vertex" };
    char str4[] = { "    endloop" };
    char str5[] = { "  endfacet" };
    fwrite(zaglavlje, sizeof(zaglavlje), 1, f);
    for (int i = 0; i < brojac; ++i)
    {
        fprintf(f, "%s %f %f %f\n", str1, objekt->niz_trokuta[i].Ni, objekt->niz_trokuta[i].Nj, objekt->niz_trokuta[i].Nk);
        fprintf(f, "%s\n", str2);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[0].Vx, objekt->niz_trokuta[i].niz_vrhova[0].Vy, objekt->niz_trokuta[i].niz_vrhova[0].Vz);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[1].Vx, objekt->niz_trokuta[i].niz_vrhova[1].Vy, objekt->niz_trokuta[i].niz_vrhova[1].Vz);
        fprintf(f, "%s %f %f %f\n", str3, objekt->niz_trokuta[i].niz_vrhova[2].Vx, objekt->niz_trokuta[i].niz_vrhova[2].Vy, objekt->niz_trokuta[i].niz_vrhova[2].Vz);
        fprintf(f, "%s\n", str4);
        fprintf(f, "%s\n", str5);
    }
    fclose(f);
}
