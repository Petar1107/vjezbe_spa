#include "longnumber.h"
int main(void)
{
	LongNumber numa = read_longnum("a.txt");
	print_longnum(numa);
	LongNumber numb = read_longnum("b.txt");
	print_longnum(numb);
	write_longnum(numa, "upisana_a.txt");
	write_longnum(numb, "upisana_b.txt");
	LongNumber numc = add_longnum(numa, numb);
	print_longnum(numc);
	numa = read_longnum("a.txt");
	LongNumber numd = mul_by_digit(numa, 9);
	print_longnum(numd);
	LongNumber nume = mul_by_pow10(numd, 3);
	print_longnum(nume);
	numa = read_longnum("a.txt");
	numb = read_longnum("b.txt");
	LongNumber numf = mul_longnum(numa, numb);
	print_longnum(numf);
	delete_longnum(numa);
	delete_longnum(numb);
	delete_longnum(numc);
	delete_longnum(numd);
	delete_longnum(nume);
	delete_longnum(numf);
}
