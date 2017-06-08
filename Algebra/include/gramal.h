#ifndef Elgamal_H
#define Elgamal_H
#include <string>
#include <NTL/ZZ.h>
#include <vector>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;
class Elgamal
{
    public:
        void generar_claves(int bits);
        Elgamal(int bits);
        Elgamal(ZZ e_1,ZZ e_2,ZZ p,int bits);
        string cifrar(std::string mensaje);
        string descifrar(string mensaje);
        ZZ raiz_primitiva(ZZ p);
        ZZ get_e1();
        ZZ get_e2();
        ZZ get_P();
        ZZ get_C1();
        void set_d(ZZ d);
        void set_P(ZZ P);
        void set_c(ZZ P);
        void set_e1(ZZ e1);
        void set_e2(ZZ e2);
        void set_k(ZZ k);
    private:
        std::string alfabeto = "0123456789 abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";;
        ZZ d;
        ZZ e_1;
        ZZ e_2;
        ZZ p;
        ZZ r;
        ZZ c;
        ZZ k;

};

#endif // Elgamal_H
