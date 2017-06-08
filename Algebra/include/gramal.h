#ifndef GRAMAL_H
#define GRAMAL_H
#include <string>
#include <NTL/ZZ.h>
#include <vector>
#include "Funciones Matematicas.h"
using namespace NTL;
using namespace std;
class gramal
{
    public:
        void generar_claves(int bits);
        gramal(int bits);
        gramal(ZZ e_1,ZZ e_2,ZZ p,int bits);
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

#endif // GRAMAL_H
