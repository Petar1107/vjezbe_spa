#include "longnumber.h"
//promini
LongNumber reverse(LongNumber num)
{
	LongNumber okrenuti=NULL;
	while (num != NULL)
	{
		LongNumber preb = num;
		num = num->next;
		preb->next = okrenuti;
		okrenuti = preb;
	}
	return okrenuti;
}

LongNumber dodaj_u_glavu(LongNumber lst, int broj)
{
	LongNumber novi = (LongNumber)malloc(sizeof(Digit));
	novi->z = broj;
	novi->next = lst;
	return novi;
}

LongNumber read_longnum(char* fname)
{
	FILE* f;
	LongNumber num = NULL;
	f = fopen(fname, "r");
	int broj;
	int c;
	for (c = getc(f); c != EOF; c = getc(f))
	{
		c = c - 48;
		num = dodaj_u_glavu(num, c);
	}
	num = reverse(num);
	return num;
}
void write_longnum(LongNumber num, char* fname)
{
	FILE* f;
	f = fopen(fname, "w");
	while (num != NULL)
	{
		fprintf(f, "%d", num->z);
		num = num->next;
	}
}
void print_longnum(LongNumber num)
{
	while (num != NULL)
	{
		printf("%d", num->z);
		num = num->next;
	}
	printf("\n");
}
void delete_longnum(LongNumber num)
{
	while (num != NULL)
	{
		LongNumber tmp = num;
		num = num->next;
		free(tmp);
	}
}
LongNumber dodaj_na_kraj(LongNumber lst, int broj) {
	LongNumber novi = (LongNumber)malloc(sizeof(Digit));
	novi->z = broj;
	novi->next = NULL;

	if (lst == NULL) {
		return novi;
	}

	LongNumber tmp = lst;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = novi;
	return lst;
}
void izednacava(LongNumber a, LongNumber b)
{
	//Izjednacavanje
	while (a!= NULL || b!= NULL) {
		if (a == NULL) {
			a=dodaj_u_glavu(a, 0);
		}
		if (b == NULL) {
			b = dodaj_u_glavu(b, 0);
		}
		a = a->next;
		b = b->next;
	}
}
LongNumber add_longnum(LongNumber a, LongNumber b)
{
	LongNumber c = NULL;
	int ostatak=0;
	a = reverse(a);
	b = reverse(b);
	while (a != NULL || b != NULL)
	{
		if (a == NULL)
		{
			a = dodaj_u_glavu(a, 0);
		}
		if (b == NULL)
		{
			b = dodaj_u_glavu(b, 0);
		}
		int broj = a->z + b->z;
		if (broj + ostatak > 9)
		{
			int znam = broj % 10;
			c = dodaj_u_glavu(c, (znam + ostatak)%10);
			ostatak = 1;
		}
		else
		{
			c = dodaj_u_glavu(c, broj + ostatak);
			ostatak = 0;
		}
		a = a->next;
		b = b->next;
	}
	if (ostatak)
	{
		c = dodaj_u_glavu(c, ostatak);
	}
	return c;
}
LongNumber mul_by_digit(LongNumber num, int x)
{
	LongNumber numd = NULL;
	int ostatak = 0;
	num = reverse(num);
	while (num != NULL)
	{
		if (num->z * x > 9)
		{
			int znam = (num->z * x) % 10;
			numd = dodaj_u_glavu(numd, (znam + ostatak) % 10);
			ostatak = (num->z * x +ostatak)/10;
		}
		else
		{
			numd = dodaj_u_glavu(numd, (num->z * x) + ostatak);
			ostatak = 0;
		}
		num = num->next;
	}
	if (ostatak)
	{
		numd = dodaj_u_glavu(numd, ostatak);
	}
	return numd;
}
LongNumber mul_by_pow10(LongNumber num, int pow)
{
	LongNumber nume = NULL;
	while (num != NULL)
	{
		nume = dodaj_u_glavu(nume, num->z);
		num = num->next;
	}
	for (int i = 0; i < pow; i++)
	{
		nume = dodaj_u_glavu(nume, 0);
	}
	nume = reverse(nume);
	return nume;
}

LongNumber mul_longnum(LongNumber numa, LongNumber numb) 
{
	LongNumber pomocni = NULL;
	LongNumber numf = NULL;
	int br = 0;
	int i = 0;
	numb = reverse(numb);
	while (numb != NULL) 
	{
		pomocni = mul_by_pow10(numa, i);
		pomocni = mul_by_digit(pomocni, numb->z);
		i++;
		numf = add_longnum(numf, pomocni);
		numb = numb->next;
	}
	return numf;
}
