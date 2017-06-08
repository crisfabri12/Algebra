#ifndef FUNCIONES MATEMATICAS_H
#define FUNCIONES MATEMATICAS_H
#include <vector>
#include <string>
#include "GA.h"
#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <sstream>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
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
std::vector<bool> ZZtoBinary(ZZ num);
ZZ stringTozz(string str);
string zzToString(ZZ z);
ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);
#endif // FUNCIONES MATEMATICAS_H
