#ifndef FUNCIONES MATEMATICAS_H
#define FUNCIONES MATEMATICAS_H
#include <vector>
#include <NTL/ZZ.h>
using namespace NTL;
ZZ modulo(ZZ a, ZZ n);
ZZ euclides(ZZ a, ZZ b);
ZZ mcd(ZZ a, ZZ b);
std::vector <ZZ> euclides_extendido(ZZ a, ZZ b);
ZZ inversa(ZZ a, ZZ alfabeto);
ZZ potencia(ZZ a, ZZ b, ZZ modu);
bool fermat(ZZ p);
std::vector<int> criba_Eratostenes(int intervalo_mayor, int intervalo_menor);
int PHI_euler(int num);
int moduloo(int a, int n);
#endif // FUNCIONES MATEMATICAS_H
