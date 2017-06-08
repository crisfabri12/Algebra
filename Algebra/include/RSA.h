#ifndef RSA_H
#define RSA_H
#include <string>
#include <NTL/ZZ.h>
#include <vector>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;
class RSA
{
    public:
        void generar_claves(int bits);
        RSA(ZZ e, ZZ n);
        RSA(int bits);
        ZZ get_N();
        ZZ get_clave_publica();
        string cifrar(std::string mensaje);
        string descifrar(string mensaje);
        void set_clavepublica(ZZ x);
        void set_claveprivada(ZZ x);
        ZZ resto_chino(ZZ c);
        ZZ exponenciacion(ZZ base,ZZ exp);
        void set_N(ZZ x);
    private:
        std::string alfabeto ;
        ZZ d;
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;

};
#endif // RSA_H
