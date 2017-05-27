#ifndef FUNCIONES INT_H
#define FUNCIONES INT_H
#include <vector>

int modulo(int a, int n);
int euclides(int a, int b);
int mcd(int a, int b);
std::vector <int> euclides_extendido(int a, int b);
int inversa(int a, int alfabeto);
int potencia(int a, int b, int modu);
void Teorema_resto();
void resto_chino(int a[],int b[],int tam);
std::vector<int> criba_Eratostenes(int intervalo_mayor, int intervalo_menor);
int* primos(int n);
std::vector<int> ejercicio9(int a,int b);
int ejercicio8(int N,int g,int A);
int gcd(int a, int b);
int xx(int a,int b);
int abs(int x);
std::vector<int> mcd_(int a, int b);
int euclides_(int a, int b);
void random(int seed,int a, int b, int n);
int PHI_euler(int num);
int exponenciacion_2(int a,int p,int n);
int exponenciacion_1(int a,int p, int n);
#endif // FUNCIONES INT_H
